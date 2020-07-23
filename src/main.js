//(async () => {
(async function test() {
  const response = await fetch('../out/main.wasm');
  const buffer = await response.arrayBuffer();
  const module = await WebAssembly.compile(buffer);
  const instance = await WebAssembly.instantiate(module);
  const result = instance.exports.sumNumber(1,6);
  console.log(result);
})();
//test();
//})();