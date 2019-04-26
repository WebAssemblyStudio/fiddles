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
        const buffer = new Uint16Array(memory.buffer, index)
        let length = buffer[0]
        let i = 2
        let text = ""
        while (i < length + 2) {
          text += String.fromCharCode(buffer[i])
          i++
        }
        document.getElementById("container").textContent = text;
    }).catch(console.error);
} catch (e) {
    console.log(e)
}
