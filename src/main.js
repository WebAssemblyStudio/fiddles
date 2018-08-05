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
  
  if (exports.test1) {
    console.time('ipow time');
    const r1 = exports.test1();
    console.timeEnd('ipow time');
    console.log('ipow:', r1);
  }

  if (exports.test2) {
    console.time('fpow time');
    const r2 = exports.test2();
    console.timeEnd('fpow time');
    console.log('fpow:', r2);
  }

}).catch(console.error);
