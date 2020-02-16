(async function () {
  let wasmModule = fetch( '../out/main.wasm' ).then( WebAssembly.compileStreaming );

  let module = await wasmModule;

  console.log( module )
  let instance = await WebAssembly.instantiate( module );
  console.log( instance )

  const buffer = new Float32Array( instance.exports.memory.buffer );
  const value = instance.exports.hi();

  const bufferX = new Float32Array( instance.exports.memory.buffer, value, 8 );

  document.getElementById( 'container' ).textContent = bufferX;

  instance.exports.change( 3, 0.25 );

  document.getElementById( 'container' ).textContent = bufferX;
})()
