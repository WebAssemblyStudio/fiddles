fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes))
.then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
  const { add, square, test } = instance.exports

  console.log('(2 + 5)^2 = ' +  square(add(2 + 5)))
  console.log(test())
}).catch(console.error);
