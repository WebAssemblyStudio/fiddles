WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { old_pow, new_pow } = result.instance.exports;
  
  // old as pow
  let res = 0.0;
  for (let y = 1e-300; y <= 1e+308; y *= 2.0) {
    for (let x = 1e-300; x <= 1e+308; x *= 2.0) {
      res += old_pow(x, y);
    }
  }
  res = 0.0;
  console.time('old as pow');
  for (let y = 1e-300; y <= 1e+308; y *= 2.0) {
    for (let x = 1e-300; x <= 1e+308; x *= 2.0) {
      res += old_pow(x, y);
    }
  }
  console.timeEnd('old as pow');


  // new as pow
  res = 0.0;
  for (let y = 1e-300; y <= 1e+308; y *= 2.0) {
    for (let x = 1e-300; x <= 1e+308; x *= 2.0) {
      res += new_pow(x, y);
    }
  }
  res = 0.0;
  console.time('NEW as pow');
  for (let y = 1e-300; y <= 1e+308; y *= 2.0) {
    for (let x = 1e-300; x <= 1e+308; x *= 2.0) {
      res += new_pow(x, y);
    }
  }
  console.timeEnd('NEW as pow');

  // JS pow
  res = 0.0;
  for (let y = 1e-300; y <= 1e+308; y *= 2.0) {
    for (let x = 1e-300; x <= 1e+308; x *= 2.0) {
      res += Math.pow(x, y);
    }
  }
  res = 0.0;
  console.time('js pow');
  for (let y = 1e-300; y <= 1e+308; y *= 2.0) {
    for (let x = 1e-300; x <= 1e+308; x *= 2.0) {
      res += Math.pow(x, y);
    }
  }
  console.timeEnd('js pow');


}).catch(console.error);
