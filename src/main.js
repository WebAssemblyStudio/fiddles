fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent += instance.exports.add(0) + ' ';
  document.getElementById("container").textContent += instance.exports.add(1) + ' ';
  document.getElementById("container").textContent += instance.exports.add(2) + ' ';
  document.getElementById("container").textContent += instance.exports.add(3) + ' ';
  document.getElementById("container").textContent += instance.exports.add(4) + ' ';
  document.getElementById("container").textContent += instance.exports.add(5) + ' ';
}).catch(console.error);

