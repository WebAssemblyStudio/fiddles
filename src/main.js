fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  console.time('c');
  document.getElementById("container").textContent = instance.exports.finonacci(40);
  console.timeEnd('c');
}).catch(console.error);
