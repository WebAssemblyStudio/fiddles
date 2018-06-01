const cycles = 500;
let step = 0;

(function() {
  var requestAnimationFrame =
    window.requestAnimationFrame ||
    window.mozRequestAnimationFrame ||
    window.webkitRequestAnimationFrame ||
    window.msRequestAnimationFrame;
  window.requestAnimationFrame = requestAnimationFrame;
})();

fetch("../out/main.wasm")
  .then(response => response.arrayBuffer())
  .then(bytes => WebAssembly.instantiate(bytes))
  .then(({ instance }) => {
    const width = 320;
    const height = 200;

    const colorsOffset = instance.exports.getColorsOffset();
    const colors = new Uint8Array(
      instance.exports.memory.buffer,
      colorsOffset,
      width * height * 4
    );
    const videoOffset = instance.exports.getVideoBufferOffset();
    const video_buffer = new Uint8Array(
      instance.exports.memory.buffer,
      videoOffset,
      width * height
    );

    instance.exports.main();

    const canvas = document.getElementById("canvas");
    const ctx = canvas.getContext("2d");
    const imageData = ctx.getImageData(0, 0, width, height);
    const data = imageData.data;

    const canvas1 = document.getElementById("canvas1");
    const ctx1 = canvas1.getContext("2d");
    const imageData1 = ctx1.getImageData(0, 0, width, height);
    const data1 = imageData1.data;

    function draw() {
      instance.exports.main();
      for (let i = 0; i < width * height; i++) {
        data[4 * i] = video_buffer[i];
        data[4 * i + 1] = video_buffer[i];
        data[4 * i + 2] = video_buffer[i];
        data[4 * i + 3] = 255;
      }
      ctx.putImageData(imageData, 0, 0);

      for (let i = 0; i < width * height * 4; i++) {
        data1[i] = colors[i];
      }
      ctx1.putImageData(imageData1, 0, 0);

      if (step < cycles) {
        requestAnimationFrame(draw);
        step++;
      }
    }

    requestAnimationFrame(draw);
  });
