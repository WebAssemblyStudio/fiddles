(async function() {
const result = await WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    memory: new WebAssembly.Memory({ initial: 1 }),
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  }
})
const exports = result.instance.exports;
const mem = new Float64Array(exports.memory.buffer);
const ptr = exports.get_ptr() >>> 3;
console.log(ptr);
let count = 0;

  (function draw(time) {
    window.requestAnimationFrame(draw);
    var cnv = document.querySelector('#glCanvas');
    var ctx = cnv.getContext("2d");
    var bcr = cnv.getBoundingClientRect();

    var width = bcr.width;
    var height = bcr.height;

    ctx.clearRect(0, 0, width, height); // clear canvas

    ctx.font = '48px serif';
    ctx.fillText('fuck', 100, 100);

    if (count === 100) count = 0;
    if (count === 0) {
      exports.fuck(time);
    }

    // ctx.rotate(mem[ptr + count]);
    // console.log(ptr + count, mem[ptr + count])
    count++;
  })()

})()

