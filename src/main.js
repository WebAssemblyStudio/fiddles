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

  (function draw() {
    // window.requestAnimationFrame(draw);
    var cnv = document.querySelector('#glCanvas');
    var ctx = cnv.getContext("2d");
    var bcr = cnv.getBoundingClientRect();

    var width = bcr.width;
    var height = bcr.height;

    ctx.clearRect(0, 0, width, height); // clear canvas

    ctx.font = '48px serif';
    ctx.fillText('fuck', 100, 100);

    const time = new Date().getSeconds();

    // const t0 = performance.now();
    // for (let i = 0; i < 10000000; i++) {
        // mem[ptr] = time;
        // exports.fuck();
    // }
    // const t1 = performance.now();
    // ctx.rotate(mem[ptr]);
    // console.log(t1 - t0 + ' ms');

    // let a;
    // const t2 = performance.now();
    // for (let i = 0; i < 10000000; i++) {
      ctx.rotate(((2 * Math.PI) / 60) * time + ((2 * Math.PI) / 60000) * time);
    // }
    // const t3 = performance.now();
    // ctx.rotate(a);
    // console.log(t3 - t2 + ' ms');
  })()

})()

