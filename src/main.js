WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  
  var acc = 0;
  console.time('t1');

  for (let i = 0; i < 10000000; i++) {
    acc += exports.isqrt32_1(i);
  }

  console.timeEnd('t1');
  console.log('acc1: ' + acc);

  acc = 0;
  console.time('t2');

  for (let i = 0; i < 10000000; i++) {
    acc += exports.isqrt32_2(i);
  }

  console.timeEnd('t2');
  console.log('acc2: ' + acc);

}).catch(console.error);
