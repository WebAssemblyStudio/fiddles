@inline
function foo(x: i32): i32 {
  if (isConstant(x)) {
    return -1;
  } else {
    return x;
  }
}

export function test(): i32 {
  return foo(10);
}
