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
  const { exp, fastexp } = result.instance.exports;

  let acc = 0.;
  // warmup exp
  for (let i = -5000000; i < 5000000; i++) {
    acc += exp(i * (1 / 5000000));
  }
  acc = 0.;
  console.time('native wasm exp');
  for (let i = -5000000; i < 5000000; i++) {
    acc += exp(i * (1 / 5000000));
  }
  console.timeEnd('native wasm exp');

  // warmup fastexp
  acc = 0.;
  for (let i = -5000000; i < 5000000; i++) {
    acc += fastexp(i * (1 / 5000000));
  }
  acc = 0.;
  console.time('fastexp');
  for (let i = -5000000; i < 5000000; i++) {
    acc += fastexp(i * (1 / 5000000));
  }
  console.timeEnd('fastexp');

}).catch(console.error);
