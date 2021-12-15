let addOne;
console.error("hi");
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  addOne = instance.exports.add_one;
}).catch(console.error);

document.getElementById("container").textContent = addOne(41);
console.log("hi");