const { AddResult, add } = wasm_bindgen;

function runApp() {
  add(5, 2);
}

export function addCallback(res) {
  alert(`Result: ${res.to_result()}`);
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp);
