const { noise_2, noise_3, noise_4 } = wasm_bindgen;

function runApp() {
  const { log } = console;
  const { random } = Math;

  const a = random();
  const b = random()
  const c = random()
  const d = random();

  log(noise_2(a, b));
  log(noise_3(a, b, c));
  log(noise_4(a, b, c, d));
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
