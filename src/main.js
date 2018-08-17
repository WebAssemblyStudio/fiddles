const { greet } = wasm_bindgen;

function runApp() {
  var m = new Map();
  m.set(1, "Value string");
  greet('World', m);
}
wasm_bindgen('../out/main_bg.wasm').then(runApp);
