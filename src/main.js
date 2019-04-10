const utf8dec = new TextDecoder("utf-8");
const utf8enc = new TextEncoder("utf-8");

let memory = null;

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => {
  const environment = { };
  environment["console_log"] = console_log.bind(this);

  return WebAssembly.instantiate(bytes, { env: environment });
}).then(results => {
  instance = results.instance;
  memory = instance.exports.memory;

  instance.exports.main();
}).catch(console.error);


function console_log(message) {
  console.log( readString(message) );  
}

function readString(start) {
  const data = new Uint8Array(memory.buffer);
  const str = [];

  for(let i = start, b; (b = data[i]) != 0; i++) {
    str.push(b);
  }

  return utf8dec.decode(new Uint8Array(str));
}