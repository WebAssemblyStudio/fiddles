const { prepareCropByRust } = wasm_bindgen;

function runApp() {
  myGreet =  prepareCropByRust(
"s", 
600,
450,
180,
214,
0.337,
0.448,
99.663,
99.552,
24.731,
67.469,
67.469,
33.978,
64.165,
20.034,
63.789,
26.25,
62.667,
"2",
1);

  alert (myGreet);
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
