// Load the WebAssembly WASM file

// fetch grabs the file
WebAssembly.instantiateStreaming(fetch('../out/main.wasm')).then(
  obj => {
    const answer = obj.instance.exports.add(20, 22)
    console.log(answer)
  }
)

// Grabbing the add function from the exports of the wasm file and adds 20 and 22