const coords = [
  -11, 8, // 0
  -4, 33, // 16
  19, 31, // 32
  20, 23, // 48
]

// Reference implementation of triangle area
const triangleArea = (ax, ay, bx, by, cx, cy) => {
  return Math.abs((
    ax * (by - cy) +
    bx * (cy - ay) +
    cx * (ay - by)
  ) / 2);
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance.exports;

  // Load array into memory
  const len = coords.length;
  const byteOffset = 0;
  const memory = new Float64Array(instance.memory.buffer, byteOffset, len);
  for (let i = 0; i < len; i++) {
    memory[i] = coords[i];
  }
});
