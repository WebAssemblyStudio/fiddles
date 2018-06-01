function consoleLogString(offset, length) {
  var bytes = new Uint8Array(memory.buffer, offset, length);
  var str = new TextDecoder('utf8').decode(bytes);
  console.log(str);
}
var memory = new WebAssembly.Memory({initial: 1});

var importObj = { console: { log: consoleLogString }, js: { mem: memory } };

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObj)
.then(obj => {
  obj.instance.exports.writeHi();
});
