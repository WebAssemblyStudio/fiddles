const { greet, sum } = wasm_bindgen

function runApp() {
  alert(greet('World'))
  alert(sum(1, 3))
}

wasm_bindgen('../out/main_bg.wasm')
  .then(
    runApp
  )
