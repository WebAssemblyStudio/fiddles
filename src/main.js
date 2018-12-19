
function init(wasm, width, height) {
  this.width = width;
  this.height = height;
  const area = width * height;
  this.area = area;

  this.byteOffset = 8192; // Step above the first few kilobytes to clear the stack variables

  const instance = wasm.instance;
  const memory = instance.exports.memory;
  const pages = 2 + ((5 * 4 * width * height) >> 16);
  memory.grow(pages);

  const heap = memory.buffer;
  this.heap = heap;

  this.force  = new Int32Array(heap, this.byteOffset + (4 * area), area);
  this.status = new Int32Array(heap, this.byteOffset + (8 * area), area);
  this.u      = new Int32Array(heap, this.byteOffset + (12 * area), area);
  this.v      = new Int32Array(heap, this.byteOffset + (16 * area), area);

  instance.exports.init(heap, this.byteOffset, width, height);
}

function step_fast(exports, signalAmplitude) {
  exports.step_fast(signalAmplitude, 0);
}

function step_slow(exports, signalAmplitude) {
  exports.step_slow(signalAmplitude, 0);
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(wasm => {
  const exports = wasm.instance.exports;

  init(wasm, 1024, 1024);

  for (let f = 0.0; f <= 1.0; f += 0.5e-1) {
    step_fast(exports, f);
  }

  console.time('fast');
  for (let f = 0.0; f <= 1.0; f += 0.5e-1) {
    step_fast(exports, f);
  }
  console.timeEnd('fast');

  for (let f = 0.0; f <= 1.0; f += 0.5e-1) {
    step_slow(exports, f);
  }

  console.time('slow');
  for (let f = 0.0; f <= 1.0; f += 0.5e-1) {
    step_slow(exports, f);
  }
  console.timeEnd('slow');
  
}).catch(console.error);
