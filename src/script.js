document.addEventListener("DOMContentLoaded", function(event) {
  fetch('../out/main.wasm').then(response => response.arrayBuffer())
    .then((buffer) => {

      const canvas = document.getElementById("canvas");
      const ctx = canvas.getContext("2d");
      const getCanvasWidth = () => canvas.width;
      const getCanvasHeight = () => canvas.height;
      const env = {
        getCanvasWidth,
        getCanvasHeight
      };

      WebAssembly.instantiate(buffer, { env }).then(result => {
        const exports = result.instance.exports;
        const memory = exports.memory;
        const { width, height } = canvas;
        const wh = width * height;
        
        memory.grow(100);
        const heap = memory.buffer;
        const HEAP_START = 0;

        exports.init(heap, HEAP_START);

        function execute() {
          exports.channel();
          var imageArray = new Uint8ClampedArray(heap, HEAP_START, 4 * wh);
          var data = new ImageData(imageArray,500,400);
          console.log(imageArray.length);
          console.log(imageArray.slice(799996));
          console.log(data.data.slice(799996));
          ctx.putImageData(data, 0, 0);
        }
        execute();
      });
    });
});

