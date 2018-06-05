extern {
  fn notify_on_update(f: SOMETHING) -> ();
  // fn notify_on_update(f: &Fn() -> ()) -> (); // does not work
}

// notify_on_update() should take this function as a param
// notify_on_update(&update);
pub extern "C" fn update() -> () {
}
