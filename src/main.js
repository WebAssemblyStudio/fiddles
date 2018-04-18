WebAssembly.instantiateStreaming(fetch('../out/main.wasm')).then(
  obj => {
    const answer = obj.instance.exports.add(12, 30)
    //console.log(answer)
  }
)


const stuffForRust = {
  env: {
    log
  }
}

function log(offset, length) {
  const str = getStringFromMemory(offset, length)
  //console.log(str)
  //console.log(`Hey I received this from rust ${offset} ${length}`)
  const app = document.getElementById('app')
  app.innerHTML = str
}

function getStringFromMemory(offset, length) {
  return Array
    .from(new Uint8Array(memory.buffer, offset, length)) // grab the memory array
    .map(c => String.fromCharCode(c)) // turn it into characters
    .join('') // turn it into a string
}

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), stuffForRust).then(
  obj => {
    memory = obj.instance.exports.memory // put the memory object of instance into a global variable
    const answer = obj.instance.exports.hello_world()
  }
)