(async function() {
  const response = await fetch("../out/main.wasm");
  const bytes = await response.arrayBuffer();
  const importObject = {
    env: {
      alert: function(str, len) {
        let bytes = new Uint8Array(memory.buffer, str, len);
        let string = new TextDecoder('utf8').decode(bytes);
        alert(string);
      }
    }
  };
  const instance = (await WebAssembly.instantiate(bytes, importObject)).instance;
  var memory = instance.exports.memory;
  instance.exports.main();
})();
