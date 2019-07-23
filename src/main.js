WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    },
    changeColor(colorNum) {
        console.log('changeColor invoked ' + colorNum)
        if (colorNum == 1) {
          document.getElementById("div-elem").style.color = "blue";
        } else if (colorNum == 2) {
          document.getElementById("div-elem").style.color = "red";
        }              
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
  document.getElementById("button-elem").onclick = function() {
    exports.setColor(2);
  }

  // window.myListener = function() {
  //     const exports = result.instance.exports;
  //   exports.changeColor(2);
  //   // console.log('button pushed')          
  // }
}).catch(console.error);
