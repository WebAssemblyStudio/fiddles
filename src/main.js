fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  let n = 10;
  let data = new Uint32Array( instance.exports.memory.buffer );
  for ( let i = 0; i < n; i++ ) {
    data[ i ] = Math.floor( Math.random( ) * 0xFFFFFFFF );
  }
  console.log( data );
  instance.exports.runall( n, 0, n * 4 );
  console.log( data );
  document.getElementById("container").textContent = "X";
}).catch(console.error);

