const { fact, fact_str } = wasm_bindgen;

function copyCStr(ptr) {
  let orig_ptr = ptr;
  const collectCString = function* () {
    let memory = new Uint8Array(wasm_bindgen.wasm.memory.buffer);
    while (memory[ptr] !== 0) {
      if (memory[ptr] === undefined) { throw new Error("Tried to read undef mem") }
      yield memory[ptr]
      ptr += 1
    }
  }

  const buffer_as_u8 = new Uint8Array(collectCString())
  const utf8Decoder = new TextDecoder("UTF-8");
  const buffer_as_utf8 = utf8Decoder.decode(buffer_as_u8);
  return buffer_as_utf8
}

function runApp() {
    var input = document.getElementById("input");
    var output = document.getElementById("output");
    var number_out = document.getElementById("number-out");
    function calcFact() {
      value = input.value | 0;
      number_out.innerText = "factorial(" + value + ") = ";
      if (value < 0) {
        output.innerText = "[Value too small.]"
        return;
      }

      let outptr = fact_str(value);
      let result = copyCStr(outptr);

      output.innerText = result;
    }
    calcFact()

    input.addEventListener("keyup", calcFact);
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
