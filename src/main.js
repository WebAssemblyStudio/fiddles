const { teste } = wasm_bindgen;

function runApp() {
  //console.log(sum(1,2));
  console.log(teste("jadsom"));
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
