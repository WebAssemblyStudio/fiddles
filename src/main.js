const importObject = {
  env: {
    log
  }
}

function log(offset, length) {
  const str = Array
    .from(new Uint8Array(memory.buffer, offset, length))
    .map(i => String.fromCharCode(i))
    .join('')
  console.log(`Hey, this is from rust: ${str}`)
}

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObject).then(
  obj => {
    memory = obj.instance.exports.memory
    obj.instance.exports.hello_world()
  }
)