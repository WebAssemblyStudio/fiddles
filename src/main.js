WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { toLowerCaseTest, toUpperCaseTest } = result.instance.exports;

  // AS bench
  toLowerCaseTest();
  console.time('AS toLowerCase');
  toLowerCaseTest();
  console.timeEnd('AS toLowerCase');

  toUpperCaseTest();
  console.time('AS toUpperCase');
  toUpperCaseTest();
  console.timeEnd('AS toUpperCase');

  // JS bench
  let res = 0;
  for (let i = 0; i <= 0x10FFFF; i++) {
     res += !!String.fromCodePoint(i).toLowerCase();
  }
  res = 0;
  console.time('JS toLowerCase');
  for (let i = 0; i <= 0x10FFFF; i++) {
     res += !!String.fromCodePoint(i).toLowerCase();
  }
  console.timeEnd('JS toLowerCase');
  res = 0;
  for (let i = 0; i <= 0x10FFFF; i++) {
     res += !!String.fromCodePoint(i).toUpperCase();
  }
  res = 0;
  console.time('JS toUpperCase');
  for (let i = 0; i <= 0x10FFFF; i++) {
     res += !!String.fromCodePoint(i).toUpperCase();
  }
  console.timeEnd('JS toUpperCase');
}).catch(console.error);
