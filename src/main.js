var canvas = document.getElementById("canvas");
var gl = canvas.getContext("webgl");
alert(gl.createShader(gl.VERTEX_SHADER));

/*
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
/**/