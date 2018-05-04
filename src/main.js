fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  //document.getElementById("container").innerText = instance.exports.add_one(41);

  //(function loop() { requestAnimationFrame(loop); impulse(); })();
});

var gl;
function init()
{
  showStatus("init");

  var screen = document.getElementById("screen");
  gl = initWebGL(screen);
  if (gl)
  {
    showStatus("init GL");
    gl.clearColor(0.0, 0.0, 0.0, 1.0);
    gl.enable(gl.DEPTH_TEST);
    gl.depthFunc(gl.LEQUAL);
    glClear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
  }
  else
  {
    showStatus("init GL failed.");
  }
}

function impulse()
{
}

function showStatus(s)
{
  document.getElementById("status").innerText = s;
}