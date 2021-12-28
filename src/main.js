fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("add").textContent = instance.exports.add(41);
  document.getElementById("clamp").textContent = instance.exports.clamp(0,5,100);
  
  document.getElementById("berp").textContent = instance.exports.berp(0,100,25);
  document.getElementById("lerp").textContent = instance.exports.lerp(0,100,0.25);
}).catch(console.error);
