#[no_mangle]
pub extern "C" fn run( a : u32, b : u32, c : u32 ) -> u32 {
  if a > b {
    if b > c {
      if a <= c {
        return 2; // This can never happen
      }
    }
  }
  1
}
