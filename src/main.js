const { greet } = wasm_bindgen;

function runApp() {
  greet('World');
}

(async () => {
  const runApp = await wasm_bindgen('../out/main_bg.wasm')
  console.log(wasm_bindgen)
  runApp()
})()
