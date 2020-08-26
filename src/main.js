const { greet, add_wasm_by_example_to_string } = wasm_bindgen;

function runApp() {
  greet('World');
  const helloString = add_wasm_by_example_to_string("Hello from ");

  // Log the result to the console
  console.log(helloString);
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);

