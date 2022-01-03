fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
 document.getElementById("container").textContent = instance.exports.minusone(60);
}).catch(console.error);

