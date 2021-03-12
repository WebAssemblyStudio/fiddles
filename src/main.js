const docappend = (id, content) => {
  const prevContent = document.getElementById(id).textContent;
  document.getElementById(id).textContent = `${prevContent}\n${content}`;
}
const runWasm = async (name, importObject = {}) => {
  const bytes = await fetch(`../out/${name}.wasm`).then(response => response.arrayBuffer())
  const { instance } = await WebAssembly.instantiate(bytes, importObject);
  docappend(name, instance.exports.main())
}

runWasm("main");

const mem = new WebAssembly.Memory({ initial: 2 });
function log(offset, length) {
  const bytes = new Uint8Array(mem.buffer, offset, length);
  const string = new TextDecoder('utf8').decode(bytes);
  docappend("memory", string)
}
runWasm("memory", { console: { log }, js: { mem } });