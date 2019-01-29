WebAssembly.instantiateStreaming(fetch('../out/main.wasm'))
  .then(obj => {
    console.log(obj.instance.exports.callByIndex(0));
    console.log(obj.instance.exports.callByIndex(1));
    console.log(obj.instance.exports.callByIndex(2));
  })




// fetch('../out/main.wasm').then(response =>
//   response.arrayBuffer()
// ).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
//   instance = results.instance;
//   document.getElementById("container").textContent = instance.exports.add(1,1);
// }).catch(console.error);

