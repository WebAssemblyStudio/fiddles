fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  //document.getElementById("container").textContent = instance.exports.add(1,1);
  document.getElementById("container").textContent = instance.exports.test(42,41);
}).catch(console.error);

