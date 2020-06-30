extern "C" {
  fn js_register_function(start:usize,len:usize) -> usize; 
  fn js_invoke_function(fn_handle:usize,a:f64,b:f64,c:f64,d:f64,e:f64,f:f64,g:f64,h:f64,i:f64,j:f64)->f64;
}

fn register_function(code:&str) -> usize{
  let start = code.as_ptr();
  let len = code.len();
  unsafe {
      js_register_function(start as usize,len)
  }
}

fn invoke_function_2(fn_handle:usize,a:f64,b:f64) -> f64 {
  unsafe {
      js_invoke_function(fn_handle,a,b,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0)
  }
}

fn log(msg:&str) {
  let fn_log = register_function(r#"
  (context, msgStart, msgEnd) => {
    let msg = context.getUtf8FromMemory(msgStart,msgEnd);
    console.log(msg); 
    // Le message est également afficher à l'écran.
    document.getElementById("container").innerHTML += msg+"<br>";
  }"#);
  let start = msg.as_ptr();
  let len = msg.len();
  invoke_function_2(fn_log,start as usize as f64,len as f64);
}

#[no_mangle]
pub fn main() {
  log("hello world")
}