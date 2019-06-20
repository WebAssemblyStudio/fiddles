//fetch('../out/main.wasm').then(response => response.arrayBuffer()).then(bytes => WebAssembly.instantiate(bytes)).then(r => gisExpress.doWork(r)).catch(console.error);

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
    
    WebAssembly.instantiateStreaming(fetch('../out/main.wasm')).then(r => {
      var i32 = new Uint32Array(r.instance.exports.memory.buffer);
      for (var i = 0; i < array.length; i++) {
        i32[i] = array[i];
      }

      alert(r.instance.exports.fileLoad(i32, i32.length));
    });
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