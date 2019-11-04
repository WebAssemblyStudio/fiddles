const { Decoder } = wasm_bindgen;

function runApp() {
  const decoder = new Decoder();
  console.log(decoder);
}

wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
