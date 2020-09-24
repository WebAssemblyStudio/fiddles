WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    log(s) {
      // console.log(s);
      alert(s);
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  // document.getElementById("container").textContent = "Result: " + exports.add(0.1, 0.2);

  var start = new Date();
  for(var i=0;i<50000;i++) {
    var r = exports.add(0.1, 0.2);
    if(i%1000 ===0) {
      console.log(">> " + r);
    }
  }
  var end = new Date();
  console.log(end.getTime() - start.getTime());

}).catch(console.error);
