

const blockData = "f90211a042d5f0401d27bdae05452ce52bcee42a2c659c112d15b5f30b126b9ec24c68c0a045454ccb94e62efdbcd08423b7eef4cac43614025010c4312a745f67401588a5a02afb19069a247c89761e8eef700649c95743f1651e837c26aab6880228bedbf3a0305dd55390d2baea9157b4b1841bf1356b1187310bacc5eb848c34ce1391875aa0b53a79d67ee772cfdc8df03402e1400e7ff4df4e97423a6296c2b71a7649af1ca0dfaffef77c95e519bd9f2ef464c69545b5085106d767ed1dfcb2fef12d3f94f5a0a898ad01e272c350dd4a7954bd3eda10837ee79de6d7a99245a3b5d638ad51aea0d5476878fd37d082f47084404592dc5fe1f88911e25709862f078712806f0c00a0345ae4503837685c7656a1d7753ba02bafec78f7dd99e18b7f34af9a2ae0d5f5a00b330c853039769f2f6c193ede0d597e84c16694c30bf45ae542c744ee08705aa0f5c48d706862325d76408f20df39f41e7c4dbd37dfbf1862fb5fed95324d7cb4a068eea910788058bc79939fe8077713bc8a18546d1f7ea5883bed970a82cbc3cfa066b9fd9323d3e0192ca69393413812bb2ebe025ebb120d31984f9e9a7a26dbd8a09852cd62db324e6bb2c94d04a5e0b24174af7dfaecebff58801be80f4d1e5400a0414befb1392d59c80ec0437feeab156080c237257ef2b352706f1946dec6c1baa060a5007191b8029e1b03785b2208e86e454eff23748c326a82767de3e16bc05e80";

console.log('blockData length:', blockData.length);

var memory;

WebAssembly.instantiateStreaming(fetch("../out/main_with_keccak.wasm"), {
  main: {
    sayHello(a) {
      console.log("Hello from WebAssembly!", a);
    },
    debug(a) {
      const debugMem = new Uint8Array(memory.buffer, a, 32);
      let debugHex = '';
      for (var i = 0; i < 32; i++) {
        if (debugMem[i] < 16) debugHex += '0';
            debugHex += debugMem[i].toString(16);
      }
      console.log("debug mem at " + a + ":", debugHex);
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    },
    eth2_blockDataSize() {
      let size = blockData.length / 2;
      //console.log('eth2_blockDataSize. returning size:', size);
      return size;
    },
    //eth2_blockDataCopy(srcOffset, length, outOffset) {
    eth2_blockDataCopy(outOffset, srcOffset, length) {
        //console.log('eth2_blockDataCopy srcOffset:', srcOffset);
        //console.log('eth2_blockDataCopy length:', length);
        //console.log('eth2_blockDataCopy outOffset:', outOffset);
        const copyBytes = new Uint8Array(length);

        for (var i = 0; i < length; i++) copyBytes[i] = parseInt(blockData.substr((srcOffset*2)+(i*2), 2), 16);

        const asBytes = new Uint8Array(memory.buffer, outOffset, length+1);
        asBytes.set(copyBytes);
    },
  },
}).then(result => {
  const exports = result.instance.exports;
  memory = exports.memory;
  //console.log('result.instance.exports:', result.instance);

  console.time('mpt_verify_40_iterations');
  const wasm_returned = exports.main();
  console.timeEnd('mpt_verify_40_iterations');

  // return result is the account leaf value (only printing the first 32 bytes of it)

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

