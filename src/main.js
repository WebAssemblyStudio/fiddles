const { Hello, greet } = wasm_bindgen;

function runApp() {
  //greet('World');

  var h = new Hello();
  console.log("new h", h);
  console.log("first", h.get());
  h.sort();
  console.log("again", h.get())

}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp);
