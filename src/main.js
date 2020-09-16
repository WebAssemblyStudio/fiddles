WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { sqrt, isqrt, isqrt_f, isqrt2, isqrt3, isqrt4 } = result.instance.exports;

  // for (let v of [0n, 1n, 2n, 3n, 4n, 5n, 2n ** 50n + 12345n, 2n ** 62n + 12345n]) {
  //   console.log('value: ' + v);
  //   console.log('sqrt: ' + sqrt(Number(v)));
  //   console.log(`isqrt: ` + isqrt(v));
  //   console.log(`isqr2: ` + isqrt2(v));
  //   console.log(`isqrt3: ` + isqrt3(v));
  //   console.log(`isqrt_f: ` + isqrt_f(v));
  // }

  let r = 0n;
  let t = performance.now();

  for (let i = 0; i < 0xFFFFF; i++) {
    // r += isqrt(BigInt(i)); // 2426 ms
    // r += isqrt_f(BigInt(i));
    // r += isqrt2(BigInt(i));
    // r += isqrt3(BigInt(i));
    r += isqrt4(BigInt(i));
  }

  t = performance.now() - t;
  console.log('time: ' + t + ' ms');
}).catch(console.error);
