function toString(buffer, ptr) {
  const U32 = new Uint32Array(buffer);
  const U16 = new Uint16Array(buffer);
  let length = U32[ptr - 4 >>> 2] >>> 1;
  let offset = ptr >>> 1;
  return String.fromCharCode.apply(String, U16.subarray(offset, offset + length));
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { memory, utoa64hex } = result.instance.exports;
  console.log(toString(memory.buffer, utoa64hex(0x000000003F3F3F3F)));
}).catch(console.error);
