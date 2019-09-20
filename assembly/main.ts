export const addImpl = (a: i32, b: i32): i32 => {
  return a + b;
};

function sub(a: i32, b: i32): i32 {
  return a - b;
}

export const subImpl = sub;

export function calc(a: i32, b: i32, impl: (a: i32, b: i32) => i32): i32 {
  return impl(a, b);
}
