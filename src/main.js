WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    printTime(s) {
      for (let prop in s) {
        console.log(prop);
      }
      console.log(s);
      console.log(new Date);
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.add(19);
}).catch(console.error);
