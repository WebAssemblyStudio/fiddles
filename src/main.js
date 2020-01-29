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

  const test1 = exports.test1;
  const test2 = exports.test2;
  
  console.time('division by uint64 constant 1e10 (mulh/shift)');
  test1();
  console.timeEnd('division by uint64 constant 1e10 (mulh/shift)');

  console.time('division by uint64 constant 1e10 (normal)');
  test2();
  console.timeEnd('division by uint64 constant 1e10 (normal)');
}).catch(console.error);
