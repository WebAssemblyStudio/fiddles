fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  let instance = results.instance;
  let canvas = document.querySelector('canvas');  
  let size = instance.exports.getSize();
  document.getElementById("size").textContent = '(' + size + 'x' + size + ')';
  canvas.height = size;
  canvas.width = size;  
  let ctx = canvas.getContext("2d"); 

  let array = new Uint8ClampedArray( 
    instance.exports.memory.buffer,  
    instance.exports.getImage(),    
    size*size*4,                     
  );
  let imageData = new ImageData(array, size, size);

  // Init algorithm
  instance.exports.init();

  // Do an iteration and update image every 1ms
  setInterval( function() {
    instance.exports.doIteration();
    instance.exports.fillImage();
    ctx.putImageData(imageData, 0, 0);
    document.getElementById("it").textContent = instance.exports.getIteration();
  }, 1);

}).catch(console.error);
