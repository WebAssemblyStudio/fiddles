const memory = new WebAssembly.Memory({initial: 2});
const importObject = {js: {mem: memory}};
let wa_membuf, wa_grid, wa_bots;

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes, importObject)
).then(results => {
  instance = results.instance;

  document.getElementById("container").innerText = "kaas";

  /*const buffer = new Uint8Array(memory.buffer);
  buffer[instance.exports.grid.value] = 123;

  console.log("hoihoi gives: " + instance.exports.hoihoi());*/

  wa_membuf = new Uint8Array(memory.buffer);
  wa_grid = instance.exports.grid.value;
  wa_bots = instance.exports.bots_data.value;
}).catch(console.error);
