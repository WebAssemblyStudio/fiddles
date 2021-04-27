const wasmImportObject = {
  eval: new Proxy({},{get:function(target,prop,receiver){ return eval(prop); }}),
  eval2: new Proxy({},{get:function(target,prop,receiver){ return eval(`(function(){${prop}})`); }}),
};

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, wasmImportObject)).then(results => {
  instance = results.instance;
  instance.exports.main();
}).catch(console.error);
