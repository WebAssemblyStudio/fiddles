var memory = new WebAssembly.Memory({ initial: 20 })

const importObject = {
  env: {
    log,
    memory
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
    obj.instance.exports.hello_world()
  }
)