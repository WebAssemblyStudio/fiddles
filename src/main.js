WebAssembly.instantiateStreaming( fetch('../out/main.wasm'))
.then(module => {
  console.log(module);
  document.getElementById("container").textContent = module.instance.exports.add(1,1);
}
).catch(console.error);

