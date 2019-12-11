WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { old_pow, new_pow } = result.instance.exports;
  
  let res = 0.0;
  console.time('old_pow');

  for (let y = 1e-53; y < 1e+53; y *= 2.0) {
    for (let x = 1e-53; x < 1e+53; x *= 8.0) {
      res += old_pow(x, y);
    }
  }

  console.timeEnd('old_pow');


}).catch(console.error);
