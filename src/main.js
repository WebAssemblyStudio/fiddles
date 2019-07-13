

const blockData = "f90649b90214f90211a042d5f0401d27bdae05452ce52bcee42a2c659c112d15b5f30b126b9ec24c68c0a045454ccb94e62efdbcd08423b7eef4cac43614025010c4312a745f67401588a5a02afb19069a247c89761e8eef700649c95743f1651e837c26aab6880228bedbf3a0305dd55390d2baea9157b4b1841bf1356b1187310bacc5eb848c34ce1391875aa0b53a79d67ee772cfdc8df03402e1400e7ff4df4e97423a6296c2b71a7649af1ca0dfaffef77c95e519bd9f2ef464c69545b5085106d767ed1dfcb2fef12d3f94f5a0a898ad01e272c350dd4a7954bd3eda10837ee79de6d7a99245a3b5d638ad51aea0d5476878fd37d082f47084404592dc5fe1f88911e25709862f078712806f0c00a0345ae4503837685c7656a1d7753ba02bafec78f7dd99e18b7f34af9a2ae0d5f5a00b330c853039769f2f6c193ede0d597e84c16694c30bf45ae542c744ee08705aa0f5c48d706862325d76408f20df39f41e7c4dbd37dfbf1862fb5fed95324d7cb4a068eea910788058bc79939fe8077713bc8a18546d1f7ea5883bed970a82cbc3cfa066b9fd9323d3e0192ca69393413812bb2ebe025ebb120d31984f9e9a7a26dbd8a09852cd62db324e6bb2c94d04a5e0b24174af7dfaecebff58801be80f4d1e5400a0414befb1392d59c80ec0437feeab156080c237257ef2b352706f1946dec6c1baa060a5007191b8029e1b03785b2208e86e454eff23748c326a82767de3e16bc05e80b90214f90211a0f39fe5a7162c45b22c02cb94230a20e2c560a4ac47139f16d5d854aa59824dbca02d1eab2837fe85989bb4c81909b72cca54cb9d1f468e7ec4e3eb456fd495a743a0a5bdd40ad518900a7e5d6eabca6a64e92eef2652dc29923588cf97da71c74ebda067443e65a990f381fac8edf910a808cc2dc2103fd1fa5e7034a707c8700ae82ca035d8a519ef64ebcd0612da781942c35a44f4a7bd3799d44795fa852d05896430a03dd798002fbde0bacdca72a40f9830dfebd407814d9a0c9b4a0020aa1a70b0a4a0ce022440e14c927be3aae6292544706bb8634be61706225d4c3538a26319e9cda0ff32461e225e1ba6ba743917423ea5533c325a301eb84d150d5616d3da46a723a0a98b509e64063e9103f9bc6b88f7bd7c16fff6f87cab04b3cdbd979eb2d2bc2ba0c2cf127b1b4fc25b6ee52426f283ce469094bcfc5628d1b6dfc16ec42d5b16fda0b0bfb7da5d53eeab7a0cfc5a3c7967d5d57f36d52b89ac7741f0c930f2c035f4a0c64b3feb9c5c536aa7bd0604972eaa941fa7e3291059cbea7e3147fcda56c01ba058441cdf89d8d096fd260bcc01a184f77ee5de3ce751e3d7b552f21b996a45d8a01e2e3820cf9c8d9b0b0189c982e8d71f9e29257e48c184c218c3192c5fc2ba04a0a179362070964bd10e6ad521210237263ff1350046a6485e2bbcc9ae24b77a7fa022e8825104733446e36377c3bfc29b391ca456c4eb74a8d28c0a6dfd12e9e5b480b90134f90131808080a0bfd028e4ddbd46a359735f552d34c0564703e437a35a9ac250e3fde4d1a53e8aa07bc9a92b34fd3cb44243cad532d806c5b56c4037bd7ad4a0f1022da71a95278080a0e777030539c5a325e56bf340093d9122e60bce40217d5ac798e4babc1a655a25a0ebf8f6d6e437ee47289a1fd7623310071ddd8f0ab6f0da3be455bdec071e566e80a0ed7c3468f9983ea04abb3300c38388275566a05872420e468beeadfe4fcf5d3ba01d79398dc95870d72a573ad00e71c6d3ff71e8baa14c4f16093cd908fb037736a0199d7eb18bed36b5ee521a0f0832a5b4a1d4aec8c78bbb49d85dfd36f63a924f80a004c839f5d54f77790d78efe546ee72186e01344775ad02e3f5c9cb2c681cbf80a0e0316b195732276c8de71499c16de5503ba4ba5b5d11438387e25061865e58188080b873f87180808080a0bd47c4f9db488edbfab24643591aabab4ec3d104abf6235a361d41bdd3ca7f7080808080808080a0dbfac81e828c6c6cd0142def55de51773458e89c250a71870d09af2d2f5088b180a06eaca5c29825ba75ba49115c2b88635f20b2a4a3e61fa722310f4a640b4815e78080b86df86b9f200cd89ae762119fed6ecd8dc969077bb2d6a3471c639a10e710a9374a121db849f8478083ffffffa056e81f171bcc55a6ff8345e692c0f86e5b48e01b996cadc001622fb5e363b421a0c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470";

console.log('blockData length:', blockData.length);

var memory;

WebAssembly.instantiateStreaming(fetch("../out/main_with_keccak.wasm"), {
  main: {
    sayHello(a) {
      console.log("Hello from WebAssembly!", a);
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    },
    eth2_blockDataSize() {
      return blockData.length / 2;
    },
    eth2_blockDataCopy(srcOffset, length, outOffset) {
        const copyBytes = new Uint8Array(length);

        for (var i = 0; i < length; i++) copyBytes[i] = parseInt(blockData.substr((srcOffset*2)+(i*2), 2), 16);

        const asBytes = new Uint8Array(memory.buffer, outOffset, length+1);
        asBytes.set(copyBytes);
    },
  },
}).then(result => {
  const exports = result.instance.exports;
  memory = exports.memory;
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

