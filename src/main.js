function fetchAndInstantiateWasm(url, imports) {
  return fetch(url)
    .then(res => {
      if (res.ok)
        return res.arrayBuffer();
      throw new Error(`Unable to fetch Web Assembly file ${url}.`);
    })
    .then(bytes => WebAssembly.compile(bytes))
    .then(module => WebAssembly.instantiate(module, imports || {}))
    .then(instance => instance.exports);
}



let mem;
let currentTop = 2 ** 14;
const encryptionContextPointer = currentTop;
currentTop += 276;
const decryptionContextPointer = currentTop;
currentTop += 276;
const keyPointer = currentTop;
currentTop += 32;
const ivPointer = currentTop;
currentTop += 16;
const blockPointer = currentTop;
const ivBuffer = [240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255];
const keyBuffer = [96, 61, 235, 16, 21, 202, 113, 190, 43, 115, 174, 240, 133, 125, 119, 129, 31, 53, 44, 7, 59, 97, 8, 215, 45, 152, 16, 163, 9, 20, 223, 244];
// const ivBuffer = "1111111111111111";
// const keyBuffer = "11111111111111111111111111111111";

let plainBuffer;

function _base64ToArrayBuffer(base64) {
  var binary_string = window.atob(base64);
  var len = binary_string.length;
  var bytes = new Uint8Array(len);
  for (var i = 0; i < len; i++) {
    bytes[i] = binary_string.charCodeAt(i);
  }
  return bytes.buffer;
}


function fillPlainBuffer(size) {
  const buf = [];
  for (let i = 0; i < size; i++) {
    buf.push(Math.floor(Math.random() * 256));

  }
  plainBuffer = new Uint8Array(buf);
}

fetchAndInstantiateWasm('./aes.wasm')
  .then(m => {
    fillPlainBuffer(2 ** 5);
    //plainBuffer = new Uint8Array(_base64ToArrayBuffer("xPp6KFrxlF+Od66QSpAZTg=="));
    console.log(plainBuffer);
    const byteView = new Uint8Array(m.memory.buffer);
    byteView.set(ivBuffer, ivPointer);
    byteView.set(keyBuffer, keyPointer);
    m.aes_setkey_enc(encryptionContextPointer, keyPointer, 32);
    byteView.set(plainBuffer, blockPointer);
    m.aes_crypt_cbc(encryptionContextPointer, 1, plainBuffer.length, ivPointer, blockPointer, blockPointer)
    const encryptedData = byteView.subarray(blockPointer, blockPointer + plainBuffer.length).slice();
    console.log(encryptedData);

    //;
    byteView.set(ivBuffer, ivPointer);
    byteView.set(keyBuffer, keyPointer);
    m.aes_setkey_dec(decryptionContextPointer, keyPointer, 32);
    byteView.set(encryptedData, blockPointer);
    m.aes_crypt_cbc(decryptionContextPointer, 0, encryptedData.length, ivPointer, blockPointer, blockPointer);
    const decryptedData = byteView.subarray(blockPointer, blockPointer + encryptedData.length).slice()
    console.log(decryptedData);
  });