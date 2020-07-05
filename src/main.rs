
fn min( a : u32, b : u32 ) -> u32 {
  if a < b {
    return a;
  } else {
    return b;
  }
}

#[no_mangle]
pub extern "C" fn run( x: u32 ) -> u32 {
  if x <= 0x7FFFFFFF {
    return min( 2*x, x );
  } else {
    return x;
  }
}
