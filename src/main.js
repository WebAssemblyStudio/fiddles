fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
  document.getElementById("add").textContent = "1 + 2 = " + instance.exports.add(1,2);
  document.getElementById("sub").textContent = "1 - 2 = " + instance.exports.sub(1,2);
}).catch(console.error);
