fn fib(n: i32) -> i32 {
  if n <= 0 {return 0};
  if n <= 1 {return 1};
  return fib(n - 1) + fib(n - 2);
}

#[no_mangle]
pub extern "C" fn process(n: i32) -> i32 {
  let res = fib(n);
  return res;
}
