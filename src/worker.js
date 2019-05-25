const PAGE_SIZE = 64 * 1024;

const mem = new WebAssembly.Memory({ initial: 100 });
mem.grow(32667);

onmessage = async function (e) {


  const obj = await WebAssembly.instantiate(e.data.module, {
    env: {
      memory: mem
    }
  });

  for (let i = 0, len = (mem.buffer.byteLength / PAGE_SIZE); i < len; i++) {
      try {
        for (let j = 0; j < PAGE_SIZE; j += 4) {
          obj.exports.main(i*PAGE_SIZE + j);
        }
        postMessage({ message: `${i} page written` });
      } catch (e) {
        console.log(e, i);
        break;
      }
  }
};