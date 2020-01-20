(async () => {
  const codePromise = fetch('../out/main.wasm');
  const { instance } = await WebAssembly.instantiateStreaming(codePromise);

  const buffer = new Uint8Array(instance.exports.memory.buffer);

  const pointer  = instance.exports.helloWorld();

  let string = "";

  for(let i = pointer; buffer[i]; i++) {
    string += String.fromCharCode(buffer[i])
  }
  // let jsonString = JSON.parse("'"+string+"'");
  console.log(typeof string);
  // document.getElementById("container").textContent = JSON.parse(string);
})()