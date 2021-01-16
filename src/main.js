fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then((buffer) => {
  doWork(buffer);
}).catch(console.error);

async function doWork(buffer) {
  const module = await WebAssembly.compile(buffer);
  const instance = await WebAssembly.instantiate(module);

  var sumResult = instance.exports.sum(1, 2);

  document.getElementById("container").textContent = "pippo";
}
