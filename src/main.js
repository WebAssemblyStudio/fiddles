fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = instance.exports.add_one(41);

  init();
  (function loop() { requestAnimationFrame(loop); impulse(); })();
});

function init()
{
  document.getElementById("container").innerText = "init";
}

function impulse()
{
  document.getElementById("containter").innerText = "impulse";
}

