const memory = new WebAssembly.Memory({ initial: 1});

function consoleLogString(offset, length) {
  const bytes = new Uint8Array(memory.buffer, offset, length);
  const string = new TextDecoder('utf8').decode(bytes);
  console.log(`this is the function ${string}`)
}

const importedObj = {
  console: {
    log: consoleLogString
  },
  js: {
    mem: memory
  }
};

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importedObj)
  .then(obj => obj.instance.exports.writeYo());

  

// fetch('../out/main.wasm').then(response =>
//   response.arrayBuffer()
// ).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
//   instance = results.instance;
//   document.getElementById("container").textContent = instance.exports.add(1,1);
// }).catch(console.error);

