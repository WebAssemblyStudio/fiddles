const { Data } = wasm_bindgen;

const WORD = 'hoge'

function runApp() {
  const data = Data.new(WORD)
  console.time('wasm')
  const result = data.repeat(100)
  console.timeEnd('wasm')
  data.free()
  // console.log(result)
}

wasm_bindgen('../out/main_bg.wasm').then(runApp);
