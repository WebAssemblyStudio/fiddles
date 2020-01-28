fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  console.log(Object.keys(instance.exports));
  document.getElementById("container").textContent = instance.exports.main();
  document.getElementById("container").textContent += "\n" + instance.exports.add(23423.234, 34234.255);
}).catch(console.error);
