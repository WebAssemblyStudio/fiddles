
const canv =document.createElement('canvas');
document.appendChild(canv);

canv.width=1024;
canv.height = 768;
const ctx = canv.getContext("2d");
let wasm_instance = null;

function create_framebuffer() {

}

function main_loop() {

}



fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  wasm_instance = instance;
  debugger;

  //document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
