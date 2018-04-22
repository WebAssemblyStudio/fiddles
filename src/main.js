const { greet, greet2 } = wasm_bindgen;

function runApp() {
  console.log(greet2(5));
  console.log(greet(-1), greet(-2), greet(-3), greet(-4), greet(-5));
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp);
