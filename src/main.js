fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(({instance}) => {
  const {add} = instance.exports;
  document.getElementById("container").innerText = add(1, 3);
}).catch(console.error);

