#[no_mangle]
pub extern "C" fn sum_of_array(array_ptr: *const f32, array_length: isize) -> f32 {
  println!("Enter wasm");
  let mut sum = 0 as f32;
    for offset in 0..array_length {
        unsafe { sum = sum + *array_ptr.offset(offset) }
    }
    sum
}