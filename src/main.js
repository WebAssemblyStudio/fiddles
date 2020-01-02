// fetch('../out/main.wasm').then(response =>
//   response.arrayBuffer()
// ).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
//   instance = results.instance;
//   console.log(instance.exports)
//   document.getElementById("container").textContent = instance.exports.main();
// }).catch(console.error);

// try {
  (async () => {
    const res = fetch('../out/main.wasm')
    const module = await WebAssembly.instantiateStreaming(res)
    console.log(module)
    // document.getElementById("container").textContent = instance.exports.main();
  })()
// } catch(err) {
//   console.error(err)
// }