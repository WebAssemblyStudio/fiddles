WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    },
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
  console: {
    logi(value) { console.log('logi: ' + value); },
    logf(value) { console.log('logf: ' + value); }
  }
}).then(result => {
  const exports = result.instance.exports;
  
  const ITERS = 1000000;

  var arr = new Array(ITERS);
  for (let i = 0; i < ITERS; ++i) {
    arr[i] = (Math.random() * ITERS) | 0;
  }

  console.time('js');
  arr.sort((a, b) => a - b);
  console.timeEnd('js');

  exports.test();

  console.time('as');
  exports.test();
  console.timeEnd('as');

}).catch(console.error);
