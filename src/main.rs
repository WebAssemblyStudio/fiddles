// Produces ( x+1, (x+1)*2 )
fn foo(x: u32) -> (u32,u32) {
  let mut a = 1;
  let mut b = 2;
  for i in 0..x {
    a += 1;
    b += 2;
  }
  ( a, b )
}

#[no_mangle]
pub extern "C" fn run( x : u32 ) -> u32 {
  let (a,b) = foo( x );
  a + b // (x+1)*3
}
