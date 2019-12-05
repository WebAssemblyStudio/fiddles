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

  let acc = 0.0;
  for (let x = -2000.0; x < 2000.0; x += 1) {
    for (let y = -2000.0; y < 2000.0; y += 1) {
      acc += pow_lut(x, y);
    }
  }
  acc = 0.0;
  console.time('pow_lut');
  for (let x = -2000.0; x < 2000.0; x += 1) {
    for (let y = -2000.0; y < 2000.0; y += 1) {
      acc += pow_lut(x, y);
    }
  }
  console.timeEnd('pow_lut');

  acc = 0.0;
  for (let x = -2000.0; x < 2000.0; x += 1) {
    for (let y = -2000.0; y < 2000.0; y += 1) {
      acc += powf(x, y);
    }
  }
  acc = 0.0;
  console.time('powf');
  for (let x = -2000.0; x < 2000.0; x += 1) {
    for (let y = -2000.0; y < 2000.0; y += 1) {
      acc += powf(x, y);
    }
  }
  console.timeEnd('powf');

}).catch(console.error);
