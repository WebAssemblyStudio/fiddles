const contianer = document.getElementById("container");
const instance = {};
const importObject = {
  env: {
    "console::clear": () => {
      container.textContent = '';
    },
    "console::log": (messageLength, messagePointer) => {
      const textDecoder = new TextDecoder();
      const messageBytes = new Uint8Array(instance.memory.buffer, messagePointer, messageLength);
      const message = textDecoder.decode(messageBytes);

      container.textContent += `${message}\n`;
    },
  },
};

container.style.cssText = "font-family: monospace;white-space: pre;";

fetch('../out/main.wasm')
  .then(response => response.arrayBuffer())
  .then(bytes => WebAssembly.instantiate(bytes, importObject))
  .then(results => {
     Object.assign(instance, results.instance.exports);
    instance.main();
  })
  .catch(console.error);


