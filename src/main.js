const NUM = 1e6;
const ITER = 500;

const memory = new WebAssembly.Memory({ initial: Math.ceil(NUM * 2 * 8 / 0x10000) });

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    memory,
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {

  const exports = result.instance.exports;
  console.log(`exports: ${Object.keys(exports)}`);

  // define mappings of input & output memory regions
  const src = new Float64Array(memory.buffer, 0, NUM);
  const dest = new Float64Array(memory.buffer, NUM * 8, NUM);

  console.log(`total mem size: ${memory.buffer.byteLength/1024/1024}MB`);

  // fill input w/ normalized values
  for (let i = 0; i < NUM; i++) {
    src[i] = Math.random() * 2 - 1;
  }

  const bench = (name) => {
    console.time(name);
    const fn = exports[name];
    for(let i = 0; i < ITER; i++) {
      fn(dest.byteOffset, src.byteOffset, NUM);
    }
    console.timeEnd(name);
  };

  bench("sigmoidApproxPtr");
  // 811.406005859375ms (100 iters)
  // 4046.489013671875ms (500 iters)

  bench("sigmoidNatPtr");
  // 1504.90380859375ms (100 iters)
  // 7569.575927734375ms (500 iters)

}).catch(console.error);
