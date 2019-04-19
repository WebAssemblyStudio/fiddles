const print = (d) => console.log(d) 
var memory = new WebAssembly.Memory({initial:1, maximum:100});

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {js: {print, memory}})).then(results => {
  instance = results.instance;
  instance.exports.main();
  document.getElementById("container").textContent = instance.exports.load_num(0);
}).catch(console.error);
