let argv = ['Hello,', 'world!']

let argc = argv.length

let exports = {
  console: {log: console.log},
  cakeml: {argc}
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, exports)).then(results => {
  instance = results.instance;
  instance.
  document.getElementById("container").innerText = instance.exports.main();
}).catch(console.error);

