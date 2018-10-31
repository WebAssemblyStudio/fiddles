canvas = document.getElementById("container"); 

async function loadKolmoblock() {
    const response = await fetch('../out/main.wasm');
    const buffer = await response.arrayBuffer();
    const module = await WebAssembly.compile(buffer);
    const instance = new WebAssembly.Instance(module);
    return instance.exports;
}

loadKolmoblock().then(mm => {
  const memory = mm.memory;
  const offset = mm.getStrOffset();
  const strBuf = new Uint8Array(memory.buffer, offset, 100);
  const str = new TextDecoder().decode(strBuf);
  canvas.textContent = strBuf;
});
