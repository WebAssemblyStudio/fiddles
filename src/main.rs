#[no_mangle]
pub extern "C" fn run(x: u32) -> u32 {
  popcount( x )
}

fn popcount( mut x: u32 ) -> u32 {
  let mut count = 0;
  while x != 0 {
    if ( x & 1 ) != 0 {
      count += 1;
    }
    x >>= 1;
  }
  count
}
