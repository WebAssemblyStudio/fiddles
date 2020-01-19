fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.add_one(120);
  document.getElementById("container").click =  function () {
    document.getElementById("container").textContent = instance.exports.add_one(150);
  //  document.getElementById("container").textContent);
  }
}).catch(console.error);
