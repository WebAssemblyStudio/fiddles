WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { benchSlow, benchFast } = result.instance.exports;
  
  // warmup
  for (let i = 0; i < 100; i++) benchSlow();
  console.time('quickselectSlow');
  for (let i = 0; i < 100; i++) benchSlow();
  console.timeEnd('quickselectSlow');

  // warmup
  for (let i = 0; i < 100; i++) benchFast();
  console.time('quickselectFast');
  for (let i = 0; i < 100; i++) benchFast();
  console.timeEnd('quickselectFast');

}).catch(console.error);
