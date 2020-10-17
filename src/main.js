let memory = new WebAssembly.Memory({ initial: 16, maximum: 16, shared: true });

console.log(memory.buffer); 

// logs: SharedArrayBuffer(1048576) as expected

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), {
  
  env: { memory }

}).then(results => {
    
  console.log(results.instance.exports.memory.buffer)

	// logs: ArrayBuffer(131072) - both size and shared parameter is being ignored
  
});