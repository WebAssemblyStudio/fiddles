(async () => {
  const codePromise = fetch('../out/main.wasm')
  const { instance } = await WebAssembly.instantiateStreaming(codePromise)

  const buffer = instance.exports.memory.buffer
})

/*
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
*/
