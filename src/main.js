WebAssembly.instantiateStreaming(fetch('../out/main.wasm'))
  .then(obj => {
    document.getElementById("container").textContent = obj.instance.exports.add(1,1);
}).catch(console.error);;

