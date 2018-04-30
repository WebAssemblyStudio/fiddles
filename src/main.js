const { Data } = wasm_bindgen

const WORD = 'hoge'
const COUNT = 10000

function runJs1() {
  let str = ''
  console.time('js1')
  for (let i = 0; i < COUNT; i++) {
    str += WORD
  }
  console.timeEnd('js1')
}

function runJs2() {
  const arr = Array(COUNT).fill(0)
  console.time('js2')
  arr.map(() => WORD).join('')
  console.timeEnd('js2')
}

function runWasm() {
  const data = Data.new(WORD)
  console.time('wasm')
  const result = data.repeat(COUNT)
  console.timeEnd('wasm')
  data.free()
  // console.log(result)
}

runJs1()
runJs2()
wasm_bindgen('../out/main_bg.wasm').then(runWasm)
