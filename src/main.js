
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  
  let gelenveri = instance.exports.myfunc("abc", "d", "e");
  let res = new Uint8Array(gelenveri.buffer, 0, 3);
  console.log(res);
}).catch(console.error);


