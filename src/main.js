fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  let bit = 16
  let presentString = {}
  let string = {}
  instance.exports.md5(presentString, bit, string);
  document.getElementById("container").textContent = string
}).catch(console.error);
