WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { idiv, idiv2 } = result.instance.exports;

  let x = BigInt(Number.MAX_SAFE_INTEGER);
  for (let i = 1n; i < 10000000n; i++) {
    if (idiv(x, i) != idiv2(x, i)) {
      console.log('result mismatch', idiv(x, i), 'expected:', idiv2(x, i));
      break;
    }
  }
  console.log('done');
}).catch(console.error);
