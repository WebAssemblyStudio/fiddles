const instanceObject = {
  env: {
    update_html
  }
}

function update_html(offset, length) {
  const str = Array.from(new Uint8Array(memory.buffer, offset, length))
  console.log(str)
}

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), instanceObject).then(
  obj => {
    memory = obj.instance.exports.memory
    obj.instance.exports.hello_world()
  }
)