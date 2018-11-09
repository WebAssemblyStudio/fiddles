(async () => {
  const { createCow, makeSound } = (await WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
    main: {
      log(msg) {
        console.log(msg);
      }
    },
    env: {
      abort(msg, file, line, column) {
        console.error("abort called at main.ts:" + line + ":" + column);
      }
    },
  })).instance.exports;
  const cow = createCow();
  makeSound(cow);
})();

