
const arr = new Array<i32>(4000000);

function ensureSize(array: usize, minSize: usize, alignLog2: u32): void {
  var oldCapacity = changetype<ArrayBufferView>(array).byteLength;
  if (minSize > <usize>oldCapacity >>> alignLog2) {
    if (minSize > 1000000 >>> alignLog2) throw new RangeError("");
    let oldData = changetype<usize>(changetype<ArrayBufferView>(array).buffer);
    let newCapacity = minSize << alignLog2;
    let newData = __realloc(oldData, newCapacity);
    memory.fill(newData + oldCapacity, 0, newCapacity - oldCapacity);
    if (newData !== oldData) { // oldData has been free'd
      store<usize>(array, __retain(newData), offsetof<ArrayBufferView>("buffer"));
      store<usize>(array, newData, offsetof<ArrayBufferView>("dataStart"));
    }
    store<u32>(array, newCapacity, offsetof<ArrayBufferView>("byteLength"));
  }
}

export function _set(index: i32, val: i32): void {
  if (<u32>index >= <u32>arr.length) {
    if (index < 0) throw new RangeError("");
    ensureSize(changetype<usize>(arr), index + 1, alignof<i32>());
    arr.length = index + 1;
  }
  unchecked(arr[index] = val);
}

export function _set2(index: i32, val: i32): void {
  ensureSize(changetype<usize>(arr), index + 1, alignof<i32>());
  unchecked(arr[index] = val);
  if (index >= arr.length) arr.length = index + 1;
}
