WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    sayHello: function() {
      console.log("Hello from WebAssembly!");
    },
    abort: function(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
  console: {
    log: function (val) { console.log(val) }
  }
}).then(result => {
  const exports = result.instance.exports;

  function jsFib(num) {
    if (num <= 1) return num;
    return jsFib(num - 1) + jsFib(num - 2);
  }

  function jsFibTail(num, a = 0, b = 1) {
    if (num == 0) return a;
    if (num == 1) return b;
    return jsFibTail(num - 1, b, a + b);
  }

  console.time('fib wasm');
  exports.fibTest();
  console.timeEnd('fib wasm');

  console.time('fib tail wasm');
  exports.fibTailTest();
  console.timeEnd('fib tail wasm');

  console.time('fib js');
  for (let i = 0; i < 5; i++) {
    jsFib(34);
  }
  console.timeEnd('fib js');

  console.time('fib tail js');
  for (let i = 0; i < 5; i++) {
    jsFibTail(34);
  }
  console.timeEnd('fib tail js');

}).catch(console.error);

