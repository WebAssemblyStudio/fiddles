let x = '../out/main.wasm';

let instance = null;
let memoryStates = new WeakMap();

let s = "";
fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.compile(bytes)
).then(results => {
  instance = new WebAssembly.Instance(results)
  // document.getElementById("container").textContent = instance.exports.main();
  console.log(instance.exports.add42(67));
}).catch(console.error);
