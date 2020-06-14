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

fn invoke_function_5(fn_handle:usize,a:f64,b:f64,c:f64,d:f64,e:f64) -> f64 {
  unsafe {
      js_invoke_function(fn_handle,a,b,c,d,e,0.0,0.0,0.0,0.0,0.0)
  }
}

fn get_2d_context(msg:&str) -> f64 {
  let fn_get_2d_context = register_function(r#"
  (context, selectorStart, selectorEnd) => {
    let selector = context.getUtf8FromMemory(selectorStart,selectorEnd);
    let obj = document.querySelector(selector);
    return context.storeObject(obj.getContext("2d"));
  }"#);
  let start = msg.as_ptr();
  let len = msg.len();
  invoke_function_2(fn_get_2d_context,start as usize as f64,len as f64)
}

fn set_color(ctxHandle:f64, color:&str) {
  let fn_set_color = register_function(r#"
  (context, ctxHandle, colorStart, colorEnd) => {
    let color = context.getUtf8FromMemory(colorStart, colorEnd);
    let ctx = context.getObject(ctxHandle);
    ctx.fillStyle = color;
  }"#);
  let start = color.as_ptr();
  let len = color.len();
  invoke_function_3(fn_set_color, ctxHandle, start as usize as f64,len as f64);
}

fn fill_rect(ctxHandle:f64, x:f64, y:f64, width:f64, height:f64) {
  let fn_fill_rect = register_function(r#"
  (context, ctxHandle, x, y, width, height) => {
    let ctx = context.getObject(ctxHandle);
    ctx.fillRect(x, y, width, height);
  }"#);
  invoke_function_5(fn_fill_rect, ctxHandle, x, y, width, height);
}

#[no_mangle]
pub fn main() {
  let ctx = get_2d_context("#screen");
  set_color(ctx,"red");
  fill_rect(ctx,10.0,10.0,50.0,50.0);
}