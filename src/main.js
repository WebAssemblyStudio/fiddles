let x = '../out/main.wasm';

let instance = null;
let memoryStates = new WeakMap();

function get_string(memory, addr) {
  var length = 0;

  while (true) {
    let buffer = new Uint8Array(memory.buffer, addr, 16);
    let term = buffer.indexOf(0);

    length += term == -1 ? 16 : term;

    if (term != -1) break;
  }
  
  const strBuf = new Uint8Array(memory.buffer, addr, length);
  return new TextDecoder().decode(strBuf);
}

fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes, {
    env: {
      printf: function (addr) {
        const memory = instance.exports.memory;
        console.log(get_string(memory, addr));
      }
    }
  })
).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = instance.exports.main();
}).catch(console.error);
