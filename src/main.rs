static mut DATA: [u32; 5] = [0; 5];

#[no_mangle]
pub extern "C" fn data( ) -> *mut u32 {
  unsafe {
    DATA.as_mut_ptr( )
  }
}


#[no_mangle]
pub extern "C" fn run( ) -> u32 {
  unsafe {
    let mut sum = 0;
    for x in &DATA {
      sum += x;
    }
    for x in &DATA {
      sum += x;
    }

    sum
  }
}