const memory = new WebAssembly.Memory({ initial: 40 })
WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  js: { mem: memory },
  main: {
    sayHello(test, test2, len) {
      console.log("Hello from WebAssembly!");
      console.log(test, test2, len)
      const buffer = new ArrayBuffer(len);
      const view = new Uint8Array(memory.buffer);
      let string = '';
      for (let i = 0; i < 40; i++) {
        var char = String.fromCharCode(view[i]);
        console.log(char);
      }
      console.log(string);
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
}).catch(console.error);
