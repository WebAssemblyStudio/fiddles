fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  doubler = instance.exports.doubler;
  document.getElementById("container").innerText = doubler(33);
}).catch(console.error);
