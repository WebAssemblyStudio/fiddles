

export function accessBad(ptr: usize, index: usize): i32 {
  return load<i32>(ptr + 5 * index, 8);
}

export function accessPOT(ptr: usize, index: usize): i32 {
  return load<i32>(ptr + 4 * index, 8);
}

var offset = 0;
export function accessOpt(ptr: usize, index: usize): i32 {
  var _offset = offset;
  var r = load<i32>(ptr + _offset, 8);
  offset = _offset + 5; // offset += 5
  return r;
}
