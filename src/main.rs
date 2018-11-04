#[no_mangle]
pub extern "C" fn fib(x: i32) -> i32 {
  if x <= 1 { return x; }
  fib(x - 1) + fib(x - 2)
}