
function foo(val: i32): i32 {
  return val + 1;
}

@inline
function test(a: i32): void {
  if (!a) return;
  foo(a);
}

export function boo(a: i32): i32 {
  test(a);
  return foo(a);
} 
