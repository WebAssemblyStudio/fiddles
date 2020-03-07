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
  const { f1, f2, f3, f4, i1, i3 } = result.instance.exports;
  
  f1(37);
  console.time('f64.f1');
  f1(37);
  console.timeEnd('f64.f1');

  f2(37);
  console.time('f64.f2');
  f2(37);
  console.timeEnd('f64.f2');

  f3(37);
  console.time('f64.f3');
  f3(37);
  console.timeEnd('f64.f3');

  f4(37);
  console.time('f64.f4');
  f4(37);
  console.timeEnd('f64.f4');

  // i32 version
  i1(37);
  console.time('i32.i1');
  i1(37);
  console.timeEnd('i32.i1');

  // i32 version
  i3(37);
  console.time('i32.i3');
  i3(37);
  console.timeEnd('i32.i3');

  console.log('');

  js(37);
  console.time('f64.js');
  js(37);
  console.timeEnd('f64.js');

}).catch(console.error);
