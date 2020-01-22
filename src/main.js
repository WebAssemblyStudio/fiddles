let memory = new WebAssembly.Memory({ initial: 1 });

function getString(buf, ptr) {
  const U32 = new Uint32Array(buf);
  const U16 = new Uint16Array(buf);
  const len = U32[(ptr - 4) >>> 2] >>> 1;
  const off = ptr >>> 1;
  return String.fromCharCode.apply(String, U16.subarray(off, off + len));
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    print(strPtr) {
      console.log(getString(memory.buffer, strPtr));
    }
  },
  env: {
    memory,
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  memory = exports.memory;
}).catch(console.error);
