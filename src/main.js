fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => {
  console.log(bytes);
  console.log(WebAssembly.instantiate(bytes));
  return WebAssembly.instantiate(bytes);
  })
.then(results => {
  conosle.log(results);
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
