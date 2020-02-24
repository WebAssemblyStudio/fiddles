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
  const { test1, test2, test3 } = result.instance.exports;

  console.time('test1-1000000');
  test1(1000000);
  console.timeEnd('test1-1000000');

  console.time('test1-10000000');
  test1(10000000);
  console.timeEnd('test1-10000000');


  console.time('test2-1000000');
  test2(1000000);
  console.timeEnd('test2-1000000');

  console.time('test2-10000000');
  test2(10000000);
  console.timeEnd('test2-10000000');

  console.time('test3-1000000');
  test3(1000000);
  console.timeEnd('test3-1000000');

  console.time('test3-10000000');
  test3(10000000);
  console.timeEnd('test3-10000000');
  
}).catch(console.error);
