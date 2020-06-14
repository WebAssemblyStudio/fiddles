// fetch('../out/main.wasm').then(response =>
//   response.arrayBuffer()
// ).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
//   instance = results.instance;
//   document.getElementById("container").textContent = instance.exports.main();
// }).catch(console.error);

(async()=>{
  const code = fetch('../out/main.wasm')
  const modul = await WebAssembly.instantiateStreaming(code)
  console.log (modul)

})