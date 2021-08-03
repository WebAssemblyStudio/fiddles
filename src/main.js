fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => {
  function toString(offset, length) {
    const bytes = new Uint8Array(memory.buffer, offset, length);
    const string = new TextDecoder('utf8').decode(bytes);
    return string;
  }

  const memory = new WebAssembly.Memory({initial:1});

  return WebAssembly.instantiate(bytes, {
    utils: {
      toString
    },
    core: {
      memory
    },
    console: {
      log: ((string) => console.log(string))
    }
  });
}).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.writeHi();
}).catch(console.error);

