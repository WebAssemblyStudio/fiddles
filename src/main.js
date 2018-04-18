WebAssembly.instantiateStreaming(fetch('../out/main.wasm')).then(
  obj => {
    const add = obj.instance.exports.add()
    console.log(add(1,2))
  }
)