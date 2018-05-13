WebAssembly.instantiateStreaming(fetch('../out/main.was'), {
  env: {
    sayHello: function() {
      console.log('Hello from WebAssembly!');
    },
    abort: function(msg, file, line, column) {
      console.error('abort called at main.ts:' + line + ':' + column);
    }
  }
}).then(result => {
  const exports = result.instance.exports;
  // document.getElementById("container").innerText = 'Result: ' + exports.add(19, 23);
  //const out = exports.test();
  //console.log('Out: ' + out);
  //document.getElementById('container').innerText = 'Result2: ' + toString(out,3);
});
