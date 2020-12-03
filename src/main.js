const { tribonacci } = wasm_bindgen;

function runApp() {
  for (let i = 0; i < 15; ++i) {
    console.log(i, tribonacci(i));
  }
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
