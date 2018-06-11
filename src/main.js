let con = {
  env: {
    trace: function trace(byteOffset) {
      var s = '';
      var a = new Uint8Array(memory.buffer);
      for (var i = byteOffset; a[i]; i++) {
        s += String.fromCharCode(a[i]);
      }
  console.log(s);
    },
  }
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, con)).then(results => {
  exports = results.instance.exports;
  memory = results.instance.exports.memory;
  //document.getElementById("container").innerText = instance.exports.add(1,1);
}).catch(console.error);
