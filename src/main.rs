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

fn invoke_function_3(fn_handle:usize,a:f64,b:f64,c:f64) -> f64 {
  unsafe {
      js_invoke_function(fn_handle,a,b,c,0.0,0.0,0.0,0.0,0.0,0.0,0.0)
  }
}

fn query_selector(msg:&str) -> f64 {
  let fn_query_selector = register_function(r#"
  (context, selectorStart, selectorEnd) => {
    let selector = context.getUtf8FromMemory(selectorStart,selectorEnd);
    let obj = document.querySelector(selector);
    return context.storeObject(obj);
  }"#);
  let start = msg.as_ptr();
  let len = msg.len();
  invoke_function_2(fn_query_selector,start as usize as f64,len as f64)
}

fn set_inner_html(elHandle:f64, msg:&str) {
  let fn_set_inner_html = register_function(r#"
  (context, elemHandle, msgStart, msgEnd) => {
    let msg = context.getUtf8FromMemory(msgStart,msgEnd);
    let el = context.getObject(elemHandle);
    el.innerHTML = msg;
  }"#);
  let start = msg.as_ptr();
  let len = msg.len();
  invoke_function_3(fn_set_inner_html, elHandle, start as usize as f64,len as f64);
}

#[no_mangle]
pub fn main() {
  let el = query_selector("#container");
  set_inner_html(el,"<b>Hello World!</b>");
}