const { greet } = wasm_bindgen;
const { greet2 } = wasm_bindgen;
const { windowcommand } = wasm_bindgen;

function runApp() {
  greet('greet111111');
  greet2('greet222222');
  windowcommand('dir');
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
