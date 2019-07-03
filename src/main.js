// var memory = null;

// function getString(ptr) {
//   if (!memory) return "memory not yet init";
//   const RUNTIME_HEADER_SIZE = 16;
//   if (!ptr) return "null";
//   var U32 = new Uint32Array(memory.buffer);
//   var U16 = new Uint16Array(memory.buffer);
//   var len16 = U32[(ptr - RUNTIME_HEADER_SIZE + 12) >>> 2] >>> 1;
//   var ptr16 = ptr >>> 1;
//   return String.fromCharCode.apply(String, U16.subarray(ptr16, ptr16 + len16));
// }

const baseModule = {};

const SIZE_OFFSET = -4;
const CHUNKSIZE = 1024;

function getStringImpl(U32, U16, ref) {
  var length = U32[(ref + SIZE_OFFSET) >>> 2] >>> 1;
  var offset = ref >>> 1;
  if (length <= CHUNKSIZE) return String.fromCharCode.apply(String, U16.subarray(offset, offset + length));
  const parts = [];
  do {
    const last = U16[offset + CHUNKSIZE - 1];
    const size = last >= 0xD800 && last < 0xDC00 ? CHUNKSIZE - 1 : CHUNKSIZE;
    parts.push(String.fromCharCode.apply(String, U16.subarray(offset, offset += size)));
    length -= size;
  } while (length > CHUNKSIZE);
  return parts.join("") + String.fromCharCode.apply(String, U16.subarray(offset, offset + length));
}

function getString(memory, ref) {
  if (!memory) return "<yet unknown>";
  const buffer = memory.buffer;
  return getStringImpl(new Uint32Array(buffer), new Uint16Array(buffer), ref);
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    },
    trace(msg, n) {
      // console.log("  trace: " + getString(msg) + (n ? " " : "") + Array.prototype.slice.call(arguments, 2, 2 + n).join(", "));
      const memory = baseModule.memory /*|| env.memory;*/
      console.log("trace: " + getString(memory, msg) + (n ? " " : "") + Array.prototype.slice.call(arguments, 2, 2 + n).join(", "));
    },
  },
}).then(result => {
  const exports = result.instance.exports;
  baseModule.memory = exports.memory;
  exports.test();
}).catch(console.error);
