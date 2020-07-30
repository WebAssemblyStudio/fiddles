const STRING_ID = 1;

let alloc = null, retain = null, retainedAlloc = null, release = null;
const memory = new WebAssembly.Memory({ initial: 128 * 1024 * 1024 >>> 16 });

function randomString(len) {
  return (
   (Math.random() * 1e19).toString(36) +  
   (Math.random() * 1e19).toString(36) +  
   (Math.random() * 1e19).toString(36) + 
   (Math.random() * 1e19).toString(36)
  ).substring(0, len);
}

const randStrings = [];

function generateRandStrings(iters) {
  for (let i = 0, sz = 1; i < iters; i++) {
    randStrings.push(randomString(sz));
    sz *= 2;
  }
}

function __allocString(str) {
  const length = str.length;
  const ptr = alloc(length << 1, STRING_ID);
  const U16 = new Uint16Array(memory.buffer);
  for (var i = 0, p = ptr >>> 1; i < length; ++i) U16[p + i] = str.charCodeAt(i);
  return ptr;
}

function allocStringNonRetained(str) {
  return retain(__allocString(str));
}

function allocStringRetained(str) {
  const length = str.length;
  const ptr = retainedAlloc(length << 1, STRING_ID);
  const U16 = new Uint16Array(memory.buffer);
  for (var i = 0, p = ptr >>> 1; i < length; ++i) U16[p + i] = str.charCodeAt(i);
  return ptr;
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    memory,
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {

  const iters = 100000;
  generateRandStrings(iters);

  const { __retainedAlloc, __alloc, __release, __retain } = result.instance.exports;

  alloc = __alloc;
  retain = __retain;
  retainedAlloc = __retainedAlloc;
  release = __release;

  console.time('allocString + retain');

  for (let i = 0; i < iters; i++) {
    allocStringNonRetained(randStrings[i]);
  }

  console.timeEnd('allocString + retain');

  console.time('allocStringRetained');

  for (let i = 0; i < iters; i++) {
    allocStringRetained(randStrings[i]);
  }

  console.timeEnd('allocStringRetained');

}).catch(console.error);
