
const importInimportObj = {
  main: {
    sayHello(memory) {
      console.log("Hello from WebAssembly!" + Math.random(), memory);
    },
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    },
    memory: new WebAssembly.Memory({ initial: 256 })
  }
}
WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), importInimportObj).then(result => {
  const exports = result.instance.exports;

  const imageWidth = 2;
  const imageHeight = 2;
  const imageWH = imageWidth * imageHeight;
  const bytesPerImage = imageWH * 4;
  const minimumMemorySize = bytesPerImage * 2 + 4;
  const pagesNeeded = Math.ceil(minimumMemorySize / (64 * 1024));
  console.log("pagesNeeded", pagesNeeded);

  exports.memory.grow(pagesNeeded);
  const inU32 = new Uint32Array(exports.memory.buffer);
  for (let i = 0; i < imageWH; i += 1) {
    inU32[i] = (i + 1) * 1;
  }
  console.log(inU32.slice(0, imageWH));
  exports.wasmLoop(2, 2);
  // exports.rotate(2, 2, 90);
  console.log(inU32.slice(imageWH, imageWH + imageWH));
}).catch(console.error);
