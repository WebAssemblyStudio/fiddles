const memory = new WebAssembly.Memory({ initial: 1 });

const logger = (offset, length) => {
  const bytes = new Uint8Array(memory.buffer, offset, length);
  const string = new TextDecoder('utf8').decode(bytes);
  console.log(string);
  const para = document.createElement("P");  
  const text = document.createTextNode(string);
  para.appendChild(text);
  document.getElementById("container").appendChild(para);
}

const importObject = {
  console: { log: logger },
  js: { mem: memory },
};

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObject).then(obj => {
  obj.instance.exports.main();
});

// fetch('../out/main.wasm').then(response =>
//   response.arrayBuffer()
// ).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
//   instance = results.instance;
//   document.getElementById("container").textContent = instance.exports.add(1,1);
// }).catch(console.error);

