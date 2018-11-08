#[no_mangle]
pub extern "C" fn sum_of_static_array() -> bool {

    let mut sum = 0 as f32;
    for offset in 0..1000 {
        sum = sum + offset as f32;
    }
  
    true
}