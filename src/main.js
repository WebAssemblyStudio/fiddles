WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { NOP, NOP2 } = result.instance.exports;
  
  console.log(NOP(0), NOP2(0));
  console.log(NOP(1), NOP2(1));
  console.log(NOP(0x1C), NOP2(0x1C));
  console.log(NOP(0x1C + 1), NOP2(0x1C + 1));
  console.log(NOP(0x1C - 1), NOP2(0x1C - 1));
  console.log(NOP(0xFC), NOP2(0xFC));
  console.log(NOP(0xFC + 1), NOP2(0xFC + 1));

  console.time('NOP');
  for (let i = 0; i < 10000000; i++) {
    NOP(i & 255);
  }
  console.timeEnd('NOP');

   console.time('NOP2');
  for (let i = 0; i < 10000000; i++) {
    NOP2(i & 255);
  }
  console.timeEnd('NOP2');


}).catch(console.error);
