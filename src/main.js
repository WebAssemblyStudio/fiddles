let x = '../out/main.wasm';

let instance = null;
let memoryStates = new WeakMap();

let s = "";
fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes, {
    env: {
      draw: function (a,b,c,d) {
        console.log(a,b,c,d)
      }
    }
  })
).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = instance.exports.add();
}).catch(console.error);
