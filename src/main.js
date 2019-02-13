//var canvas = document.getElementById("canvas");
//var gl = canvas.getContext("webgl");

var imports = {
  test: function() {
    alert("HI!")
  }
}

WebAssembly.compileStreaming(fetch('../out/main.wasm'))
.then(module => WebAssembly.instantiate(module, imports))
.then(instance => {
  var memory = new Uint8Array(instance.exports.memory.buffer);
  function readString(pointer) {
    var str = "";

    while(memory[pointer] != 0) {
      str += memory[pointer];
      pointer++;
    }

    return str;
  }

  alert(instance.exports)
  var helloworld = instance.exports.main();
  alert("!");
  alert(readString(helloworld));
});