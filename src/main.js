function bench(fn, name) {
  let acc = 0;
  let t = performance.now();
  for (let i = -10000000.0; i <= 10000000.0; i += 0.333333) {
    acc += fn(i);
  }
  t = performance.now() - t;
  console.log(name + ': ' + t + ' ms');
  return acc;
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  const { sat_conv_rust, sat_conv_opt, sat_conv_opt2 } = exports;
  
  bench(sat_conv_rust, 'sat_conv_rust');
  bench(sat_conv_opt, 'sat_conv_opt');
  bench(sat_conv_opt2, 'sat_conv_opt2');

  bench(sat_conv_rust, 'sat_conv_rust');
  bench(sat_conv_opt, 'sat_conv_opt');
  bench(sat_conv_opt2, 'sat_conv_opt2');



}).catch(console.error);
