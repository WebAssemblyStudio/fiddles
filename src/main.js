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
//const ivBuffer = [240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255];
//const keyBuffer = [96, 61, 235, 16, 21, 202, 113, 190, 43, 115, 174, 240, 133, 125, 119, 129, 31, 53, 44, 7, 59, 97, 8, 215, 45, 152, 16, 163, 9, 20, 223, 244];
const keyBuffer =[79 ,109, 104, 101 ,113, 74 ,84 ,111, 114 ,120 ,80 ,87, 78 ,51 ,65, 90 ,107 ,66 ,118, 75, 56, 55 ,71 ,106 ,108, 69 ,53, 89, 88, 86, 100 ,49];
const ivBuffer =[86, 107, 110, 97, 54 ,82 ,122, 76 ,73 ,112, 53, 101, 114, 71, 121, 117]
// const ivBuffer = [49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49];
// const keyBuffer = [49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49];

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




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

var contentss;
function dispFile(contents) {
  document.getElementById('contents').innerHTML = contents
}
function clickElem(elem) {
  // Thx user1601638 on Stack Overflow (6/6/2018 - https://stackoverflow.com/questions/13405129/javascript-create-and-save-file )
  var eventMouse = document.createEvent("MouseEvents")
  eventMouse.initMouseEvent("click", true, false, window, 0, 0, 0, 0, 0, false, false, false, false, 0, null)
  elem.dispatchEvent(eventMouse)
}
function openFile(func) {
  readFile = function (e) {
    var file = e.target.files[0];
    if (!file) {
      return;
    }
    var reader = new FileReader();
    reader.onload = function (e) {
      contentss = e.target.result;
      if (contentss.split(",")[0].indexOf("base64") >= 0) {
        contentss = contentss.split(",")[1];
      }
      console.log(contentss);
      fetchAndInstantiateWasm('./aes.wasm')
        .then(m => {
          //fillPlainBuffer(2 ** 5);
          plainBuffer = new Uint8Array(_base64ToArrayBuffer(contentss));
          console.log(plainBuffer);
          const byteView = new Uint8Array(m.memory.buffer);
          //byteView.set(ivBuffer, ivPointer);
          //byteView.set(keyBuffer, keyPointer);
          //m.aes_setkey_enc(encryptionContextPointer, keyPointer, 32);
          //byteView.set(plainBuffer, blockPointer);
          //m.aes_crypt_cbc(encryptionContextPointer, 1, plainBuffer.length, ivPointer, blockPointer, blockPointer)
          //const encryptedData = byteView.subarray(blockPointer, blockPointer + plainBuffer.length).slice();
          //console.log(encryptedData);

          //;
          byteView.set(ivBuffer, ivPointer);
          byteView.set(keyBuffer, keyPointer);
          m.aes_setkey_dec(decryptionContextPointer, keyPointer, 256);
          byteView.set(plainBuffer, blockPointer);
          m.aes_crypt_cbc(decryptionContextPointer, 0, plainBuffer.length, ivPointer, blockPointer, blockPointer);
          console.log(plainBuffer);
          const decryptedData = byteView.subarray(blockPointer, blockPointer + plainBuffer.length).slice()
          console.log(decryptedData);


          //var enc = new TextDecoder("utf-8");
          //console.log(enc.decode(decryptedData));
        });
    }
    reader.readAsDataURL(file)
  }
  fileInput = document.createElement("input")
  fileInput.type = 'file'
  fileInput.style.display = 'none'
  fileInput.onchange = readFile
  fileInput.func = func
  document.body.appendChild(fileInput)
  clickElem(fileInput)
}