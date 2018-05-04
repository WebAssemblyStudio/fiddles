var instance = null;
var importObject = { 
  'env': { 
    'memoryBase': 0,
    'tableBase': 0,
    'memory': new WebAssembly.Memory({initial: 256}),
    'table': new WebAssembly.Table({initial: 0, element: 'anyfunc'}),
    'CallJS': function(){ 
      document.getElementById('file').click();
      console.log('clicked')} 
  } 
};

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, importObject)).then(results => {
  instance = results.instance;
  instance.exports.Test(); 
}).catch(err=>{
  console.log(err)
});