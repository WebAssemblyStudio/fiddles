fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;


  document.getElementById("container").innerHTML = instance.exports.main();
  document.getElementById("container").innerHTML += "<br/>" + instance.exports.add(23423.234, 34234.255);
  document.getElementById("container").innerHTML += "<br/>" + instance.exports.getNumber();
}).catch(console.error);
