extern "C" {
  fn wasm_log(start:usize,len:usize);
}

fn log(msg:&str){
  let start = msg.as_ptr();
  let len = msg.len();
  unsafe {
      wasm_log(start as usize,len);
  }
}

#[no_mangle]
pub fn main() {
  log("hello world!");
}