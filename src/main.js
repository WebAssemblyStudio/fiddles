fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  console.log(JSON.stringify(instance.exports.test()));
  document.getElementById("container").textContent = instance.exports.test();
}).catch(console.error);
