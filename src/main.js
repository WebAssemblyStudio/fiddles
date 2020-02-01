fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  instance.exports.setCell(10,10,5);
  document.getElementById("container").textContent = instance.exports.getCell(10,10);
}).catch(console.error);

