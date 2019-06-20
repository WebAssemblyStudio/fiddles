//WebAssembly.instantiateStreaming(fetch('../out/gisexpress.io.wasm')).then(r => gisExpress.doWork(r)).catch(console.error);

var gisExpress = {
   doWork : function(r)
   {
    wasm = r.instance.exports;
    document.getElementById("container").textContent = gisExpress.asString(gisExpress.asArray(new Uint8Array(wasm.memory.buffer), wasm.getJson()));
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
   
    WebAssembly.instantiateStreaming(fetch('../out/gisexpress.io.wasm')).then(r => {
      var wasm = r.instance.exports;
      var i32 = new Uint32Array(wasm.memory.buffer);

      for (var i = 0; i < array.length; i++) {
        i32[i] = array[i];
      }

      alert(wasm.load());
      alert(gisExpress.asString(i32));
      //alert(gisExpress.asString(gisExpress.asArray(new Uint8Array(wasm.memory.buffer), wasm.getJson())));
      //alert(gisExpress.asString(gisExpress.asArray(i8, ptr)));
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