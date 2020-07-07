static mut DATA: [u32; 8] = [1,2,3,4,5,6,7,8];

#[no_mangle]
pub extern "C" fn ptr( ) -> *const u32 {
  unsafe {
    DATA.as_ptr( )
  }
}

#[no_mangle]
pub extern "C" fn run( ) {
  unsafe {
    for i in 0..8 {
      if i < 4 {
        DATA[ i ] += 3;
      } else if i < 100 {
        DATA[ i ] += 9;
      } else {
        DATA[ i ] += 5;
      }
    }
  }
}
