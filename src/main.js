fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.add(2, 2);

  const result = instance.exports.greet();
  const memory = instance.exports.memory;
  const buffer = new Uint8Array(memory.buffer, result, 11);
  const str = new TextDecoder("utf8").decode(buffer);

  document.getElementById("greeting").textContent = str;
}).catch(console.error);
