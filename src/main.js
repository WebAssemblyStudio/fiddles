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

  exports.filterTest1();
  exports.filterTest1();
  exports.filterTest1();
  exports.filterTest1();
  exports.filterTest1();


  console.time('as-std filter');
  const stdlen = exports.filterTest1();
  console.timeEnd('as-std filter');
  console.log('as-std len:', stdlen);

  exports.filterTest2();
  exports.filterTest2();
  exports.filterTest2();
  exports.filterTest2();
  exports.filterTest2();

  console.time('new filter');
  const newlen = exports.filterTest2();
  console.timeEnd('new filter');
  console.log('new len:', newlen);


  const array = Array.from({ length: 8000000 }, (v, i) => i);
  console.time('js filter');
  var res = array.filter((value, index) => {
    return (index & 15) == 0 && (value & 32) == 0;
  });
  const jslen = res.length;
  console.timeEnd('js filter');
  console.log('js len:', jslen);
}).catch(console.error);
