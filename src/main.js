"use strict";

const SIZE = 1e8;

let alloc = null;
let retain = null;
let memory = null;
let Float64Array_ID = 0;

function js_sum(arr) {
  let sum = 0.0;
  for(let i = 0; i < arr.length; i++) {
    sum += arr[i];
  }
  return sum;
}

function js_reduce(arr) {
  return arr.reduce((a, b) => a + b, 0.0);
}

function __allocFloat64Array(values) {
  // simplified version of https://github.com/AssemblyScript/assemblyscript/blob/master/lib/loader/index.js#L164
  const length = values.length;
  const buf = alloc(length << 3, 0);
  const arr = alloc(12, Float64Array_ID);
  const buffer = memory.buffer;
  const U32 = new Uint32Array(buffer);
  U32[arr + 0 >>> 2] = retain(buf);
  U32[arr + 4 >>> 2] = buf;
  U32[arr + 8 >>> 2] = length << 3;
  new Float64Array(buffer).set(values, buf >>> 3);
  return arr;
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  let arr = Float64Array.from({ length: SIZE }, _ => Math.random());

  alloc = exports.__alloc;
  retain = exports.__retain;
  memory = exports.memory;
  Float64Array_ID = exports.Float64Array_ID;

  let res
  const arrPtr = __allocFloat64Array(arr);


  // warmup sum
  js_sum(arr);
  // measure 'js sum'
  console.time('js sum');
  res = js_sum(arr);
  console.timeEnd('js sum');
  console.log('js sum result = ' + res);
  console.log('\n');

  // warmup reduce
  js_reduce(arr);
  // measure 'js reduce'
  console.time('js reduce');
  res = js_reduce(arr);
  console.timeEnd('js reduce');
  console.log('js reduce result = ' + res);
  console.log('\n');

  // warmup sum
  exports.sum(arrPtr);
  // measure 'wasm sum'
  console.time('wasm sum');
  res = exports.sum(arrPtr);
  console.timeEnd('wasm sum');
  console.log('wasm sum result = ' + res);
  console.log('\n');

  // warmup reduce
  exports.reduce(arrPtr);
  // measure 'wasm reduce'
  console.time('wasm reduce');
  res = exports.reduce(arrPtr);
  console.timeEnd('wasm reduce');
  console.log('wasm reduce result = ' + res);
  console.log('\n');

  // warmup empty
  exports.emptyFunc(arrPtr);
  // measure 'wasm empty'
  console.time('wasm empty');
  exports.emptyFunc(arrPtr);
  console.timeEnd('wasm empty');

}).catch(console.error);
