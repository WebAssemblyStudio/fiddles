fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.getRandomNumber(0, 10);
  document.getElementById("container1").textContent = instance.exports.getXFromAngle(1, 1, 1, 1);
  document.getElementById("container2").textContent = instance.exports.getYFromAngle(1, 1, 1, 1);
  document.getElementById("container3").textContent = instance.exports.getAngle(1, 2, 2, 3, true);
  document.getElementById("container4").textContent = instance.exports.getAngle(1, 2, 2, 3, false);
}).catch(console.error);
