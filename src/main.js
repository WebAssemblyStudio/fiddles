fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container1").textContent = instance.exports.add_f32();
  document.getElementById("container2").textContent = instance.exports.add_f64();
}).catch(console.error);
