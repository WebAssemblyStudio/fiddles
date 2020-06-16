extern "C" {
  fn get_magic_number() -> i32;
}

#[no_mangle]
pub fn main() -> i32 {
    unsafe {
      get_magic_number()
    }
}