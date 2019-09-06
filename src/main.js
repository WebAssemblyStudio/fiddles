fetch('../out/main.wasm')
  .then(response =>response.arrayBuffer())
  .then(bytes => WebAssembly.instantiate(bytes))
  .then(results => {
    const { add_one } = results.instance.exports;
    console.log(add_one(41));
    document.getElementById("container").textContent = add_one(41);
  })
  .catch(console.error);
