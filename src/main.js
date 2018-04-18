WebAssembly.instantiateStreaming(fetch('../out/main.wasm')).then(
  obj => {
    const answer = obj.instance.exports.add(22, 20)
    console.log(answer)
  }
)