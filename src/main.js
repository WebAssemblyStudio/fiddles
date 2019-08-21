const { greet } = wasm_bindgen;
const { add_one } = wasm_bindgen;
function runApp() {
  greet('World');
  add_one(8);
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
