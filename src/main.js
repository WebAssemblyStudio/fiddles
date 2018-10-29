fetch('../out/main.wasm')
  .then(response =>
    response.arrayBuffer()
  )
  .then(bytes => WebAssembly.instantiate(bytes))
  .then(results => {
    const { instance } = results;
    const { add_one } = instance.exports;
    document.getElementById("container").textContent = add_one(41); 
  }).catch(console.error);
