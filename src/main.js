
function getString(ptr: number, buffer: ArrayBuffer): string {
  var U16 = new Uint16Array(buffer);
  var U32 = new Uint32Array(buffer);
  var dataLength = U32[ptr >>> 2];
  var dataOffset = (ptr + 4) >>> 1;
  var dataRemain = dataLength;
  var parts = [];
  const chunkSize = 1024;
  while (dataRemain > chunkSize) {
    let last = U16[dataOffset + chunkSize - 1];
    let size = last >= 0xD800 && last < 0xDC00 ? chunkSize - 1 : chunkSize;
    let part = U16.subarray(dataOffset, dataOffset += size);
    parts.push(String.fromCharCode.apply(String, part));
    dataRemain -= size;
  }
  return parts.join('') + String.fromCharCode.apply(String, U16.subarray(dataOffset, dataOffset + dataRemain));
}

var buffer = null;

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    },
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
  console: {
    logi(value) { console.log('logi: ' + value); },
    logf(value) { console.log('logf: ' + value); },
    logs(strPtr) {
      console.log(getString(strPtr), buffer);
    }
  }
}).then(result => {
  const exports = result.instance.exports;
  // buffer = exports.memory.buffer;
  console.log(exports);
  // document.getElementById("container").innerText = "Result: " + exports.add(19, 23);
}).catch(console.error);
