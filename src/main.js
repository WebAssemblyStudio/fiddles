let exports;
let buffer;
(async() => {
  let response = await fetch('../out/main.wasm');
  let results = await WebAssembly.instantiate(await response.arrayBuffer());
  //or
  // let results = await WebAssembly.instantiateStreaming(fetch('../out/main.wasm'));
  let instance = results.instance;
  exports = instance.exports;
  buffer = new Uint8Array(exports.memory.buffer);

  findPower(5,3);
  
  printHelloWorld();
})();

const findPower = (base = 0, power = 0) => {
  console.log(exports.power(base,power));
}

const printHelloWorld = () => {
  let pointer = exports.helloWorld();
  let str = "";
  for(let i = pointer;buffer[i];i++){
    str += String.fromCharCode(buffer[i]);
  }
  console.log(str);
}