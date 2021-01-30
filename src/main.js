(async() => {
  const codePromise = fetch('../out/main.wasm'); // fetch main.wasm, present when we build the code
  const module = await WebAssembly.instantiateStreaming(codePromise); // recommended way by mozilla
  console.log(module);
})()

// fetch('../out/main.wasm').then(response =>
//   response.arrayBuffer()
// ).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
//   instance = results.instance;
//   document.getElementById("container").textContent = instance.exports.main();
// }).catch(console.error);
