WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { powf_new, powf_old } = result.instance.exports;

  // console.log(powf_old(1.5, 104.1234), powf_new(1.5, 104.1234));
  // console.log(powf_old(1.5333333333, 10.1234), powf_new(1.5333333333, 10.1234));

  let res = 0.0;
  for (let z = 0; z < 20; z++) {
    for (let y = 1e-40; y <= 1e+40; y *= 2.0) {
      for (let x = 1e-40; x <= 1e+40; x *= 2.0) {
        res += powf_old(x, y);
      }
    }
  }
  res = 0.0;
  console.time('old as pow');
  for (let z = 0; z < 20; z++) {
    for (let y = 1e-40; y <= 1e+40; y *= 2.0) {
      for (let x = 1e-40; x <= 1e+40; x *= 2.0) {
        res += powf_old(x, y);
      }
    }
  }
  console.timeEnd('old as pow');
  console.log(res);


  res = 0.0;
  for (let z = 0; z < 20; z++) {
    for (let y = 1e-40; y <= 1e+40; y *= 2.0) {
      for (let x = 1e-40; x <= 1e+40; x *= 2.0) {
        res += powf_new(x, y);
      }
    }
  }
  res = 0.0;
  console.time('new as pow');
  for (let z = 0; z < 20; z++) {
    for (let y = 1e-40; y <= 1e+40; y *= 2.0) {
      for (let x = 1e-40; x <= 1e+40; x *= 2.0) {
        res += powf_new(x, y);
      }
    }
  }
  console.timeEnd('new as pow');
  console.log(res);

}).catch(console.error);
