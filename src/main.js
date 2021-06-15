const readMemStr = ( offset, length ) => {
        const strBuffer = new Uint8Array(wasm.memory.buffer, offset, length)
        const str = new TextDecoder().decode(strBuffer)
        console.log(str)
    }

const imports = {
    env: {
        setText: (x) =>  document.getElementById("container").textContent = x,
        strLog: readMemStr
    }
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, imports)).then(results => {
  instance = results.instance;
  window.wasm = instance.exports;
  document.getElementById('click').addEventListener('click', () => {
    instance.exports.onClick();
    wasm.greet();
  });
}).catch(console.error);
