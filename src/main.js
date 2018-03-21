fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

const { sumOfMultiplesUntil } = instance.exports;

  document.getElementById("container").innerText = sumOfMultiplesUntil(999);
});
