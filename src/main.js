fetch('../out/main.wasm').then(response => response.arrayBuffer()).then(bytes => WebAssembly.instantiate(bytes)).then(r => gisExpress.doWork(r)).catch(console.error);

let wasm;

var gisExpress = {
   doWork : function(r)
   {
    wasm = r.instance.exports;
    document.getElementById("container").textContent = gisExpress.asString(gisExpress.asArray(new Uint8Array(r.instance.exports.memory.buffer), wasm.test()));
  },

  fileChanged : function ()
  {
    var reader = new FileReader();
    reader.onload = function () { gisExpress.fileLoad(this.result); };
    reader.readAsArrayBuffer(this.files[0]);
  },

  fileLoad : function (r)
  {
    var array = new Uint8Array(r);
    wasm.fileLoad(array, array.length);
  },

  asArray : function(h, p) 
  {
    let arr = []; let n = 0;
    for (i = p; h[i]; i++) { arr[n++] = h[i]; }
    return arr;
  },

  asString : function(uintArray) 
  {
      return decodeURIComponent(escape(String.fromCharCode.apply(null, uintArray)));
  }
}

document.getElementById('fileOpen').addEventListener('change', gisExpress.fileChanged, false);