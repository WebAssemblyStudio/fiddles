#[no_mangle]
pub extern "C" fn run( a: u32 ) -> u32 {
  // Always returns 'a'
  if a < 0x80 {
    return a & 0xFF;
  } else {
    return a;
  }
}
