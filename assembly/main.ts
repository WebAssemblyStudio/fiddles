function loadTheThing<T>(input: T, offset: i32): i32 {
  return load<i32>(changetype<usize>(input) + offset);
}

export function foo(input: i32):  void {
  loadTheThing<i32>(input, 4);
}
