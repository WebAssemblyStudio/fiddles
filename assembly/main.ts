

export function access1(ptr: usize, index: usize): i32 {
  return load<i32>(ptr + 5 * index, 8);
}
