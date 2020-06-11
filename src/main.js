WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {

  const dt = 0.01;
  const steps = 20_000_000;

  const exports = result.instance.exports;

  console.log(`Steps: ${steps}, increment: ${dt}`);

  exports.init();

  const startTime = performance.now();
  exports.bench(steps, dt);
  const deltaTime = performance.now() - startTime;

  console.log('dt: ' + deltaTime + ' ms');
}).catch(console.error);
