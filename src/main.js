var functionStack = null;

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  functionStack = instance.exports;
}).catch(console.error);

function onContentChanged(referenceObject) {
  document.getElementById("container").textContent = eval("functionStack." + referenceObject.value);
}

