fetch('../out/main.wasm')
.then(response => response.arrayBuffer())
.then(bytes => WebAssembly.instantiate(bytes))
.then(({instance}) => {
  document.getElementById("container").innerText = instance.exports.main()
}).catch(console.error)
