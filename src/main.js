WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  let n;

  n = 10000000;

  console.time('benchOrig (' + n + ')');
  exports.benchOrig(n);
  console.timeEnd('benchOrig (' + n + ')');

  n = 1000000000;

  console.time('benchOrig (' + n + ')');
  exports.benchOrig(n);
  console.timeEnd('benchOrig (' + n + ')');



  n = 10000000;

  console.time('benchNext (' + n + ')');
  exports.benchNext(n);
  console.timeEnd('benchNext (' + n + ')');

  n = 1000000000;

  console.time('benchNext (' + n + ')');
  exports.benchNext(n);
  console.timeEnd('benchNext (' + n + ')');

  // console.log(exports.castOrig(0), exports.castNext(0));
  // console.log(exports.castOrig(-0), exports.castNext(-0));
  // console.log(exports.castOrig(1.0), exports.castNext(1.0));
  // console.log(exports.castOrig(Number.MIN_VALUE), exports.castNext(Number.MIN_VALUE));
  // console.log(exports.castOrig(-Number.MIN_VALUE), exports.castNext(-Number.MIN_VALUE));
  // console.log(exports.castOrig(Number.MIN_VALUE / 1.999999999), exports.castNext(Number.MIN_VALUE / 1.999999999));
  // console.log(exports.castOrig(NaN), exports.castNext(NaN));
  // console.log(exports.castOrig(Infinity), exports.castNext(Infinity));
  // console.log(exports.castOrig(-Infinity), exports.castNext(-Infinity));

}).catch(console.error);
