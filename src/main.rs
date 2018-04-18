
#[no_mangle] // When compiling don't mess with the name
// Define a function, add, which takes in 2 integers and returns an integer
// pub extern C allows other languages to use the function -- function itself starts from fn
pub extern "C" fn add(a: i32, b: i32) -> i32 {
 a + b
}


/*

Since there are no strings in webassembly, to output a string you need:
1) Put the string in memory
2) Send the offset and length of the string to javascript
3) Javascript needs to get and parse the string from memory

*/

use std::ffi::CString;

extern "C" {
  fn log(_: i32, _: i32);
}

#[no_mangle]
pub unsafe extern "C" fn hello_world() {
  let string = "Hello world!"; // create the string
  let length = string.len() as i32; // grab the length
  let cstring = CString::new(string).unwrap(); // set it as a cstring value
  let offset = cstring.into_raw() as i32; // put it into memory
  log(offset, length) // send it to javascript
}