(async function () {
  const mem = new WebAssembly.Memory({ initial: 100 });
  mem.grow(32667);

  const obj = await WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), {
    env: {
      memory: mem
    }
  });
  try {
    const ret = obj.instance.exports.main(1);
    alert(new Uint8Array(mem.buffer).slice(0, 10).join(","));
    document.getElementById("container").textContent = ret;
  } catch (e) {
    alert(e);
  }

})()
