WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  exports.test1();
  exports.test1();
  exports.test1();
  exports.test1();
  exports.test1();

  console.time('t1');
  exports.test1();
  console.timeEnd('t1');

  exports.test2();
  exports.test2();
  exports.test2();
  exports.test2();
  exports.test2();

  console.time('t2');
  exports.test2();
  console.timeEnd('t2');

  exports.test3();
  exports.test3();
  exports.test3();
  exports.test3();
  exports.test3();

  console.time('t3');
  exports.test3();
  console.timeEnd('t3');
}).catch(console.error);
