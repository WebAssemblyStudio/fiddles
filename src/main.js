const { noise_2D, noise_3D, noise_4D } = wasm_bindgen;

function runApp() {
  console.log("Hello");
}

(async () => {
  const response = await fetch("../out/main_bg.wasm");
  const blob = await response.blob();

  const url = URL.createObjectURL(blob);

  window.top.open(url);
})().catch(console.error);

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
