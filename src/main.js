const memory = new WebAssembly.Memory({ initial: 20 });

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    memory,
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  const mem = memory.buffer;
  const size = 1 << 16;

  const src = new Uint8Array(mem, 0);
  const dst = new Uint8Array(mem, size);

  src.set(Array.from({ length: size }, (v, i) => i));
  dst.set(Array.from({ length: size }, (v, i) => i));

  console.time('memcmp');
  for (let i = 0; i < 1000; i++)
    exports.memcmp(0, size, size);
  console.timeEnd('memcmp');

  console.time('memcmp2');
  for (let i = 0; i < 1000; i++)
    exports.memcmp2(0, size, size);
  console.timeEnd('memcmp2');
  
  console.log(
    exports.memcmp(0, size, size),
    exports.memcmp2(0, size, size)
  );

}).catch(console.error);
