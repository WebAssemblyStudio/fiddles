fetch('http://89.32.249.18//Kalco/TestLab/604e7e611caef87ddeb2.module.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  console.log(instance)
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
