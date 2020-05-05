const F64 = new Float64Array(1);
const U64 = new BigUint64Array(F64.buffer);

function unpack(ptr) {
  F64[0] = ptr;
  return U64[0];
}

function pack(bigintPtr) {
  U64[0] = bigintPtr;
  return F64[0];
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  const output = unpack(exports.test(pack(BigInt('0x8000000012345678'))));

  document.getElementById("container").textContent = "Result: " + '0x' + output.toString(16);
}).catch(console.error);
