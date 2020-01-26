fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {
  unity: {
    read: () => 21,
    write: (x) => console.log(x)
  }
})).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);

