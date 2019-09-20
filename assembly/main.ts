export const addImpl = (a: i32, b: i32): i32 => {
  return a + b;
};

export function add(a: i32, b: i32, impl: (a: i32, b: i32) => i32): i32 {
  return impl(a, b);
}
