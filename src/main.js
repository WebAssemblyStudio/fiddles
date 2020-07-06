WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    helloWorld() {
      const myDate = new Date();
      console.log("Hello from WebAssembly!" + " ; Time At :" + myDate.toLocaleString() + " " + myDate.getMilliseconds());
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  const myDate = new Date();
  document.getElementById("container").textContent = "来一个加法: 56 + 23 = " + exports.add(56, 23) + " ; Time At :" + myDate.toLocaleString() + " " +  myDate.getMilliseconds();
}).catch(console.error);
