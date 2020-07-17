export function fibo(n: i32): i32 {
  if (n < 2)
    return 1;
  else
    return fibo(n-1) + fibo(n-2);
}
