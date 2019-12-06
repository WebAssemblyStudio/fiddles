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
  const { log_lut, logf, exp_lut, expf, powf, pow_lut } = exports;
  const { log2_new, log2 } = exports;
  // console.log(exports.exp_lut(0.22124e-20), expf(0.22124e-20));
  // console.log(exports.exp_lut(-1.0), expf(-1.0));
  // console.log(exports.exp_lut(-0.5), expf(-0.5));
  // console.log(exports.exp_lut(-0.0), expf(-0.0));
  // console.log(exports.exp_lut(+0.0), expf(+0.0));
  // console.log(exports.exp_lut(+0.5), expf(+0.5));
  // console.log(exports.exp_lut(+1.5), expf(+1.5));
  // console.log(exports.exp_lut(+2.0), expf(+2.0));
  // console.log(exports.exp_lut(+125.0), expf(+125.0));
  // console.log(exports.exp_lut(-Infinity), expf(-Infinity));

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

  // console.log('[+0.5, Inf]:  ' + powf( 0.5, Infinity), pow_lut( 0.5, Infinity));
  // console.log('[-0.5, Inf]:  ' + powf(-0.5, Infinity), pow_lut(-0.5, Infinity));
  // console.log('[   0, Inf]:  ' + powf(0.0, Infinity), pow_lut(0.0, Infinity));
  // console.log('[ Inf, Inf]:  ' + powf(Infinity, Infinity), pow_lut(Infinity, Infinity));
  // console.log('[ Inf,-Inf]:  ' + powf(Infinity,-Infinity), pow_lut(Infinity,-Infinity));
  // console.log('[-Inf,-Inf]:  ' + powf(-Infinity, -Infinity), pow_lut(-Infinity, -Infinity));

  // let acc = 0.0;
  // for (let x = -2000.0; x < 2000.0; x += 1) {
  //   for (let y = -2000.0; y < 2000.0; y += 1) {
  //     acc += pow_lut(x, y);
  //   }
  // }
  // acc = 0.0;
  // console.time('pow_lut (NEW!)');
  // for (let x = -2000.0; x < 2000.0; x += 1) {
  //   for (let y = -2000.0; y < 2000.0; y += 1) {
  //     acc += pow_lut(x, y);
  //   }
  // }
  // console.timeEnd('pow_lut (NEW!)');

  // acc = 0.0;
  // for (let x = -2000.0; x < 2000.0; x += 1) {
  //   for (let y = -2000.0; y < 2000.0; y += 1) {
  //     acc += powf(x, 4);
  //   }
  // }
  // acc = 0.0;
  // console.time('powf (old)');
  // for (let x = -2000.0; x < 2000.0; x += 1) {
  //   for (let y = -2000.0; y < 2000.0; y += 1) {
  //     acc += powf(x, y);
  //   }
  // }
  // console.timeEnd('powf (old)');

  // acc = 0.0;

  // console.time('Math.pow (js)');
  // for (let x = -2000.0; x < 2000.0; x += 1) {
  //   for (let y = -2000.0; y < 2000.0; y += 1) {
  //     // acc += Math.fround(Math.pow(x, y));
  //     acc += Math.pow(x, y);
  //   }
  // }
  // console.timeEnd('Math.pow (js)');

  let acc = 0.0;
  for (let x = -1000.0; x < 1000.0; x += 0.0001) {
    acc += Math.log2(x);
  }
  acc = 0.0;
  console.time('Math.log2 (js)');
  for (let x = -1000.0; x < 1000.0; x += 0.0001) {
    acc += Math.log2(x);
  }
  console.timeEnd('Math.log2 (js)');

  acc = 0.0;
  for (let x = -1000.0; x < 1000.0; x += 0.0001) {
    acc += log2_new(x);
  }
  acc = 0.0;
  console.time('log2 (NEW!)');
  for (let x = -1000.0; x < 1000.0; x += 0.0001) {
    acc += log2_new(x);
  }
  console.timeEnd('log2 (NEW!)');

  acc = 0.0;
  for (let x = -1000.0; x < 1000.0; x += 0.0001) {
    acc += log2(x);
  }
  acc = 0.0;
  console.time('log2 (old)');
  for (let x = -1000.0; x < 1000.0; x += 0.0001) {
    acc += log2(x);
  }
  console.timeEnd('log2 (old)');

}).catch(console.error);
