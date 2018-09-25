var memory = new WebAssembly.Memory({ initial: 1 });
var decoder = new TextDecoder('utf8');

var modules = {
  js: {
    mem: memory
  },

  utils: {
    int_log: function(val) {
      console.log(val);
    },

    str_log: function(offset, len) {
      var bytes = new Uint8Array(memory.buffer, offset, len);
      var str = decoder.decode(bytes);
      console.log(str);
    }
  }
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => {
  return WebAssembly.instantiate(bytes, modules);
}).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = instance.exports.sayHello5();

}).catch(console.error);

