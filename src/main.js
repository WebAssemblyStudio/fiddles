const {module, instance} = await WebAssembly.instantiateStreaming(fetch('../out/main.wasm'));
document.getElementById("container").textContent = instance.exports.main();
console.log(module, instance);