#[no_mangle]

use pos::*;

pub extern "C" fn add_one(x: i32) -> i32 {
//    x + 1

  let p = pos::new();
  p.x + p.y
}

