/*
 What is memory?
 [0, 0, 0, 0, 32, 0]

 1st : put the string in memory
 => 2nd : send offset and length
 3rd : retreive the string from javascript
*/

extern "C" {
  fn log(_:i32, _:i32);
}

#[no_mangle]
pub unsafe extern "C" fn hello_world() {
  log(32, 12)
}