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
        const arrayBuffer = memory.buffer
        const buffer = new Uint16Array(arrayBuffer, index, exports.length() + 2)
        let text = ""
        for (let i = 2; i < buffer.length; i++) {
            let str = String.fromCharCode(buffer[i])
            text += str
        }
        document.getElementById("container").textContent = text;
    }).catch(console.error);
} catch (e) {
    console.log(e)
}
