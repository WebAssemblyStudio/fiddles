const { sum } = wasm_bindgen;

function runApp() {
  var result = sum(1, 2);
  alert(result);
}

wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
