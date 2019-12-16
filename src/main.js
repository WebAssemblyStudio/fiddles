function add() {
  fetch('../out/main.wasm').then(response =>
    response.arrayBuffer())
  .then(bytes => WebAssembly.instantiate(bytes))
  .then(results => {
    instance = results.instance;
    let op1 = document.getElementById("op1").value;
    let op2 = document.getElementById("op2").value;
    document.getElementById("sum").value = instance.exports.add(op1, op2);
  })
  .catch(console.error);
}