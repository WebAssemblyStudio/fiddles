fetch("main.wasm").then(response => 
  response.arrayBuffer()
).then(bytes => 
  WebAssembly.instantiate(bytes, { imports: {} })
).then(results => {
  const exports = results.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
});