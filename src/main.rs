#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
  unsafe {
    *((x - 41) as *mut i32) = 32;
  }
  x + unsafe {
    *((x / 42) as *mut i32)
  }
}