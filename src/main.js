function comparedJS(
  r1,
  g1,
  b1,

  r2,
  g2,
  b2,
) {
  let _r = r1-r2;
  let _g = g1-g2;
  let _b = b1-b2;

  if(Math.sqrt(Math.pow(_r,2)+Math.pow(_g,2)+Math.pow(_g,2))<150) {
    return 1;
  }
  return 0;
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { compared, compared2 } = result.instance.exports;
  
  let acc = 0;
  for (let r = 0; r < 255; r++) {
    for (let g = 0; g < 255; g++) {
      for (let b = 0; b < 255; b++) {
        acc += compared(r, g, b, 0, 255, b)
      }
    }
  }

  acc = 0;
  console.time('orig AS');
  for (let r = 0; r < 255; r++) {
    for (let g = 0; g < 255; g++) {
      for (let b = 0; b < 255; b++) {
        acc += compared(r, g, b, 0, 255, b)
      }
    }
  }
  console.timeEnd('orig AS');

  acc = 0;
  for (let r = 0; r < 255; r++) {
    for (let g = 0; g < 255; g++) {
      for (let b = 0; b < 255; b++) {
        acc += compared2(r, g, b, 0, 255, b)
      }
    }
  }

  acc = 0;
  console.time('opt AS');
  for (let r = 0; r < 255; r++) {
    for (let g = 0; g < 255; g++) {
      for (let b = 0; b < 255; b++) {
        acc += compared2(r, g, b, 0, 255, b)
      }
    }
  }
  console.timeEnd('opt AS');

  acc = 0;
  for (let r = 0; r < 255; r++) {
    for (let g = 0; g < 255; g++) {
      for (let b = 0; b < 255; b++) {
        acc += comparedJS(r, g, b, 0, 255, b)
      }
    }
  }

  acc = 0;
  console.time('JS');
  for (let r = 0; r < 255; r++) {
    for (let g = 0; g < 255; g++) {
      for (let b = 0; b < 255; b++) {
        acc += comparedJS(r, g, b, 0, 255, b)
      }
    }
  }
  console.timeEnd('JS');

}).catch(console.error);
