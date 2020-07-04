fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  const instance = results.instance;
  const exports = instance.exports;
  let data = new Uint32Array( exports.memory.buffer, exports.ptr( ) );
  data[ 0 ] = 2;
  data[ 1 ] = 5;
  data[ 2 ] = 8;
  data[ 3 ] = 20;
  data[ 4 ] = 5;
  data[ 5 ] = 7;
  data[ 6 ] = 13;
  data[ 7 ] = 99;
  data[ 8 ] = 5; // Out-of-Bounds. Should not change

  console.log( data.slice( 0, 20 ) );
  exports.run( );
  console.log( data.slice( 0, 20 ) );
}).catch(console.error);
