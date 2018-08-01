fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes, {
    env: {
      add: function (a, b) {
        return a + b;
      }
    }
  })
).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = instance.exports.main();
}).catch(console.error);

