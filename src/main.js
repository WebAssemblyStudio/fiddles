const instanceObject = {
  env: {
    update_html
  }
}

function render(html) {
  const app = document.getElementById('app')
  app.innerHTML = html
}

function update_html(offset, length) {
  const str = Array.from(new Uint8Array(memory.buffer, offset, length))
    .map(c => String.fromCharCode(c))
    .join('')
  render(str)
}

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), instanceObject).then(
  obj => {
    memory = obj.instance.exports.memory
    obj.instance.exports.hello_world()
  }
)