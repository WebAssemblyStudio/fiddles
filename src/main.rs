/*
 What is memory?
 [0, 0, 0, 0, 32, 0]

 1st : put the string in memory
 2nd : send offset and length
 3rd : retreive the string from javascript
*/


#[no_mangle]
pub extern "C" fn add(a: i32, b: i32) -> i32 {
  a + b
}