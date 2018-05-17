const { greet, get_string } = wasm_bindgen;

function runApp() {
  greet('World');
  let strFromWasm = get_string();
  console.log(strFromWasm);

  let otherString = get_string_2();
  console.log(otherString);
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp);
