fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  // document.getElementById("container").textContent = instance.exports.add(1,1);
  document.getElementById("container1").textContent = instance.exports.addf(.1,.2);
  document.getElementById("container2").textContent = instance.exports.addcf();
  document.getElementById("container3").textContent = instance.exports.addcd();
}).catch(console.error);

