#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    x + 1
}

#[no_mangle]
pub extern "C" fn display_array(array_ptr: *const f32, array_length: isize) -> f32 {
  println!("Enter wasm");
    for offset in 0..array_length {
        //unsafe { println!("Rust - value in array: {:?}", *array_ptr.offset(offset)); }
    }
    let mut x:f32 = 0 as f32;
   unsafe {x = *array_ptr.offset(2)};
   x
}