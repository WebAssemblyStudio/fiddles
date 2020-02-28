 fetch('../out/main.wasm').then(response =>
   response.arrayBuffer()
 ).then((buffer) => {
   doWork(buffer);
 }).catch(console.error);

async function doWork(buffer){
  const module = await WebAssembly.compile(buffer);
  const instance = await WebAssembly.instantiate(module);

  // obtain the module memory
  const linearMemory = instance.exports.memory;

  // create a buffer starting at the reference to the exported string
  const offset = instance.exports.get_hello();
  const stringBuffer = new Uint8Array(linearMemory.buffer, offset, instance.exports.get_hello_len());

  // create a string from this buffer
  let str = '';
  for (let i=0; i<stringBuffer.length; i++) {
    str += String.fromCharCode(stringBuffer[i]);
  }

  console.log(str);
}