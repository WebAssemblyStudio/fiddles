fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("add").textContent = "1+2="+instance.exports.add(1, 2);
  document.getElementById("sub").textContent = "2-1="+instance.exports.sub(2, 1);
}).catch(console.error);
