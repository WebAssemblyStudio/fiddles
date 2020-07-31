WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { test1, test2 }  = result.instance.exports;
  console.log(test1(0), test2(0));
  console.log(test1(1), test2(1));
  console.log(test1(127), test2(127));
  console.log(test1(128), test2(128));
  console.log(test1(255), test2(255));
}).catch(console.error);
