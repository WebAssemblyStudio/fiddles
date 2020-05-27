fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  let result = instance.exports.add(1,1);
  document.getElementById("container").textContent = result;
}).catch(console.error);
