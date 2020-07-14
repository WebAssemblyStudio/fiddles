
fn gcd( a: u32, b: u32 ) -> u32 {
  if b == 0 {
    return a;
  } else {
    return gcd( b, a % b );
  }
}

#[no_mangle]
pub extern "C" fn run( x: u32 ) -> u32 {
  if ( x <= 0x7FFFFFFF ) {
    gcd( x, 2 * x )
  } else {
    x
  }
}
