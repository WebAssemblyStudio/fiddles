fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  const canvas0 = document.getElementsByTagName( 'canvas' )[0];
  const canvas1 = document.getElementsByTagName( 'canvas' )[1];
  const ctx0 = canvas0.getContext( '2d' );
  const ctx1 = canvas1.getContext( '2d' );
  let imgData = ctx1.createImageData( 100, 100 );

  let n = 100000;

  instance = results.instance;
  let inputOff = instance.exports.prepare( );
  let stuff = new Uint8Array( instance.exports.memory.buffer, inputOff, 7 * n );
  for ( let i = 0; i < n; i++ ) {
    stuff[ i * 7 + 0 ] = Math.random( ) * 100;
    stuff[ i * 7 + 1 ] = Math.random( ) * 100;
    stuff[ i * 7 + 2 ] = 1 + Math.random( ) * 10;
    stuff[ i * 7 + 3 ] = 1 + Math.random( ) * 10;
    stuff[ i * 7 + 4 ] = Math.random( ) * 256;
    stuff[ i * 7 + 5 ] = Math.random( ) * 256;
    stuff[ i * 7 + 6 ] = Math.random( ) * 256;
  }

  let start = Date.now( );
  let j = 0;
  while ( j < 7 * n ) {
    let x = stuff[ j++ ];
    let y = stuff[ j++ ];
    let w = stuff[ j++ ];
    let h = stuff[ j++ ];
    let r = stuff[ j++ ];
    let g = stuff[ j++ ];
    let b = stuff[ j++ ];
    
    ctx0.fillStyle = `rgb(${r}, ${g}, ${b})`;
    ctx0.fillRect( x, y, w, h );
  }
  console.log( Date.now( ) - start );

  start = Date.now( );
  let outputOff = instance.exports.run( n );
  let output = new Uint8Array( instance.exports.memory.buffer, outputOff, 100 * 100 * 4 );
  imgData.data.set( output );
  ctx1.putImageData( imgData, 0, 0 );
  console.log( Date.now( ) - start );
}).catch(console.error);
