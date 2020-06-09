#[no_mangle]
pub extern "C" fn run_extern( a: u32, b: u32, c: u32 ) -> u32 {
  run( a, b, c )
}

fn run( a: u32, b: u32, c: u32 ) -> u32 {
  if a < b {
    if b < c {
      if c < a { // Never true
        return 2;
      }
    }
  }
  return 1;
}
