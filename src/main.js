(async() => {
  const codePromise = fetch('../out/main.wasm')
  const {instance} = await WebAssembly.instantiateStreaming(codePromise)

  const buffer = new Uint8Array(instance.exports.memory.buffer)

  const pointer = instance.exports.helloStr()

  let string=""
  for(let i=pointer; buffer[i]; i++){
    string += String.fromCharCode(buffer[i])
  }

  document.getElementById('container').textContent = string

  //sqroot number
  document.getElementById('number').textContent = instance.exports.rootsq(7)

})()
