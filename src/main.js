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
  const { charsFromByte, charsFromByte2 } = result.instance.exports;
  
  let total = 0;

  for (let i = 0; i < 100000000; i++)
    charsFromByte(i & 0xFF);

  console.time('t1');
  for (let i = 0; i < 10000000; i++) {
   total += charsFromByte(i & 0xFF);
  }
  console.timeEnd('t1');
  console.log(total);

  total = 0;
  for (let i = 0; i < 100000000; i++)
    charsFromByte2(i & 0xFF);

  console.time('t2');
  for (let i = 0; i < 10000000; i++) {
   total += charsFromByte2(i & 0xFF);
  }
  console.timeEnd('t2');
  console.log(total);

}).catch(console.error);
