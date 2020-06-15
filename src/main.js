async function run() {
  let response = await fetch('../out/main.wasm');
  let bytes = await response.arrayBuffer();
  let module = await WebAssembly.instantiate(bytes, {
    env: {
      wasm_log(start,len) {
        const utf8dec = new TextDecoder("utf-8");
        let memory = new Uint8Array(module.instance.exports.memory.buffer);
        let text = utf8dec.decode(memory.subarray(start,start+len));
        document.getElementById("container").innerHTML += text+"<br>";
      }
    }
  });
  let num = module.instance.exports.main();
}

run();