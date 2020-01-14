// this just copy from loader.js //

const STRING_ID = 1;
const ID_OFFSET = -8;
const SIZE_OFFSET = -4;
const CHUNKSIZE = 1024;

function __allocString(str) {
  const length = str.length;
  const ptr = __alloc(length << 1, STRING_ID);
  const U16 = new Uint16Array(memory.buffer);
  for (var i = 0, p = ptr >>> 1; i < length; ++i) U16[p + i] = str.charCodeAt(i);
  return ptr;
}

function __getString(ptr) {
  const buffer = memory.buffer;
  const id = new Uint32Array(buffer)[ptr + ID_OFFSET >>> 2];
  if (id !== STRING_ID) throw Error("not a string: " + ptr);
  return getStringImpl(buffer, ptr);
}

function getStringImpl(buffer, ptr) {
  const U32 = new Uint32Array(buffer);
  const U16 = new Uint16Array(buffer);
  var length = U32[(ptr + SIZE_OFFSET) >>> 2] >>> 1;
  var offset = ptr >>> 1;
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

///////////////////////////////////

let __alloc = null;
let __retain = null;
let memory = null;

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    getSth() {
      return __retain(__allocString('world')); // __alloc / __allocString require requre __retain
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  __retain = exports.__retain;
  __alloc = exports.__alloc;
  memory = exports.memory;

  const resPtr = exports.test2();
  const resStr = __getString(resPtr);

  document.getElementById("container").textContent = "Result: " + resStr;
  // free / __release
  exports.__release(resPtr);
}).catch(console.error);