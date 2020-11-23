fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  //document.getElementById("container").textContent = instance.exports.add(1,1);
const {fill, mem} = instance.exports;
fill(0, 13, 5);
fill(10, 77, 7);
fill(20, 255, 1000);
console.log(new Uint8Array(mem.buffer, 0, 50));
  //console.log(instance.exports.add(1,1));

}).catch(console.error);

