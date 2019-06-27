export function createTypedArray<TArray, T>(
  buffer: ArrayBuffer, 
  byteOffset: usize = 0, 
  length: i32 = 0
): TArray {
  if (buffer.byteLength - byteOffset > length * sizeof<T>()) {
    throw new RangeError("Invalid typed array length");
  }
  var arr = __alloc(offsetof<TArray>(), idof<TArray>());
  store<ArrayBuffer>(arr, buffer, 0); // buffer
  store<ArrayBuffer>(arr, changetype<usize>(buffer) + byteOffset, sizeof<usize>()); // dataStart
  store<i32>(arr, length * sizeof<T>(), sizeof<usize>() * 2); // dataLength
  return changetype<TArray>(arr);
}

let buf = new ArrayBuffer(32);
let indices = createTypedArray<Int32Array, i32>(buf, 8, 24 / 4);

assert(indices.buffer === buf);
assert(indices.byteOffset == 8);
assert(indices.byteLength == 24);
assert(indices.length == 24 / 4);
