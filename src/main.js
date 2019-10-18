fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => {

  var wasmModule = new WebAssembly.Module(bytes);
  var wasmInstance = new WebAssembly.Instance(wasmModule);

  var bufferSize = 10e3;

  var offset = wasmInstance.exports.getOffset();
  //Definir buffer
  var buffer = new Uint32Array(wasmInstance.exports.memory.buffer,offset,bufferSize)
  wasmInstance.exports.setSize(buffer.length)
  
  for(var i in buffer){
    buffer[i] = 10;
  }

  var sum = wasmInstance.exports.getSum()
  alert(sum)

  document.getElementById("container").textContent = wasmInstance.exports.main();

}).catch(console.error);
