const print = (d) => console.log(d) 

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {js: {print}})).then(results => {
  instance = results.instance;
  instance.exports.main();
  document.getElementById("container").textContent = instance.exports.load_num(0,1);
}).catch(console.error);
