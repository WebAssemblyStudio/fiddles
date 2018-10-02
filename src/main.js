fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  // instance.exports._start();
  // document.getElementById("container").innerText = instance.exports.camlCurried_function__test_1636();
}).catch(console.error);

