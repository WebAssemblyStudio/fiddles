const {
  Int32Array,
  WebAssembly: { instantiateStreaming },
  document: { body },
  console
} = globalThis;

(async () => { 
  const module = (await instantiateStreaming(fetch('../out/main.wasm'))).instance.exports;

  const { buffer } = module.memory;

  const length = 4;
  const arbitraryOffset0 = 100;
  const arbitraryOffset1 = 200;
  const a = new Int32Array(buffer, arbitraryOffset0, length);
  const b = new Int32Array(buffer, arbitraryOffset1, length);

  a.set([ 6, 2, 3, 10 ]);
  b.set([ 3, 2, 3, 20 ]);

  const outputArrayOffset = module.subtractArrays(a.byteOffset, b.byteOffset);

  const outputArray = new Int32Array(buffer, outputArrayOffset, length);

  const container = body.querySelector("#container");

  container.textContent = outputArray;
})().catch(console.error);