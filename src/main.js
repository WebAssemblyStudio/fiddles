WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  // warmup inner loop
  for (let i = 0; i < 10000; i++) exports.benchInnerLoop(256, 256, 0, 0);

  console.time('inner loop + int indexes');
    exports.benchInnerLoop(1024, 1024, 0, 0);
  console.timeEnd('inner loop + int indexes');

  // warmup one loop
  for (let i = 0; i < 10000; i++) exports.benchOneLoop(256, 256, 0, 0);

  console.time('one loop + float indexes');
    exports.benchOneLoop(1024, 1024, 0, 0);
  console.timeEnd('one loop + float indexes');

}).catch(console.error);
