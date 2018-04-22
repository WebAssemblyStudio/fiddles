const memory = new WebAssembly.Memory({ initial: 2 });
const _start = () => {console.log("in start")}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {
  env: {memory, _start}
})).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = instance.exports.Main(3);
});
