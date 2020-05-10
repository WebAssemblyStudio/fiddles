let instance = null;

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes,
    {
      env: {
        consolelog: console.log,
        consolelogstr: (offset, len) => {
          const strBuffer = new Uint8Array(
            instance.exports.memory.buffer,
            offset,
            len
          );
          const c_str = new TextDecoder().decode(strBuffer)
          console.log(c_str);
        }
      }
    }
  )).then(results => {
  instance = results.instance;

  document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
