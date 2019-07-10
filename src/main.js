const memory = new WebAssembly.Memory({initial: 1});

const interop = {
  print: console.log,
  mem: memory,
  writeString: (str, offset) => {
    var stringBytes = new TextEncoder('utf8').encode(str);
    var buffer = new Uint8Array(memory.buffer, offset, stringBytes.length);
    buffer.set(stringBytes);
    return stringBytes.length;
  },
  readString: (offset, length) => {
    const bytes = new Uint8Array(memory.buffer, offset, length);
    return new TextDecoder('utf8').decode(bytes);
  },
  slowCharToUpper: (offset) => {
    const char = interop.readString(offset, 1);
    interop.writeString(char.toUpperCase(), offset);
  }
}


fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, { interop})).then(results => {
  instance = results.instance;
  const result = instance.exports.add(1,2);
  //const length = interop.writeString("hello", 0);
  //instance.exports.stringToUpper(0, length)
  //const result = interop.readString(0, length);
  document.getElementById("container").textContent = result;
}).catch(console.error);