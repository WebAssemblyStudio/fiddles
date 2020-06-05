fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  const a = 7;
  document.getElementById("container").textContent = instance.exports.run1( a ) + ' / ' +  instance.exports.run2( a );
}).catch(console.error);
