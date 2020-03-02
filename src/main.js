fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {
  env: {
    consoleLog: console.error
  }
})).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.getSqrt(5);
}).catch(console.error);
