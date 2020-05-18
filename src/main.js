function toString(buffer, ptr) {
  const U32 = new Uint32Array(buffer);
  const U16 = new Uint16Array(buffer);
  let length = U32[ptr - 4 >>> 2] >>> 1;
  let offset = ptr >>> 1;
  return String.fromCharCode.apply(String, U16.subarray(offset, offset + length));
}

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
  const { memory, utoa64hex_lut, utoa64hex_simple } = result.instance.exports;

  const value = 0x000002111F3F3F30;

  console.log('utoa64hex_lut:    0x' + toString(memory.buffer, utoa64hex_lut(value)));
  console.log('utoa64hex_simple: 0x' + toString(memory.buffer, utoa64hex_simple(value)));
}).catch(console.error);
