
function bench_js() {
  var acc = 0.0;
  for (let i = 0; i < 10000000; i++) {
    acc += Math.imul(i & 1 ? 2.0 : -2.0, i);
  }
  return acc;
}

function test(name, func) {
  console.log('\n' + name + ':\n');
  console.log(func(2, 4), 8);            // 8
  console.log(func(-1, 8), -8);          // -8
  console.log(func(-2, -2), 4);          // 4
  console.log(func(0xffffffff, 5), -5);  // -5
  console.log(func(0xfffffffe, 5), -10); // -10
  console.log(func(1e+60, 1e+60), 0); // 0
  console.log(func(1e+60,-1e+60), 0); // 0
  console.log(func(-1e+60,-1e+60), 0); // 0
  console.log(func(1e+24, 1e2), -2147483648); // -2147483648
  console.log(func(1e+24, -1e2), -2147483648);
  console.log(func(-1e+24, 1e2), -2147483648);
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  // test('Math.imul js', Math.imul);
  // test('Math.imul as fixed', exports.imulFixed);
  // test('Math.imul as original', exports.imulOriginal);

  for (let i = 0; i < 10; i++) bench_js();
  
  console.time('imul js');
  var res_js = bench_js();
  console.timeEnd('imul js');
  console.log('res js: ' + res_js);

  for (let i = 0; i < 10; i++) exports.bench();

  console.time('imul as fixed');
  var res_js = exports.bench();
  console.timeEnd('imul as fixed');
  console.log('res as: ' + res_js);
  
}).catch(console.error);
