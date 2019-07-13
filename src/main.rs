#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
  return x + 101;
}