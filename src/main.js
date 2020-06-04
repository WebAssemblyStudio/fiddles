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

  const utf8dec = new TextDecoder("utf-8");
  const utf8enc = new TextEncoder("utf-8");
  let text = "Ferris";
  let text_bytes = utf8enc.encode(text);
  let len = text_bytes.length;
  let start = module.instance.exports.wasm_malloc(len);
  let memory = new Uint8Array(module.instance.exports.memory.buffer);
  memory.set(text_bytes, start);
  module.instance.exports.main(start,len);
}

run();