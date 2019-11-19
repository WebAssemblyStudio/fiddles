WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { toLowerCase, toUpperCase } = result.instance.exports;

  // AS bench
  let res = 0;
  for (let i = 0; i <= 0x10FFFF; i++) {
    res += !!toLowerCase(i);
  }
  res = 0;
  console.time('AS toLowerCase');
  for (let i = 0; i <= 0x10FFFF; i++) {
    res += !!toLowerCase(i);
  }
  console.timeEnd('AS toLowerCase');
  res = 0;
  for (let i = 0; i <= 0x10FFFF; i++) {
    res += !!toUpperCase(i);
  }
  res = 0;
  console.time('AS toUpperCase');
  for (let i = 0; i <= 0x10FFFF; i++) {
    res += !!toUpperCase(i);
  }
  console.timeEnd('AS toUpperCase');

  // JS bench
  res = 0;
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
