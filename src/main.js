fetch('../memarray.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  let arr = new Uint32Array( instance.exports.memory.buffer, 1024 );
  arr[0] = 10;
  arr[1] = 21;
  arr[2] = 30;
  arr[3] = 40;
  arr[4] = 50;
  arr[5] = 60;

  console.log( arr );
  document.getElementById("container").textContent = instance.exports.run( );
}).catch(console.error);
