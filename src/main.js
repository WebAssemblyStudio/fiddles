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
  
  let acc = 0;
  console.time('t1');
  for (let i = 0; i < 1e8; i += 0.5) {
    acc += exports.dtoi32_1(i);
  }
  console.timeEnd('t1');

  acc = 0;
  console.time('t2');
  for (let i = 0; i < 1e8; i += 0.5) {
    acc += exports.dtoi32_2(i);
  }
  console.timeEnd('t2');
}).catch(console.error);
