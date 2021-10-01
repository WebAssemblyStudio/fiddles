fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.MAINNN();
  console.log("add: "+instance.exports.add(7,6));
  console.log("sub: "+instance.exports.sub(7,6));
  console.log("div: "+instance.exports.div(42,6));
  console.log("mul: "+instance.exports.mul(7,6));
}).catch(console.error);
