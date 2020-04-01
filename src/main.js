let x = '../out/main.wasm';

let s = "";
fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes)
).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.noise2D(0.4, 0.8);
}).catch(console.error);
