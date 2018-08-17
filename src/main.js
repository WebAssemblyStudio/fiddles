
const memory = new WebAssembly.Memory({ initial: 2 });

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    memory,
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
  console: {
    logi(value) { console.log('logi: ' + value); },
    logf(value) { console.log('logf: ' + value); }
  }
}).then(result => {
  const buf     = memory.buffer;
  const exports = result.instance.exports;
  const test    = exports.test;

  const arr = new Float64Array([1, 2, 3, 4, 5]);
  const F64 = new Float64Array(buf);
  F64.set(arr, 1);
  test();

}).catch(console.error);
