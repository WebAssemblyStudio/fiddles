WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  const prime = exports.isPrime;

  const t0 = performance.now();
    for (let q = 0; q < 1000; q++){
        prime(q)
    }
    const t1 = performance.now();
    console.log(`Call to WASM took ${t1 - t0} milliseconds.`);

  var numericArray = [10, 20, 30, 40];
  console.log(numericArray);
  const sum = exports.sumArray(numericArray);
  console.log(sum);

  document.getElementById("intros").textContent = "Hello!: " + exports.getGreeting('Eytan');
  document.getElementById("container").textContent = "Result of addition: " + exports.add(19, 23);
  document.getElementById("container2").textContent = "Result of multiplication: " + exports.multiply(1000,1000);

}).catch(console.error);
