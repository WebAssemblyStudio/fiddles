const importModule = async (path, options) => {
  const {instance:{exports}} = await WebAssembly.instantiateStreaming(fetch(path), options);
  return exports;
}
const main = {
  externallyDeclaredPassThrough(input) {
    console.log(`Passing ${input} through...`);
    return input;
  }
}
const env = {
  abort:(msg, file, line, column) => console.error(`abort called at main.ts: line: ${line}, column: ${column}`)
};
const init = async ()=>{
  const {add} = await importModule('../out/main.wasm', {main, env});
  document.getElementById('container').textContent = `Result: ${add(19, 23)}`;
}
init();




