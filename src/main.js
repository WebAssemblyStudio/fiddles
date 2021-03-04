WebAssembly.instantiateStreaming(fetch("../out/main.wasm")).then(({instance}) => {
  const result = instance.exports.greet();
  const memory = instance.exports.memory;
  const buffer = new Uint8Array(memory.buffer, result, 11);
  const str = new TextDecoder("utf8").decode(buffer);
  document.getElementById("container").textContent = str;
}).catch(console.error);
