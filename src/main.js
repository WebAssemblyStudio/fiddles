const INK_FUNCTION_TABLE = new WebAssembly.Table({initial: 10, element: "anyfunc"})

const INK_STD = {
  log(s) {
    console.log(`${s}`);
  },
  sleep(timeout, cbid, ...state) {
    setTimeout(() => {
      const cb = INK_FUNCTION_TABLE.get(cbid);
      cb(...state);
    }, timeout)
  },
};

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), {
  std: INK_STD,
  js: {
    fnt: INK_FUNCTION_TABLE,
  },
});
