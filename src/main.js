fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  let n = 10;

  let start = Date.now( );
  let slowRes = instance.exports.fib( n );
  console.log( Date.now( ) - start );

  start = Date.now( );
  let fastRes = instance.exports.fib2( n );
  console.log( Date.now( ) - start );

  document.getElementById("container").textContent = slowRes + ' ; ' + fastRes;
}).catch(console.error);
