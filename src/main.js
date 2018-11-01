const F64 = new Float64Array(1);
const U64 = new Uint32Array(F64.buffer);

function getU64(lo, hi) {
  return { lo: lo >>> 0, hi: hi >>> 0 };
}

function getU64_v2(val) {
  F64[0] = val;
  return { lo: U64[0], hi: U64[1] };
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  let res;

  console.time('t1');
  for (let i = 0; i < 10000000; i++) {
    let lo = exports.getU64();
    let hi = exports.getHiPart();
    res = getU64(lo, hi);
  }
  console.timeEnd('t1');

  console.time('t2');
  for (let i = 0; i < 10000000; i++) {
    let val = exports.getU64_v2();
    res = getU64_v2(val);
  }
  console.timeEnd('t2');
  
}).catch(console.error);
