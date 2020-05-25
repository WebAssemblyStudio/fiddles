fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  let n = 4;
  document.getElementById("container").textContent = instance.exports.run1( n ) + ' ' + instance.exports.run2( n ) + ' ' + instance.exports.run3( n ) + ' ' + instance.exports.run4( n );
}).catch(console.error);
