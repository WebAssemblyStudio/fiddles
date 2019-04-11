window['aes']=(key,param)=>{
  return `${key}--${param}`
}

const { s } = wasm_bindgen;

function runApp() {
  console.log(s("ndsfjksnfkj"))
  
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
