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
    mul2( &mut DATA );
    add1( &mut DATA );
  }
}

fn mul2( data: &mut [u32] ) {
  for i in 0..data.len( ) {
    data[ i ] *= 2;
  }
}

fn add1( data: &mut [u32] ) {
  for i in 0..data.len( ) {
    data[ i ] += 1;
  }
}
