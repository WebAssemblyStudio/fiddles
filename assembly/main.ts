export function fib(x: i32): i32 {
  if (x <= 1) return x;
  return fib(x - 1) + fib(x - 2);
}
