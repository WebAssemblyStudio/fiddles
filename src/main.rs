#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
  println!("{}",1);
  x + 1
}