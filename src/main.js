const importObject = {
  env: {
    logResult(result) {
      console.log(result);
    },
  } 
};

function copyCStr(module, ptr) {
  let orig_ptr = ptr;
  function* collectCString() {
    let memory = new Uint8Array(module.memory.buffer);
    while (memory[ptr] !== 0) {
      if (memory[ptr] === undefined) { throw new Error("Tried to read undef mem") }
      yield memory[ptr]
      ptr += 1
    }
  }

  const buffer_as_u8 = new Uint8Array(collectCString())
  const utf8Decoder = new TextDecoder("UTF-8");
  const buffer_as_utf8 = utf8Decoder.decode(buffer_as_u8);
  module.dealloc_str(orig_ptr);
  return buffer_as_utf8
}

fetch('../out/main.wasm')
  .then(response => response.arrayBuffer())
  .then(bytes => WebAssembly.instantiate(bytes, importObject))
  .then(results => {
    const instance = results.instance;
    const module = instance.exports;

    /*
    Chapter 3
    const containerElement = document.getElementById("container");
    containerElement.textContent = module.multiple_two(41);
    */

    /*Chapter 4 */
    const pointer = module.getWelcomeMessage();
    const message = copyCStr(module, pointer);
    document.getElementById("container").textContent = message;

  })
  .catch(console.error);
