struct Store {
  val: i32,
}

static mut store: Store = Store { val: 4 };

#[no_mangle]
pub fn add(a: i32) -> i32 {
  unsafe {
    store.val += a;
    store.val
  }
}