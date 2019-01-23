
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

  test('Math.imul js', Math.imul);
  test('Math.imul as fixed', exports.imulFixed);
  test('Math.imul as original', exports.imulOriginal);
  //test('imul as', exports.imul);
  
}).catch(console.error);
