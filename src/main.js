function js(x) {
  if (x === 1 || x === 2) {
    return 1;
  }
  return js(x - 1) + js(x - 2);
}

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
  const { f1, f2, f3, f4, f5 } = result.instance.exports;
  
  f1(37);
  console.time('f1');
  f1(37);
  console.timeEnd('f1');

  f2(37);
  console.time('f2');
  f2(37);
  console.timeEnd('f2');

  f3(37);
  console.time('f3');
  f3(37);
  console.timeEnd('f3');

  f4(37);
  console.time('f4');
  f4(37);
  console.timeEnd('f4');

  // i32 version
  f5(37);
  console.time('f5');
  f5(37);
  console.timeEnd('f5');

  js(37);
  console.time('js');
  js(37);
  console.timeEnd('js');

}).catch(console.error);
