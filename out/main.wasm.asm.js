function asmFunc(global, env, buffer) {
 "use asm";
 var HEAP8 = new global.Int8Array(buffer);
 var HEAP16 = new global.Int16Array(buffer);
 var HEAP32 = new global.Int32Array(buffer);
 var HEAPU8 = new global.Uint8Array(buffer);
 var HEAPU16 = new global.Uint16Array(buffer);
 var HEAPU32 = new global.Uint32Array(buffer);
 var HEAPF32 = new global.Float32Array(buffer);
 var HEAPF64 = new global.Float64Array(buffer);
 var Math_imul = global.Math.imul;
 var Math_fround = global.Math.fround;
 var Math_abs = global.Math.abs;
 var Math_clz32 = global.Math.clz32;
 var Math_min = global.Math.min;
 var Math_max = global.Math.max;
 var Math_floor = global.Math.floor;
 var Math_ceil = global.Math.ceil;
 var Math_sqrt = global.Math.sqrt;
 var abort = env.abort;
 var nan = global.NaN;
 var infinity = global.Infinity;
 var i64toi32_i32$HIGH_BITS = 0;
 function add($0, $1) {
  $0 = $0 | 0;
  $1 = $1 | 0;
  return $0 << $1 | 0 | 0;
 }
 
 function something($0, $1, $2) {
  $0 = +$0;
  $1 = +$1;
  $2 = +$2;
  return +($0 + $1 + $2);
 }
 
 function slope($0, $1, $2, $3) {
  $0 = +$0;
  $1 = +$1;
  $2 = +$2;
  $3 = +$3;
  return +(($3 - $1) / ($2 - $0));
 }
 
 function max($0, $1) {
  $0 = +$0;
  $1 = +$1;
  var wasm2asm_f64$0 = 0.0, wasm2asm_f64$1 = 0.0, wasm2asm_i32$0 = 0;
  return +(wasm2asm_f64$0 = $0, wasm2asm_f64$1 = $1, wasm2asm_i32$0 = $0 > $1, wasm2asm_i32$0 ? wasm2asm_f64$0 : wasm2asm_f64$1);
 }
 
 return {
  add: add, 
  something: something, 
  slope: slope, 
  max: max
 };
}
