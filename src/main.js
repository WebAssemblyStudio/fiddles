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
      var i8 = new Uint32Array(wasm.memory.buffer);

      for (var i = 0; i < array.length; i++) {
        i32[i] = array[i];
      }
      
      var len = wasm.load();
      
      console.log(len);
      console.log(String.fromCharCode.apply(null, gisExpress.getUtf8(i8.slice(0, len))));

      //alert(gisExpress.asString(gisExpress.asArray(i32, wasm.load())));
      //alert(gisExpress.asString(gisExpress.asArray(new Uint8Array(wasm.memory.buffer), wasm.getJson())));
      //alert(gisExpress.asString(gisExpress.asArray(i8, ptr)));
    });
  },

  getUtf8 : function(array){
    var n = 0;
    var value = [];
    for( var i = 0 ; i < array.length ; i++ ){
      var c = array[i];
      if(c > 4000000000){
        var d = array[++i];
        switch(c){
          case 4294967235:{
            switch(d){
              case 4294967175: c = 199; break;
              case 4294967207: c = 231; break;
              case 4294967190: c = 214; break;
              case 4294967222: c = 246; break;
              case 4294967196: c = 220; break;
              case 4294967228: c = 252; break;              
            }
          } break;
          case 4294967236:{
            switch(d){
              case 4294967198: c = 286; break;
              case 4294967199: c = 287; break;
              case 4294967216: c = 304; break;
              case 4294967217: c = 305; break;
            }
          } break;
          case 4294967237:{
            switch(d){
              case 4294967198: c = 350; break;
              case 4294967199: c = 351; break;
            }
          } break;
        }
      }

      value[n++] = c;
    }

    return value;
  }
}

document.getElementById('fileOpen').addEventListener('change', gisExpress.fileChanged, false);