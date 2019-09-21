fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  var start = Date.now();
  document.getElementById("container").textContent = instance.exports.main();
  var elpsd = Date.now() - start;
  console.log(elpsd);
}).catch(console.error);
