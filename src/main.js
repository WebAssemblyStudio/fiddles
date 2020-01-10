const { greet } = wasm_bindgen;

function runApp() {
  //greet('World');
  console.log(Object.keys(wasm_bindgen))
  try {
    console.log(wasm_bindgen.Object)
  } catch (e) {
    console.log("didn't find wasm_bindgen.Object")
  }
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
