pub enum Foo {
  Even(f64),
  Odd(i32, i32)
}

#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    match even_odd(x - 1) {
      Foo::Even(y) => (13435.0 + y) as i32,
      Foo::Odd(y, z) => x - y + 1000 + z
    }
}

pub fn even_odd(x : i32) -> Foo {
  if x % 2 == 1 {
    Foo::Odd(x, x - 1)
  } else {
    Foo::Even(x as f64)
  }
}