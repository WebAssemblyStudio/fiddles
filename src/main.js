var canvas = document.getElementById("canvas");
var gl = canvas.getContext("webgl");

var memory = new WebAssembly.Memory({initial: 1});
var gl_objects = new Map();
var next_id = 0;

/*

gl_createProgram()
gl_attachShader()
gl_linkProgram()
gl_getProgramParameter()
gl_deleteProgram()

gl_getAttribLoction()
gl_enableVertexAttribArray()
gl_vertexAttribPointer()

gl_createBuffer()
gl_bindBuffer()
gl_bufferData()
gl_viewport()

gl_clearColor()
gl_clear()
gl_useProgram()
gl_drawArrays()
*/

gl_createShader()
gl_shaderSource()
gl_compileShader()
gl_getShaderParameter()
gl_deleteShader()

var imports = {
  gl_createShader: function(type) {
    var shaderPointer = next_id++;

    Map.set(shaderPointer, gl.createShader(type))
    return shaderPointer;
  },
  gl_shaderSource: function(shaderPointer, sourcePointer) {
    var shader = Map.get(shaderPointer);
    var source = readString(sourcePointer)
  }
}

WebAssembly.compileStreaming(fetch('../out/main.wasm'))
.then(module => WebAssembly.instantiate(module, imports))
.then(instance => {
  var memory = new Uint8Array(instance.exports.memory.buffer);
  function readString(pointer) {
    var str = "";

    while(memory[pointer] != 0) {
      str += String.fromCharCode(memory[pointer]);
      pointer++;
    }

    return str;
  }

  var helloworld = instance.exports.main();
  alert(readString(helloworld));
});