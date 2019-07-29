// fetch('../out/main.wasm').then(response =>
//   response.arrayBuffer()
// ).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
//   instance = results.instance;
//   document.getElementById("container").textContent = instance.exports.multiply(3,3);
// }).catch(console.error);

(async () => {
  try {
    const response = await fetch('../out/main.wasm');
    const bytes = await response.arrayBuffer();
    const results = await WebAssembly.instantiate(bytes);
    instance = results.instance;
    document.getElementById("container").textContent = instance.exports.multiply(3,10);
  } catch(error) {
    console.error(error);
  } 
})();
