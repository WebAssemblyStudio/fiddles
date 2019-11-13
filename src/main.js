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
  const { test1, test2 } = result.instance.exports;

  console.time('t1');
  for (let i = 0; i < 100000000; i++) {
    test1();
  }
  console.timeEnd('t1');

  console.time('t2');
  for (let i = 0; i < 100000000; i++) {
    test2();
  }
  console.timeEnd('t2');
  
}).catch(console.error);
