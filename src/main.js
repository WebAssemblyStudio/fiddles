const response = await fetch('../out/main.wasm');
const bytes = await response.arrayBuffer();
const { instance } = await WebAssembly.instantiate(bytes);
document.getElementById("container").textContent = instance.exports.main();
