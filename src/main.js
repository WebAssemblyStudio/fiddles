WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello(x) {
      console.log(x);
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
  console.log(exports.__rtti_base.value)
  // console.log(exports.memory.grow(10))
  const x = 2
  for(let i = 0; i < x; i++) exports.fill(i)
  
  console.log(exports.count())
  exports.log(exports.getSum(x))
  console.log(exports.__rtti_base.value)
  
}).catch(console.error);
