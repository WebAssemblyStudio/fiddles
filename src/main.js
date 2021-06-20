/*
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  const instance = results.instance;
  document.getElementById("output").textContent = instance.exports.add(1, 1);
}).catch(console.error);
*/

import {} from "./parser.js";

fetch("../src/input.wat").then(response =>
  response.text()
).then(input => {
});