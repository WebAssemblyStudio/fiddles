fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  const api = instance.exports;

  document.getElementById("container").textContent = api.hello(2);
}).catch(console.error);
