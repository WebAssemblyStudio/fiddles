fetch('../out/main.wasm')
.then(response => response.arrayBuffer())
.then(bytes => WebAssembly.instantiate(bytes, { env: { cos: Math.cos }}))
.then(results => {
  let mod = {};
  let inst = results.instance;
  mod.alloc = inst.exports.alloc;
  mod.dealloc = inst.exports.dealloc;
  mod.fill = inst.exports.fill;

  let canvas = document.getElementById("screen");
  let width = canvas.width;
  let height = canvas.height;

  if (canvas.getContext) {
    var ctx = canvas.getContext('2d');

    let byteSize = width * height * 4;
    var pointer = mod.alloc( byteSize );

    var usub = new Uint8ClampedArray(inst.exports.memory.buffer, pointer, byteSize);
    var img = new ImageData(usub, width, height);

    var start = null;
    function step(timestamp) {
      var progress;
      if (start === null) start = timestamp;
      progress = timestamp - start;
      if (progress > 100) {
        mod.fill(pointer, width, height, timestamp);

        start = timestamp

        window.requestAnimationFrame(draw);
      } else {
        window.requestAnimationFrame(step);
      }
    }

    function draw() {
      ctx.putImageData(img, 0, 0)
      window.requestAnimationFrame(step);
    }

    window.requestAnimationFrame(step);
  }
})
.catch(console.error);
