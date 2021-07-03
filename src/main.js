(async () => {
  const codePromise = fetch ('../out.main.wasm')
  const { instance } = await WebAssembly.instantiateStreaming(codePromise)

  const buffer = instance.exports.memory.buffer // [128734, 324231, 12,3,12 3, 'H', 'E', 'L', 'L']

  const pointer = instance.exports.helloWorld()

  let string = ""
  for(let i = pointer; buffer[i]; i++) {
    string += String.fromCharCode(buffer[i])
  }

  document.getElementById('container').textContent = string
})()