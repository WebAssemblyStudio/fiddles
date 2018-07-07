const { add } = wasm_bindgen;

// For more comments about what's going on here, check out the `hello_world`
// example at https://webassembly.studio/?f=gzubao6tg3
wasm_bindgen('../out/main_bg.wasm').then(() => {
  alert('1 + 2 = ' + add(1, 2))
});