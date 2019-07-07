fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent ="<strong>" + instance.exports.add_one(411) + "</strong>";
}).catch(console.error);
