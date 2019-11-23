const { greet, rgb2hex } = wasm_bindgen;

function rgb2hexJS(color) {
  let str = '#';
  color.forEach(c => {
    c = c.toString(16);

    if (c.length === 1) c = `0${c}`;
  })

  return str.toUpperCase();
}

function perf(arrayFunc, args) {
  arrayFunc.forEach(func => {
    const perf_time = [];

    for (let  i = 0; i < 10000; i++) {
      const t0 = performance.now();
      func.f(...args);
      const t1 = performance.now();
      perf_time.push(t1 - t0);
    }

    const mid_time = perf_time.reduce((acc, curr) => acc + curr, 0) / perf_time.length;
    console.log(`${func.name}: ${mid_time.toFixed(4)} milliseconds`);
    console.log(`Первичное время исполнения без оптимизации: ${perf_time[0]}\n\n`)
  });
}

function runApp() {
  perf([{name: 'webasm', f: rgb2hex}, {name: 'js', f: rgb2hexJS}], [[255, 255, 255]]);
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);