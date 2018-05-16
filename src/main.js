WebAssembly.instantiateStreaming(fetch('../out/main.wasm')).then(obj => {
  const answer = obj.instance.exports.add(12, 30)
  console.log(answer)
})