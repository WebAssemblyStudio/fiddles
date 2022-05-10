let canvas = document.getElementById('canvas');
let ctx = canvas.getContext("2d");


fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  console.log(ctx);

  document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
