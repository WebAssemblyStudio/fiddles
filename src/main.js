WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  let m = 10;
  let n = 10;
  let length = m*n;
  let myArrayPtr = exports.init(n, m) + 4 * 8;
  let myArray = new Int32Array(exports.memory.buffer, myArrayPtr, length);
  const canvas = document.getElementById('container');
  console.log(canvas.getContext('2d'));
}).catch(console.error);
