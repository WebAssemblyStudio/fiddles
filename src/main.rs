#[no_mangle]
pub extern "C" fn test_comp() -> i32 {
  let data = vec![0x30, 0x3a];
  if (data[0] == 0x30) {
    1
  } else {
    0
  }
}