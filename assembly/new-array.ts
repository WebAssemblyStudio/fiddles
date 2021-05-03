import { BLOCK_MAXSIZE } from "rt/common";
import { E_INDEXOUTOFRANGE, E_INVALIDLENGTH, E_ILLEGALGENTYPE, E_EMPTYARRAY, E_HOLEYARRAY } from "util/error";

// @inline @lazy const MIN_CAPACITY = 8;
@inline @lazy const MIN_CAPACITY = 12;


// NOTE: n should fix in range (1; 1 << 31]
// @ts-ignore: decorator
@inline function nextPowerOf2(n: usize): usize {
  return 1 << 32 - clz(n - 1);
}

function ensureCapacity(array: usize, minSize: usize, alignLog2: u32, canGrow: bool = true): void {
  // Depends on the fact that Arrays mimic ArrayBufferView
  var oldCapacity = <usize>changetype<ArrayBufferView>(array).byteLength;
  if (minSize > oldCapacity >>> alignLog2) {
    if (minSize > BLOCK_MAXSIZE >>> alignLog2) throw new RangeError(E_INVALIDLENGTH);
    let oldData = changetype<usize>(changetype<ArrayBufferView>(array).buffer);
    let newCapacity = max<usize>(minSize, MIN_CAPACITY) << alignLog2;
    if (canGrow) {
      // Find next power of two size. It usually grows old capacity by factor of two.
      // Make sure we don't reach BLOCK_MAXSIZE for new growed capacity.
      // newCapacity = min<usize>(nextPowerOf2(newCapacity), BLOCK_MAXSIZE);
      newCapacity = min<usize>(oldCapacity * 2, BLOCK_MAXSIZE);
      // newCapacity = min<usize>(((oldCapacity + 20) << 1) - 20, BLOCK_MAXSIZE);
    }
    let newData = __renew(oldData, newCapacity);
    memory.fill(newData + oldCapacity, 0, newCapacity - oldCapacity);
    if (newData !== oldData) { // oldData has been free'd
      store<usize>(array, newData, offsetof<ArrayBufferView>("buffer"));
      store<usize>(array, newData, offsetof<ArrayBufferView>("dataStart"));
      __link(array, changetype<usize>(newData), false);
    }
    store<u32>(array, <u32>newCapacity, offsetof<ArrayBufferView>("byteLength"));
  }
}

export class NewArray<T> {
  [key: number]: T;

  // Mimicking ArrayBufferView isn't strictly necessary here but is done to allow glue code
  // to work with typed and normal arrays interchangeably. Technically, normal arrays do not need
  // `dataStart` (equals `buffer`) and `byteLength` (equals computed `buffer.byteLength`), but the
  // block is 16 bytes anyway so it's fine to have a couple extra fields in there.

  private buffer: ArrayBuffer;
  @unsafe readonly dataStart: usize;
  private byteLength: i32;

  // Also note that Array<T> with non-nullable T must guard against uninitialized null values
  // whenever an element is accessed. Otherwise, the compiler wouldn't be able to guarantee
  // type-safety anymore. For lack of a better word, such an array is "holey".

  private length_: i32;

  constructor(length: i32 = 0) {
    if (<u32>length > <u32>BLOCK_MAXSIZE >>> alignof<T>()) throw new RangeError(E_INVALIDLENGTH);
    // reserve capacity for at least MIN_CAPACITY elements
    var bufferSize = <usize>max(length, MIN_CAPACITY) << alignof<T>();
    var buffer = changetype<ArrayBuffer>(__new(bufferSize, idof<ArrayBuffer>()));
    memory.fill(changetype<usize>(buffer), 0, bufferSize);
    this.buffer = buffer; // links
    this.dataStart = changetype<usize>(buffer);
    this.byteLength = <i32>bufferSize;
    this.length_ = length;
  }

  get length(): i32 {
    return this.length_;
  }

  set length(newLength: i32) {
    ensureCapacity(changetype<usize>(this), newLength, alignof<T>(), false);
    this.length_ = newLength;
  }

  @operator("[]") private __get(index: i32): T {
    if (<u32>index >= <u32>this.length_) throw new RangeError(E_INDEXOUTOFRANGE);
    var value = load<T>(this.dataStart + (<usize>index << alignof<T>()));
    if (isReference<T>()) {
      if (!isNullable<T>()) {
        if (!changetype<usize>(value)) throw new Error(E_HOLEYARRAY);
      }
    }
    return value;
  }

  @unsafe @operator("{}") private __uget(index: i32): T {
    return load<T>(this.dataStart + (<usize>index << alignof<T>()));
  }

  @operator("[]=") private __set(index: i32, value: T): void {
    if (<u32>index >= <u32>this.length_) {
      if (index < 0) throw new RangeError(E_INDEXOUTOFRANGE);
      ensureCapacity(changetype<usize>(this), index + 1, alignof<T>());
      this.length_ = index + 1;
    }
    this.__uset(index, value);
  }

  @unsafe @operator("{}=") private __uset(index: i32, value: T): void {
    store<T>(this.dataStart + (<usize>index << alignof<T>()), value);
    if (isManaged<T>()) {
      __link(changetype<usize>(this), changetype<usize>(value), true);
    }
  }

  push(value: T): i32 {
    var length = this.length_;
    var newLength = length + 1;
    ensureCapacity(changetype<usize>(this), newLength, alignof<T>());
    if (isManaged<T>()) {
      store<usize>(this.dataStart + (<usize>length << alignof<T>()), changetype<usize>(value));
      __link(changetype<usize>(this), changetype<usize>(value), true);
    } else {
      store<T>(this.dataStart + (<usize>length << alignof<T>()), value);
    }
    this.length_ = newLength;
    return newLength;
  }
}