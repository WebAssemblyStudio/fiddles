const F64 = new Float64Array(1);
const U64 = new Uint32Array(F64.buffer);

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    },
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
  console: {
    logByte(index, value) { 
      console.log(`array[${ index }] = 0x${ value.toString(16).padStart(2, '0') }`);
    },
    logLowHi(lo, hi) {
      F64[0] = lo;
      var low = '0x' + (U64[1].toString(16) + U64[0].toString(16)).padStart(16, '0');

      F64[0] = hi;
      var high = '0x' + (U64[1].toString(16) + U64[0].toString(16)).padStart(16, '0');

      console.log(low, high);
    }
  }
}).then(result => {
  const exports = result.instance.exports;
}).catch(console.error);
