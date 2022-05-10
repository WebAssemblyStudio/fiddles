let c = document.getElementById("container");

// chargement du module
WebAssembly.instantiateStreaming(
  fetch('../out/main.wasm'),
  {},
)
.then((result) => {
  let instance = result.instance;

  // instance.exports contient toutes les fonctions de main.c
  // annotées par WASM_EXPORT
  c.textContent = instance.exports.answer();
})
.catch((err) => {
  throw err;
});
  
