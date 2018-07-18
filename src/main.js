fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  var h = new Uint8Array(instance.exports.memory.buffer);
  var p = instance.exports.allocMemory(20);
  fillMemory(h, p);
  document.getElementById("container").innerText = utf8ToString(h, p);
}).catch(console.error);


function fillMemory(h, p)
{
  let str = [72, 101, 108, 108, 111, 32, 87, 111, 114, 108, 100];
  for (i = p; i < (p + str.length); i++) {
    h[i] = str[i - p];
  }
}

function utf8ToString(h, p)
{
  let s = "";
  for (i = p; h[i]; i++) {
    s += String.fromCharCode(h[i]);
  }
  return s;
}