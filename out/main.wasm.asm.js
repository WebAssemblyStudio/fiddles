function asmFunc(global, env, buffer) {
 "almost asm";
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
 var println = env.println;
 var i64toi32_i32$HIGH_BITS = 0;
 function getArrayOffset() {
  return 16 | 0;
 }
 
 function quickSort($0, $1, $2) {
  $0 = $0 | 0;
  $1 = $1 | 0;
  $2 = $2 | 0;
  var $3 = 0, $5 = 0, $4 = 0, $7 = 0, $6 = 0, $10 = 0, $8 = 0, $9 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0;
  if (($2 | 0) > ($1 | 0)) {
   $8 = $2 + 4294967295 | 0;
   label$2 : do {
    $0 = $1;
    label$3 : {
     if (($1 | 0) >= ($8 | 0)) break label$3;
     $5 = $8;
     $3 = $1;
     label$4 : do {
      $4 = ($5 << 2 | 0) + 16 | 0;
      $9 = ($3 << 2 | 0) + 16 | 0;
      $0 = $3 + 1 | 0;
      $10 = ($0 << 2 | 0) + 16 | 0;
      $6 = HEAPU32[$10 >> 2] | 0;
      label$5 : {
       label$6 : {
        label$7 : do {
         $7 = HEAPU32[$9 >> 2] | 0;
         if (($7 | 0) > ($6 | 0)) break label$6;
         $7 = HEAPU32[$4 >> 2] | 0;
         wasm2asm_i32$0 = $4;
         wasm2asm_i32$1 = $6;
         HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
         wasm2asm_i32$0 = $10;
         wasm2asm_i32$1 = $7;
         HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
         $4 = $4 + 4294967292 | 0;
         $6 = $7;
         $5 = $5 + 4294967295 | 0;
         if (($3 | 0) < ($5 | 0)) continue label$7;
         break label$7;
        } while (1);
        break label$5;
       };
       wasm2asm_i32$0 = $10;
       wasm2asm_i32$1 = $7;
       HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
       wasm2asm_i32$0 = $9;
       wasm2asm_i32$1 = $6;
       HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
       $3 = $0;
       if (($3 | 0) < ($5 | 0)) continue label$4;
       break label$3;
      };
      break label$4;
     } while (1);
     $0 = $3;
    };
    quickSort($4 | 0, $1 | 0, $0 | 0);
    $1 = $0 + 1 | 0;
    if (($1 | 0) < ($2 | 0)) continue label$2;
    break label$2;
   } while (1);
  }
 }
 
 function sort() {
  var $0 = 0;
  quickSort($0 | 0, 0 | 0, 10 | 0);
  println(16 | 0, 10 | 0);
 }
 
 function __wasm_grow_memory(pagesToAdd) {
  pagesToAdd = pagesToAdd | 0;
  var oldPages = __wasm_current_memory() | 0;
  var newPages = oldPages + pagesToAdd | 0;
  if ((oldPages < newPages) && (newPages < 65535)) {
   var newBuffer = new ArrayBuffer(Math_imul(newPages, 65536));
   var newHEAP8 = new global.Int8Array(newBuffer);
   newHEAP8.set(HEAP8);
   HEAP8 = newHEAP8;
   HEAP16 = new global.Int16Array(newBuffer);
   HEAP32 = new global.Int32Array(newBuffer);
   HEAPU8 = new global.Uint8Array(newBuffer);
   HEAPU16 = new global.Uint16Array(newBuffer);
   HEAPU32 = new global.Uint32Array(newBuffer);
   HEAPF32 = new global.Float32Array(newBuffer);
   HEAPF64 = new global.Float64Array(newBuffer);
   buffer = newBuffer;
  }
  return oldPages;
 }
 
 function __wasm_current_memory() {
  return buffer.byteLength / 65536 | 0;
 }
 
 return {
  memory: Object.create(Object.prototype, {
   grow: {
    value: __wasm_grow_memory
   }, 
   buffer: {
    get: function () {
     return buffer;
    }
    
   }
  }), 
  getArrayOffset: getArrayOffset, 
  quickSort: quickSort, 
  sort: sort
 };
}
