fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  //document.getElementById("container").innerText = instance.exports.add(3, 9);

  document.getElementById("container").innerText = instance.exports.main();
});
