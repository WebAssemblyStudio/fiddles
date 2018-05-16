WebAssembly.instantiateStreaming(fetch('../out/main.wasm')).then(obj => {
  const answer = obj.instance.exports.fib(12)
  console.log(answer)
})