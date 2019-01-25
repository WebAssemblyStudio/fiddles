const  x = '../out/main.wasm';
let instance = null;

fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes)
).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.pow();
}).catch(console.error);
