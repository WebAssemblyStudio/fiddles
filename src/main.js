WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    log() { console.log("it runs!"); },
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
  Math,
}).then(result => {
  const exports = result.instance.exports;
  const index = exports.main();
  const canvas = document.querySelector("canvas") || document.createElement("canvas");
  canvas.width = 800;
  canvas.height = 600;
  if (!canvas.parentElement) {
    document.body.appendChild(canvas);
  }
  const ctx = canvas.getContext("2d");
  const dv = new DataView(exports.memory.buffer);
  const u8 = Uint8Array.BYTES_PER_ELEMENT;
  const f64 = Float64Array.BYTES_PER_ELEMENT;
  requestAnimationFrame(function frame() {
    requestAnimationFrame(frame);
    exports.frame();
    ctx.fillStyle = "black";
    ctx.fillRect(0, 0, 800, 600);
    var pointer = index;
    ctx.fillStyle = "white";
    var x = 0;
    var y = 0;

    for (let i = 0; i < 1000; i++) {
      console.log(pointer);
      debugger;
      x = dv.getFloat64(pointer, true);
      pointer += f64;
      y = dv.getFloat64(pointer, true);
      pointer += f64;
      color = dv.getUint8(pointer, true);
      pointer += u8 + f64;
      ctx.fillRect(x, y, 1, 1);
    }
  });
  
}).catch(console.error);
