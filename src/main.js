function toString(buffer, ptr) {
  const U32 = new Uint32Array(buffer);
  const U16 = new Uint16Array(buffer);
  let length = U32[ptr - 4 >>> 2] >>> 1;
  let offset = ptr >>> 1;
  return String.fromCharCode.apply(String, U16.subarray(offset, offset + length));
}

const COUNT = 1000000;

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    log(s) { console.log('i32: ' + s); }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { memory, utoa64hex_lut, utoa64hex_simple, bench_lut, bench_simple } = result.instance.exports;

  const value = 0x000002110F3F3031;

  console.log('utoa64hex_lut:    0x' + toString(memory.buffer, utoa64hex_lut(value)));
  console.log('utoa64hex_simple: 0x' + toString(memory.buffer, utoa64hex_simple(value)));

  // bench_lut();
  // bench_lut();

  // console.time('bench_lut');
  // bench_lut();
  // console.timeEnd('bench_lut');

  // bench_simple();
  // bench_simple();

  // console.time('bench_simple');
  // bench_simple();
  // console.timeEnd('bench_simple');

  // console.log('bench done!');
  

}).catch(console.error);
