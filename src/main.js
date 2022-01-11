let x = '../out/main.wasm';

let instance = null;
let memoryStates = new WeakMap();


let s = "";
fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes, {
    env: {
      
    }
  })
).then(results => {
  instance = results.instance;
  console.log(Object.keys(instance.exports).join('|'))
  document.getElementById("container").textContent = instance.exports.mround(-0.5);
}).catch(console.error);
