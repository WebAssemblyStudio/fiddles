fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  // let val = document.querySelector('input').value;
  document.getElementById("sqrt").textContent = instance.exports.sqrt(64);
  document.getElementById("add").textContent = instance.exports.add(10,4);
  document.getElementById("sub").textContent = instance.exports.sub(10,4);
  document.getElementById("div").textContent = instance.exports.div(10,4);
}).catch(console.error);

// (async function loadWasm(imports) {
//   const res = await fetch('../out/main.wasm')
//   const buffer = await res.arrayBuffer()
//   const module = await WebAssembly.compile(buffer)
//   const instance = await WebAssembly.instantiate(module, imports)
//   return instance
// })()
