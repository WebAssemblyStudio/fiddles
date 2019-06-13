function calcular() {
  fetch('../out/main.wasm').then(response =>
    response.arrayBuffer()
  ).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
    instance = results.instance;
    document.getElementById("resultado").value = instance.exports.calculateFactorial(document.getElementById("valorInicial").value);
  }).catch(console.error);
}
