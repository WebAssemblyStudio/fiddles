fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
  //document.getElementById("container2").textContent = String.fromCharCode(instance.exports.hello());
  document.getElementById("container3").textContent = instance.exports.bignumber(1024.10);

  const buffer = new Uint8Array(instance.exports.memory.buffer);
  const pointer = instance.exports.hello();
  let string = "";

  for (let i = pointer; buffer[i]; i++) {
    string += String.fromCharCode(buffer[i]);
  }

  document.getElementById("container2").textContent = string;


}).catch(console.error);
