//console.log('exports:',Object.keys(exports),exports);
exports.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(lib => {
  console.log(lib);
  document.getElementById("container").innerHTML =`<h3>Output</h3>
  <br/>Result: ${lib.add(19, 23)};
  <br/>encodeHex: ${lib.__getString(lib.encodeHex(new Uint8Array([100,200,1,2,3,4])))};
  <br/>encodeHex2: ${(lib.encodeHex2(new Uint8Array(100)))};
  <br/>Result: ${lib.add(22, 23)};
  `;
  const AS_ARRAY_OFFSET = 24;
  const u = new Uint8Array([100,200,0,33,33,33,99]);
  const _uPtr = lib.initU8Array(u.length);
  // const _u = new Uint8Array(
  //   lib.memory.buffer,
  //   _uPtr + AS_ARRAY_OFFSET,
  //   u.length
  // );
  const _u = lib.__getUint8Array(_uPtr);
  _u.set(u);
  const _doJobRes = lib.doJob(_uPtr);
  console.log(_u,_uPtr,_doJobRes,lib.__getString(_doJobRes));

  function encodeHex(binary:Uint8Array){
    const _uPtr = lib.initU8Array(u.length);
    const _u = lib.__getUint8Array(_uPtr);
    const _doJobRes = lib.doJob(_uPtr);
    return lib.__getString(_doJobRes);
  }

}).catch(console.error);
