
const memory = new WebAssembly.Memory({ initial: 1 });
//console.log(memory.buffer);

const mem = new Uint8Array(memory.buffer);
mem.set([1, 2, 3, 4]);

console.log(mem);

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    memory,
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    },
    trace: console.log.bind(console)
  },
}).then(result => {
  const { mdeterm } = result.instance.exports;

  document.getElementById("container").textContent = "Result: " + mdeterm();
}).catch(console.error);
