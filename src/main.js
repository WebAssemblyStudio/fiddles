fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = instance.exports.dec2mbin(-10).toString(2);
}).catch(console.error);
