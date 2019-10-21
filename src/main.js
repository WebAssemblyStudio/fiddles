fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  hl = new Date();
  document.getElementById("container").textContent = instance.exports.add_one(10000);
  console.log(new Date() - hl);
}).catch(console.error);
