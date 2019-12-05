function exp2f(x) {
  return Math.fround(Math.exp(x * Math.LN2));
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  const { log_lut, logf } = exports;
  // console.log(exports.exp2_lut(0.22124e-20), exp2f(0.22124e-20));
  // console.log(exports.exp2_lut(-1.0), exp2f(-1.0));
  // console.log(exports.exp2_lut(-0.5), exp2f(-0.5));
  // console.log(exports.exp2_lut(-0.0), exp2f(-0.0));
  // console.log(exports.exp2_lut(+0.0), exp2f(+0.0));
  // console.log(exports.exp2_lut(+0.5), exp2f(+0.5));
  // console.log(exports.exp2_lut(+1.5), exp2f(+1.5));
  // console.log(exports.exp2_lut(+2.0), exp2f(+2.0));
  // console.log(exports.exp2_lut(+125.0), exp2f(+125.0));
  // console.log(exports.exp2_lut(-Infinity), exp2f(-Infinity));

  // console.log(exports.log_lut(0.22124e-20), logf(0.22124e-20), Math.fround(Math.log(0.22124e-20)));
  // console.log(exports.log_lut(-1.0), logf(-1.0));
  // console.log(exports.log_lut(-0.5), logf(-0.5));
  // console.log(exports.log_lut(-0.0), logf(-0.0));
  // console.log(exports.log_lut(+0.0), logf(+0.0));
  // console.log(exports.log_lut(+0.5), logf(+0.5));
  // console.log(exports.log_lut(+1.5), logf(+1.5));
  // console.log(exports.log_lut(+2.0), logf(+2.0));
  // console.log(exports.log_lut(+125.0), logf(+125.0));
  // console.log(exports.log_lut(-Infinity), logf(-Infinity));
  // console.log(exports.log_lut(Infinity), logf(Infinity));
  // console.log(exports.log_lut(NaN), logf(NaN));

  let acc = 0.0;
  for (let i = -1000.0; i < 1000.0; i += 1e-4) {
    acc += log_lut(i);
  }
  acc = 0.0;
  console.time('log_lut');
  for (let i = -2000.0; i < 2000.0; i += 1e-4) {
    acc += log_lut(i);
  }
  console.timeEnd('log_lut');

  acc = 0.0;
  for (let i = -1000.0; i < 1000.0; i += 1e-4) {
    acc += logf(i);
  }
  acc = 0.0;
  console.time('logf');
  for (let i = -2000.0; i < 2000.0; i += 1e-4) {
    acc += logf(i);
  }
  console.timeEnd('logf');

}).catch(console.error);
