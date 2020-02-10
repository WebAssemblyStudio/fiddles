const { sum } = wasm_bindgen;

function runApp() {
  document.getElementById('result').value = sum(
    document.getElementById('numA').value,
    document.getElementById('numB').value
  );

}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
