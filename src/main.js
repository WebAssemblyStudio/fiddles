
function test(exports, angle) {
  console.log(
    'angle: '    + angle,
    ' as sin: '  + exports.sin(angle), 
    ' js sin: '  + Math.sin(angle), 
    ' abs err: ' + Math.abs(exports.sin(angle) - Math.sin(angle))
  );
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  
  test(exports, 0);
  test(exports, Math.PI);
  test(exports, Math.PI / 2);
  test(exports, 3 * Math.PI / 4);
  test(exports, 4 * Math.PI / 3);
  test(exports, 123456);

}).catch(console.error);
