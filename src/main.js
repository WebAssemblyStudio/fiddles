let instance = null;

function utf8_to_string(h, p) {
  let s = "";
  for (i = p; h[i]; i++) {
    s += String.fromCharCode(h[i]);
  }
  return s;
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {
    env: {
      print: function (p) {
        let h = new Uint8Array(instance.exports.memory.buffer);
        console.log(utf8_to_string(h, p));
      }
    }
  })).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
