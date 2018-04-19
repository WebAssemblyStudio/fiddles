(async function() {
  const ffi = {
    js_log: function(i) {
      console.log('Call By JS: ' + i);
    }
  }

  const res = await fetch( '../out/main.wasm');
  const results = await WebAssembly.instantiateStreaming(res, {
    env: ffi,
  });

  const ins = results.instance;
  ins.exports.logic();
})();
