fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.getRandomNumber(0, 10);
  document.getElementById("container1").textContent = instance.exports.degreeToRadians(58);
}).catch(console.error);
