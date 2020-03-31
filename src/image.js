const { calculate } = wasm_bindgen;

function handleImage() {
  const begin = performance.now()
  const arr = Array(500_000).fill(0);
  arr.forEach((elem, index) => {
    if (index % 42 == 0) {
      elem = 42
    } else {
      elem = 12
    }
    
  })


  const end = performance.now();

  const wasm_begin = performance.now()
  const len = calculate(arr);
  const wasm_end = performance.now()


  console.log({ js_result: end - begin, wasm_result: wasm_end-wasm_begin, len:arr.length })

}

wasm_bindgen('../out/main_bg.wasm').then(handleImage).catch(console.error);