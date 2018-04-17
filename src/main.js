const instanceObject = {
  env: {
    update
  }
}

function getStringFromMemory(offset, length) {
  return Array
    .from(new Uint8Array(memory.buffer, offset, length))
    .map(c => String.fromCharCode(c))
    .join('')
}

function render(html) {
  const app = document.getElementById("app")
  app.innerHTML = html
}

function update(offset, length) {
  const str = getStringFromMemory(offset, length)
  render(str)
}

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), instanceObject).then(
  obj => {
    memory = obj.instance.exports.memory
    obj.instance.exports.hello_world()
  }
)
