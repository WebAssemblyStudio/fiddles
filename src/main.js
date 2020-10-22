function jsSum(n) {
  let sum = 0
  let i = 0
  while (i < n) {
    sum += i
    i++
  }
  return sum
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { sum: wasmSum } = result.instance.exports;

  let N = 999999999, dt, t;

  // warmup
  jsSum(N);
  jsSum(N);

  t = performance.now();
  jsSum(N);
  dt = performance.now() - t;
  console.log('sum (javascript): ' + dt + ' ms');

  // warmup
  wasmSum(N);
  wasmSum(N);

  t = performance.now();
  wasmSum(N);
  dt = performance.now() - t;
  console.log('sum (wasm): ' + dt + ' ms');


}).catch(console.error);
