(async function() {
  const result = await WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
    env: {
      memory: new WebAssembly.Memory({ initial: 1 }),
      abort(msg, file, line, column) {
        console.error("abort called at main.ts:" + line + ":" + column);
      }
    },
    console: {
      log(value) {
        console.log(value);
      }
    }
  })
  const exports = result.instance.exports;
  const mem = new Float64Array(exports.memory.buffer);
  const ptr = exports.get_ptr() >>> 3;
  let count = 0;
  exports.animate(2000);

  (function draw(time) {
    if (count < 2000) window.requestAnimationFrame(draw);
    var cnv = document.querySelector('#glCanvas');
    var ctx = cnv.getContext("2d");
    var bcr = cnv.getBoundingClientRect();

    var width = bcr.width;
    var height = bcr.height;

    ctx.clearRect(0, 0, width, height); // clear canvas

    ctx.font = '48px serif';
    ctx.fillText('Hello World!!', 100, 100);

    ctx.translate(mem[ptr + count], 0);
    count++;
  })()
})()

