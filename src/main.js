fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  
  var a=25;
  var c= document.getElementById("container");
  c.textContent = instance.exports.main();
  c.textContent = c.textContent + " " + instance.exports.squarer(a);
  c.textContent = c.textContent + " " + instance.exports.main();
}).catch(console.error);
