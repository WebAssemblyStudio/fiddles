console.log('start');

let instance = null;

function onClick() {
  var n = document.getElementById("num").value;
  var x = parseInt(n);
  fetch('../out/main.wasm').then(response =>
    response.arrayBuffer()
  ).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
    instance = results.instance;
    y = instance.exports.main(x);
  }).catch(console.error);
  document.getElementById("outtxt").innerHTML = x + "を2倍すると" + y;
}
