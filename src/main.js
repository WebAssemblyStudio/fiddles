var importObj = {
  js: {
    memory : new WebAssembly.Memory({ initial: 1 }),
    table : new WebAssembly.Table({ initial: 1, element: "anyfunc" })
  }
};
Promise.all([
  WebAssembly.instantiateStreaming(fetch('../out/shared0.wasm'), importObj),
  WebAssembly.instantiateStreaming(fetch('../out/shared1.wasm'), importObj)
]).then(function(results) {
  console.log(results[1].instance.exports.doIt());  // prints 42
});