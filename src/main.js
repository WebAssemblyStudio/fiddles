let x = '../out/main.wasm';

let instance = null;

let s = "";
fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes)
).then(results => {
  instance = results.instance;
  var start = performance.now();
  instance.exports.benchmark();
  document.getElementById("container").textContent = performance.now() - start;
}).catch(console.error);
