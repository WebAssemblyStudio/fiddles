const { Hello } = wasm_bindgen;

function runApp() {

  var h = new Hello();
  console.log("new h", h); // logs Hello { ptr: undefined } .. which seems wrong.
  console.log("first", h.get());

}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp);
