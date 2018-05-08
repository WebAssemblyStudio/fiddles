fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  const t = Date.now();
  results.instance.exports.sleep();
  document.getElementById("container").innerText = Date.now() - t;
}).catch(e => {
  document.getElementById("container").innerText = e;
});