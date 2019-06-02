let instance;
let imageData;
let ctx2d;
let ctxbm;

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'))
.then(results => {
  instance = results.instance;
  main();
}).catch(console.error);


function main() {
  initWorld();
  setInterval(stepWorld, 5);
}

function initWorld() {
  let container = document.querySelector('#container');
  let canvas = document.querySelector('canvas');


  let size = instance.exports.get_image_size();
  canvas.width = size;
  canvas.height = size;
  ctx2d = canvas.getContext('2d');

  instance.exports.init_world();
  let offset = instance.exports.get_image_offset();
  let array = new Uint8ClampedArray(instance.exports.memory.buffer, offset, size*size*4);
  imageData = new ImageData(array, size, size);
  console.log('end initWorld');
}

function stepWorld() {
  container.textContent = instance.exports.step_world();    
  ctx2d.putImageData(imageData, 0, 0);
}

function getAnt() {
  return [
    instance.exports.get_ant_x(),
    instance.exports.get_ant_y(),
    instance.exports.get_ant_d(),
  ]
}