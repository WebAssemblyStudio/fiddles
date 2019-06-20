fetch('../out/main.wasm').then(response => response.arrayBuffer()).then(bytes => WebAssembly.instantiate(bytes)).then(r => doWork(r)).catch(console.error);

function doWork(r){
  const arrayBuffer = r.instance.exports.memory.buffer;
  const buffer = new Uint8Array(arrayBuffer);
  
  alert(toString(toArray(buffer, r.instance.exports.test())));

  //document.getElementById("container").textContent = utf8ToString(h, p);
}

function toArray(h, p) {
  let arr = []; let n = 0;
  for (i = p; h[i]; i++) { arr[n++] = h[i]; }
  return arr;
}

function toString(uintArray) {
    var encodedString = String.fromCharCode.apply(null, uintArray);
    var decodedString = decodeURIComponent(escape(encodedString));
    return decodedString;
}