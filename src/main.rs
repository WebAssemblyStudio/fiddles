#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
  let mut a = 0;
  let mut b = x;
    while b != 0 {
      a += 1;
      b -= 1;
    }
    a
}