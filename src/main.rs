#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    x + 1
}

#[no_mangle]
pub extern "C" fn mod_fortytwo(x: i32) -> i32 {
    x % 42
}

fn slide(x:i32, y:i32) -> i32 {
  x ^ y
}

#[no_mangle]
pub extern "C" fn wiggle(a: i32) -> i32 {
    let mut x = a;
    let mut y = x ^ 5286852;
    for i in 1..100 {
      let old = x;
      x = slide(x, y);
      y = old;
    }
    x
}