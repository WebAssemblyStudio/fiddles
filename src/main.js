fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  //document.getElementById("container").innerText = instance.exports.main();
  instance.exports.initialize(1,1,1,0);
  instance.exports.initialize(2,2,2,1);
  instance.exports.initialize(3,3,3,2);
  console.log(instance.exports.getStruct(4))
}).catch(console.error);
