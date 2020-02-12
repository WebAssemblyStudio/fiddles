#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
  unsafe {
    *std::mem::transmute::<i32, *mut i32>(x - 41) = 32;
  }
  x + unsafe {
    *std::mem::transmute::<i32, *const i32>(x / 43)
  }
}