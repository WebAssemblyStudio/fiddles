fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  debugger;
  document.getElementById("container").innerText = instance.exports.Main(10);
});