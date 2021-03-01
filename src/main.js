
// Now handles fill requests with RGB colors. Next handle rects with pixel data.


var width = undefined;
var height = undefined;

const memSize = 256;
const memory = new WebAssembly.Memory({ initial: memSize, maximum: memSize });

var onEnterFrame = function(waInstance, ctx) {

    const fillReqCount = waInstance.exports.fillRequestCount();
    
    if (fillReqCount > 0) {
      const fillReq = waInstance.exports.fillRequest();
      const data = new Int32Array(waInstance.exports.memory.buffer, fillReq, 5 * fillReqCount);

      for (var i=0; i < fillReqCount * 5; i+=5) {
        const col = '#' + (data[i + 4]&0xffffff).toString(16);
        ctx.fillStyle=col;
        ctx.fillRect(data[i+0],data[i+1],data[i+2],data[i+3]);
      }
    }

    

    // const data = new Uint8ClampedArray(waInstance.exports.memory.buffer, pointer, width * height * 4);
    // const img = new ImageData(data, width, height);

    // ctx.putImageData(img, 0, 0);
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

  onEnterFrame(instance, ctx);

}).catch(console.error);