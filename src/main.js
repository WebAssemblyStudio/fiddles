fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.MAINNN();
  console.log(instance.exports.add(7,6));
  console.log(instance.exports.sub(7,6));
  console.log(instance.exports.mul(7,6));
}).catch(console.error);
