const width = 100;
const height = 100;

const memSize = 256;
const memory = new WebAssembly.Memory({ initial: memSize, maximum: memSize });

var onEnterFrame = function(waInstance, ctx) {
    // console.log("a");
    // context.clearRect(0, 0, innerWidth, innerHeight);
    // context.beginPath();
    // context.arc(x, 100, 30, 0, 2 * Math.PI);
    // context.stroke();
    // x += 1;

    const pointer = waInstance.exports.render();
    const data = new Uint8ClampedArray(waInstance.exports.memory.buffer, pointer, width * height * 4);
    const img = new ImageData(data, width, height);
    ctx.putImageData(img, 0, 0);
    
    requestAnimationFrame(function() {
        onEnterFrame(waInstance, ctx);
    });
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, { env: { memory } })).then(results => {
  instance = results.instance;

  // Get 2d drawing context
  const ctx = document.getElementById('c').getContext('2d');
  
  onEnterFrame(instance, ctx);

}).catch(console.error);