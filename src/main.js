let exports;
(async() => {
  let response = await fetch('../out/main.wasm');
  let results = await WebAssembly.instantiate(await response.arrayBuffer());
  let instance = results.instance;
  exports = instance.exports;
  let buffer = new Uint8Array(exports.memory.buffer);
  console.log(exports.power(5,3));
  let pointer = exports.helloWorld();
  let str = "";
  for(let i = pointer;buffer[i];i++){
    str += String.fromCharCode(buffer[i]);
  }
  console.log(str);
})();
