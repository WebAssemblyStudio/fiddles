WebAssembly.instantiateStreaming(fetch('../out/main.wasm'))
      .then(obj => {
        console.log(obj.instance.exports.callByIndex(0)); // returns 42
        console.log(obj.instance.exports.callByIndex(1)); // returns 13
        console.log(obj.instance.exports.callByIndex(2)); // returns an error, because there is no index position 2 in the table
      });