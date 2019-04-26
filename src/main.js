try {
    WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
        main: {
          sayHello() {
            console.log("Hello from WebAssembly!");
          }
        },
        env: {
          abort(msg, file, line, column) {
            console.error("abort called at main.ts:" + line + ":" + column);
          }
        },
    }).then(result => {
        const exports = result.instance.exports;
        const memory = exports.memory;
        const index = exports.call()
        var buffer = new Uint16Array(memory.buffer, index)
        let text = String.fromCharCode.apply(null, new Uint16Array(memory.buffer, index + 4, buffer[0]))
        document.getElementById("container").textContent = text;
    }).catch(console.error);
} catch (e) {
    console.log(e)
}
