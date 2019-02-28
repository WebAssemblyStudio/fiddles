let x = '../out/main.wasm';

let instance = null;

let s = "";
fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes, {
    env: {
      putc_js: function (c) {
        c = String.fromCharCode(c);
        //var text = document.createTextNode(c);
        //node.appendChilddocument.write(c);    
        document.getElementById("container").textContent += c;
    
      }
    }
  })
).then(results => {
  instance = results.instance;
  instance.exports.main();
}).catch(console.error);
                           