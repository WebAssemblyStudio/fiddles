WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    console_log(val) {
      console.log(String.fromCodePoint(val));
    },
    console_i32(x) {
      console.log(x);
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  for (let i = 0; i < 0x007FFFFF; i++) {
    exports.toUpper(i);
  }

  console.time('t');
  for (let i = 0; i < 0x007FFFFF; i++) {
    exports.toUpper(i);
  }
  console.timeEnd('t');
}).catch(console.error);
