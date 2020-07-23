let add;

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  // document.getElementById("container").textContent = instance.exports.main();
  add = instance.exports.add;
  document.getElementById("container").textContent = add(5,6)
}).catch(console.error);
