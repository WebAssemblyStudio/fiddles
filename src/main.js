function leibnizPow(i) {
  return Math.pow(-1, i) / (2 * i + 1);
}

function leibniz(n) {
  var r = 0;
  for (var i = 0; i < n; i++) {
    r += leibnizPow(i);
  }
  return 4 * r;
}


WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  console.time('leibniz.js');
  const rjs = leibniz(parseInt(100000000));
  console.timeEnd('leibniz.js');
  console.log('leibniz.js: ' + rjs);

  console.time('leibniz.as');
  const ras = exports.leibniz(parseInt(100000000));
  console.timeEnd('leibniz.as');
  console.log('leibniz.js: ' + ras);
}).catch(console.error);
