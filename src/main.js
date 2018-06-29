fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  let container = document.getElementById("container");
  container.innerText += 'Add 1, 2, 3: ' + instance.exports.something(1,2,3) + '\n';
  container.innerText += 'Slope of (2,5) to (4, 10): ' + instance.exports.slope(2, 5, 4, 10) + '\n';
  container.innerText += 'Biggest number between 5 and 10: ' + instance.exports.max(5, 10) + '\n';
  container.innerText += 'Add all nums to 10: ' + instance.exports.addAllTo(10) + '\n';

}).catch(console.error);

