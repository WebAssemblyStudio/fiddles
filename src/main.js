const importObj = {
  js: {
    memory: new WebAssembly.Memory({ initial: 1 }),
    table: new WebAssembly.Table({ 
      initial: 1,
      element: "anyfunc" })
  }
};

Promise.all([
  WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObj),
  WebAssembly.instantiateStreaming(fetch('../out/main1.wasm'), importObj)
]).then(
  res => console.log(res[1].instance.exports.doIt())
)




// fetch('../out/main.wasm').then(response =>
//   response.arrayBuffer()
// ).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
//   instance = results.instance;
//   document.getElementById("container").textContent = instance.exports.add(1,1);
// }).catch(console.error);

