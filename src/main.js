var memory = new WebAssembly.Memory({initial:1, maximum:100});


function print(offset) {
  const length = 1
  const charCode = new Uint32Array(memory.buffer, 4, length);
  console.log(String.fromCharCode(charCode))
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {js: {print, memory}})).then(results => {
  instance = results.instance;
  instance.exports.main();
  document.getElementById("container").textContent = String.fromCharCode(instance.exports.load_num(1));
}).catch(console.error);
