WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const container = document.getElementById("container");
  container.textContent = '';

  const { batchPush, batchPushNew } = result.instance.exports;
  const N = 1000000;

  let t = performance.now();
  // batchPush(N); // FF88 = 61557 ms
  batchPushNew(N); // FF88 = 9 ms
  t = performance.now() - t;

  container.textContent += `Array#push(${N}): ${t} ms\n`;

}).catch(console.error);
