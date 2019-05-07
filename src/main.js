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

  gcd = (num1: number, num2: number): number => {
      if (num1 === 0 || num2 === 0) {
        return 0;
      }
      if (num1 === num2) {
        return num1;
      }
      if (num1 > num2) {
        return gcd(num1 - num2, num2);
      }
      return gcd(num1, num2 - num1);
  };

  gcd10000 = (num1: number, num2: number) => {
    let result = 0;
    for (let k = 0; k < 10000; ++k) {
      result += gcd(num1, num2);
    }
  }

  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);

  let tt0 = performance.now();
  let gcd = exports.gcd(36366, 986);
  let tt1 = performance.now();
  document.getElementById("gcdts").textContent = "GCD: " + gcd + "Time: " + (tt1 - tt0);

  let t0 = performance.now();
  let gcd = exports.gcd10000(36366, 986);
  let t1 = performance.now();
  document.getElementById("gcdas").textContent = "GCD: " + gcd + "Time: " + (t1 - t0);
}).catch(console.error);
