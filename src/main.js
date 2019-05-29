let squarer;

function loadWebAssembly(fileName) {
  return fetch(fileName)
    .then(response => response.arrayBuffer())
    .then(buffer => WebAssembly.compile(buffer))
    .then(module => {return new WebAssembly.Instance(module) });
};
  
loadWebAssembly('../out/main.wasm')
  .then(instance => {
    squarer = instance.exports.squarer;
    console.log('square 8 = ' + squarer(8));
  }); 