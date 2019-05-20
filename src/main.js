fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  // document.getElementById("container").textContent = instance.exports.add(1,1);
  // document.getElementById("container").textContent = instance.exports.sub(2,1);
  document.getElementById("container").textContent = instance.exports.addone(3);
}).catch(console.error);

