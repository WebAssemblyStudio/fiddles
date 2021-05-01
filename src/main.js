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
  // batchPush(N); // FF88 = 61557 ms, Chrome90 = 69552 ms
  batchPushNew(N); // FF88 = 9 ms, Chrome90 = 9 ms
  t = performance.now() - t;

  container.textContent += `Array#push(${N}): ${t} ms\n`;

  let jsArr = new Array();
  for (let i = 0; i < N; i++) {
    jsArr.push(i);
  }
  jsArr = new Array();

  t = performance.now();
  for (let i = 0; i < N; i++) {
    jsArr.push(i);
  }
  t = performance.now() - t;

  container.textContent += `Array#push(${N}) (JS): ${t} ms\n`;

}).catch(console.error);
