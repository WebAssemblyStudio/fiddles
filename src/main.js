const textDecoder = new TextDecoder();
const instance = {};

fetch('../out/main.wasm')
  .then(response => response.arrayBuffer())
  .then(bytes => WebAssembly.instantiate(bytes, {
    env: {
      print(messageLength, messagePointer) {
        const messageBytes = new Uint8Array(instance.memory.buffer, messagePointer, messageLength);
        const message = textDecoder.decode(messageBytes);
        console.log(message);
      },
    },
  }))
  .then(results => {
    Object.assign(instance, results.instance.exports);
    instance.main();
  })
  .catch(console.error);
