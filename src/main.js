
const types = {
  "-1": "Unknown",
  "0":  "Null",
  "1":  "Reference",
  "2":  "String",
  "3":  "Array",

  "4":  "I8",
  "5":  "I16",
  "6":  "I32",
  "7":  "I64",

  "8":  "U8",
  "9":  "U16",
  "10": "U32",
  "11": "U64",

  "12": "F32",
  "13": "F64"
};

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    log: function(value) {
      console.log("type: " + types[value + ""]);
    },
    abort: function(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  }
}).then(result => {
}).catch(console.error);

