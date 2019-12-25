let instance = null;

// var buf = new Uint8Array(mod.instance.exports.memory.buffer, ptr, len)
// var msg = new TextDecoder('utf8').decode(buf);
// alert(msg);
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
      },
      jt_blockNumber: function() {
        console.log("jt_blockNumber", 100)
        return 100;
      },
      jt_getBalance: function(a, c, i) {
        let h = new Uint8Array(instance.exports.memory.buffer);
        let address = utf8_to_string(h, a)
        let currency = utf8_to_string(h, c)
        let issuer = utf8_to_string(h, i)
        console.log("jt_getBalance", address, currency, issuer, 10000)
        return 10000
      },
      jtc_move: function(f, t, b, c, i) {
        let h = new Uint8Array(instance.exports.memory.buffer);
        let fromAddress = utf8_to_string(h, f)
        let toAddress = utf8_to_string(h, t)
        let currency = utf8_to_string(h, c)
        let issuer = utf8_to_string(h, i)
        console.log("jtc_move", fromAddress + " => " + toAddress, b, currency, issuer)
        return 0;
      }
    }
  })).then(results => {
    instance = results.instance;
    document.getElementById("container").textContent = instance.exports.main()
}).catch(console.error);
