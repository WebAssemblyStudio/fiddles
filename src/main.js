WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  const s = 1024 * 4;

  exports.boxBlur(s, s);

  console.time('boxBlur');
  exports.boxBlur(s, s);
  console.timeEnd('boxBlur');


  exports.boxBlur_2(s, s);

  console.time('boxBlur_2');
  exports.boxBlur_2(s, s);
  console.timeEnd('boxBlur_2');
}).catch(console.error);
