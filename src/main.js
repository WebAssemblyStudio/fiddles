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
  const { rem256s, rem256s_opt } = result.instance.exports;
  // console.log(0, rem256s(0), rem256s_opt(0));
  // console.log(1, rem256s(1), rem256s_opt(1));
  // console.log(3, rem256s(3), rem256s_opt(3));
  // console.log(255, rem256s(255), rem256s_opt(255));
  // console.log(256, rem256s(256), rem256s_opt(256));
  // console.log(0x7FFFFFFF, rem256s(0x7FFFFFFF), rem256s_opt(0x7FFFFFFF));
  // console.log(0xFFFFFFFF, rem256s(0xFFFFFFFF), rem256s_opt(0xFFFFFFFF));
  // console.log(-2, rem256s(-2), rem256s_opt(-2));
  // console.log(-256, rem256s(-256), rem256s_opt(-256));

  let t = performance.now();
  for (let i = 0; i < 0x7FFFFFF; i++) {
    rem256s(i);
  }
  t = performance.now() - t;
  console.log('rem256s:', t + ' ms');

  t = performance.now();
  for (let i = 0; i < 0x7FFFFFF; i++) {
    rem256s_opt(i);
  }
  t = performance.now() - t;
  console.log('rem256s_opt:', t + ' ms');
}).catch(console.error);
