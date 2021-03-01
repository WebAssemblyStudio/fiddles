var width = undefined;
var height = undefined;

const memSize = 256;
const memory = new WebAssembly.Memory({ initial: memSize, maximum: memSize });

var onEnterFrame = function(waInstance, ctx) {
    const pointer = waInstance.exports.render();
    const data = new Uint8ClampedArray(waInstance.exports.memory.buffer, pointer, width * height * 4);
    const img = new ImageData(data, width, height);

    // ctx.canvas.width  = window.innerWidth;
    // ctx.canvas.height = window.innerHeight;
    // console.log(height);

    ctx.putImageData(img, 0, 0);
    // ctx.putImageData(img, 0, 0);
    
    requestAnimationFrame(function() {
        onEnterFrame(waInstance, ctx);
    });
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, { env: { memory } })).then(results => {
  instance = results.instance;

  width = instance.exports.width();
  height = instance.exports.height();

  const canvas = document.getElementById('c');
  canvas.width = width;
  canvas.height = height;
  const ctx = canvas.getContext('2d');
  
  ctx.fillStyle="green";
  ctx.fillRect(0,0,width,height);

  onEnterFrame(instance, ctx);

}).catch(console.error);