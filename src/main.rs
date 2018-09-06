#[no_mangle]
pub extern "C" fn test() -> bool {
  let val: i32 = -1;
  let res: u64 = val as u64;
  res == 0xffffffffffffffff // true
}