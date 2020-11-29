const { greet, greet2, add_one } = wasm_bindgen;

function runApp() {
  let int_return=add_one(123);
  console.log(int_return);
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
