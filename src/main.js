
// string loader copied from https://github.com/AssemblyScript/assemblyscript/blob/master/lib/loader/index.js
const ID_OFFSET = -8;
const SIZE_OFFSET = -4;
const STRING_ID = 1;
//const U32 = Uint32Array;

var memory;

// Provide views for all sorts of basic values
var buffer, I8, U8, I16, U16, I32, U32, F32, F64, I64, U64;
const BIGINT = typeof BigUint64Array !== "undefined";
const CHUNKSIZE = 1024;

/** Updates memory views if memory has grown meanwhile. */
function checkMem() {
  // see: https://github.com/WebAssembly/design/issues/1210
  if (buffer !== memory.buffer) {
    buffer = memory.buffer;
    I8  = new Int8Array(buffer);
    U8  = new Uint8Array(buffer);
    I16 = new Int16Array(buffer);
    U16 = new Uint16Array(buffer);
    I32 = new Int32Array(buffer);
    U32 = new Uint32Array(buffer);
    if (BIGINT) {
      I64 = new BigInt64Array(buffer);
      U64 = new BigUint64Array(buffer);
    }
    F32 = new Float32Array(buffer);
    F64 = new Float64Array(buffer);
  }
}

/** Gets a string from an U32 and an U16 view on a memory. */
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

/** Reads a string from the module's memory by its pointer. */
function __getString(ref) {
  checkMem();
  const id = U32[ref + ID_OFFSET >>> 2];
  if (id !== STRING_ID) throw Error("not a string: " + ref);
  return getStringImpl(U32, U16, ref);
}


WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  memory = result.instance.exports.memory;
  document.getElementById("container").textContent = "Result: " + __getString(exports.greet(3));
}).catch(console.error);
