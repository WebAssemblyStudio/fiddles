(async () => {
  const codePromise = fetch('../out/main.wasm')
  const { instance } = await WebAssembly.instantiateStreaming(codePromise)
  const buffer = new Uint8Array(instance.exports.memory.buffer)
  const pointer = instance.exports.printText()

  const _point = instance.exports.check()
  const _Ppoint = instance.exports._Rstring()
  if (_point == 1) {
    let print = ""
    for(let i = _Ppoint; buffer[i]; i++) {
      print += String.fromCharCode(buffer[i])
    }
    console.log(print)
  }

  let string = ""
  for(let i = pointer; buffer[i]; i++) {
    string += String.fromCharCode(buffer[i])
  }
  document.getElementById('container').textContent = string
})()