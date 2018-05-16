/*
  >Let's do an hello world<

  What is memory anyway?
  [0, 0, 0, 0, 0, 85, 122, 132, 123, 0, 0, 0, 0]

  1. Put a string in memory
  2. Send the offset and the length to javascript
  3. In javascript, extract the string and parse it
*/


#[no_mangle]
pub extern "C" fn add(a: i32, b: i32) -> i32 {
  a + b
}