fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  print(instance.exports.getValue());
  instance.exports.getValue(1000)
  print(instance.exports.getValue());
}).catch(console.error);
function print(val){
  const div = document.createElement('div');
  div.innerText=val;
  document.getElementById("container").appendChild(div);
}