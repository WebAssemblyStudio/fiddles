let memory = new WebAssembly.Memory({ initial: 1, maximum: 1000 });

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, { memory })).then(results => {
  console.log(Array(memory.buffer.slice(0, 64)));
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
