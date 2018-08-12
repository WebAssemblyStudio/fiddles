function foo<T>(arr: T[]): T[] {
  return arr;
}

export function test(arr: i32[]): i32[] {
  return foo(arr);
}
