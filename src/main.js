var canvas = document.getElementById("canvas");
var gl = canvas.getContext("webgl");

var memory = new WebAssembly.Memory({initial: 1});
var array = new Uint8Array(memory.buffer);

function getString(pointer)
  var string = "";
  while (memory[pointer] != 0) {
    string += String.fromCharCode(memory[pointer]);
    pointer++;
  }

  return string;
}

var objects = new Map();
var next_index = 0;

/*
gl_viewport()
gl_clearColor()
gl_clear()
gl_useProgram()
gl_drawArrays()
*/

var imports = {
  gl_createShader: function(type) {
    objects.set(next_index, gl.createShader(type))
    return next_index++;
  },
  gl_shaderSource: function(shader, source) {
    gl.shaderSource(objects.get(shader), getString(source));
  },
  gl_compileShader: function(shader) {
    gl.compileShader(objects.get(shader));
  },
  gl_getShaderParameter: function(shader, parameter) {
    return Number(gl.compileShader(objects.get(shader), parameter));
  },
  gl_deleteShader: function(shader) {
    gl.deleteShader(objects.get(shader));
    objects.delete(shader);
  },
  gl_createProgram: function() {
    objects.set(next_index, gl.createProgram());
    return next_index++;
  },
  gl_attachShader: function(program, shader) {
    gl.attachShader(objects.get(program), objects.get(shader));
  },
  gl_linkProgram: function(program) {
    gl.linkProgram(objects.get(program));
  },
  gl_getProgramParameter: function(program, parameter) {
    return Number(gl.getProgramParameter(objects.get(program), parameter));
  },
  gl_deleteProgram: function(program) {
    gl.deleteShader(objects.get(program));
    objects.delete(program);
  },
  gl_getAttribLoction: function(program, attribute) {
    return Number(gl.getAttribLocation(objects.get(program), attribute));
  },
  gl_enableVertexAttribArray: function(attribute) {
    gl.enableVertexAttribArray(attribute);
  },
  gl_disableVertexAttribArray: function(attribute) {
    gl.disableVertexAttribArray(attribute);
  },
  gl_createBuffer: function() {
    objects.set(next_index, gl.createBuffer());
    return next_index;
  },
  gl_bindBuffer: function(target, buffer) {
    gl.bindBuffer(target, objects.get(buffer));
  }
  gl_bufferData
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