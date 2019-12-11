WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { old_powf, new_powf } = result.instance.exports;
  
  // old as pow
  let res = 0.0;
  for (let z = 0; z < 50; z++) {
    for (let y = 1e-40; y <= 1e+40; y *= 2.0) {
      for (let x = 1e-40; x <= 1e+40; x *= 2.0) {
        res += old_powf(x, y);
      }
    }
  }
  res = 0.0;
  console.time('old as pow');
  for (let z = 0; z < 50; z++) {
    for (let y = 1e-40; y <= 1e+40; y *= 2.0) {
      for (let x = 1e-40; x <= 1e+40; x *= 2.0) {
        res += old_powf(x, y);
      }
    }
  }
  console.timeEnd('old as pow');


  // new as pow
  res = 0.0;
  for (let z = 0; z < 50; z++) {
    for (let y = 1e-40; y <= 1e+40; y *= 2.0) {
      for (let x = 1e-40; x <= 1e+40; x *= 2.0) {
        res += new_powf(x, y);
      }
    }
  }
  res = 0.0;
  console.time('NEW as pow');
  for (let z = 0; z < 50; z++) {
    for (let y = 1e-40; y <= 1e+40; y *= 2.0) {
      for (let x = 1e-40; x <= 1e+40; x *= 2.0) {
        res += new_powf(x, y);
      }
    }
  }
  console.timeEnd('NEW as pow');

  // JS pow
  res = 0.0;
  for (let z = 0; z < 50; z++) {
    for (let y = 1e-40; y <= 1e+40; y *= 2.0) {
      for (let x = 1e-40; x <= 1e+40; x *= 2.0) {
        res += Math.fround(Math.pow(x, y));
      }
    }
  }
  res = 0.0;
  console.time('js pow');
  for (let z = 0; z < 50; z++) {
    for (let y = 1e-40; y <= 1e+40; y *= 2.0) {
      for (let x = 1e-40; x <= 1e+40; x *= 2.0) {
        res += Math.fround(Math.pow(x, y));
      }
    }
  }
  console.timeEnd('js pow');


}).catch(console.error);
