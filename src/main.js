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
   const output = document.getElementById('container');
  function log(message = '') {
    output.value += `${message}\n`;
  }
  const exports = result.instance.exports;

  const { __pin, __unpin, __newArray, __getArray, __getArrayView } = exports;

    // Create a new array, but this time in JavaScript. Note that the array is
    // again not reachable from within WebAssembly, only externally, so we
    // should pin it to prevent it from becoming garbage collected too early.
    let arrayPtr = __pin(__newArray(exports.Int32Array_ID, [
      3, 4, 5, 6, 7, 8, 9
    ]));
    log('Array pointer: ' + arrayPtr)

    // Log its elements to make sure these are the provided values
    log('Initial values: ' + __getArray(arrayPtr).join(', '))
}).catch(console.error);
