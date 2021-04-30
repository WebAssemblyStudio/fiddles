import { BLOCK_MAXSIZE } from "rt/common";
import { E_INDEXOUTOFRANGE, E_INVALIDLENGTH, E_ILLEGALGENTYPE, E_EMPTYARRAY, E_HOLEYARRAY } from "util/error";

@inline function nextPowerOf2(n: u32): u32 {
  return n == 0 ? 8 : 1 << (32 - clz(n - 1));
}

/** Ensures that the given array has _at least_ the specified backing size. */
function ensureSize(array: usize, minSize: usize, alignLog2: u32, growFactor: u32 = 0): void {
  // depends on the fact that Arrays mimic ArrayBufferView
  var oldCapacity = changetype<ArrayBufferView>(array).byteLength;
  if (minSize > <usize>oldCapacity >>> alignLog2) {
    if (minSize > BLOCK_MAXSIZE >>> alignLog2) throw new RangeError(E_INVALIDLENGTH);
    let oldData = changetype<usize>(changetype<ArrayBufferView>(array).buffer);
    // let newCapacity = minSize << alignLog2 + growFactor;
    // let newCapacity = growFactor
    //   ? max(8 << alignLog2, <usize>oldCapacity) << 1
    //   : minSize << alignLog2;
    let newCapacity = nextPowerOf2(minSize << alignLog2);
    let newData = __renew(oldData, newCapacity);
    memory.fill(newData + oldCapacity, 0, newCapacity - oldCapacity);
    if (newData !== oldData) { // oldData has been free'd
      store<usize>(array, newData, offsetof<ArrayBufferView>("buffer"));
      store<usize>(array, newData, offsetof<ArrayBufferView>("dataStart"));
      __link(array, changetype<usize>(newData), false);
    }
    store<u32>(array, newCapacity, offsetof<ArrayBufferView>("byteLength"));
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

  static create<T>(capacity: i32 = 0): Array<T> {
    WARNING("'Array.create' is deprecated. Use 'new Array' instead, making sure initial elements are initialized.");
    var array = new Array<T>(capacity);
    array.length = 0;
    return array;
  }

  constructor(length: i32 = 0) {
    if (<u32>length > <u32>BLOCK_MAXSIZE >>> alignof<T>()) throw new RangeError(E_INVALIDLENGTH);
    var bufferSize = <usize>max(8, length) << alignof<T>(); // change
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
    ensureSize(changetype<usize>(this), newLength, alignof<T>());
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
      ensureSize(changetype<usize>(this), index + 1, alignof<T>(), 1);
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
    ensureSize(changetype<usize>(this), newLength, alignof<T>(), 1);
    if (isManaged<T>()) {
      store<usize>(this.dataStart + (<usize>length << alignof<T>()), changetype<usize>(value));
      __link(changetype<usize>(this), changetype<usize>(value), true);
    } else {
      store<T>(this.dataStart + (<usize>length << alignof<T>()), value);
    }
    this.length_ = newLength;
    return newLength;
  }

  pop(): T {
    var length = this.length_;
    if (length < 1) throw new RangeError(E_EMPTYARRAY);
    var element = load<T>(this.dataStart + (<usize>(--length) << alignof<T>()));
    this.length_ = length;
    return element;
  }

  // RT integration

  @unsafe private __visit(cookie: u32): void {
    if (isManaged<T>()) {
      let cur = this.dataStart;
      let end = cur + (<usize>this.length_ << alignof<T>());
      while (cur < end) {
        let val = load<usize>(cur);
        if (val) __visit(val, cookie);
        cur += sizeof<usize>();
      }
    }
    __visit(changetype<usize>(this.buffer), cookie);
  }
}