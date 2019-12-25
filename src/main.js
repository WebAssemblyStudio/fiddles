var iif = {strings: {}, lastStringId: 1}
var importObject = {
  env: {
    imported_func: arg => console.log(arg),
    new_js_string: function(utf8, len) {
      console.log(utf8, len);
      const view = new Uint8Array(iif.main.memory.buffer, utf8, len);
      const utf8dec = new TextDecoder("utf-8");
      const decoded = utf8dec.decode(view);
      let stringId = iif.lastStringId + 10;
      while (typeof iif.strings[stringId] !== "undefined") stringId += 1;
      if (stringId > 2147483647) {
        // Can't easily pass more than that through WASM.
        stringId = -2147483648;
        while (typeof iif.strings[stringId] !== "undefined") stringId += 1;
        if (stringId > 2147483647) throw new Error("Out of string IDs!");
      }
      iif.strings[stringId] = decoded;
      console.log('stringId', stringId);
      return (iif.lastStringId = stringId);
    },
    console_log: function(js) {
      console.log(js);
      if (window.console) console.log("main]", iif.strings[js]);
      delete iif.strings[js];
    }
  }
};

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObject).then((results) => {
  instance = results.instance;
  console.log(instance);
  iif.main = instance.exports;
  document.getElementById("container").textContent = instance.exports.test();
}).catch(console.error);
// .then(response =>
//   response.arrayBuffer()
// ).then(bytes => WebAssembly.instantiateStreaming(bytes, importObject)).then(results => {
//   instance = results.instance;
//   document.getElementById("container").textContent = instance.exports.test();
// }).catch(console.error);
