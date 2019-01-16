WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  let res = exports.conv(1e11);
  console.log('old: ' + (res >>> 0));

  res = exports.conv2(1e11);
  console.log('new: ' + (res >>> 0));

  res = exports.conv3(1e11);
  console.log('new v2: ' + (res >>> 0));

  console.time('old');
  exports.bench();
  console.timeEnd('old');

  console.time('new');
  exports.bench2();
  console.timeEnd('new');

  console.time('new v2');
  exports.bench3();
  console.timeEnd('new v2');

}).catch(console.error);
