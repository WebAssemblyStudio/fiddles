fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  console.log(instance.exports.vec2(5, 5));
  console.log(String(instance.exports.vec2(5, 5)));
}).catch(console.error);
