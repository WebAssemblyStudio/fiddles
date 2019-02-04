export function fib(x: f64): f64 {
  if (x <= 1) return x;
  return fib(x - 1) + fib(x - 2);
}
