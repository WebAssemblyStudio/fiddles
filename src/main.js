const importObject = {
  env: {
    log
  }
}

function getStringFromMemory(offset, length) {
  return Array
    .from(new Uint8Array(memory.buffer, offset, length))
    .map(i => String.fromCharCode(i))
    .join('')
}

function updateHtml(html) {
  const app = document.getElementById('app')
  app.innerHTML = html
}

function log(offset, length) {
  const str = getStringFromMemory(offset, length)
  updateHtml(str)
}

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObject).then(
  obj => {
    memory = obj.instance.exports.memory
    obj.instance.exports.hello_world()
  }
)