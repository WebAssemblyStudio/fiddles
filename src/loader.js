let x = '../out/main.wasm';

let instance = null;
let memoryStates = new WeakMap();

const GET_USERAGENT_ID = 10;
const CALL_ALERT_ID = 20;

let module = {
  // entry可以用js-skein和jsvm加固
  entry: function (id, ptr) {
    let memory = instance.exports.memory.buffer;

    if (id === GET_USERAGENT_ID) {
      let userAgent = navigator.userAgent;
      let i = 0;
      for (; i < userAgent.length; i++) {
        memory[ptr + i] = userAgent.charCodeAt(i);
      }
      memory[ptr + i] = 0;
    } 
    else if (id === CALL_ALERT_ID) {
      let text = "";
      while (memory[ptr]) {
        text += String.fromCharCode(memory[ptr++]);
      }
      alert(text);
    }
  }
}

fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes, {
    env: module
  })
).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
