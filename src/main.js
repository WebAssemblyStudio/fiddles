fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.getRandomNumber(0, 10);
  document.getElementById("container1").textContent = instance.exports.getXFromAngle(1, 1, 1, 1);
  document.getElementById("container2").textContent = instance.exports.getYFromAngle(1, 1, 1, 1);
  document.getElementById("container3").textContent = instance.exports.getAngle(1, 2, 2, 3, true);
  document.getElementById("container4").textContent = instance.exports.getAngle(1, 2, 2, 3, false);
  document.getElementById("container5").textContent = instance.exports.getPercentageFromNumber(33, 20, 50);
  document.getElementById("container6").textContent = instance.exports.getNumberFromPercentage(33, 20, 50);
  document.getElementById("container7").textContent = instance.exports.getDistanceBetweenTwoPoints(1, 1, 2, 2);
  document.getElementById("container8").textContent = instance.exports.degreeToRadians(180);
  document.getElementById("container9").textContent = instance.exports.fract(10.4);
  document.getElementById("container10").textContent = instance.exports.mod(10, 3);
  document.getElementById("container11").textContent = instance.exports.mix(2, 4, 9);
  document.getElementById("container12").textContent = instance.exports.smoothStep(1, 50, 10);
}).catch(console.error);
