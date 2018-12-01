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
  const { test1, test2, test3 } = result.instance.exports;
  let t1 = 0;
  for (let i = -6147480; i < 6147480; i++) {
    t1 = test1(t1, i);
  }
  console.time('t1');
  for (let i = -6147480; i < 6147480; i++) {
    t1 = test1(t1, i);
  }
  console.timeEnd('t1');

  for (let i = -6147480; i < 6147480; i++) {
    t1 = test2(t1, i);
  }
  t1 = 0;
  console.time('t2');
  for (let i = -6147480; i < 6147480; i++) {
    t1 = test2(t1, i);
  }
  console.timeEnd('t2');

  for (let i = -6147480; i < 6147480; i++) {
    t1 = test3(t1, i);
  }
  t1 = 0;
  console.time('t3');
  for (let i = -6147480; i < 6147480; i++) {
    t1 = test3(t1, i);
  }
  console.timeEnd('t3');
}).catch(console.error);
