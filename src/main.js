let wasmFunctions;

window.onload = () => {
  fetch('../out/main.wasm')
  .then(response => response.arrayBuffer())
  .then(bytes => WebAssembly.instantiate(bytes))
  .then(results => {
    wasmFunctions = results.instance.exports;
  })
  .catch(console.error);
};

function add() {
  let op1 = document.getElementById("op1").value;
  let op2 = document.getElementById("op2").value;
  document.getElementById("sum").value = wasmFunctions.add(op1, op2);
}