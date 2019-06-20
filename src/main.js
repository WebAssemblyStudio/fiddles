fetch('../out/main.wasm').then(response => response.arrayBuffer()).then(bytes => WebAssembly.instantiate(bytes)).then(r => gisExpress.doWork(r)).catch(console.error);

let wasm;

var gisExpress = {
   doWork : function(r){
    wasm = r.instance.exports;
    //const buffer = new Uint8Array(r.instance.exports.memory.buffer);
    //document.getElementById("container").textContent = toString(toArray(buffer, wasm.test()));
  },

  fileChanged : function () 
  {
    var reader = new FileReader();
    reader.onload = function () { gisExpress.fileLoad(new Uint8Array(this.result)); }
    reader.readAsArrayBuffer(this.files[0]);
  },

  fileLoad : function (r){
    alert(r);
  },

  toArray : function(h, p) {
    let arr = []; let n = 0;
    for (i = p; h[i]; i++) { arr[n++] = h[i]; }
    return arr;
  },

  toString : function(uintArray) {
      return decodeURIComponent(escape(String.fromCharCode.apply(null, uintArray)));
  }
}

document.getElementById('fileOpen').addEventListener('change', gisExpress.fileChanged, false);