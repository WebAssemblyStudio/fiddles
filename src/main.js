(async () => {
  const codePromise = fetch('../out/main.wasm')
  const module = await WebAssembly.instantiateStreaming(codePromise)

  const { instance } = module
  
  const add = instance.exports.add
  const minus = instance.exports.minus

  const a = 1, b = 2

  document.getElementById('add').textContent = `Tổng của ${a} và ${b} là ${add(1,2)}`
  document.getElementById('minus').textContent = `Hiệu của ${a} trừ ${b} là ${minus(1,2)}`

})()
