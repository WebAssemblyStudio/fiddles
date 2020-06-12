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
  const { div100_1, div100_2 } = result.instance.exports;

  const n = 20000000;

  let t = performance.now();
  for (let i = 0; i < n; i++) {
    div100_1(i);
  }
  let e = performance.now() - t;
  console.log('div100_1: ' + e + ' ms'); // 214


  t = performance.now();
  for (let i = 0; i < n; i++) {
    div100_2(i);
  }
  e = performance.now() - t;
  console.log('div100_2: ' + e + ' ms'); // 115
}).catch(console.error);
