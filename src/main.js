WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { decimalCount32_old, decimalCount32_new } = result.instance.exports;
  
  for (let i = 0; i < 1e10; i += 100) decimalCount32_old(i);
  console.time('decimalCount32_old');
  for (let i = 0; i < 1e10; i += 100) decimalCount32_old(i);
  console.timeEnd('decimalCount32_old');

  for (let i = 0; i < 1e10; i += 100) decimalCount32_new(i);
  console.time('decimalCount32_new');
  for (let i = 0; i < 1e10; i += 100) decimalCount32_new(i);
  console.timeEnd('decimalCount32_new');

}).catch(console.error);
