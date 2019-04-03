let x = '../out/main.wasm';

let instance = null;
let memoryStates = new WeakMap();

let s = "";
fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes, {
    env: {
      putstr_js: function (c,count) {
        let s=String.fromCharCode.apply(null, new Uint8Array(instance.exports.memory.buffer).slice(c,c+count));
        console.log(s);
      }
    }
  })
).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
