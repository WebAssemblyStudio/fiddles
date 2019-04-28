fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  //
let memory = instance.exports.memory;

const d= document.createElement('div')
document.body.appendChild(d)
d.textContent = (memory.buffer.byteLength); // 1 page.  
console.log(3840*2160/65536)
memory.grow(126);
console.log(memory.buffer.byteLength); // 11 pages.
  //
  document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
