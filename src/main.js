(async () => {
  const {instance} = await WebAssembly.instantiateStreaming(fetch('../out/main.wasm'))
  console.log(instance)

  const buffer = instance.exports.memory.buffer
  const pointer=instance.exports.helloWorld()
})()
