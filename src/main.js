fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  buffer   = new Int8Array(instance.exports.memory.buffer);
  document.getElementById("container").textContent = buffer_string(buffer, instance.exports.main());
}).catch(console.error);

function buffer_string(buffer, index)
{
  let s = "";

  while (buffer[index] != 0)
  {
    s += String.fromCharCode(buffer[index++]);
  }

  return s;
}