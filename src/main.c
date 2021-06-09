#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT greet () {
  return "hello world";

}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"))
.then(({instance}) => {//invoke the exported function
const result = instance.exports.greet();
document.getElemntById ("container").textContent = result; 
});
