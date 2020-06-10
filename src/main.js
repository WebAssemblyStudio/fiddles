fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {

  let instance = results.instance;
  let canvas = document.querySelector('canvas');  
  let size = instance.exports.get_size();
  canvas.height = size;
  canvas.width = size;  
  let ctx = canvas.getContext("2d");  
  
  let array = new Uint8ClampedArray( 
    instance.exports.memory.buffer,  
    instance.exports.get_image(),    
    size*size*4,                     
  );
  let imageData = new ImageData(array, size, size);

  instance.exports.init();

  //timeout 1 pour aller plus vite
  setInterval(function(){
    instance.exports.move();
    instance.exports.fill_image();
    ctx.putImageData(imageData, 0, 0);
    document.getElementById("iteration").textContent = instance.exports.get_iteration();
  }, 1);  

}).catch(console.error);
