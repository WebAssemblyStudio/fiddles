const { greet, addition } = wasm_bindgen;

function runApp() {
  greet('World');
  let r = addition(2, 8);
  alert(r)
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp);
