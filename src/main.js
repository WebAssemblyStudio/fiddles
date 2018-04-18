const instanceObject = {
  env: {
    update_html
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

function update_html(offset, length) {
  const str = getStringFromMemory(offset, length)
  render(str)
}

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), instanceObject).then(
  obj => {
    memory = obj.instance.exports.memory
    update = obj.instance.exports.update
    obj.instance.exports.init()
  }
)
