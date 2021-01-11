WebAssembly.instantiateStreaming(fetch("../out/main.wasm"))
 .then(({ instance }) => {
   // invoke the exported function
   const result = instance.exports.greet();
   document.getElementById("container").textContent = result;
});