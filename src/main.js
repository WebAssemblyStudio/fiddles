function squareRoot() {
  fetch('../out/main.wasm').then(response =>
    response.arrayBuffer()
  ).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
    instance = results.instance;
    document.getElementById("result").textContent = "Result: " + instance.exports.squareRoot(document.getElementById("base").value);
  }).catch(console.error);
}
