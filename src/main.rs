#[no_mangle]
pub extern "C" fn fibonacci(x: i32) -> i32 {
  match x {
    1 | 2 => 1,
    _ => fibonacci(x - 1) + fibonacci(x - 2)
  }
}