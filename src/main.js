const { Decoder } = wasm_bindgen;

function runApp() {
  const decoder = new Decoder();
}

wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
