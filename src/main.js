const inp = document.getElementById("in");
const submit = document.getElementById("submit");
const output = document.getElementById("container");

let instance;

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
}).catch(console.error);


submit.onclick = (ev) => {
  output.innerText = instance.exports.encrypt(inp.value);
}