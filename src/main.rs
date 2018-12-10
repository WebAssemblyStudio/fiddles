#[no_mangle]
pub extern "C" fn compute_something_complicated(x: i32, y: i32, z: i32) -> i32 {
    let mut result = x + y;
    for i in 0..x {
     for j in 0..y {
      result += z*i + j*y
    } 
    }

    return result * x + y + z;
}