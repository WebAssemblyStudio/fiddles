const STRING_ID = 1;
const ARRAYBUFFERVIEW_DATASTART_OFFSET = 4;
const SIZE_OFFSET = -4;

let memory = null;
let alloc = null;
 
function __allocString(str) {
  const length = str.length;
  const ptr = alloc(length << 1, STRING_ID);
  const U16 = new Uint16Array(memory.buffer);
  for (var i = 0, p = ptr >>> 1; i < length; ++i) {
    U16[p + i] = str.charCodeAt(i);
  }
  return ptr;
}

function getTypedArrayView(Type, alignLog2, ptr) {
  const buffer = memory.buffer;
  const U32 = new Uint32Array(buffer);
  const bufPtr = U32[ptr + ARRAYBUFFERVIEW_DATASTART_OFFSET >>> 2];
  return new Type(buffer, bufPtr, U32[bufPtr + SIZE_OFFSET >>> 2] >>> alignLog2);
}

function getFloat64Array(ptr) {
  return new Float64Array(getTypedArrayView(Float64Array, 3, ptr));
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  memory = exports.memory;
  alloc = exports.__alloc;

  const __retain = exports.__retain;
  const __release = exports.__release;

  const str = "ATGC";
  const inStrPtr = __retain(__allocString(str));

  const outArrPtr = exports.squiggle(inStrPtr, str.length);
  const resultArr = getFloat64Array(outArrPtr);
  console.log('result:', resultArr);

  // free resources
  __release(outArrPtr);
  __release(inStrPtr);
}).catch(console.error);