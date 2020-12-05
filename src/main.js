(async () => {
  // Load and instantiate the wasm file, and we specify the source of the wasm
  // file here. Once the returned promise is resolved we're ready to go and
  // use our imports.
  await wasm_bindgen('../out/main_bg.wasm');

  const { tribonacci } = wasm_bindgen.wasm;

  for (let i = 0; i < 15; ++i) {
    console.log(i, tribonacci(i));
  }

})().catch(console.error);