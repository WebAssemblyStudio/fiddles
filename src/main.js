fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance.exports;

  // Pseudo code using tables could look like this
  // tbl[i]()
  
  console.log(instance.call_by_index(0));
});
