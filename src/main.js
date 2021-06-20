WebAssembly.instantiateStreaming(
  fetch("../out/main.wasm"),
  { console }
);
