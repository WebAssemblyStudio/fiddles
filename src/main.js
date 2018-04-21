const { Data } = wasm_bindgen;

function runApp() {
  const data = Data.new(20)
  console.log(data)
  alert(data.getValue())
  data.free()
  console.log(data)
}

wasm_bindgen('../out/main_bg.wasm').then(runApp);
