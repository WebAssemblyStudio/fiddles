fetch('../out/main.7.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = btoa(String.fromCharCode.apply(null, new Uint8Array(bytes)));
  // = instance.exports.main();
})).catch(console.error);
