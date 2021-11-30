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
 var putc_js = env.putc_js;
 var global$0 = 66608;
 var global$1 = 66608;
 var global$2 = 1059;
 var i64toi32_i32$HIGH_BITS = 0;
 function main() {
  var $0 = 0, i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, $1 = 0, i64toi32_i32$2 = 0, $2 = 0, $42 = 0, $3 = 0, $16 = 0, $19 = 0, $21 = 0, $23 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  $0 = global$0 - 96 | 0;
  global$0 = $0;
  wasm2asm_i32$0 = $0 + 82 | 0;
  wasm2asm_i32$1 = HEAPU8[1058 >> 0] | 0;
  HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
  wasm2asm_i32$0 = $0 + 80 | 0;
  wasm2asm_i32$1 = HEAPU16[1056 >> 1] | 0;
  HEAP16[wasm2asm_i32$0 >> 1] = wasm2asm_i32$1;
  i64toi32_i32$2 = 1048;
  i64toi32_i32$0 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
  i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
  $16 = i64toi32_i32$0;
  i64toi32_i32$0 = $0 + 72 | 0;
  i64toi32_i32$1 = i64toi32_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = $16;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = i64toi32_i32$1;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  i64toi32_i32$2 = 1040;
  i64toi32_i32$1 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
  i64toi32_i32$0 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
  $19 = i64toi32_i32$1;
  i64toi32_i32$1 = $0 - 4294967232 | 0;
  i64toi32_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = $19;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = i64toi32_i32$0;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  i64toi32_i32$2 = 1032;
  i64toi32_i32$0 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
  i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
  $21 = i64toi32_i32$0;
  i64toi32_i32$0 = $0;
  i64toi32_i32$1 = i64toi32_i32$1;
  wasm2asm_i32$0 = $0;
  wasm2asm_i32$1 = $21;
  HEAP32[(wasm2asm_i32$0 + 56 | 0) >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = $0;
  wasm2asm_i32$1 = i64toi32_i32$1;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 60 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 61 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 62 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 63 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  i64toi32_i32$2 = 1024;
  i64toi32_i32$1 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
  i64toi32_i32$0 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
  $23 = i64toi32_i32$1;
  i64toi32_i32$1 = $0;
  i64toi32_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$0 = $0;
  wasm2asm_i32$1 = $23;
  HEAP32[(wasm2asm_i32$0 + 48 | 0) >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = $0;
  wasm2asm_i32$1 = i64toi32_i32$0;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 52 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 53 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 54 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 55 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  label$1 : {
   __stpncpy($0 | 0, $0 + 48 | 0 | 0, 39 | 0) | 0;
   $3 = $0;
   $1 = HEAPU8[$0 >> 0] | 0;
   if (($1 | 0) == (0 | 0)) break label$1;
   $2 = $3;
   label$2 : do {
    label$3 : {
     label$4 : {
      label$5 : {
       if ((($1 + 4294967199 | 0) & 255 | 0) >>> 0 < 26 >>> 0) {
        $42 = 243;
        if ((($1 << 24 | 0) >> 24 | 0 | 0) > (109 | 0)) break label$4;
        break label$5;
       }
       if ((($1 + 4294967231 | 0) & 255 | 0) >>> 0 >= 26 >>> 0) break label$3;
       $42 = 243;
       if ((($1 << 24 | 0) >> 24 | 0 | 0) > (77 | 0)) break label$4;
      };
      $42 = 13;
     };
     wasm2asm_i32$0 = $2;
     wasm2asm_i32$1 = $1 + $42 | 0;
     HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
    };
    $1 = HEAPU8[($2 + 1 | 0) >> 0] | 0;
    $2 = $2 + 1 | 0;
    if ($1) continue label$2;
    break label$2;
   } while (1);
   $1 = HEAPU8[$3 >> 0] | 0;
   if (($1 | 0) == (0 | 0)) break label$1;
   $2 = $0 | 1 | 0;
   label$7 : do {
    putc_js(($1 << 24 | 0) >> 24 | 0 | 0);
    $1 = HEAPU8[$2 >> 0] | 0;
    $2 = $2 + 1 | 0;
    if ($1) continue label$7;
    break label$7;
   } while (1);
  };
  putc_js(10 | 0);
  global$0 = $0 + 96 | 0;
  return 0 | 0;
 }
 
 function memset($0, $1, $2) {
  $0 = $0 | 0;
  $1 = $1 | 0;
  $2 = $2 | 0;
  var i64toi32_i32$2 = 0, i64toi32_i32$0 = 0, $3 = 0, $4 = 0, $5 = 0, i64toi32_i32$1 = 0, $5$hi = 0, i64toi32_i32$4 = 0, i64toi32_i32$3 = 0, $14 = 0, $92 = 0, $103$hi = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  label$1 : {
   if (($2 | 0) == (0 | 0)) break label$1;
   wasm2asm_i32$0 = $0;
   wasm2asm_i32$1 = $1;
   HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
   $3 = $0 + $2 | 0;
   wasm2asm_i32$0 = $3 + 4294967295 | 0;
   wasm2asm_i32$1 = $1;
   HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
   if ($2 >>> 0 < 3 >>> 0) break label$1;
   wasm2asm_i32$0 = $0;
   wasm2asm_i32$1 = $1;
   HEAP8[(wasm2asm_i32$0 + 2 | 0) >> 0] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0;
   wasm2asm_i32$1 = $1;
   HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $3 + 4294967293 | 0;
   wasm2asm_i32$1 = $1;
   HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $3 + 4294967294 | 0;
   wasm2asm_i32$1 = $1;
   HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
   if ($2 >>> 0 < 7 >>> 0) break label$1;
   wasm2asm_i32$0 = $0;
   wasm2asm_i32$1 = $1;
   HEAP8[(wasm2asm_i32$0 + 3 | 0) >> 0] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $3 + 4294967292 | 0;
   wasm2asm_i32$1 = $1;
   HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
   if ($2 >>> 0 < 9 >>> 0) break label$1;
   $4 = (0 - $0 | 0) & 3 | 0;
   $3 = $0 + $4 | 0;
   $1 = Math_imul($1 & 255 | 0, 16843009);
   wasm2asm_i32$0 = $3;
   wasm2asm_i32$1 = $1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   $4 = ($2 - $4 | 0) & 4294967292 | 0;
   $2 = $3 + $4 | 0;
   wasm2asm_i32$0 = $2 + 4294967292 | 0;
   wasm2asm_i32$1 = $1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   if ($4 >>> 0 < 9 >>> 0) break label$1;
   wasm2asm_i32$0 = $3;
   wasm2asm_i32$1 = $1;
   HEAP32[(wasm2asm_i32$0 + 8 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $3;
   wasm2asm_i32$1 = $1;
   HEAP32[(wasm2asm_i32$0 + 4 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $2 + 4294967288 | 0;
   wasm2asm_i32$1 = $1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $2 + 4294967284 | 0;
   wasm2asm_i32$1 = $1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   if ($4 >>> 0 < 25 >>> 0) break label$1;
   wasm2asm_i32$0 = $3;
   wasm2asm_i32$1 = $1;
   HEAP32[(wasm2asm_i32$0 + 16 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $3;
   wasm2asm_i32$1 = $1;
   HEAP32[(wasm2asm_i32$0 + 12 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $3;
   wasm2asm_i32$1 = $1;
   HEAP32[(wasm2asm_i32$0 + 20 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $3;
   wasm2asm_i32$1 = $1;
   HEAP32[(wasm2asm_i32$0 + 24 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $2 + 4294967272 | 0;
   wasm2asm_i32$1 = $1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $2 + 4294967268 | 0;
   wasm2asm_i32$1 = $1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $2 + 4294967276 | 0;
   wasm2asm_i32$1 = $1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $2 + 4294967280 | 0;
   wasm2asm_i32$1 = $1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   $92 = $4;
   $4 = $3 & 4 | 0 | 24 | 0;
   $2 = $92 - $4 | 0;
   if ($2 >>> 0 < 32 >>> 0) break label$1;
   i64toi32_i32$0 = 0;
   i64toi32_i32$0 = i64toi32_i32$0;
   $5 = $1;
   $5$hi = i64toi32_i32$0;
   i64toi32_i32$0 = i64toi32_i32$0;
   i64toi32_i32$0 = i64toi32_i32$0;
   i64toi32_i32$2 = $1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$3 = 32;
   i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
    $14 = 0;
   } else {
    i64toi32_i32$1 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$4 | 0) | 0;
    $14 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
   }
   $103$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $5$hi;
   i64toi32_i32$1 = $103$hi;
   i64toi32_i32$0 = $14;
   i64toi32_i32$2 = $5$hi;
   i64toi32_i32$3 = $5;
   i64toi32_i32$2 = i64toi32_i32$1 | i64toi32_i32$2 | 0;
   i64toi32_i32$2 = i64toi32_i32$2;
   $5 = i64toi32_i32$0 | $5 | 0;
   $5$hi = i64toi32_i32$2;
   $1 = $3 + $4 | 0;
   label$2 : do {
    i64toi32_i32$2 = $5$hi;
    i64toi32_i32$0 = $1;
    i64toi32_i32$2 = i64toi32_i32$2;
    wasm2asm_i32$0 = $1;
    wasm2asm_i32$1 = $5;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    wasm2asm_i32$0 = $1;
    wasm2asm_i32$1 = i64toi32_i32$2;
    (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    i64toi32_i32$0 = $1 + 8 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    wasm2asm_i32$0 = i64toi32_i32$0;
    wasm2asm_i32$1 = $5;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    wasm2asm_i32$0 = i64toi32_i32$0;
    wasm2asm_i32$1 = i64toi32_i32$2;
    (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    i64toi32_i32$0 = $1 + 16 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    wasm2asm_i32$0 = i64toi32_i32$0;
    wasm2asm_i32$1 = $5;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    wasm2asm_i32$0 = i64toi32_i32$0;
    wasm2asm_i32$1 = i64toi32_i32$2;
    (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    i64toi32_i32$0 = $1 + 24 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    wasm2asm_i32$0 = i64toi32_i32$0;
    wasm2asm_i32$1 = $5;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    wasm2asm_i32$0 = i64toi32_i32$0;
    wasm2asm_i32$1 = i64toi32_i32$2;
    (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
    $1 = $1 + 32 | 0;
    $2 = $2 + 4294967264 | 0;
    if ($2 >>> 0 > 31 >>> 0) continue label$2;
    break label$2;
   } while (1);
  };
  return $0 | 0;
 }
 
 function __stpncpy($0, $1, $2) {
  $0 = $0 | 0;
  $1 = $1 | 0;
  $2 = $2 | 0;
  var $3 = 0, $4 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0;
  label$1 : {
   label$2 : {
    if (($1 ^ $0 | 0) & 3 | 0) {
     $3 = $2;
     break label$2;
    }
    $4 = ($2 | 0) != (0 | 0);
    label$4 : {
     label$5 : {
      if ((($2 | 0) == (0 | 0) | ($1 & 3 | 0 | 0) == (0 | 0) | 0 | 0) == (0 | 0)) {
       label$7 : do {
        $3 = HEAPU8[$1 >> 0] | 0;
        wasm2asm_i32$0 = $0;
        wasm2asm_i32$1 = $3;
        HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
        if (($3 | 0) == (0 | 0)) break label$1;
        $4 = ($2 | 0) != (1 | 0);
        $0 = $0 + 1 | 0;
        $3 = $2 + 4294967295 | 0;
        $1 = $1 + 1 | 0;
        if (($2 | 0) != (1 | 0)) {
         $2 = $3;
         if ($1 & 3 | 0) continue label$7;
        }
        break label$7;
       } while (1);
       if (($4 | 0) == (0 | 0)) break label$5;
       break label$4;
      }
      $3 = $2;
      if ($4) break label$4;
     };
     return memset($0 | 0, 0 | 0, 0 | 0) | 0 | 0;
    };
    if (HEAPU8[$1 >> 0] | 0) {
     if ($3 >>> 0 < 4 >>> 0) break label$2;
     label$10 : do {
      $2 = HEAPU32[$1 >> 2] | 0;
      if ((($2 ^ 4294967295 | 0) & ($2 + 4278124287 | 0) | 0) & 2155905152 | 0) break label$2;
      wasm2asm_i32$0 = $0;
      wasm2asm_i32$1 = $2;
      HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
      $0 = $0 + 4 | 0;
      $1 = $1 + 4 | 0;
      $3 = $3 + 4294967292 | 0;
      if ($3 >>> 0 > 3 >>> 0) continue label$10;
      break label$10;
     } while (1);
     break label$2;
    }
    return memset($0 | 0, 0 | 0, $3 | 0) | 0 | 0;
   };
   $2 = 0;
   if (($3 | 0) == (0 | 0)) break label$1;
   label$11 : {
    label$12 : do {
     $4 = HEAPU8[$1 >> 0] | 0;
     wasm2asm_i32$0 = $0;
     wasm2asm_i32$1 = $4;
     HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
     if (($4 | 0) == (0 | 0)) break label$11;
     $0 = $0 + 1 | 0;
     $1 = $1 + 1 | 0;
     $3 = $3 + 4294967295 | 0;
     if ($3) continue label$12;
     break label$12;
    } while (1);
    break label$1;
   };
   $2 = $3;
  };
  return memset($0 | 0, 0 | 0, $2 | 0) | 0 | 0;
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
  main: main
 };
}
