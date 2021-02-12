#[no_mangle]
pub extern "C" fn mul4(cond: i32, z: i32) -> i32 {
  let mut x;
  let mut y;

  if cond != 0 {
    x = 3 * z;
    y = z;
  } else {
    x = 2 * z;
    y = 2 * z;
  }
  x + y
}
