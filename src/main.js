const log = function (...inputs) {
  for (let text of inputs.flatMap(text => String(text).split("\n"))) {
    const node = document.createTextNode(text);
    container.appendChild(node);
    container.appendChild(document.createElement("br"));
  }
}



const memory = new WebAssembly.Memory({initial: 1});

const importObject = {
  js: {
    memory,
    log: function (byteOffset, length) {
      const typedArray = new Uint8Array(memory.buffer, byteOffset, length);
      const string = [...typedArray].map(code => String.fromCharCode(code)).join("")
      log(string);
    }
  }
};

const results = await WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), importObject);
const { instance: { exports } } = results;

const $ = document.querySelector.bind(document);
const container = $("#container");



exports.helloWorldCount(4);