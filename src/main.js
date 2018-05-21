fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = "Fermat : " + instance.exports.little_fermat(5);
  document.getElementById("container").innerText += "Legacy : " + instance.exports.isprime(5);
});