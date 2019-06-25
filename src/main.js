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
      
      var len = wasm.load();
      console.log(len);
      console.log(String.fromCharCode.apply(null, i32.slice(0, len)));

      //alert(gisExpress.asString(gisExpress.asArray(i32, wasm.load())));
      //alert(gisExpress.asString(gisExpress.asArray(new Uint8Array(wasm.memory.buffer), wasm.getJson())));
      //alert(gisExpress.asString(gisExpress.asArray(i8, ptr)));
    });
  }
}

document.getElementById('fileOpen').addEventListener('change', gisExpress.fileChanged, false);