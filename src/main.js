fetch('../out/main.wasm').then(response => response.arrayBuffer())
.then(bytes => WebAssembly.instantiate(bytes))
.then(results => {
  instance = results.instance;
  instance.exports.addlah;
  //document.getElementById("add_result").textContent = instance.exports.addlah(1,2);
  //document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
