

document.addEventListener( 'DOMContentLoaded', ev => {
  const canvas = document.getElementsByTagName( 'canvas' )[0];
  const ctx = canvas.getContext( '2d' );
  console.log( ctx );

  const imports = {
    env: {
      draw: ( x, y, w, h, r, g, b ) => {
        ctx.fillStyle = `rgb(${r}, ${g}, ${b})`;
        ctx.fillRect( x, y, w, h );
      }
    }
  };

  let n = 10000;
  let stuff = new Uint8Array( 7 * n );
  for ( let i = 0; i < n; i++ ) {
    stuff[ i * 7 + 0 ] = Math.random( ) * 100;
    stuff[ i * 7 + 1 ] = Math.random( ) * 100;
    stuff[ i * 7 + 2 ] = 1 + Math.random( ) * 10;
    stuff[ i * 7 + 3 ] = 1 + Math.random( ) * 10;
    stuff[ i * 7 + 4 ] = Math.random( ) * 256;
    stuff[ i * 7 + 5 ] = Math.random( ) * 256;
    stuff[ i * 7 + 6 ] = Math.random( ) * 256;
  }

  //imports.draw( 20, 20, 10, 10, 255, 0, 0 );
  let start = Date.now( );

  fetch('../out/main.wasm')
    .then(response => response.arrayBuffer())
    .then(bytes => WebAssembly.instantiate(bytes, imports))
    .then(results => {
      results.instance.exports.run( );
    })
    .catch(console.error);
} );
