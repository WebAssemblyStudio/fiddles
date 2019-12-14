fn add_one(x: i32) -> (i32,i32) {
  let mut a = 1;
  let mut b = 2;
  for i in 0..x {
    a += 1;
    b += 2;
  }
  ( a, b )
}

#[no_mangle]
pub extern "C" fn foo( x : i32 ) -> i32 {
  let (a,b) = add_one( x );
  a + b
}
