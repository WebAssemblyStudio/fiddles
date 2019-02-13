



const width = 4096;
const height = 4096;
const data = new ImageData(width, height);

const bytesPerImage  = data.width * data.height * 4;
const numPagesNeeded = Math.ceil(bytesPerImage * 2 / (64 * 1024));

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    memory: new WebAssembly.Memory({ initial: numPagesNeeded }),
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  
  console.time('t');

  const view = new Uint8ClampedArray(exports.memory.buffer);
  view.set(data.data);

  // measure 256 ms
  console.time('rotate 4k x 4k on 270deg took:');
  exports.rotate(data.width, data.height, 270);
  console.timeEnd('rotate 4k x 4k on 270deg took:');

  return new ImageData(
    view.slice(bytesPerImage, bytesPerImage * 2),
    false ? data.height : data.width,
    false ? data.width : data.height,
  );

}).catch(console.error);
