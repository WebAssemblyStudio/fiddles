
WebAssembly.instantiateStreaming(fetch("../out/main_with_keccak.wasm"), {
  main: {
    sayHello(a) {
      console.log("Hello from WebAssembly!", a);
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  console.log('result.instance.exports:', result.instance);
  // put block data in memory before calling function 
  // WRONG. can't do this because don't know what memory location to use. 
  // const blockData = "f86b9f200cd89ae762119fed6ecd8dc969077bb2d6a3471c639a10e710a9374a121db849f8478083ffffffa056e81f171bcc55a6ff8345e692c0f86e5b48e01b996cadc001622fb5e363b421a0c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470";
  // const copyBytes = new Uint8Array(blockData.length / 2);

  /*
  for (var i = 0; i < length; i++) copyBytes[i] = parseInt(inputHex.substr((dataOffset*2)+(i*2), 2), 16);

  const asBytes = new Uint8Array(exported_mem.buffer, resultOffset, length+1);
  asBytes.set(copyBytes);
  */

  const wasm_returned = exports.mpt_verify(19, 23);

  const returnBytes = new Uint8Array(exports.memory.buffer, wasm_returned, 32);
    let convertedBack = '';
  for (var i = 0; i < 32; i++) {
    if (returnBytes[i] < 16) convertedBack += '0';
    convertedBack += returnBytes[i].toString(16);
  }
  console.log('wasm returned:', convertedBack);
  //document.getElementById("container").textContent = "Result: " + wasm_returned + " (0x" + wasm_returned.toString(16) + ")";
  document.getElementById("container").textContent = "Result: " + wasm_returned + " (0x" + convertedBack + ")";
  
}).catch(console.error);

