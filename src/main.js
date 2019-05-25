
function wait(n) {
	return new Promise( (resolve) => setTimeout(resolve, n));
}

const PAGE_SIZE = 64 * 1024;

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
    const output = document.getElementById("container");

    for (let i = 0, len = (mem.buffer.byteLength / PAGE_SIZE); i < len; i++) {
      		try {
            for (let j = 0; j < PAGE_SIZE; j++) {
              obj.instance.exports.main(i*PAGE_SIZE + j);
            }
            output.textContent = `${i} page written`;
            await wait(0);
          } catch (e) {
            console.log(e, i);
            break;
          }
    }
  } catch (e) {
    alert(e);
  }

})()
