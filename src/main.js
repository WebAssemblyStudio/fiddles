// If you are not using a bundler add a <script> tag to your HTML
// Where the `src` points to the iife bundle (as-bind.iife.js), for example: https://unpkg.com/as-bind
// Then, INSTEAD of using the import syntax, do: `const { AsBind } = AsBindIIFE;`

const { AsBind } = AsBindIIFE;

const wasm = fetch("../out/main.wasm");

const asyncTask = async () => {
  const asBindInstance = await AsBind.instantiate(wasm);

  // You can now use your wasm / as-bind instance!
  const response = asBindInstance.exports.squiggle("ATGC", 4);
  console.log(response); // AsBind: Hello World!
};
asyncTask();