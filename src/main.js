fetch('../out/i64.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  var i64 = results.instance.exports;
  return fetch('../out/main.wasm').then(response =>
    response.arrayBuffer()
  ).then(bytes => WebAssembly.instantiate(bytes, {"i64": i64})).then(results => {
    instance = results.instance;
    document.getElementById("container").textContent = instance.exports.addsome(41);
  });
}).catch(console.error);
