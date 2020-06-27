WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { clamp, clamp1, clamp2 } = result.instance.exports;

  const it = 4.0 / 1_0000_0000.0;
  
  let t = 0.0, e = 0.0;
  t = performance.now();

  for (let x = -2.0; x < 2.0; x += it) {
    clamp(x, -1.0, 1.0);
  }
  
  e = performance.now() - t;
  console.log('clamp: ' + e + ' ms');



  t = performance.now();

  for (let x = -2.0; x < 2.0; x += it) {
    clamp1(x, -1.0, 1.0);
  }
  
  e = performance.now() - t;
  console.log('clamp1: ' + e + ' ms');



  t = performance.now();

  for (let x = -2.0; x < 2.0; x += it) {
    clamp2(x, -1.0, 1.0);
  }
  
  e = performance.now() - t;
  console.log('clamp2: ' + e + ' ms');

}).catch(console.error);
