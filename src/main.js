var importObject = {
  console: {
    log: function(arg) {
      console.log(arg);
    }
  }
};

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObject)
.then(obj => {
  console.debug(obj.instance.exports);
  obj.instance.exports.logIt();
});