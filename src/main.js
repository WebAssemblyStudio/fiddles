fetch('../out/main.wasm')
  .then(response => response.arrayBuffer())
  .then(bytes => WebAssembly.instantiate(bytes))
  .then(results => {
    const { add } = results.instance.exports;
    document.getElementById("container").textContent = add(1, 2);
  })
  .catch(console.error);
