console.clear();

// Customize according to expectations
const INITIAL_REF_TABLE_SIZE = 100;

const ref_table = new WebAssembly.Table({
  element: 'anyref',
  initial: INITIAL_REF_TABLE_SIZE
});

const ref_table_size = new WebAssembly.Global({ value: 'i32', mutable: true }, INITIAL_REF_TABLE_SIZE);

const { call } = Function.prototype;
const tablePrototype = WebAssembly.Table.prototype;
// AssemblyScript does not yet expose the native reference types table
// instructions and it couldn't yet because Binaryen doesn't either yet.
const table_get = call.bind(tablePrototype.get);
const table_set = call.bind(tablePrototype.set);
const table_grow = call.bind(tablePrototype.grow);

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  console: {
    log: console.log
  },
  main: {
    null_ref: null,
    ref_table,
    ref_table_size,
    table_get,
    table_set,
    table_grow,
    log(value) {
      console.warn(value);
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(({ instance }) => {
  const exports = instance.exports;
  const result = exports.test('hello anyref');
  document.getElementById("container").textContent = "Result: " + result;
}).catch(console.error);
