let wasm = '../out/main.wasm';

let instance = null;

fetch(wasm)
  .then(response => response.arrayBuffer())
  .then(bytes =>
    WebAssembly.instantiate(bytes, {
      env: {}
    })
  )
  .then(results => {
    instance = results.instance;
    document.getElementById("container").textContent = instance.exports.main();
  })
  .catch(console.error);
