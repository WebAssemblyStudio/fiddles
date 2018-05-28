const imports = {
  system: {
    act: function(a) {
      return a + 7;
    }
  }
}

fetch('../out/success.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, imports)).then(results => {
  instance = results.instance;
  document.getElementById("success-container").innerText = instance.exports.helloWorld();
});

fetch('../out/failure.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, imports)).then(results => {
  instance = results.instance;
  document.getElementById("failure-container").innerText = instance.exports.helloWorld();
});