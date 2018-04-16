const importObject = {
  env: {
    log
  }
}

function log(offset, length) {
  console.log(`Hey, this is from rust: ${offset}, ${length}`)
}

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObject).then(
  obj => {
    obj.instance.exports.hello_world()
  }
)