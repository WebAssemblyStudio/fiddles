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

  measure(exports.bench_rev2, 'rev2');
  measure(exports.bench_rev11, 'rev11');
  measure(exports.bench_rev11a, 'rev11a');
  measure(exports.bench_rev12, 'rev12');
  measure(exports.bench_rev_table, 'rev_table');
}).catch(console.error);
