fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText += "sum_bad: " + instance.exports.sum_bad(10) + "\n";
  document.getElementById("container").innerText += "sum_good: " + instance.exports.sum_good(10) + "\n";
}).catch(console.error);

