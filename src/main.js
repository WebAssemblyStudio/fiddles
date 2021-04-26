fetch("../out/main.wasm")
  .then((response) => response.arrayBuffer())
  .then((bytes) =>
    WebAssembly.instantiate(bytes, {
      env: {
        __syscall1: (...args) => console.log('Called __syscall1', args),
        __syscall2: (...args) => console.log('Called __syscall2', args),
        __syscall3: (...args) => console.log('Called __syscall3', args),
        __syscall4: (...args) => console.log('Called __syscall4', args),
        __syscall5: (...args) => console.log('Called __syscall5', args),
        __syscall6: (...args) => console.log('Called __syscall6', args),
      },
    })
  )
  .then(({ instance }) => {
      const result = instance.exports.vec2(10.65, 0.5);
      console.log({ result });
  })
  .catch(console.error);
