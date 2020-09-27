function measure(fn, name) {
  // warmup
  fn(); fn();
  let t = performance.now();
  let res = fn();
  t = performance.now() - t;
  console.log(`${name} time: ${t}ms`);
  console.log('result: ' + (res >>> 0));
  console.log('-----------------------');
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  console.log('-----------------------');

  measure(exports.bench_rev64,  'rev64');
  measure(exports.bench_rev64a, 'rev64a');
  measure(exports.bench_rev64b, 'rev64b');
  measure(exports.bench_rev64_table, 'rev64_table');

  measure(exports.bench_rev32,  'rev32');
  measure(exports.bench_rev32a, 'rev32a');
  measure(exports.bench_rev32_table, 'rev32_table');

  measure(exports.bench_rev16,  'rev16');
  measure(exports.bench_rev16a, 'rev16a');
  measure(exports.bench_rev16_table, 'rev16_table');

  measure(exports.bench_rev8,  'rev8');
  measure(exports.bench_rev8a, 'rev8a');
  measure(exports.bench_rev8b, 'rev8b');
  measure(exports.bench_rev8_table, 'rev8_table');
}).catch(console.error);
