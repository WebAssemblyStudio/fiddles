
const arr = new Array<i32>(4000000);

export function _set(index: i32, val: i32): void {
  if (<u32>index >= <u32>arr.length) {
    if (index < 0) throw new RangeError("");
    arr.length = index + 1;
  }
  unchecked(arr[index] = val);
}

export function _set2(index: i32, val: i32): void {
  if (!(<u32>index >= <u32>arr.length)) {
    unchecked(arr[index] = val);
  } else {
    if (index < 0) throw new RangeError("");
    arr.length = index + 1;
    unchecked(arr[index] = val);
  }
}
