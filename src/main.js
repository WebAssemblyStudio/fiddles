const importObject = {
    env: {
        logResult(result) {
            console.log(result);
        },
    }
}


// fetch('../out/main.wasm').then(response =>
//   response.arrayBuffer()
// ).then(bytes => WebAssembly.instantiate(bytes, importObject)).then(results => {
//   instance = results.instance;
//   document.getElementById("container").textContent = instance.exports.add_one(41);
//   const module = results.instance.exports;
//   let pointer = module.getWelcomeMessage();
//   let message = copyCStr(module, pointer);
//   document.getElementById("container").textContent = message;
  
// }).catch(console.error);
const { greet } = wasm_bindgen;

function showGreeting() {
  const greeting = greet('JSConf Asia');
  document.getElementById("container").textContent = greeting;
}

wasm_bindgen('../out/main.wasm')
  .then(showGreeting)
  .catch(console.error);



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

