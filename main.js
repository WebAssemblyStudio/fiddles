function copyCStr(module, ptr) {
  let orig_ptr = ptr;
  const collectCString = function* () {
    let memory = new Uint8Array(module.memory.buffer);
    while (memory[ptr] !== 0) {
      if (memory[ptr] === undefined) { throw new Error("Tried to read undef mem") }
      yield memory[ptr]
      ptr += 1
    }
  }

  const buffer_as_u8 = new Uint8Array(collectCString())
  return buffer_as_utf8
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer();
).then(bytes => WebAssembly.instantiate(bytes,
  {
  env: {
    alert: function(ptr, number) {
      let str = copyCStr(Module, ptr);
      console.log(str);
    }
  }
)).then(results => {
  let mod = results.instance;
  Module.memory      = mod.exports.memory;
  Module.run         = mod.exports.run;
  Module.run();
});