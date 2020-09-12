declare function foo(): i32;

// 103 bytes
export function test1(): i32 {
  return foo() | 1;
}

export function test2(): i32 {
  foo();
  return 1;
}