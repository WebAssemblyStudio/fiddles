

var tbl = new WebAssembly.Table({initial:2, element:"anyfunc"});

var importObj = {
  main: {
  },
  env: {
    table: tbl,
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
};


WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), importObj).then(result => {
  console.log(tbl.length);
  console.log(tbl.get(0)());
  console.log(tbl.get(1)());
}).catch(console.error);
