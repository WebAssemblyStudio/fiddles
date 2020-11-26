

// fetch('../out/main.wasm').then(response =>
//   response.arrayBuffer()
// ).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
//   instance = results.instance;
//   document.getElementById("container").textContent = instance.exports.main();
// }).catch(console.error);

(async () => {
  const codePromise = fetch('../out/main.wasm')
  const module = await WebAssembly.instantiateStreaming(codePromise)
  console.log(module)
  console.log('???');
})