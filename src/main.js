const instanceObject = {
  env: {
    log
  }
}

function log(offset, length) {
  console.log(`I received this from rust ${offset} ${length}`)
}

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), instanceObject).then(
  obj => {
    obj.instance.exports.hello_world()
  }
)