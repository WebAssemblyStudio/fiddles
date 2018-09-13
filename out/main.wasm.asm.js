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
 var fimport$0 = env.putc_js;
 var fimport$1 = env.__syscall1;
 var fimport$2 = env.__syscall3;
 var fimport$3 = env.__syscall5;
 var global$0 = 70208;
 var global$1 = 70208;
 var global$2 = 4664;
 var i64toi32_i32$HIGH_BITS = 0;
 function $0() {
  var $0_1 = 0, $1_1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0;
  $0_1 = global$0 - 160 | 0;
  global$0 = $0_1;
  label$1 : do {
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 148 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = 0;
   HEAP32[(wasm2asm_i32$0 + 144 | 0) >> 2] = wasm2asm_i32$1;
   $2(1024 | 0, $0_1 + 144 | 0 | 0) | 0;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 132 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = 1;
   HEAP32[(wasm2asm_i32$0 + 128 | 0) >> 2] = wasm2asm_i32$1;
   $2(1024 | 0, $0_1 + 128 | 0 | 0) | 0;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 116 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = 2;
   HEAP32[(wasm2asm_i32$0 + 112 | 0) >> 2] = wasm2asm_i32$1;
   $2(1024 | 0, $0_1 + 112 | 0 | 0) | 0;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 100 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = 3;
   HEAP32[(wasm2asm_i32$0 + 96 | 0) >> 2] = wasm2asm_i32$1;
   $2(1024 | 0, $0_1 + 96 | 0 | 0) | 0;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 84 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = 4;
   HEAP32[(wasm2asm_i32$0 + 80 | 0) >> 2] = wasm2asm_i32$1;
   $2(1024 | 0, $0_1 + 80 | 0 | 0) | 0;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 68 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = 5;
   HEAP32[(wasm2asm_i32$0 + 64 | 0) >> 2] = wasm2asm_i32$1;
   $2(1024 | 0, $0_1 - 4294967232 | 0 | 0) | 0;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 52 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = 6;
   HEAP32[(wasm2asm_i32$0 + 48 | 0) >> 2] = wasm2asm_i32$1;
   $2(1024 | 0, $0_1 + 48 | 0 | 0) | 0;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 36 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = 7;
   HEAP32[(wasm2asm_i32$0 + 32 | 0) >> 2] = wasm2asm_i32$1;
   $2(1024 | 0, $0_1 + 32 | 0 | 0) | 0;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 20 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = 8;
   HEAP32[(wasm2asm_i32$0 + 16 | 0) >> 2] = wasm2asm_i32$1;
   $2(1024 | 0, $0_1 + 16 | 0 | 0) | 0;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 4 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = 9;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   $2(1024 | 0, $0_1 | 0) | 0;
   $1_1 = $1_1 + 1 | 0;
   if (($1_1 | 0) != (10 | 0)) continue label$1;
   break label$1;
  } while (1);
  global$0 = $0_1 + 160 | 0;
  return 0 | 0;
 }
 
 function $1($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var $3_1 = 0, $4_1 = 0, $5_1 = 0, $6_1 = 0, $7_1 = 0;
  if (($2_1 | 0) >= (1 | 0)) {
   $0_1 = 0;
   label$2 : do {
    $4_1 = 0;
    $5_1 = $1_1 + ($0_1 << 3 | 0) | 0;
    if (HEAPU32[($5_1 + 4 | 0) >> 2] | 0) {
     $7_1 = $5_1 + 4 | 0;
     $3_1 = 0;
     label$4 : do {
      fimport$0(HEAP8[((HEAPU32[$5_1 >> 2] | 0) + $3_1 | 0) >> 0] | 0 | 0);
      $3_1 = $3_1 + 1 | 0;
      $4_1 = HEAPU32[$7_1 >> 2] | 0;
      if ($3_1 >>> 0 < $4_1 >>> 0) continue label$4;
      break label$4;
     } while (1);
    }
    $6_1 = $4_1 + $6_1 | 0;
    $0_1 = $0_1 + 1 | 0;
    if (($0_1 | 0) != ($2_1 | 0)) continue label$2;
    break label$2;
   } while (1);
   return $6_1 | 0;
  }
  return 0 | 0;
 }
 
 function $2($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  var $2_1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0;
  $2_1 = global$0 - 16 | 0;
  global$0 = $2_1;
  wasm2asm_i32$0 = $2_1;
  wasm2asm_i32$1 = $1_1;
  HEAP32[(wasm2asm_i32$0 + 12 | 0) >> 2] = wasm2asm_i32$1;
  $1_1 = $17(HEAPU32[1032 >> 2] | 0 | 0, $0_1 | 0, $1_1 | 0) | 0;
  global$0 = $2_1 + 16 | 0;
  return $1_1 | 0;
 }
 
 function $3($0_1) {
  $0_1 = $0_1 | 0;
  var wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0;
  if ($0_1 >>> 0 >= 4294963201 >>> 0) {
   wasm2asm_i32$0 = 31;
   wasm2asm_i32$1 = 0 - $0_1 | 0;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   $0_1 = 4294967295;
  }
  return $0_1 | 0;
 }
 
 function $4($0_1) {
  $0_1 = $0_1 | 0;
  return $3(fimport$1(6 | 0, HEAPU32[($0_1 + 60 | 0) >> 2] | 0 | 0) | 0 | 0) | 0 | 0;
 }
 
 function $5($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var $4_1 = 0, $3_1 = 0, $8_1 = 0, $5_1 = 0, $6_1 = 0, $7_1 = 0, $9_1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  $3_1 = global$0 - 16 | 0;
  global$0 = $3_1;
  wasm2asm_i32$0 = $3_1;
  wasm2asm_i32$1 = $1_1;
  HEAP32[(wasm2asm_i32$0 + 8 | 0) >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = $3_1;
  wasm2asm_i32$1 = $2_1;
  HEAP32[(wasm2asm_i32$0 + 12 | 0) >> 2] = wasm2asm_i32$1;
  $1_1 = HEAPU32[($0_1 + 28 | 0) >> 2] | 0;
  wasm2asm_i32$0 = $3_1;
  wasm2asm_i32$1 = $1_1;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  $1_1 = (HEAPU32[($0_1 + 20 | 0) >> 2] | 0) - $1_1 | 0;
  wasm2asm_i32$0 = $3_1;
  wasm2asm_i32$1 = $1_1;
  HEAP32[(wasm2asm_i32$0 + 4 | 0) >> 2] = wasm2asm_i32$1;
  $6_1 = 2;
  label$1 : {
   label$2 : {
    $7_1 = $1_1 + $2_1 | 0;
    $4_1 = $3(fimport$2(146 | 0, HEAPU32[($0_1 + 60 | 0) >> 2] | 0 | 0, $3_1 | 0, 2 | 0) | 0 | 0) | 0;
    if (($7_1 | 0) != ($4_1 | 0)) {
     $1_1 = $3_1;
     $9_1 = $0_1 + 60 | 0;
     label$4 : do {
      if (($4_1 | 0) <= (4294967295 | 0)) break label$2;
      $8_1 = HEAPU32[($1_1 + 4 | 0) >> 2] | 0;
      $5_1 = $4_1 >>> 0 > $8_1 >>> 0;
      $1_1 = (wasm2asm_i32$0 = $1_1 + 8 | 0, wasm2asm_i32$1 = $1_1, wasm2asm_i32$2 = $5_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
      $8_1 = $4_1 - (wasm2asm_i32$0 = $8_1, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = $5_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0;
      wasm2asm_i32$0 = $1_1;
      wasm2asm_i32$1 = (HEAPU32[$1_1 >> 2] | 0) + $8_1 | 0;
      HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
      wasm2asm_i32$0 = $1_1;
      wasm2asm_i32$1 = (HEAPU32[($1_1 + 4 | 0) >> 2] | 0) - $8_1 | 0;
      HEAP32[(wasm2asm_i32$0 + 4 | 0) >> 2] = wasm2asm_i32$1;
      $7_1 = $7_1 - $4_1 | 0;
      $6_1 = $6_1 - $5_1 | 0;
      $5_1 = $3(fimport$2(146 | 0, HEAPU32[$9_1 >> 2] | 0 | 0, $1_1 | 0, $6_1 | 0) | 0 | 0) | 0;
      $4_1 = $5_1;
      if (($7_1 | 0) != ($4_1 | 0)) continue label$4;
      break label$4;
     } while (1);
    }
    $1_1 = HEAPU32[($0_1 + 44 | 0) >> 2] | 0;
    wasm2asm_i32$0 = $0_1 + 28 | 0;
    wasm2asm_i32$1 = $1_1;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    wasm2asm_i32$0 = $0_1 + 20 | 0;
    wasm2asm_i32$1 = $1_1;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    wasm2asm_i32$0 = $0_1;
    wasm2asm_i32$1 = $1_1 + (HEAPU32[($0_1 + 48 | 0) >> 2] | 0) | 0;
    HEAP32[(wasm2asm_i32$0 + 16 | 0) >> 2] = wasm2asm_i32$1;
    $4_1 = $2_1;
    break label$1;
   };
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = 0;
   HEAP32[(wasm2asm_i32$0 + 16 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = 0;
   (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 20 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 21 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 22 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 23 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
   $4_1 = 0;
   wasm2asm_i32$0 = $0_1 + 28 | 0;
   wasm2asm_i32$1 = 0;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = HEAPU32[$0_1 >> 2] | 0 | 32 | 0;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   if (($6_1 | 0) == (2 | 0)) break label$1;
   $1_1 = HEAPU32[($1_1 + 4 | 0) >> 2] | 0;
   global$0 = $3_1 + 16 | 0;
   return $2_1 - $1_1 | 0 | 0;
  };
  global$0 = $3_1 + 16 | 0;
  return $4_1 | 0;
 }
 
 function $6($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var $3_1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0;
  $3_1 = global$0 - 16 | 0;
  global$0 = $3_1;
  wasm2asm_i32$0 = $0_1;
  wasm2asm_i32$1 = 1;
  HEAP32[(wasm2asm_i32$0 + 36 | 0) >> 2] = wasm2asm_i32$1;
  label$1 : {
   if ((HEAPU8[$0_1 >> 0] | 0) & 64 | 0) break label$1;
   if ((fimport$2(54 | 0, HEAPU32[($0_1 + 60 | 0) >> 2] | 0 | 0, 21523 | 0, $3_1 + 8 | 0 | 0) | 0 | 0) == (0 | 0)) break label$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = 255;
   HEAP8[(wasm2asm_i32$0 + 75 | 0) >> 0] = wasm2asm_i32$1;
  };
  $0_1 = $5($0_1 | 0, $1_1 | 0, $2_1 | 0) | 0;
  global$0 = $3_1 + 16 | 0;
  return $0_1 | 0;
 }
 
 function $7($0_1, $1_1, $1$hi, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  var i64toi32_i32$1 = 0, i64toi32_i32$2 = 0, $3_1 = 0, i64toi32_i32$0 = 0, i64toi32_i32$4 = 0, i64toi32_i32$3 = 0, $11_1 = 0, $8_1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  $3_1 = global$0 - 16 | 0;
  global$0 = $3_1;
  $8_1 = HEAPU32[($0_1 + 60 | 0) >> 2] | 0;
  i64toi32_i32$0 = $1$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$2 = $1_1;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$1 = 0;
   $11_1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
   $11_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
  }
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$1 = $1$hi;
  i64toi32_i32$1 = i64toi32_i32$1;
  if (($3(fimport$3(140 | 0, $8_1 | 0, $11_1 | 0, $1_1 | 0, $3_1 + 8 | 0 | 0, $2_1 | 0) | 0 | 0) | 0 | 0) >= (0 | 0)) {
   i64toi32_i32$0 = $3_1;
   i64toi32_i32$1 = HEAPU32[($3_1 + 8 | 0) >> 2] | 0;
   i64toi32_i32$2 = (wasm2asm_i32$0 = $3_1, HEAPU8[(wasm2asm_i32$0 + 12 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 13 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 14 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 15 | 0) >> 0] | 0 | 0) << 24);
   i64toi32_i32$2 = i64toi32_i32$2;
   $1_1 = i64toi32_i32$1;
   $1$hi = i64toi32_i32$2;
   global$0 = $3_1 + 16 | 0;
   i64toi32_i32$2 = i64toi32_i32$2;
   i64toi32_i32$2 = i64toi32_i32$2;
   i64toi32_i32$1 = i64toi32_i32$1;
   i64toi32_i32$HIGH_BITS = i64toi32_i32$2;
   return i64toi32_i32$1 | 0;
  }
  i64toi32_i32$2 = $3_1;
  i64toi32_i32$1 = 4294967295;
  wasm2asm_i32$0 = i64toi32_i32$2;
  wasm2asm_i32$1 = 4294967295;
  HEAP32[(wasm2asm_i32$0 + 8 | 0) >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$2;
  wasm2asm_i32$1 = i64toi32_i32$1;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 12 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 13 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 14 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 15 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  global$0 = i64toi32_i32$2 + 16 | 0;
  i64toi32_i32$1 = 4294967295;
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$2 = 4294967295;
  i64toi32_i32$HIGH_BITS = i64toi32_i32$1;
  return i64toi32_i32$2 | 0;
 }
 
 function $8($0_1) {
  $0_1 = $0_1 | 0;
  var $1_1 = 0, $2_1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0;
  $2_1 = HEAPU32[27 >> 2] | 0;
  if (((HEAPU32[($0_1 + 76 | 0) >> 2] | 0) & 3221225471 | 0 | 0) != ($2_1 | 0)) {
   $0_1 = $0_1 + 76 | 0;
   label$2 : {
    label$3 : do {
     $1_1 = HEAPU32[$0_1 >> 2] | 0;
     if (($1_1 | 0) == (0 | 0)) break label$2;
     if ((HEAPU32[$0_1 >> 2] | 0 | 0) != ($1_1 | 0)) continue label$3;
     break label$3;
    } while (1);
    wasm2asm_i32$0 = $0_1;
    wasm2asm_i32$1 = $1_1 | 1073741824 | 0;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    $1_1 = HEAPU32[$0_1 >> 2] | 0;
    if ($1_1) label$5 : do {
     if ((fimport$2(240 | 0, $0_1 | 0, 128 | 0, $1_1 | 0) | 0 | 0) == (4294967258 | 0)) fimport$2(240 | 0, $0_1 | 0, 0 | 0, $1_1 | 0) | 0;
     $1_1 = HEAPU32[$0_1 >> 2] | 0;
     if ($1_1) continue label$5;
     break label$5;
    } while (1);
    $2_1 = $2_1 | 1073741824 | 0;
   };
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $2_1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   $1_1 = 1;
  }
  return $1_1 | 0;
 }
 
 function $9($0_1) {
  $0_1 = $0_1 | 0;
  var $1_1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0;
  $0_1 = $0_1 + 76 | 0;
  label$1 : do {
   $1_1 = HEAPU32[$0_1 >> 2] | 0;
   if (($1_1 | 0) != (HEAPU32[$0_1 >> 2] | 0 | 0)) continue label$1;
   break label$1;
  } while (1);
  wasm2asm_i32$0 = $0_1;
  wasm2asm_i32$1 = 0;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  label$2 : {
   if (($1_1 & 1073741824 | 0 | 0) == (0 | 0)) break label$2;
   if ((fimport$2(240 | 0, $0_1 | 0, 129 | 0, 1 | 0) | 0 | 0) != (4294967258 | 0)) break label$2;
   fimport$2(240 | 0, $0_1 | 0, 1 | 0, 1 | 0) | 0;
  };
 }
 
 function $10($0_1) {
  $0_1 = $0_1 | 0;
  var $1_1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  $1_1 = HEAPU8[($0_1 + 74 | 0) >> 0] | 0;
  wasm2asm_i32$0 = $0_1;
  wasm2asm_i32$1 = $1_1 + 4294967295 | 0 | $1_1 | 0;
  HEAP8[(wasm2asm_i32$0 + 74 | 0) >> 0] = wasm2asm_i32$1;
  $1_1 = HEAPU32[$0_1 >> 2] | 0;
  if (($1_1 & 8 | 0 | 0) == (0 | 0)) {
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = 0;
   HEAP32[(wasm2asm_i32$0 + 4 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = 0;
   (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 8 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 9 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 10 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 11 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
   $1_1 = HEAPU32[($0_1 + 44 | 0) >> 2] | 0;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 28 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 20 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1 + (HEAPU32[($0_1 + 48 | 0) >> 2] | 0) | 0;
   HEAP32[(wasm2asm_i32$0 + 16 | 0) >> 2] = wasm2asm_i32$1;
   return 0 | 0;
  }
  wasm2asm_i32$0 = $0_1;
  wasm2asm_i32$1 = $1_1 | 32 | 0;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  return 4294967295 | 0;
 }
 
 function $11($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var $3_1 = 0, $4_1 = 0, $5_1 = 0, $6_1 = 0, $8_1 = 0, $7_1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0, wasm2asm_i32$4 = 0;
  label$1 : {
   label$2 : {
    label$3 : {
     $3_1 = HEAPU32[($2_1 + 16 | 0) >> 2] | 0;
     if ($3_1) {
      $5_1 = HEAPU32[($2_1 + 20 | 0) >> 2] | 0;
      if (($3_1 - $5_1 | 0) >>> 0 >= $1_1 >>> 0) break label$3;
      break label$1;
     }
     if ($10($2_1 | 0) | 0) break label$2;
     $5_1 = HEAPU32[($2_1 + 20 | 0) >> 2] | 0;
     if (((HEAPU32[($2_1 + 16 | 0) >> 2] | 0) - $5_1 | 0) >>> 0 < $1_1 >>> 0) break label$1;
    };
    label$5 : {
     if ((HEAP8[($2_1 + 75 | 0) >> 0] | 0 | 0) < (0 | 0)) break label$5;
     $4_1 = $0_1;
     $3_1 = 0;
     label$6 : do {
      if (($1_1 | 0) == ($3_1 | 0)) break label$5;
      $3_1 = $3_1 + 1 | 0;
      $7_1 = $4_1 + $1_1 | 0;
      $8_1 = $4_1 + 4294967295 | 0;
      $4_1 = $8_1;
      if ((HEAPU8[($7_1 + 4294967295 | 0) >> 0] | 0 | 0) != (10 | 0)) continue label$6;
      break label$6;
     } while (1);
     $6_1 = ($1_1 - $3_1 | 0) + 1 | 0;
     wasm2asm_i32$2 = $2_1;
     wasm2asm_i32$3 = $0_1;
     wasm2asm_i32$4 = $6_1;
     wasm2asm_i32$1 = HEAPU32[($2_1 + 36 | 0) >> 2] | 0;
     wasm2asm_i32$0 = FUNCTION_TABLE_iiii[wasm2asm_i32$1 & 7](wasm2asm_i32$2 | 0, wasm2asm_i32$3 | 0, wasm2asm_i32$4 | 0) | 0;
     $4_1 = wasm2asm_i32$0;
     if ($4_1 >>> 0 < $6_1 >>> 0) break label$2;
     $0_1 = ($8_1 + $1_1 | 0) + 1 | 0;
     $5_1 = HEAPU32[($2_1 + 20 | 0) >> 2] | 0;
     $1_1 = $3_1 + 4294967295 | 0;
    };
    $20($5_1 | 0, $0_1 | 0, $1_1 | 0) | 0;
    $3_1 = $2_1 + 20 | 0;
    wasm2asm_i32$0 = $3_1;
    wasm2asm_i32$1 = (HEAPU32[$3_1 >> 2] | 0) + $1_1 | 0;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    $4_1 = $6_1 + $1_1 | 0;
   };
   return $4_1 | 0;
  };
  wasm2asm_i32$4 = $2_1;
  wasm2asm_i32$3 = $0_1;
  wasm2asm_i32$2 = $1_1;
  wasm2asm_i32$1 = HEAPU32[($2_1 + 36 | 0) >> 2] | 0;
  wasm2asm_i32$0 = FUNCTION_TABLE_iiii[wasm2asm_i32$1 & 7](wasm2asm_i32$4 | 0, wasm2asm_i32$3 | 0, wasm2asm_i32$2 | 0) | 0;
  return wasm2asm_i32$0 | 0;
 }
 
 function $12($0_1, $0$hi, $1_1, $1$hi) {
  $0_1 = $0_1 | 0;
  $0$hi = $0$hi | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  var i64toi32_i32$2 = 0, i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, i64toi32_i32$3 = 0, i64toi32_i32$4 = 0, $10_1 = 0, $11_1 = 0, $12_1 = 0, $2_1 = 0, $13_1 = 0, $14_1 = 0, $15_1 = 0, $16_1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0;
  i64toi32_i32$0 = $0$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$2 = $0_1;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 0;
  if ((i64toi32_i32$0 | 0) < (i64toi32_i32$1 | 0)) $10_1 = 1; else {
   if ((i64toi32_i32$0 | 0) <= (i64toi32_i32$1 | 0)) {
    if (i64toi32_i32$2 >>> 0 >= i64toi32_i32$3 >>> 0) $11_1 = 0; else $11_1 = 1;
    $12_1 = $11_1;
   } else $12_1 = 0;
   $10_1 = $12_1;
  }
  i64toi32_i32$2 = $1$hi;
  i64toi32_i32$2 = i64toi32_i32$2;
  $2_1 = $1_1 & 32767 | 0;
  if (($10_1 | $2_1 | 0 | 0) == (0 | 0)) {
   i64toi32_i32$2 = $0$hi;
   i64toi32_i32$2 = i64toi32_i32$2;
   return (wasm2asm_i32$0 = 2, wasm2asm_i32$1 = 3, wasm2asm_i32$2 = ($0_1 | i64toi32_i32$2 | 0 | 0) == (0 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0;
  }
  label$2 : {
   if (($2_1 | 0) == (32767 | 0)) {
    i64toi32_i32$2 = $0$hi;
    i64toi32_i32$2 = i64toi32_i32$2;
    i64toi32_i32$3 = $0_1;
    i64toi32_i32$0 = 4294967295;
    i64toi32_i32$1 = 4294967295;
    if ((i64toi32_i32$2 | 0) < (i64toi32_i32$0 | 0)) $13_1 = 1; else {
     if ((i64toi32_i32$2 | 0) <= (i64toi32_i32$0 | 0)) {
      if (i64toi32_i32$3 >>> 0 > i64toi32_i32$1 >>> 0) $14_1 = 0; else $14_1 = 1;
      $15_1 = $14_1;
     } else $15_1 = 0;
     $13_1 = $15_1;
    }
    if ($13_1) break label$2;
    return 0 | 0;
   }
   i64toi32_i32$3 = $0$hi;
   i64toi32_i32$3 = i64toi32_i32$3;
   i64toi32_i32$1 = $0_1;
   i64toi32_i32$2 = 0;
   i64toi32_i32$0 = 61;
   i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = 0;
    $16_1 = i64toi32_i32$3 >>> i64toi32_i32$4 | 0;
   } else {
    i64toi32_i32$2 = i64toi32_i32$3 >>> i64toi32_i32$4 | 0;
    $16_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$3 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$4 | 0) | 0;
   }
   i64toi32_i32$2 = i64toi32_i32$2;
   return $16_1 & 4 | 0 | 0;
  };
  i64toi32_i32$2 = $0$hi;
  i64toi32_i32$2 = i64toi32_i32$2;
  i64toi32_i32$3 = $0_1;
  i64toi32_i32$1 = 2147483647;
  i64toi32_i32$0 = 4294967295;
  i64toi32_i32$1 = i64toi32_i32$2 & i64toi32_i32$1 | 0;
  i64toi32_i32$1 = i64toi32_i32$1;
  return (i64toi32_i32$3 & i64toi32_i32$0 | 0 | i64toi32_i32$1 | 0 | 0) == (0 | 0) | 0;
 }
 
 function $13($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var $3_1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0;
  $3_1 = 1;
  if ($0_1) {
   if ($1_1 >>> 0 <= 127 >>> 0) {
    wasm2asm_i32$0 = $0_1;
    wasm2asm_i32$1 = $1_1;
    HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
    return 1 | 0;
   }
   label$3 : {
    label$4 : {
     label$5 : {
      if (HEAPU32[(HEAPU32[103 >> 2] | 0) >> 2] | 0) {
       if ($1_1 >>> 0 > 2047 >>> 0) break label$5;
       wasm2asm_i32$0 = $0_1;
       wasm2asm_i32$1 = $1_1 & 63 | 0 | 128 | 0;
       HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
       wasm2asm_i32$0 = $0_1;
       wasm2asm_i32$1 = $1_1 >>> 6 | 0 | 192 | 0;
       HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
       return 2 | 0;
      }
      if (($1_1 & 4294967168 | 0 | 0) != (57216 | 0)) break label$3;
      wasm2asm_i32$0 = $0_1;
      wasm2asm_i32$1 = $1_1;
      HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
      return 1 | 0;
     };
     if ($1_1 >>> 0 < 55296 >>> 0 | ($1_1 & 4294959104 | 0 | 0) == (57344 | 0) | 0) break label$4;
     if (($1_1 + 4294901760 | 0) >>> 0 > 1048575 >>> 0) break label$3;
     wasm2asm_i32$0 = $0_1;
     wasm2asm_i32$1 = $1_1 >>> 18 | 0 | 240 | 0;
     HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
     wasm2asm_i32$0 = $0_1;
     wasm2asm_i32$1 = $1_1 & 63 | 0 | 128 | 0;
     HEAP8[(wasm2asm_i32$0 + 3 | 0) >> 0] = wasm2asm_i32$1;
     wasm2asm_i32$0 = $0_1;
     wasm2asm_i32$1 = ($1_1 >>> 12 | 0) & 63 | 0 | 128 | 0;
     HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
     wasm2asm_i32$0 = $0_1;
     wasm2asm_i32$1 = ($1_1 >>> 6 | 0) & 63 | 0 | 128 | 0;
     HEAP8[(wasm2asm_i32$0 + 2 | 0) >> 0] = wasm2asm_i32$1;
     return 4 | 0;
    };
    wasm2asm_i32$0 = $0_1;
    wasm2asm_i32$1 = $1_1 >>> 12 | 0 | 224 | 0;
    HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
    wasm2asm_i32$0 = $0_1;
    wasm2asm_i32$1 = $1_1 & 63 | 0 | 128 | 0;
    HEAP8[(wasm2asm_i32$0 + 2 | 0) >> 0] = wasm2asm_i32$1;
    wasm2asm_i32$0 = $0_1;
    wasm2asm_i32$1 = ($1_1 >>> 6 | 0) & 63 | 0 | 128 | 0;
    HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
    return 3 | 0;
   };
   wasm2asm_i32$0 = 31;
   wasm2asm_i32$1 = 84;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   $3_1 = 4294967295;
  }
  return $3_1 | 0;
 }
 
 function $14($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  if ($0_1) return $13($0_1 | 0, $1_1 | 0, 0 | 0) | 0 | 0;
  return 0 | 0;
 }
 
 function $15($0_1) {
  $0_1 = $0_1 | 0;
  var $1_1 = 0, $2_1 = 0, $4_1 = 0, $3_1 = 0;
  $3_1 = HEAPU32[103 >> 2] | 0;
  label$1 : {
   label$2 : {
    label$3 : {
     label$4 : do {
      if ((HEAPU8[($1_1 + 1040 | 0) >> 0] | 0 | 0) == ($0_1 | 0)) break label$3;
      $2_1 = 87;
      $1_1 = $1_1 + 1 | 0;
      if (($1_1 | 0) != (87 | 0)) continue label$4;
      break label$4;
     } while (1);
     break label$2;
    };
    $2_1 = $1_1;
    if (($1_1 | 0) == (0 | 0)) break label$1;
   };
   $1_1 = 1136;
   label$5 : do {
    $0_1 = HEAPU8[$1_1 >> 0] | 0;
    $4_1 = $1_1 + 1 | 0;
    $1_1 = $4_1;
    if ($0_1) continue label$5;
    $1_1 = $4_1;
    $2_1 = $2_1 + 4294967295 | 0;
    if ($2_1) continue label$5;
    break label$5;
   } while (1);
   HEAPU32[($3_1 + 20 | 0) >> 2] | 0;
   return $4_1 | 0;
  };
  HEAPU32[($3_1 + 20 | 0) >> 2] | 0;
  return 1136 | 0;
 }
 
 function $16($0_1, $1_1, $1$hi, $2_1, $2$hi, $3_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, i64toi32_i32$2 = 0, i64toi32_i32$3 = 0, $4_1 = 0, $5_1 = 0, $6_1 = 0, $40 = 0, $28_1 = 0, $28$hi = 0, $31_1 = 0, $31$hi = 0, $48 = 0, $48$hi = 0, $50 = 0, $50$hi = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  $4_1 = global$0 - 32 | 0;
  global$0 = $4_1;
  label$1 : {
   i64toi32_i32$0 = $2$hi;
   i64toi32_i32$0 = i64toi32_i32$0;
   $5_1 = $2_1;
   $6_1 = $2_1 & 32767 | 0;
   if (($6_1 | 0) == (32767 | 0)) break label$1;
   label$2 : {
    label$3 : {
     if (($6_1 | 0) == (0 | 0)) {
      i64toi32_i32$0 = $1$hi;
      i64toi32_i32$0 = $2$hi;
      i64toi32_i32$0 = $1$hi;
      i64toi32_i32$1 = $2$hi;
      i64toi32_i32$2 = 0;
      i64toi32_i32$3 = 0;
      if (($24($1_1 | 0, i64toi32_i32$0 | 0, $2_1 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$3 | 0) | 0 | 0) == (0 | 0)) break label$3;
      i64toi32_i32$3 = $1$hi;
      i64toi32_i32$3 = $2$hi;
      i64toi32_i32$3 = $1$hi;
      i64toi32_i32$2 = $2$hi;
      i64toi32_i32$1 = 0;
      i64toi32_i32$0 = 1081540608;
      $33($4_1 | 0, $1_1 | 0, i64toi32_i32$3 | 0, $2_1 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$0 | 0);
      i64toi32_i32$2 = $4_1;
      i64toi32_i32$0 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
      i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
      $28_1 = i64toi32_i32$0;
      $28$hi = i64toi32_i32$1;
      i64toi32_i32$2 = i64toi32_i32$2 + 8 | 0;
      i64toi32_i32$1 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
      i64toi32_i32$0 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
      $31_1 = i64toi32_i32$1;
      $31$hi = i64toi32_i32$0;
      i64toi32_i32$0 = $28$hi;
      i64toi32_i32$1 = $31$hi;
      $16($4_1 + 16 | 0 | 0, $28_1 | 0, i64toi32_i32$0 | 0, $31_1 | 0, i64toi32_i32$1 | 0, $3_1 | 0);
      i64toi32_i32$2 = $4_1;
      i64toi32_i32$1 = HEAPU32[(i64toi32_i32$2 + 24 | 0) >> 2] | 0;
      i64toi32_i32$0 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 28 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 29 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 30 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 31 | 0) >> 0] | 0 | 0) << 24);
      i64toi32_i32$0 = i64toi32_i32$0;
      $2_1 = i64toi32_i32$1;
      $2$hi = i64toi32_i32$0;
      i64toi32_i32$2 = i64toi32_i32$2;
      i64toi32_i32$0 = HEAPU32[(i64toi32_i32$2 + 16 | 0) >> 2] | 0;
      i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 20 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 21 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 22 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 23 | 0) >> 0] | 0 | 0) << 24);
      i64toi32_i32$1 = i64toi32_i32$1;
      $1_1 = i64toi32_i32$0;
      $1$hi = i64toi32_i32$1;
      $40 = (HEAPU32[$3_1 >> 2] | 0) + 4294967176 | 0;
      break label$2;
     }
     wasm2asm_i32$0 = $3_1;
     wasm2asm_i32$1 = ($5_1 & 32767 | 0) + 4294950914 | 0;
     HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
     i64toi32_i32$1 = 0;
     i64toi32_i32$1 = i64toi32_i32$1;
     i64toi32_i32$2 = $5_1 | 16382 | 0;
     i64toi32_i32$0 = 0;
     i64toi32_i32$3 = 49150;
     i64toi32_i32$0 = i64toi32_i32$1 & i64toi32_i32$0 | 0;
     $48 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
     $48$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$0 = i64toi32_i32$0;
     i64toi32_i32$1 = $2_1;
     i64toi32_i32$2 = 4294967295;
     i64toi32_i32$3 = 4294901760;
     i64toi32_i32$2 = i64toi32_i32$0 & i64toi32_i32$2 | 0;
     $50 = i64toi32_i32$1 & i64toi32_i32$3 | 0;
     $50$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $48$hi;
     i64toi32_i32$0 = $48;
     i64toi32_i32$1 = $50$hi;
     i64toi32_i32$3 = $50;
     i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
     i64toi32_i32$1 = i64toi32_i32$1;
     $2_1 = i64toi32_i32$0 | i64toi32_i32$3 | 0;
     $2$hi = i64toi32_i32$1;
     break label$1;
    };
    $40 = 0;
   };
   $5_1 = $40;
   wasm2asm_i32$0 = $3_1;
   wasm2asm_i32$1 = $5_1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  };
  i64toi32_i32$1 = $1$hi;
  i64toi32_i32$0 = $0_1;
  i64toi32_i32$1 = i64toi32_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = $1_1;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = i64toi32_i32$1;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  i64toi32_i32$1 = $2$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$1 = i64toi32_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = $2_1;
  HEAP32[(wasm2asm_i32$0 + 8 | 0) >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = i64toi32_i32$1;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 12 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 13 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 14 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 15 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  global$0 = $4_1 + 32 | 0;
 }
 
 function $17($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var $3_1 = 0, i64toi32_i32$1 = 0, i64toi32_i32$0 = 0, $4_1 = 0, $81 = 0, $5_1 = 0, $7_1 = 0, $6_1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  $3_1 = global$0 - 288 | 0;
  global$0 = $3_1;
  wasm2asm_i32$0 = $3_1;
  wasm2asm_i32$1 = $2_1;
  HEAP32[(wasm2asm_i32$0 + 284 | 0) >> 2] = wasm2asm_i32$1;
  i64toi32_i32$1 = $3_1 + 272 | 0;
  i64toi32_i32$0 = 0;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = 0;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = i64toi32_i32$0;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  i64toi32_i32$1 = $3_1 + 264 | 0;
  i64toi32_i32$0 = 0;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = 0;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = i64toi32_i32$0;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  i64toi32_i32$1 = $3_1 + 256 | 0;
  i64toi32_i32$0 = 0;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = 0;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = i64toi32_i32$0;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  i64toi32_i32$1 = $3_1;
  i64toi32_i32$0 = 0;
  wasm2asm_i32$0 = $3_1;
  wasm2asm_i32$1 = 0;
  HEAP32[(wasm2asm_i32$0 + 248 | 0) >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = $3_1;
  wasm2asm_i32$1 = i64toi32_i32$0;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 252 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 253 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 254 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 255 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  i64toi32_i32$1 = $3_1;
  i64toi32_i32$0 = 0;
  wasm2asm_i32$0 = $3_1;
  wasm2asm_i32$1 = 0;
  HEAP32[(wasm2asm_i32$0 + 240 | 0) >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = $3_1;
  wasm2asm_i32$1 = i64toi32_i32$0;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 244 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 245 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 246 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 247 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  wasm2asm_i32$0 = $3_1;
  wasm2asm_i32$1 = HEAPU32[($3_1 + 284 | 0) >> 2] | 0;
  HEAP32[(wasm2asm_i32$0 + 280 | 0) >> 2] = wasm2asm_i32$1;
  $2_1 = 4294967295;
  if (($18(0 | 0, $1_1 | 0, $3_1 + 280 | 0 | 0, $3_1 + 80 | 0 | 0, $3_1 + 240 | 0 | 0) | 0 | 0) > (4294967295 | 0)) {
   if ((HEAPU32[($0_1 + 76 | 0) >> 2] | 0 | 0) >= (0 | 0)) $6_1 = $8($0_1 | 0) | 0;
   $2_1 = HEAPU32[$0_1 >> 2] | 0;
   label$3 : {
    label$4 : {
     label$5 : {
      if ((HEAP8[($0_1 + 74 | 0) >> 0] | 0 | 0) > (0 | 0)) {
       $5_1 = $2_1 & 32 | 0;
       if ((HEAPU32[($0_1 + 48 | 0) >> 2] | 0 | 0) == (0 | 0)) break label$5;
       break label$4;
      }
      wasm2asm_i32$0 = $0_1;
      wasm2asm_i32$1 = $2_1 & 4294967263 | 0;
      HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
      $5_1 = $2_1 & 32 | 0;
      if (HEAPU32[($0_1 + 48 | 0) >> 2] | 0) break label$4;
     };
     $7_1 = $0_1 + 48 | 0;
     wasm2asm_i32$0 = $7_1;
     wasm2asm_i32$1 = 80;
     HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
     wasm2asm_i32$0 = $0_1;
     wasm2asm_i32$1 = $3_1 + 80 | 0;
     HEAP32[(wasm2asm_i32$0 + 16 | 0) >> 2] = wasm2asm_i32$1;
     wasm2asm_i32$0 = $0_1;
     wasm2asm_i32$1 = $3_1;
     HEAP32[(wasm2asm_i32$0 + 28 | 0) >> 2] = wasm2asm_i32$1;
     wasm2asm_i32$0 = $0_1;
     wasm2asm_i32$1 = $3_1;
     HEAP32[(wasm2asm_i32$0 + 20 | 0) >> 2] = wasm2asm_i32$1;
     $4_1 = HEAPU32[($0_1 + 44 | 0) >> 2] | 0;
     wasm2asm_i32$0 = $0_1;
     wasm2asm_i32$1 = $3_1;
     HEAP32[(wasm2asm_i32$0 + 44 | 0) >> 2] = wasm2asm_i32$1;
     $2_1 = $18($0_1 | 0, $1_1 | 0, $3_1 + 280 | 0 | 0, $3_1 + 80 | 0 | 0, $3_1 + 240 | 0 | 0) | 0;
     $81 = $2_1;
     if (($4_1 | 0) == (0 | 0)) break label$3;
     wasm2asm_i32$1 = $0_1;
     wasm2asm_i32$2 = 0;
     wasm2asm_i32$3 = 0;
     wasm2asm_i32$0 = HEAPU32[($0_1 + 36 | 0) >> 2] | 0;
     FUNCTION_TABLE_iiii[wasm2asm_i32$0 & 7](wasm2asm_i32$1 | 0, wasm2asm_i32$2 | 0, wasm2asm_i32$3 | 0) | 0;
     wasm2asm_i32$0 = $0_1 + 44 | 0;
     wasm2asm_i32$3 = $4_1;
     HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$3;
     wasm2asm_i32$0 = $7_1;
     wasm2asm_i32$3 = 0;
     HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$3;
     wasm2asm_i32$0 = $0_1 + 16 | 0;
     wasm2asm_i32$3 = 0;
     HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$3;
     wasm2asm_i32$0 = $0_1 + 28 | 0;
     wasm2asm_i32$3 = 0;
     HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$3;
     $1_1 = $0_1 + 20 | 0;
     $4_1 = HEAPU32[$1_1 >> 2] | 0;
     wasm2asm_i32$0 = $1_1;
     wasm2asm_i32$3 = 0;
     HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$3;
     $81 = (wasm2asm_i32$0 = $2_1, wasm2asm_i32$3 = 4294967295, wasm2asm_i32$2 = $4_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$3);
     break label$3;
    };
    $81 = $18($0_1 | 0, $1_1 | 0, $3_1 + 280 | 0 | 0, $3_1 + 80 | 0 | 0, $3_1 + 240 | 0 | 0) | 0;
   };
   $2_1 = $81;
   $1_1 = HEAPU32[$0_1 >> 2] | 0;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$3 = $1_1 | $5_1 | 0;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$3;
   $1_1 = $1_1 & 32 | 0;
   if ($6_1) $9($0_1 | 0);
   $2_1 = (wasm2asm_i32$0 = 4294967295, wasm2asm_i32$3 = $2_1, wasm2asm_i32$2 = $1_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$3);
  }
  global$0 = $3_1 + 288 | 0;
  return $2_1 | 0;
 }
 
 function $18($0_1, $1_1, $2_1, $3_1, $4_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  $3_1 = $3_1 | 0;
  $4_1 = $4_1 | 0;
  var $5_1 = 0, i64toi32_i32$3 = 0, $8_1 = 0, $6_1 = 0, i64toi32_i32$4 = 0, $7_1 = 0, i64toi32_i32$0 = 0, $9_1 = 0, i64toi32_i32$1 = 0, i64toi32_i32$2 = 0, $10_1 = 0, $11_1 = 0, i64toi32_i32$5 = 0, $12_1 = 0, $14$hi = 0, $14_1 = 0, $13_1 = 0, $18$hi = 0, $16_1 = 0, $15_1 = 0, $17_1 = 0, $18_1 = 0, $19_1 = 0, $20_1 = 0, $21_1 = 0, $22_1 = 0, $23_1 = 0, $24$hi = 0, $24_1 = 0, $25_1 = 0, $203 = 0, $26_1 = 0, $32$hi = 0, $31_1 = 0, $27_1 = 0, $28_1 = 0, $29_1 = 0, $30_1 = 0, $32_1 = 0, i64toi32_i32$6 = 0, $34_1 = 0, $33_1 = 0, $449 = 0, $103 = 0, $104 = 0, $105 = 0, $666 = 0, $106 = 0, $107 = 0, $108 = 0, $38 = 0, $35 = 0, $36 = 0, $37 = 0, $535 = 0, $538 = 0, $965 = 0, $965$hi = 0, $1474 = 0, $1474$hi = 0, $1482 = 0, $1482$hi = 0, $1485 = 0, $1485$hi = 0, $1534 = 0, $1534$hi = 0, $1537 = 0, $1537$hi = 0, $1541 = 0, $1541$hi = 0, $1544 = 0, $1544$hi = 0, $1571 = 0, $1573$hi = 0, $1575$hi = 0, $1577 = 0, $1577$hi = 0, $1579$hi = 0, $1583 = 0, $1583$hi = 0, $109 = 0, $1905 = 0, $1905$hi = 0, $1908 = 0, $1908$hi = 0, $2050 = 0, $2050$hi = 0, $2053 = 0, $2053$hi = 0, $2125 = 0, $2125$hi = 0, $2128 = 0, $2128$hi = 0, $2131 = 0, $2131$hi = 0, $2134 = 0, $2134$hi = 0, $2184 = 0, $2184$hi = 0, $2187 = 0, $2187$hi = 0, $2191 = 0, $2191$hi = 0, $2194 = 0, $2194$hi = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0, wasm2asm_i32$4 = 0;
  label$1 : {
   $8_1 = global$0 - 8016 | 0;
   global$0 = $8_1;
   $35 = $8_1 + 640 | 0 | 8 | 0;
   $33_1 = 0 - ($8_1 + 640 | 0) | 0;
   $27_1 = $8_1 + 640 | 0 | 9 | 0;
   $36 = $8_1 + 7752 | 0;
   $28_1 = $8_1 + 640 | 0;
   $37 = $8_1 + 346 | 0;
   $25_1 = $8_1 + 347 | 0;
   label$2 : {
    label$3 : {
     label$4 : {
      label$5 : do {
       label$6 : {
        label$7 : {
         label$8 : {
          label$9 : {
           label$10 : {
            label$11 : {
             label$12 : {
              label$13 : {
               label$14 : {
                label$15 : {
                 label$16 : {
                  label$17 : {
                   label$18 : {
                    label$19 : {
                     label$20 : {
                      if ($0_1) label$22 : do {
                       $9_1 = $1_1;
                       if (($5_1 | 0) > (2147483647 - $21_1 | 0 | 0)) break label$4;
                       $21_1 = $5_1 + $21_1 | 0;
                       $1_1 = HEAPU8[$9_1 >> 0] | 0;
                       if (($1_1 | 0) == (0 | 0)) break label$2;
                       $5_1 = $9_1;
                       label$23 : {
                        label$24 : {
                         $1_1 = $1_1 & 255 | 0;
                         if ($1_1) label$26 : do {
                          if (($1_1 | 0) == (37 | 0)) break label$24;
                          $1_1 = HEAPU8[($5_1 + 1 | 0) >> 0] | 0;
                          $5_1 = $5_1 + 1 | 0;
                          $1_1 = $1_1 & 255 | 0;
                          if ($1_1) continue label$26;
                          break label$26;
                         } while (1);
                         $1_1 = $5_1;
                         $5_1 = $5_1 - $9_1 | 0;
                         $7_1 = 2147483647 - $21_1 | 0;
                         if (($5_1 | 0) <= ($7_1 | 0)) break label$23;
                         break label$4;
                        };
                        $7_1 = $5_1;
                        label$27 : {
                         label$28 : do {
                          if ((HEAPU8[($7_1 + 1 | 0) >> 0] | 0 | 0) != (37 | 0)) break label$27;
                          $5_1 = $5_1 + 1 | 0;
                          $6_1 = HEAPU8[($7_1 + 2 | 0) >> 0] | 0;
                          $1_1 = $7_1 + 2 | 0;
                          $7_1 = $1_1;
                          if (($6_1 | 0) == (37 | 0)) continue label$28;
                          break label$28;
                         } while (1);
                         $5_1 = $5_1 - $9_1 | 0;
                         $7_1 = 2147483647 - $21_1 | 0;
                         if (($5_1 | 0) > ($7_1 | 0)) break label$4;
                         break label$23;
                        };
                        $1_1 = $7_1;
                        $5_1 = $5_1 - $9_1 | 0;
                        $7_1 = 2147483647 - $21_1 | 0;
                        if (($5_1 | 0) > ($7_1 | 0)) break label$4;
                       };
                       if (((HEAPU8[$0_1 >> 0] | 0) & 32 | 0 | 0) == (0 | 0)) $11($9_1 | 0, $5_1 | 0, $0_1 | 0) | 0;
                       if ($5_1) continue label$22;
                       break label$20;
                       break label$22;
                      } while (1);
                      label$30 : do {
                       $9_1 = $1_1;
                       if (($5_1 | 0) > (2147483647 - $21_1 | 0 | 0)) break label$4;
                       $21_1 = $5_1 + $21_1 | 0;
                       label$31 : {
                        $5_1 = HEAPU8[$9_1 >> 0] | 0;
                        if ($5_1) {
                         label$33 : {
                          $5_1 = $5_1 & 255 | 0;
                          if ($5_1) label$35 : do {
                           if (($5_1 | 0) == (37 | 0)) break label$33;
                           $5_1 = HEAPU8[($1_1 + 1 | 0) >> 0] | 0;
                           $1_1 = $1_1 + 1 | 0;
                           $5_1 = $5_1 & 255 | 0;
                           if ($5_1) continue label$35;
                           break label$35;
                          } while (1);
                          $5_1 = $1_1 - $9_1 | 0;
                          $7_1 = 2147483647 - $21_1 | 0;
                          if (($5_1 | 0) <= ($7_1 | 0)) break label$31;
                          break label$4;
                         };
                         $7_1 = $1_1;
                         $5_1 = $7_1;
                         label$36 : {
                          label$37 : do {
                           if ((HEAPU8[($5_1 + 1 | 0) >> 0] | 0 | 0) != (37 | 0)) break label$36;
                           $7_1 = $7_1 + 1 | 0;
                           $6_1 = HEAPU8[($5_1 + 2 | 0) >> 0] | 0;
                           $1_1 = $5_1 + 2 | 0;
                           $5_1 = $1_1;
                           if (($6_1 | 0) == (37 | 0)) continue label$37;
                           break label$37;
                          } while (1);
                          $5_1 = $7_1 - $9_1 | 0;
                          $7_1 = 2147483647 - $21_1 | 0;
                          if (($5_1 | 0) > ($7_1 | 0)) break label$4;
                          break label$31;
                         };
                         $1_1 = $5_1;
                         $5_1 = $7_1 - $9_1 | 0;
                         $7_1 = 2147483647 - $21_1 | 0;
                         if (($5_1 | 0) <= ($7_1 | 0)) break label$31;
                         break label$4;
                        }
                        if ($0_1) break label$2;
                        label$38 : {
                         label$39 : {
                          label$40 : {
                           label$41 : {
                            label$42 : {
                             label$43 : {
                              label$44 : {
                               label$45 : {
                                label$46 : {
                                 if ($29_1) {
                                  $5_1 = HEAPU32[($4_1 + 4 | 0) >> 2] | 0;
                                  $203 = 1;
                                  if (($5_1 | 0) == (0 | 0)) break label$38;
                                  $19($3_1 + 16 | 0 | 0, $5_1 | 0, $2_1 | 0);
                                  $5_1 = HEAPU32[($4_1 + 8 | 0) >> 2] | 0;
                                  if (($5_1 | 0) == (0 | 0)) break label$46;
                                  $19($3_1 + 32 | 0 | 0, $5_1 | 0, $2_1 | 0);
                                  $5_1 = HEAPU32[($4_1 + 12 | 0) >> 2] | 0;
                                  if (($5_1 | 0) == (0 | 0)) break label$45;
                                  $19($3_1 + 48 | 0 | 0, $5_1 | 0, $2_1 | 0);
                                  $5_1 = HEAPU32[($4_1 + 16 | 0) >> 2] | 0;
                                  if (($5_1 | 0) == (0 | 0)) break label$44;
                                  $19($3_1 - 4294967232 | 0 | 0, $5_1 | 0, $2_1 | 0);
                                  $5_1 = HEAPU32[($4_1 + 20 | 0) >> 2] | 0;
                                  if (($5_1 | 0) == (0 | 0)) break label$43;
                                  $19($3_1 + 80 | 0 | 0, $5_1 | 0, $2_1 | 0);
                                  $5_1 = HEAPU32[($4_1 + 24 | 0) >> 2] | 0;
                                  if (($5_1 | 0) == (0 | 0)) break label$42;
                                  $19($3_1 + 96 | 0 | 0, $5_1 | 0, $2_1 | 0);
                                  $5_1 = HEAPU32[($4_1 + 28 | 0) >> 2] | 0;
                                  if (($5_1 | 0) == (0 | 0)) break label$41;
                                  $19($3_1 + 112 | 0 | 0, $5_1 | 0, $2_1 | 0);
                                  $5_1 = HEAPU32[($4_1 + 32 | 0) >> 2] | 0;
                                  if (($5_1 | 0) == (0 | 0)) break label$40;
                                  $19($3_1 + 128 | 0 | 0, $5_1 | 0, $2_1 | 0);
                                  $5_1 = HEAPU32[($4_1 + 36 | 0) >> 2] | 0;
                                  if (($5_1 | 0) == (0 | 0)) break label$39;
                                  $19($3_1 + 144 | 0 | 0, $5_1 | 0, $2_1 | 0);
                                  global$0 = $8_1 + 8016 | 0;
                                  return 1 | 0;
                                 }
                                 break label$1;
                                };
                                $203 = 2;
                                break label$38;
                               };
                               $203 = 3;
                               break label$38;
                              };
                              $203 = 4;
                              break label$38;
                             };
                             $203 = 5;
                             break label$38;
                            };
                            $203 = 6;
                            break label$38;
                           };
                           $203 = 7;
                           break label$38;
                          };
                          $203 = 8;
                          break label$38;
                         };
                         $203 = 9;
                        };
                        $1_1 = $203;
                        $5_1 = $4_1 + ($1_1 << 2 | 0) | 0;
                        label$48 : do {
                         if (HEAPU32[$5_1 >> 2] | 0) break label$19;
                         $5_1 = $5_1 + 4 | 0;
                         $21_1 = 1;
                         $1_1 = $1_1 + 1 | 0;
                         if ($1_1 >>> 0 <= 9 >>> 0) continue label$48;
                         break label$48;
                        } while (1);
                        break label$2;
                       };
                       if ($5_1) continue label$30;
                       break label$30;
                      } while (1);
                     };
                     $5_1 = $1_1 + 1 | 0;
                     label$49 : {
                      label$50 : {
                       $11_1 = HEAP8[($1_1 + 1 | 0) >> 0] | 0;
                       $15_1 = $11_1 + 4294967248 | 0;
                       if ($15_1 >>> 0 <= 9 >>> 0) {
                        $6_1 = (HEAPU8[($1_1 + 2 | 0) >> 0] | 0 | 0) == (36 | 0);
                        $5_1 = (wasm2asm_i32$0 = $1_1 + 3 | 0, wasm2asm_i32$1 = $5_1, wasm2asm_i32$2 = $6_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                        $17_1 = (wasm2asm_i32$0 = $15_1, wasm2asm_i32$1 = 4294967295, wasm2asm_i32$2 = $6_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                        $29_1 = (wasm2asm_i32$0 = 1, wasm2asm_i32$1 = $29_1, wasm2asm_i32$2 = $6_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                        $10_1 = 0;
                        $11_1 = HEAP8[($1_1 + (wasm2asm_i32$0 = 3, wasm2asm_i32$1 = 1, wasm2asm_i32$2 = $6_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) >> 0] | 0;
                        $1_1 = $11_1 + 4294967264 | 0;
                        if ($1_1 >>> 0 > 31 >>> 0) break label$49;
                        break label$50;
                       }
                       $17_1 = 4294967295;
                       $10_1 = 0;
                       $1_1 = $11_1 + 4294967264 | 0;
                       if ($1_1 >>> 0 > 31 >>> 0) break label$49;
                      };
                      $1_1 = 1 << $1_1 | 0;
                      if (($1_1 & 75913 | 0 | 0) == (0 | 0)) break label$49;
                      $6_1 = $5_1 + 1 | 0;
                      label$52 : do {
                       $10_1 = $1_1 | $10_1 | 0;
                       $5_1 = $6_1;
                       $11_1 = HEAP8[$5_1 >> 0] | 0;
                       $1_1 = $11_1 + 4294967264 | 0;
                       if ($1_1 >>> 0 >= 32 >>> 0) break label$49;
                       $6_1 = $5_1 + 1 | 0;
                       $1_1 = 1 << $1_1 | 0;
                       if ($1_1 & 75913 | 0) continue label$52;
                       break label$52;
                      } while (1);
                     };
                     label$53 : {
                      label$54 : {
                       label$55 : {
                        label$56 : {
                         label$57 : {
                          if (($11_1 | 0) == (42 | 0)) {
                           $1_1 = (HEAP8[($5_1 + 1 | 0) >> 0] | 0) + 4294967248 | 0;
                           if ($1_1 >>> 0 > 9 >>> 0) break label$57;
                           if ((HEAPU8[($5_1 + 2 | 0) >> 0] | 0 | 0) != (36 | 0)) break label$57;
                           wasm2asm_i32$0 = $4_1 + ($1_1 << 2 | 0) | 0;
                           wasm2asm_i32$1 = 10;
                           HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                           $12_1 = $5_1 + 3 | 0;
                           $29_1 = 1;
                           $15_1 = HEAPU32[(($3_1 + ((HEAP8[($5_1 + 1 | 0) >> 0] | 0) << 4 | 0) | 0) + 4294966528 | 0) >> 2] | 0;
                           if (($15_1 | 0) > (4294967295 | 0)) break label$53;
                           break label$56;
                          }
                          $15_1 = 0;
                          $6_1 = $11_1 + 4294967248 | 0;
                          if ($6_1 >>> 0 > 9 >>> 0) break label$55;
                          $1_1 = 0;
                          label$59 : do {
                           $15_1 = 4294967295;
                           if ($1_1 >>> 0 <= 214748364 >>> 0) {
                            $1_1 = Math_imul($1_1, 10);
                            $15_1 = (wasm2asm_i32$0 = 4294967295, wasm2asm_i32$1 = $1_1 + $6_1 | 0, wasm2asm_i32$2 = ($6_1 | 0) > (2147483647 - $1_1 | 0 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                           }
                           $6_1 = HEAP8[($5_1 + 1 | 0) >> 0] | 0;
                           $12_1 = $5_1 + 1 | 0;
                           $5_1 = $12_1;
                           $1_1 = $15_1;
                           $6_1 = $6_1 + 4294967248 | 0;
                           if ($6_1 >>> 0 < 10 >>> 0) continue label$59;
                           break label$59;
                          } while (1);
                          if (($15_1 | 0) >= (0 | 0)) break label$53;
                          break label$4;
                         };
                         if ($29_1) break label$19;
                         $12_1 = $5_1 + 1 | 0;
                         if (($0_1 | 0) == (0 | 0)) break label$54;
                         $5_1 = HEAPU32[$2_1 >> 2] | 0;
                         wasm2asm_i32$0 = $2_1;
                         wasm2asm_i32$1 = $5_1 + 4 | 0;
                         HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                         $29_1 = 0;
                         $15_1 = HEAPU32[$5_1 >> 2] | 0;
                         if (($15_1 | 0) > (4294967295 | 0)) break label$53;
                        };
                        $15_1 = 0 - $15_1 | 0;
                        $10_1 = $10_1 | 8192 | 0;
                        break label$53;
                       };
                       $12_1 = $5_1;
                       break label$53;
                      };
                      $29_1 = 0;
                      $15_1 = 0;
                     };
                     $5_1 = 0;
                     $11_1 = 4294967295;
                     label$61 : {
                      label$62 : {
                       label$63 : {
                        label$64 : {
                         label$65 : {
                          label$66 : {
                           if ((HEAPU8[$12_1 >> 0] | 0 | 0) == (46 | 0)) {
                            $6_1 = HEAP8[($12_1 + 1 | 0) >> 0] | 0;
                            if (($6_1 | 0) != (42 | 0)) break label$66;
                            $1_1 = (HEAP8[($12_1 + 2 | 0) >> 0] | 0) + 4294967248 | 0;
                            if ($1_1 >>> 0 > 9 >>> 0) break label$65;
                            if ((HEAPU8[($12_1 + 3 | 0) >> 0] | 0 | 0) != (36 | 0)) break label$65;
                            wasm2asm_i32$0 = $4_1 + ($1_1 << 2 | 0) | 0;
                            wasm2asm_i32$1 = 10;
                            HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                            $1_1 = $12_1 + 4 | 0;
                            $449 = HEAPU32[(($3_1 + ((HEAP8[($12_1 + 2 | 0) >> 0] | 0) << 4 | 0) | 0) + 4294966528 | 0) >> 2] | 0;
                            break label$62;
                           }
                           $1_1 = $12_1;
                           $19_1 = 0;
                           break label$61;
                          };
                          $1_1 = $12_1 + 1 | 0;
                          $16_1 = $6_1 + 4294967248 | 0;
                          if ($16_1 >>> 0 > 9 >>> 0) break label$64;
                          $12_1 = 0;
                          $6_1 = $1_1;
                          label$68 : do {
                           $11_1 = 4294967295;
                           if ($12_1 >>> 0 <= 214748364 >>> 0) {
                            $1_1 = Math_imul($12_1, 10);
                            $11_1 = (wasm2asm_i32$0 = 4294967295, wasm2asm_i32$1 = $1_1 + $16_1 | 0, wasm2asm_i32$2 = ($16_1 | 0) > (2147483647 - $1_1 | 0 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                           }
                           $19_1 = 1;
                           $16_1 = HEAP8[($6_1 + 1 | 0) >> 0] | 0;
                           $1_1 = $6_1 + 1 | 0;
                           $6_1 = $1_1;
                           $12_1 = $11_1;
                           $16_1 = $16_1 + 4294967248 | 0;
                           if ($16_1 >>> 0 < 10 >>> 0) continue label$68;
                           break label$68;
                          } while (1);
                          break label$61;
                         };
                         if ($29_1) break label$19;
                         $1_1 = $12_1 + 2 | 0;
                         if (($0_1 | 0) == (0 | 0)) break label$63;
                         $6_1 = HEAPU32[$2_1 >> 2] | 0;
                         wasm2asm_i32$0 = $2_1;
                         wasm2asm_i32$1 = $6_1 + 4 | 0;
                         HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                         $449 = HEAPU32[$6_1 >> 2] | 0;
                         break label$62;
                        };
                        $19_1 = 1;
                        $11_1 = 0;
                        break label$61;
                       };
                       $449 = 0;
                      };
                      $11_1 = $449;
                      $19_1 = ($11_1 >>> 31 | 0) ^ 1 | 0;
                     };
                     label$70 : do {
                      $6_1 = $5_1;
                      $5_1 = (HEAP8[$1_1 >> 0] | 0) + 4294967231 | 0;
                      if ($5_1 >>> 0 > 57 >>> 0) break label$19;
                      $1_1 = $1_1 + 1 | 0;
                      $5_1 = HEAPU8[((Math_imul($6_1, 58) + $5_1 | 0) + 2960 | 0) >> 0] | 0;
                      if (($5_1 + 4294967295 | 0) >>> 0 < 8 >>> 0) continue label$70;
                      break label$70;
                     } while (1);
                     if (($5_1 | 0) == (0 | 0)) break label$19;
                     label$71 : {
                      label$72 : {
                       if (($5_1 | 0) == (27 | 0)) {
                        if (($17_1 | 0) > (4294967295 | 0)) break label$19;
                        $5_1 = 0;
                        if (($0_1 | 0) == (0 | 0)) continue label$5;
                        break label$72;
                       }
                       if (($17_1 | 0) >= (0 | 0)) {
                        wasm2asm_i32$0 = $4_1 + ($17_1 << 2 | 0) | 0;
                        wasm2asm_i32$1 = $5_1;
                        HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                        $5_1 = $3_1 + ($17_1 << 4 | 0) | 0;
                        i64toi32_i32$2 = $5_1 + 8 | 0;
                        i64toi32_i32$0 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
                        i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                        $535 = i64toi32_i32$0;
                        i64toi32_i32$0 = $8_1;
                        i64toi32_i32$1 = i64toi32_i32$1;
                        wasm2asm_i32$0 = $8_1;
                        wasm2asm_i32$1 = $535;
                        HEAP32[(wasm2asm_i32$0 + 360 | 0) >> 2] = wasm2asm_i32$1;
                        wasm2asm_i32$0 = $8_1;
                        wasm2asm_i32$1 = i64toi32_i32$1;
                        (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 364 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 365 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 366 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 367 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
                        i64toi32_i32$2 = $5_1;
                        i64toi32_i32$1 = HEAPU32[$5_1 >> 2] | 0;
                        i64toi32_i32$0 = (wasm2asm_i32$0 = $5_1, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                        $538 = i64toi32_i32$1;
                        i64toi32_i32$1 = $8_1;
                        i64toi32_i32$0 = i64toi32_i32$0;
                        wasm2asm_i32$0 = $8_1;
                        wasm2asm_i32$1 = $538;
                        HEAP32[(wasm2asm_i32$0 + 352 | 0) >> 2] = wasm2asm_i32$1;
                        wasm2asm_i32$0 = $8_1;
                        wasm2asm_i32$1 = i64toi32_i32$0;
                        (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 356 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 357 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 358 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 359 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
                        $5_1 = 0;
                        if (($0_1 | 0) == (0 | 0)) continue label$5;
                        break label$72;
                       }
                       if (($0_1 | 0) == (0 | 0)) break label$71;
                       $19($8_1 + 352 | 0 | 0, $5_1 | 0, $2_1 | 0);
                      };
                      $12_1 = $10_1 & 4294901759 | 0;
                      $17_1 = (wasm2asm_i32$0 = $12_1, wasm2asm_i32$1 = $10_1, wasm2asm_i32$2 = $10_1 & 8192 | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                      $13_1 = 0;
                      $22_1 = 2940;
                      $5_1 = HEAP8[($1_1 + 4294967295 | 0) >> 0] | 0;
                      $20_1 = (wasm2asm_i32$0 = (wasm2asm_i32$0 = $5_1 & 4294967263 | 0, wasm2asm_i32$1 = $5_1, wasm2asm_i32$2 = ($5_1 & 15 | 0 | 0) == (3 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1), wasm2asm_i32$1 = $5_1, wasm2asm_i32$2 = $6_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                      $5_1 = $20_1 + 4294967231 | 0;
                      if ($5_1 >>> 0 > 55 >>> 0) break label$10;
                      $10_1 = $25_1;
                      label$75 : {
                       label$76 : {
                        label$77 : {
                         label$78 : {
                          label$79 : {
                           label$80 : {
                            label$81 : {
                             label$82 : {
                              label$83 : {
                               label$84 : {
                                label$85 : {
                                 label$86 : {
                                  label$87 : {
                                   label$88 : {
                                    label$89 : {
                                     label$90 : {
                                      label$91 : {
                                       label$92 : {
                                        label$93 : {
                                         label$94 : {
                                          label$95 : {
                                           label$96 : {
                                            label$97 : {
                                             label$98 : {
                                              label$99 : {
                                               label$100 : {
                                                label$101 : {
                                                 switch ($5_1 - 1 | 0 | 0) {
                                                 case 0:
                                                  break label$9;
                                                 case 1:
                                                  break label$98;
                                                 case 2:
                                                  break label$9;
                                                 case 3:
                                                  break label$101;
                                                 case 4:
                                                  break label$101;
                                                 case 5:
                                                  break label$101;
                                                 case 6:
                                                  break label$9;
                                                 case 7:
                                                  break label$9;
                                                 case 8:
                                                  break label$9;
                                                 case 9:
                                                  break label$9;
                                                 case 10:
                                                  break label$9;
                                                 case 11:
                                                  break label$9;
                                                 case 12:
                                                  break label$9;
                                                 case 13:
                                                  break label$9;
                                                 case 14:
                                                  break label$9;
                                                 case 15:
                                                  break label$9;
                                                 case 16:
                                                  break label$9;
                                                 case 17:
                                                  break label$97;
                                                 case 18:
                                                  break label$9;
                                                 case 19:
                                                  break label$9;
                                                 case 20:
                                                  break label$9;
                                                 case 21:
                                                  break label$9;
                                                 case 22:
                                                  break label$90;
                                                 case 23:
                                                  break label$9;
                                                 case 24:
                                                  break label$9;
                                                 case 25:
                                                  break label$9;
                                                 case 26:
                                                  break label$9;
                                                 case 27:
                                                  break label$9;
                                                 case 28:
                                                  break label$9;
                                                 case 29:
                                                  break label$9;
                                                 case 30:
                                                  break label$9;
                                                 case 31:
                                                  break label$101;
                                                 case 32:
                                                  break label$9;
                                                 case 33:
                                                  break label$95;
                                                 case 34:
                                                  break label$100;
                                                 case 35:
                                                  break label$101;
                                                 case 36:
                                                  break label$101;
                                                 case 37:
                                                  break label$101;
                                                 case 38:
                                                  break label$9;
                                                 case 39:
                                                  break label$100;
                                                 case 40:
                                                  break label$9;
                                                 case 41:
                                                  break label$9;
                                                 case 42:
                                                  break label$9;
                                                 case 43:
                                                  break label$94;
                                                 case 44:
                                                  break label$93;
                                                 case 45:
                                                  break label$92;
                                                 case 46:
                                                  break label$91;
                                                 case 47:
                                                  break label$9;
                                                 case 48:
                                                  break label$9;
                                                 case 49:
                                                  break label$89;
                                                 case 50:
                                                  break label$9;
                                                 case 51:
                                                  break label$87;
                                                 case 52:
                                                  break label$9;
                                                 case 53:
                                                  break label$9;
                                                 case 54:
                                                  break label$90;
                                                 default:
                                                  break label$101;
                                                 };
                                                };
                                                if (($11_1 | 0) <= (4294967295 | 0)) if ($19_1) break label$4;;
                                                i64toi32_i32$2 = $8_1;
                                                i64toi32_i32$0 = HEAPU32[($8_1 + 360 | 0) >> 2] | 0;
                                                i64toi32_i32$1 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 364 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 365 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 366 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 367 | 0) >> 0] | 0 | 0) << 24);
                                                i64toi32_i32$1 = i64toi32_i32$1;
                                                $14_1 = i64toi32_i32$0;
                                                $14$hi = i64toi32_i32$1;
                                                i64toi32_i32$2 = $8_1;
                                                i64toi32_i32$1 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                                                i64toi32_i32$0 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 356 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 357 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 358 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 359 | 0) >> 0] | 0 | 0) << 24);
                                                i64toi32_i32$0 = i64toi32_i32$0;
                                                $18_1 = i64toi32_i32$1;
                                                $18$hi = i64toi32_i32$0;
                                                wasm2asm_i32$0 = $8_1;
                                                wasm2asm_i32$1 = 0;
                                                HEAP32[(wasm2asm_i32$0 + 668 | 0) >> 2] = wasm2asm_i32$1;
                                                i64toi32_i32$0 = $14$hi;
                                                i64toi32_i32$0 = i64toi32_i32$0;
                                                if (($14_1 >>> 15 | 0) & 1 | 0) {
                                                 $23_1 = 1;
                                                 $30_1 = 3440;
                                                 i64toi32_i32$0 = $18$hi;
                                                 i64toi32_i32$0 = $14$hi;
                                                 i64toi32_i32$0 = i64toi32_i32$0;
                                                 i64toi32_i32$2 = $14_1;
                                                 i64toi32_i32$1 = 2147483648;
                                                 i64toi32_i32$3 = 0;
                                                 i64toi32_i32$1 = i64toi32_i32$0 ^ i64toi32_i32$1 | 0;
                                                 i64toi32_i32$1 = i64toi32_i32$1;
                                                 $14_1 = i64toi32_i32$2 ^ i64toi32_i32$3 | 0;
                                                 $14$hi = i64toi32_i32$1;
                                                 i64toi32_i32$1 = i64toi32_i32$1;
                                                 i64toi32_i32$1 = $18$hi;
                                                 i64toi32_i32$2 = $14$hi;
                                                 if (($12($18_1 | 0, i64toi32_i32$1 | 0, $14_1 | 0, i64toi32_i32$2 | 0) | 0 | 0) <= (1 | 0)) break label$8;
                                                 break label$7;
                                                }
                                                if ($17_1 & 2048 | 0) break label$99;
                                                $23_1 = $17_1 & 1 | 0;
                                                $30_1 = (wasm2asm_i32$0 = 3446, wasm2asm_i32$1 = 3441, wasm2asm_i32$2 = $23_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                                                i64toi32_i32$2 = $18$hi;
                                                i64toi32_i32$2 = $14$hi;
                                                i64toi32_i32$2 = $18$hi;
                                                i64toi32_i32$1 = $14$hi;
                                                if (($12($18_1 | 0, i64toi32_i32$2 | 0, $14_1 | 0, i64toi32_i32$1 | 0) | 0 | 0) > (1 | 0)) break label$7;
                                                break label$8;
                                               };
                                               i64toi32_i32$0 = $8_1;
                                               i64toi32_i32$1 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                                               i64toi32_i32$2 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 356 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 357 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 358 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 359 | 0) >> 0] | 0 | 0) << 24);
                                               i64toi32_i32$2 = i64toi32_i32$2;
                                               $14_1 = i64toi32_i32$1;
                                               $14$hi = i64toi32_i32$2;
                                               i64toi32_i32$2 = i64toi32_i32$2;
                                               i64toi32_i32$2 = i64toi32_i32$2;
                                               i64toi32_i32$0 = i64toi32_i32$1;
                                               i64toi32_i32$1 = 4294967295;
                                               i64toi32_i32$3 = 4294967295;
                                               if ((i64toi32_i32$2 | 0) < (i64toi32_i32$1 | 0)) $103 = 1; else {
                                                if ((i64toi32_i32$2 | 0) <= (i64toi32_i32$1 | 0)) {
                                                 if (i64toi32_i32$0 >>> 0 > i64toi32_i32$3 >>> 0) $104 = 0; else $104 = 1;
                                                 $105 = $104;
                                                } else $105 = 0;
                                                $103 = $105;
                                               }
                                               if ($103) break label$86;
                                               if ($17_1 & 2048 | 0) break label$84;
                                               $13_1 = $17_1 & 1 | 0;
                                               $22_1 = (wasm2asm_i32$0 = 2942, wasm2asm_i32$1 = 2940, wasm2asm_i32$2 = $13_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                                               i64toi32_i32$0 = $14$hi;
                                               i64toi32_i32$0 = i64toi32_i32$0;
                                               i64toi32_i32$3 = $14_1;
                                               i64toi32_i32$2 = 1;
                                               i64toi32_i32$1 = 0;
                                               if (i64toi32_i32$0 >>> 0 > i64toi32_i32$2 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$3 >>> 0 >= i64toi32_i32$1 >>> 0 | 0) | 0) break label$15;
                                               break label$16;
                                              };
                                              $23_1 = 1;
                                              $30_1 = 3443;
                                              i64toi32_i32$3 = $18$hi;
                                              i64toi32_i32$3 = $14$hi;
                                              i64toi32_i32$3 = $18$hi;
                                              i64toi32_i32$0 = $14$hi;
                                              if (($12($18_1 | 0, i64toi32_i32$3 | 0, $14_1 | 0, i64toi32_i32$0 | 0) | 0 | 0) <= (1 | 0)) break label$8;
                                              break label$7;
                                             };
                                             wasm2asm_i32$0 = $8_1 + 300 | 0;
                                             wasm2asm_i32$1 = 0;
                                             HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                                             i64toi32_i32$1 = $8_1;
                                             i64toi32_i32$0 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                                             i64toi32_i32$3 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 356 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 357 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 358 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 359 | 0) >> 0] | 0 | 0) << 24);
                                             i64toi32_i32$3 = i64toi32_i32$3;
                                             wasm2asm_i32$0 = $8_1;
                                             wasm2asm_i32$1 = i64toi32_i32$0;
                                             HEAP32[(wasm2asm_i32$0 + 296 | 0) >> 2] = wasm2asm_i32$1;
                                             wasm2asm_i32$0 = $8_1;
                                             wasm2asm_i32$1 = $8_1 + 296 | 0;
                                             HEAP32[(wasm2asm_i32$0 + 352 | 0) >> 2] = wasm2asm_i32$1;
                                             $11_1 = 4294967295;
                                             $9_1 = $8_1 + 296 | 0;
                                             break label$96;
                                            };
                                            $9_1 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                                            if (($11_1 | 0) == (0 | 0)) break label$81;
                                           };
                                           $5_1 = 0;
                                           $7_1 = $9_1;
                                           label$104 : do {
                                            $6_1 = HEAPU32[$7_1 >> 2] | 0;
                                            if (($6_1 | 0) == (0 | 0)) break label$82;
                                            $6_1 = $14($8_1 + 292 | 0 | 0, $6_1 | 0) | 0;
                                            $10_1 = ($6_1 | 0) < (0 | 0);
                                            if ($10_1 | $6_1 >>> 0 > ($11_1 - $5_1 | 0) >>> 0 | 0) break label$83;
                                            $7_1 = $7_1 + 4 | 0;
                                            $5_1 = $6_1 + $5_1 | 0;
                                            if ($11_1 >>> 0 > $5_1 >>> 0) continue label$104;
                                            break label$104;
                                           } while (1);
                                           break label$82;
                                          };
                                          i64toi32_i32$1 = $8_1;
                                          i64toi32_i32$3 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                                          i64toi32_i32$0 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 356 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 357 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 358 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 359 | 0) >> 0] | 0 | 0) << 24);
                                          i64toi32_i32$0 = i64toi32_i32$0;
                                          wasm2asm_i32$0 = $8_1 + 346 | 0;
                                          wasm2asm_i32$1 = i64toi32_i32$3;
                                          HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                                          $11_1 = 1;
                                          $9_1 = $37;
                                          $17_1 = $12_1;
                                          break label$9;
                                         };
                                         $666 = $15(HEAPU32[31 >> 2] | 0 | 0) | 0;
                                         break label$88;
                                        };
                                        $5_1 = 0;
                                        $7_1 = $6_1 & 255 | 0;
                                        if ($7_1 >>> 0 > 7 >>> 0) continue label$5;
                                        label$105 : {
                                         switch ($7_1 - 1 | 0 | 0) {
                                         case 0:
                                          break label$80;
                                         case 1:
                                          break label$79;
                                         case 2:
                                          break label$78;
                                         case 3:
                                          break label$77;
                                         case 4:
                                          break label$5;
                                         case 5:
                                          break label$76;
                                         case 6:
                                          break label$75;
                                         default:
                                          break label$105;
                                         };
                                        };
                                        wasm2asm_i32$0 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                                        wasm2asm_i32$1 = $21_1;
                                        HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                                        continue label$5;
                                       };
                                       $9_1 = $25_1;
                                       i64toi32_i32$1 = $8_1;
                                       i64toi32_i32$0 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                                       i64toi32_i32$3 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 356 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 357 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 358 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 359 | 0) >> 0] | 0 | 0) << 24);
                                       i64toi32_i32$3 = i64toi32_i32$3;
                                       $14_1 = i64toi32_i32$0;
                                       $14$hi = i64toi32_i32$3;
                                       i64toi32_i32$3 = i64toi32_i32$3;
                                       i64toi32_i32$3 = i64toi32_i32$3;
                                       if (((i64toi32_i32$0 | i64toi32_i32$3 | 0 | 0) == (0 | 0) | 0) == (0 | 0)) label$107 : do {
                                        $9_1 = $9_1 + 4294967295 | 0;
                                        i64toi32_i32$3 = $14$hi;
                                        i64toi32_i32$3 = i64toi32_i32$3;
                                        wasm2asm_i32$0 = $9_1;
                                        wasm2asm_i32$1 = $14_1 & 7 | 0 | 48 | 0;
                                        HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                                        i64toi32_i32$3 = i64toi32_i32$3;
                                        i64toi32_i32$3 = i64toi32_i32$3;
                                        i64toi32_i32$1 = $14_1;
                                        i64toi32_i32$0 = 0;
                                        i64toi32_i32$2 = 3;
                                        i64toi32_i32$4 = i64toi32_i32$2 & 31 | 0;
                                        if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
                                         i64toi32_i32$0 = 0;
                                         $106 = i64toi32_i32$3 >>> i64toi32_i32$4 | 0;
                                        } else {
                                         i64toi32_i32$0 = i64toi32_i32$3 >>> i64toi32_i32$4 | 0;
                                         $106 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$3 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$4 | 0) | 0;
                                        }
                                        i64toi32_i32$0 = i64toi32_i32$0;
                                        $14_1 = $106;
                                        $14$hi = i64toi32_i32$0;
                                        i64toi32_i32$0 = i64toi32_i32$0;
                                        i64toi32_i32$0 = i64toi32_i32$0;
                                        i64toi32_i32$3 = $14_1;
                                        i64toi32_i32$1 = 0;
                                        i64toi32_i32$2 = 0;
                                        if ((i64toi32_i32$3 | 0) != (i64toi32_i32$2 | 0) | (i64toi32_i32$0 | 0) != (i64toi32_i32$1 | 0) | 0) continue label$107;
                                        break label$107;
                                       } while (1);
                                       if (($17_1 & 8 | 0 | 0) == (0 | 0)) break label$13;
                                       $5_1 = $25_1 - $9_1 | 0;
                                       $11_1 = (wasm2asm_i32$0 = $11_1, wasm2asm_i32$1 = $5_1 + 1 | 0, wasm2asm_i32$2 = ($11_1 | 0) > ($5_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                                       if ($19_1) break label$12;
                                       break label$11;
                                      };
                                      $11_1 = (wasm2asm_i32$0 = $11_1, wasm2asm_i32$1 = 8, wasm2asm_i32$2 = $11_1 >>> 0 > 8 >>> 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                                      $17_1 = $17_1 | 8 | 0;
                                      $20_1 = 120;
                                     };
                                     i64toi32_i32$2 = $8_1;
                                     i64toi32_i32$3 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                                     i64toi32_i32$0 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 356 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 357 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 358 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 359 | 0) >> 0] | 0 | 0) << 24);
                                     i64toi32_i32$0 = i64toi32_i32$0;
                                     $14_1 = i64toi32_i32$3;
                                     $14$hi = i64toi32_i32$0;
                                     i64toi32_i32$0 = i64toi32_i32$0;
                                     i64toi32_i32$0 = i64toi32_i32$0;
                                     if (((i64toi32_i32$3 | i64toi32_i32$0 | 0 | 0) == (0 | 0) | 0) == (0 | 0)) {
                                      $5_1 = $20_1 & 32 | 0;
                                      $9_1 = $25_1;
                                      label$109 : do {
                                       $9_1 = $9_1 + 4294967295 | 0;
                                       i64toi32_i32$0 = $14$hi;
                                       i64toi32_i32$0 = i64toi32_i32$0;
                                       wasm2asm_i32$0 = $9_1;
                                       wasm2asm_i32$1 = HEAPU8[(($14_1 & 15 | 0) + 3424 | 0) >> 0] | 0 | $5_1 | 0;
                                       HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                                       i64toi32_i32$0 = i64toi32_i32$0;
                                       i64toi32_i32$0 = i64toi32_i32$0;
                                       i64toi32_i32$2 = $14_1;
                                       i64toi32_i32$3 = 0;
                                       i64toi32_i32$1 = 4;
                                       i64toi32_i32$4 = i64toi32_i32$1 & 31 | 0;
                                       if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
                                        i64toi32_i32$3 = 0;
                                        $107 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
                                       } else {
                                        i64toi32_i32$3 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
                                        $107 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
                                       }
                                       i64toi32_i32$3 = i64toi32_i32$3;
                                       $14_1 = $107;
                                       $14$hi = i64toi32_i32$3;
                                       i64toi32_i32$3 = i64toi32_i32$3;
                                       i64toi32_i32$3 = i64toi32_i32$3;
                                       i64toi32_i32$0 = $14_1;
                                       i64toi32_i32$2 = 0;
                                       i64toi32_i32$1 = 0;
                                       if ((i64toi32_i32$0 | 0) != (i64toi32_i32$1 | 0) | (i64toi32_i32$3 | 0) != (i64toi32_i32$2 | 0) | 0) continue label$109;
                                       break label$109;
                                      } while (1);
                                      if (($17_1 & 8 | 0 | 0) == (0 | 0)) break label$13;
                                      i64toi32_i32$1 = $8_1;
                                      i64toi32_i32$0 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                                      i64toi32_i32$3 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 356 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 357 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 358 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 359 | 0) >> 0] | 0 | 0) << 24);
                                      i64toi32_i32$3 = i64toi32_i32$3;
                                      if ((i64toi32_i32$0 | i64toi32_i32$3 | 0 | 0) == (0 | 0)) break label$13;
                                      $22_1 = ($20_1 >> 4 | 0) + 2940 | 0;
                                      $13_1 = 2;
                                      if ($19_1) break label$12;
                                      break label$11;
                                     }
                                     $9_1 = $25_1;
                                     if ($19_1) break label$12;
                                     break label$11;
                                    };
                                    $5_1 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                                    $666 = (wasm2asm_i32$0 = $5_1, wasm2asm_i32$1 = 2950, wasm2asm_i32$2 = $5_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                                   };
                                   $9_1 = $666;
                                   $6_1 = (wasm2asm_i32$0 = 2147483647, wasm2asm_i32$1 = $11_1, wasm2asm_i32$2 = ($11_1 | 0) < (0 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                                   $5_1 = $22($9_1 | 0, 0 | 0, $6_1 | 0) | 0;
                                   $5_1 = (wasm2asm_i32$0 = $5_1 - $9_1 | 0, wasm2asm_i32$1 = $6_1, wasm2asm_i32$2 = $5_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                                   $10_1 = $9_1 + $5_1 | 0;
                                   if (($11_1 | 0) <= (4294967295 | 0)) break label$85;
                                   $17_1 = $12_1;
                                   $11_1 = $5_1;
                                   break label$9;
                                  };
                                  i64toi32_i32$1 = $8_1;
                                  i64toi32_i32$3 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                                  i64toi32_i32$0 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 356 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 357 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 358 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 359 | 0) >> 0] | 0 | 0) << 24);
                                  i64toi32_i32$0 = i64toi32_i32$0;
                                  $14_1 = i64toi32_i32$3;
                                  $14$hi = i64toi32_i32$0;
                                  i64toi32_i32$0 = i64toi32_i32$0;
                                  i64toi32_i32$0 = i64toi32_i32$0;
                                  i64toi32_i32$1 = i64toi32_i32$3;
                                  i64toi32_i32$3 = 1;
                                  i64toi32_i32$2 = 0;
                                  if (i64toi32_i32$0 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$1 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0) break label$16;
                                  break label$15;
                                 };
                                 i64toi32_i32$1 = $14$hi;
                                 i64toi32_i32$1 = 0;
                                 i64toi32_i32$2 = 0;
                                 i64toi32_i32$0 = $14$hi;
                                 i64toi32_i32$3 = $14_1;
                                 i64toi32_i32$4 = i64toi32_i32$2 - i64toi32_i32$3 | 0;
                                 i64toi32_i32$6 = i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0;
                                 i64toi32_i32$5 = i64toi32_i32$6 + i64toi32_i32$0 | 0;
                                 i64toi32_i32$5 = i64toi32_i32$1 - i64toi32_i32$5 | 0;
                                 i64toi32_i32$5 = i64toi32_i32$5;
                                 $14_1 = i64toi32_i32$4;
                                 $14$hi = i64toi32_i32$5;
                                 i64toi32_i32$5 = i64toi32_i32$5;
                                 i64toi32_i32$2 = $8_1;
                                 i64toi32_i32$5 = i64toi32_i32$5;
                                 wasm2asm_i32$0 = $8_1;
                                 wasm2asm_i32$1 = i64toi32_i32$4;
                                 HEAP32[(wasm2asm_i32$0 + 352 | 0) >> 2] = wasm2asm_i32$1;
                                 wasm2asm_i32$0 = $8_1;
                                 wasm2asm_i32$1 = i64toi32_i32$5;
                                 (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 356 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 357 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 358 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 359 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
                                 $13_1 = 1;
                                 i64toi32_i32$5 = i64toi32_i32$5;
                                 i64toi32_i32$5 = i64toi32_i32$5;
                                 i64toi32_i32$1 = i64toi32_i32$4;
                                 i64toi32_i32$2 = 1;
                                 i64toi32_i32$3 = 0;
                                 if (i64toi32_i32$5 >>> 0 > i64toi32_i32$2 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$4 >>> 0 >= i64toi32_i32$3 >>> 0 | 0) | 0) break label$15;
                                 break label$16;
                                };
                                $17_1 = $12_1;
                                $11_1 = $5_1;
                                if ((HEAPU8[$10_1 >> 0] | 0 | 0) == (0 | 0)) break label$9;
                                break label$4;
                               };
                               $13_1 = 1;
                               $22_1 = 2941;
                               i64toi32_i32$1 = $14$hi;
                               i64toi32_i32$1 = i64toi32_i32$1;
                               i64toi32_i32$3 = $14_1;
                               i64toi32_i32$5 = 1;
                               i64toi32_i32$2 = 0;
                               if (i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0) break label$16;
                               break label$15;
                              };
                              if ($10_1) break label$3;
                             };
                             if (($5_1 | 0) < (0 | 0)) break label$4;
                             $12_1 = $17_1 & 73728 | 0;
                             if ($12_1) break label$17;
                             break label$18;
                            };
                            $5_1 = 0;
                            $12_1 = $17_1 & 73728 | 0;
                            if (($12_1 | 0) == (0 | 0)) break label$18;
                            break label$17;
                           };
                           wasm2asm_i32$0 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                           wasm2asm_i32$1 = $21_1;
                           HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                           continue label$5;
                          };
                          i64toi32_i32$1 = $21_1;
                          i64toi32_i32$3 = i64toi32_i32$1 >> 31 | 0;
                          i64toi32_i32$1 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                          i64toi32_i32$3 = i64toi32_i32$3;
                          wasm2asm_i32$0 = i64toi32_i32$1;
                          wasm2asm_i32$1 = $21_1;
                          HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                          wasm2asm_i32$0 = i64toi32_i32$1;
                          wasm2asm_i32$1 = i64toi32_i32$3;
                          (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
                          continue label$5;
                         };
                         wasm2asm_i32$0 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                         wasm2asm_i32$1 = $21_1;
                         HEAP16[wasm2asm_i32$0 >> 1] = wasm2asm_i32$1;
                         continue label$5;
                        };
                        wasm2asm_i32$0 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                        wasm2asm_i32$1 = $21_1;
                        HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                        continue label$5;
                       };
                       wasm2asm_i32$0 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                       wasm2asm_i32$1 = $21_1;
                       HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                       continue label$5;
                      };
                      i64toi32_i32$1 = $21_1;
                      i64toi32_i32$3 = i64toi32_i32$1 >> 31 | 0;
                      i64toi32_i32$1 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
                      i64toi32_i32$3 = i64toi32_i32$3;
                      wasm2asm_i32$0 = i64toi32_i32$1;
                      wasm2asm_i32$1 = $21_1;
                      HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                      wasm2asm_i32$0 = i64toi32_i32$1;
                      wasm2asm_i32$1 = i64toi32_i32$3;
                      (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
                      continue label$5;
                     };
                     break label$1;
                    };
                    wasm2asm_i32$0 = 31;
                    wasm2asm_i32$1 = 22;
                    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                    break label$3;
                   };
                   if (($15_1 | 0) <= ($5_1 | 0)) break label$17;
                   $16_1 = $15_1 - $5_1 | 0;
                   $7_1 = $16_1 >>> 0 < 256 >>> 0;
                   $21($8_1 + 368 | 0 | 0, 32 | 0, (wasm2asm_i32$0 = $16_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $7_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
                   $11_1 = HEAPU32[$0_1 >> 2] | 0;
                   $6_1 = $11_1 & 32 | 0;
                   label$110 : {
                    if (($7_1 | 0) == (0 | 0)) {
                     $7_1 = ($6_1 | 0) == (0 | 0);
                     $6_1 = $16_1;
                     label$112 : do {
                      if ($7_1 & 1 | 0) {
                       $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
                       $11_1 = HEAPU32[$0_1 >> 2] | 0;
                      }
                      $10_1 = $11_1 & 32 | 0;
                      $7_1 = ($10_1 | 0) == (0 | 0);
                      $6_1 = $6_1 + 4294967040 | 0;
                      if ($6_1 >>> 0 > 255 >>> 0) continue label$112;
                      break label$112;
                     } while (1);
                     if ($10_1) break label$17;
                     $16_1 = $16_1 & 255 | 0;
                     break label$110;
                    }
                    if ($6_1) break label$17;
                   };
                   $11($8_1 + 368 | 0 | 0, $16_1 | 0, $0_1 | 0) | 0;
                  };
                  label$114 : {
                   if (($5_1 | 0) == (0 | 0)) break label$114;
                   $7_1 = 0;
                   label$115 : do {
                    $6_1 = HEAPU32[$9_1 >> 2] | 0;
                    if (($6_1 | 0) == (0 | 0)) break label$114;
                    $6_1 = $14($8_1 + 292 | 0 | 0, $6_1 | 0) | 0;
                    $7_1 = $6_1 + $7_1 | 0;
                    if ($7_1 >>> 0 > $5_1 >>> 0) break label$114;
                    if (((HEAPU8[$0_1 >> 0] | 0) & 32 | 0 | 0) == (0 | 0)) $11($8_1 + 292 | 0 | 0, $6_1 | 0, $0_1 | 0) | 0;
                    $9_1 = $9_1 + 4 | 0;
                    if ($7_1 >>> 0 < $5_1 >>> 0) continue label$115;
                    break label$115;
                   } while (1);
                  };
                  label$117 : {
                   if (($12_1 | 0) != (8192 | 0) | ($15_1 | 0) <= ($5_1 | 0) | 0) break label$117;
                   $10_1 = $15_1 - $5_1 | 0;
                   $7_1 = $10_1 >>> 0 < 256 >>> 0;
                   $21($8_1 + 368 | 0 | 0, 32 | 0, (wasm2asm_i32$0 = $10_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $7_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
                   $9_1 = HEAPU32[$0_1 >> 2] | 0;
                   $6_1 = $9_1 & 32 | 0;
                   label$118 : {
                    if (($7_1 | 0) == (0 | 0)) {
                     $7_1 = ($6_1 | 0) == (0 | 0);
                     $6_1 = $10_1;
                     label$120 : do {
                      if ($7_1 & 1 | 0) {
                       $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
                       $9_1 = HEAPU32[$0_1 >> 2] | 0;
                      }
                      $11_1 = $9_1 & 32 | 0;
                      $7_1 = ($11_1 | 0) == (0 | 0);
                      $6_1 = $6_1 + 4294967040 | 0;
                      if ($6_1 >>> 0 > 255 >>> 0) continue label$120;
                      break label$120;
                     } while (1);
                     if ($11_1) break label$117;
                     $10_1 = $10_1 & 255 | 0;
                     break label$118;
                    }
                    if ($6_1) break label$117;
                   };
                   $11($8_1 + 368 | 0 | 0, $10_1 | 0, $0_1 | 0) | 0;
                  };
                  $5_1 = (wasm2asm_i32$0 = $15_1, wasm2asm_i32$1 = $5_1, wasm2asm_i32$2 = ($15_1 | 0) > ($5_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                  continue label$5;
                 };
                 i64toi32_i32$3 = $14$hi;
                 i64toi32_i32$3 = i64toi32_i32$3;
                 $18_1 = $14_1;
                 $18$hi = i64toi32_i32$3;
                 $9_1 = $25_1;
                 break label$14;
                };
                $9_1 = $25_1;
                label$122 : do {
                 $9_1 = $9_1 + 4294967295 | 0;
                 i64toi32_i32$3 = $14$hi;
                 i64toi32_i32$3 = i64toi32_i32$3;
                 i64toi32_i32$3 = i64toi32_i32$3;
                 i64toi32_i32$1 = 0;
                 i64toi32_i32$1 = __wasm_i64_udiv($14_1 | 0, i64toi32_i32$3 | 0, 10 | 0, i64toi32_i32$1 | 0) | 0;
                 i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
                 i64toi32_i32$3 = i64toi32_i32$3;
                 $18_1 = i64toi32_i32$1;
                 $18$hi = i64toi32_i32$3;
                 i64toi32_i32$3 = i64toi32_i32$3;
                 i64toi32_i32$3 = i64toi32_i32$3;
                 i64toi32_i32$1 = 0;
                 i64toi32_i32$1 = __wasm_i64_mul($18_1 | 0, i64toi32_i32$3 | 0, 10 | 0, i64toi32_i32$1 | 0) | 0;
                 i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
                 $965 = i64toi32_i32$1;
                 $965$hi = i64toi32_i32$3;
                 i64toi32_i32$3 = $14$hi;
                 i64toi32_i32$2 = $14_1;
                 i64toi32_i32$1 = $965$hi;
                 i64toi32_i32$5 = $965;
                 i64toi32_i32$0 = i64toi32_i32$2 - i64toi32_i32$5 | 0;
                 i64toi32_i32$6 = i64toi32_i32$2 >>> 0 < i64toi32_i32$5 >>> 0;
                 i64toi32_i32$4 = i64toi32_i32$6 + i64toi32_i32$1 | 0;
                 i64toi32_i32$4 = i64toi32_i32$3 - i64toi32_i32$4 | 0;
                 i64toi32_i32$4 = i64toi32_i32$4;
                 wasm2asm_i32$0 = $9_1;
                 wasm2asm_i32$1 = i64toi32_i32$0 | 48 | 0;
                 HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                 i64toi32_i32$4 = i64toi32_i32$3;
                 i64toi32_i32$4 = i64toi32_i32$3;
                 i64toi32_i32$3 = i64toi32_i32$2;
                 i64toi32_i32$2 = 9;
                 i64toi32_i32$5 = 4294967295;
                 $5_1 = i64toi32_i32$4 >>> 0 > i64toi32_i32$2 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$3 >>> 0 > i64toi32_i32$5 >>> 0 | 0) | 0;
                 i64toi32_i32$3 = $18$hi;
                 i64toi32_i32$3 = i64toi32_i32$3;
                 $14_1 = $18_1;
                 $14$hi = i64toi32_i32$3;
                 if ($5_1) continue label$122;
                 break label$122;
                } while (1);
               };
               i64toi32_i32$3 = $18$hi;
               i64toi32_i32$3 = i64toi32_i32$3;
               $5_1 = $18_1;
               if (($5_1 | 0) == (0 | 0)) break label$13;
               label$123 : do {
                $9_1 = $9_1 + 4294967295 | 0;
                $6_1 = ($5_1 >>> 0) / (10 >>> 0) | 0;
                wasm2asm_i32$0 = $9_1;
                wasm2asm_i32$1 = $5_1 - Math_imul($6_1, 10) | 0 | 48 | 0;
                HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                $10_1 = $5_1 >>> 0 > 9 >>> 0;
                $5_1 = $6_1;
                if ($10_1) continue label$123;
                break label$123;
               } while (1);
              };
              if (($19_1 | 0) == (0 | 0)) break label$11;
             };
             if (($11_1 | 0) < (0 | 0)) break label$4;
            };
            $17_1 = (wasm2asm_i32$0 = $17_1 & 4294901759 | 0, wasm2asm_i32$1 = $17_1, wasm2asm_i32$2 = $19_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
            i64toi32_i32$5 = $8_1;
            i64toi32_i32$3 = HEAPU32[($8_1 + 352 | 0) >> 2] | 0;
            i64toi32_i32$4 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 356 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 357 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 358 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 359 | 0) >> 0] | 0 | 0) << 24);
            i64toi32_i32$4 = i64toi32_i32$4;
            $14_1 = i64toi32_i32$3;
            $14$hi = i64toi32_i32$4;
            i64toi32_i32$4 = i64toi32_i32$4;
            i64toi32_i32$4 = i64toi32_i32$4;
            if (($11_1 | ((i64toi32_i32$3 | i64toi32_i32$4 | 0 | 0) == (0 | 0) | 0) == (0 | 0) | 0 | 0) == (0 | 0)) {
             $9_1 = $25_1;
             $10_1 = $9_1;
             $11_1 = 0;
             break label$9;
            }
            i64toi32_i32$4 = $14$hi;
            i64toi32_i32$4 = i64toi32_i32$4;
            $5_1 = ($25_1 - $9_1 | 0) + (($14_1 | i64toi32_i32$4 | 0 | 0) == (0 | 0)) | 0;
            $11_1 = (wasm2asm_i32$0 = $11_1, wasm2asm_i32$1 = $5_1, wasm2asm_i32$2 = ($11_1 | 0) > ($5_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
           };
           $10_1 = $25_1;
          };
          $19_1 = $10_1 - $9_1 | 0;
          $20_1 = (wasm2asm_i32$0 = $19_1, wasm2asm_i32$1 = $11_1, wasm2asm_i32$2 = ($11_1 | 0) < ($19_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
          if (($20_1 | 0) > (2147483647 - $13_1 | 0 | 0)) break label$4;
          $16_1 = $13_1 + $20_1 | 0;
          $5_1 = (wasm2asm_i32$0 = $16_1, wasm2asm_i32$1 = $15_1, wasm2asm_i32$2 = ($15_1 | 0) < ($16_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
          if (($5_1 | 0) > ($7_1 | 0)) break label$4;
          label$125 : {
           $17_1 = $17_1 & 73728 | 0;
           if ($17_1 | ($16_1 | 0) >= ($15_1 | 0) | 0) break label$125;
           $23_1 = $5_1 - $16_1 | 0;
           $7_1 = $23_1 >>> 0 < 256 >>> 0;
           $21($8_1 + 368 | 0 | 0, 32 | 0, (wasm2asm_i32$0 = $23_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $7_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
           $10_1 = HEAPU32[$0_1 >> 2] | 0;
           $6_1 = $10_1 & 32 | 0;
           label$126 : {
            if (($7_1 | 0) == (0 | 0)) {
             $7_1 = ($6_1 | 0) == (0 | 0);
             $6_1 = $23_1;
             label$128 : do {
              if ($7_1 & 1 | 0) {
               $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
               $10_1 = HEAPU32[$0_1 >> 2] | 0;
              }
              $12_1 = $10_1 & 32 | 0;
              $7_1 = ($12_1 | 0) == (0 | 0);
              $6_1 = $6_1 + 4294967040 | 0;
              if ($6_1 >>> 0 > 255 >>> 0) continue label$128;
              break label$128;
             } while (1);
             if ($12_1) break label$125;
             $23_1 = $23_1 & 255 | 0;
             break label$126;
            }
            if ($6_1) break label$125;
           };
           $11($8_1 + 368 | 0 | 0, $23_1 | 0, $0_1 | 0) | 0;
          };
          if (((HEAPU8[$0_1 >> 0] | 0) & 32 | 0 | 0) == (0 | 0)) $11($22_1 | 0, $13_1 | 0, $0_1 | 0) | 0;
          label$131 : {
           if (($17_1 | 0) != (65536 | 0) | ($16_1 | 0) >= ($15_1 | 0) | 0) break label$131;
           $13_1 = $5_1 - $16_1 | 0;
           $7_1 = $13_1 >>> 0 < 256 >>> 0;
           $21($8_1 + 368 | 0 | 0, 48 | 0, (wasm2asm_i32$0 = $13_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $7_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
           $10_1 = HEAPU32[$0_1 >> 2] | 0;
           $6_1 = $10_1 & 32 | 0;
           label$132 : {
            if (($7_1 | 0) == (0 | 0)) {
             $7_1 = ($6_1 | 0) == (0 | 0);
             $6_1 = $13_1;
             label$134 : do {
              if ($7_1 & 1 | 0) {
               $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
               $10_1 = HEAPU32[$0_1 >> 2] | 0;
              }
              $12_1 = $10_1 & 32 | 0;
              $7_1 = ($12_1 | 0) == (0 | 0);
              $6_1 = $6_1 + 4294967040 | 0;
              if ($6_1 >>> 0 > 255 >>> 0) continue label$134;
              break label$134;
             } while (1);
             if ($12_1) break label$131;
             $13_1 = $13_1 & 255 | 0;
             break label$132;
            }
            if ($6_1) break label$131;
           };
           $11($8_1 + 368 | 0 | 0, $13_1 | 0, $0_1 | 0) | 0;
          };
          label$136 : {
           if (($19_1 | 0) >= ($11_1 | 0)) break label$136;
           $12_1 = $20_1 - $19_1 | 0;
           $7_1 = $12_1 >>> 0 < 256 >>> 0;
           $21($8_1 + 368 | 0 | 0, 48 | 0, (wasm2asm_i32$0 = $12_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $7_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
           $11_1 = HEAPU32[$0_1 >> 2] | 0;
           $6_1 = $11_1 & 32 | 0;
           label$137 : {
            if (($7_1 | 0) == (0 | 0)) {
             $7_1 = ($6_1 | 0) == (0 | 0);
             $6_1 = $12_1;
             label$139 : do {
              if ($7_1 & 1 | 0) {
               $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
               $11_1 = HEAPU32[$0_1 >> 2] | 0;
              }
              $10_1 = $11_1 & 32 | 0;
              $7_1 = ($10_1 | 0) == (0 | 0);
              $6_1 = $6_1 + 4294967040 | 0;
              if ($6_1 >>> 0 > 255 >>> 0) continue label$139;
              break label$139;
             } while (1);
             if ($10_1) break label$136;
             $12_1 = $12_1 & 255 | 0;
             break label$137;
            }
            if ($6_1) break label$136;
           };
           $11($8_1 + 368 | 0 | 0, $12_1 | 0, $0_1 | 0) | 0;
          };
          if (((HEAPU8[$0_1 >> 0] | 0) & 32 | 0 | 0) == (0 | 0)) $11($9_1 | 0, $19_1 | 0, $0_1 | 0) | 0;
          if (($17_1 | 0) != (8192 | 0) | ($16_1 | 0) >= ($15_1 | 0) | 0) continue label$5;
          $11_1 = $5_1 - $16_1 | 0;
          $7_1 = $11_1 >>> 0 < 256 >>> 0;
          $21($8_1 + 368 | 0 | 0, 32 | 0, (wasm2asm_i32$0 = $11_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $7_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
          $9_1 = HEAPU32[$0_1 >> 2] | 0;
          $6_1 = $9_1 & 32 | 0;
          label$142 : {
           if (($7_1 | 0) == (0 | 0)) {
            $7_1 = ($6_1 | 0) == (0 | 0);
            $6_1 = $11_1;
            label$144 : do {
             if ($7_1 & 1 | 0) {
              $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
              $9_1 = HEAPU32[$0_1 >> 2] | 0;
             }
             $15_1 = $9_1 & 32 | 0;
             $7_1 = ($15_1 | 0) == (0 | 0);
             $6_1 = $6_1 + 4294967040 | 0;
             if ($6_1 >>> 0 > 255 >>> 0) continue label$144;
             break label$144;
            } while (1);
            if ($15_1) continue label$5;
            $11_1 = $11_1 & 255 | 0;
            break label$142;
           }
           if ($6_1) continue label$5;
          };
          $11($8_1 + 368 | 0 | 0, $11_1 | 0, $0_1 | 0) | 0;
          continue label$5;
         };
         i64toi32_i32$4 = $18$hi;
         i64toi32_i32$4 = $14$hi;
         i64toi32_i32$4 = $18$hi;
         i64toi32_i32$4 = $14$hi;
         i64toi32_i32$4 = $18$hi;
         i64toi32_i32$3 = $14$hi;
         i64toi32_i32$5 = i64toi32_i32$4;
         i64toi32_i32$2 = i64toi32_i32$3;
         $12_1 = $23($18_1 | 0, i64toi32_i32$4 | 0, $14_1 | 0, i64toi32_i32$3 | 0, $18_1 | 0, i64toi32_i32$4 | 0, $14_1 | 0, i64toi32_i32$3 | 0) | 0;
         label$146 : {
          $11_1 = $23_1 + 3 | 0;
          if ($17_1 & 8192 | 0 | ($15_1 | 0) <= ($11_1 | 0) | 0) break label$146;
          $10_1 = $15_1 - $11_1 | 0;
          $5_1 = $10_1 >>> 0 < 256 >>> 0;
          $21($8_1 + 368 | 0 | 0, 32 | 0, (wasm2asm_i32$0 = $10_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $5_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
          $6_1 = HEAPU32[$0_1 >> 2] | 0;
          $7_1 = $6_1 & 32 | 0;
          label$147 : {
           if (($5_1 | 0) == (0 | 0)) {
            $5_1 = ($7_1 | 0) == (0 | 0);
            $7_1 = $10_1;
            label$149 : do {
             if ($5_1 & 1 | 0) {
              $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
              $6_1 = HEAPU32[$0_1 >> 2] | 0;
             }
             $9_1 = $6_1 & 32 | 0;
             $5_1 = ($9_1 | 0) == (0 | 0);
             $7_1 = $7_1 + 4294967040 | 0;
             if ($7_1 >>> 0 > 255 >>> 0) continue label$149;
             break label$149;
            } while (1);
            if ($9_1) break label$146;
            $10_1 = $10_1 & 255 | 0;
            break label$147;
           }
           if ($7_1) break label$146;
          };
          $11($8_1 + 368 | 0 | 0, $10_1 | 0, $0_1 | 0) | 0;
         };
         label$151 : {
          label$152 : {
           label$153 : {
            $5_1 = HEAPU32[$0_1 >> 2] | 0;
            if (($5_1 & 32 | 0 | 0) == (0 | 0)) {
             $11($30_1 | 0, $23_1 | 0, $0_1 | 0) | 0;
             if (((HEAPU32[$0_1 >> 2] | 0) & 32 | 0 | 0) == (0 | 0)) break label$153;
             break label$152;
            }
            if ($5_1 & 32 | 0) break label$152;
           };
           $5_1 = ($20_1 & 32 | 0) >>> 5 | 0;
           $11((wasm2asm_i32$0 = (wasm2asm_i32$0 = 3467, wasm2asm_i32$1 = 3471, wasm2asm_i32$2 = $5_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1), wasm2asm_i32$1 = (wasm2asm_i32$0 = 3459, wasm2asm_i32$1 = 3463, wasm2asm_i32$2 = $5_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1), wasm2asm_i32$2 = $12_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0, 3 | 0, $0_1 | 0) | 0;
          };
          if (($17_1 & 73728 | 0 | 0) != (8192 | 0) | ($15_1 | 0) <= ($11_1 | 0) | 0) break label$151;
          $10_1 = $15_1 - $11_1 | 0;
          $5_1 = $10_1 >>> 0 < 256 >>> 0;
          $21($8_1 + 368 | 0 | 0, 32 | 0, (wasm2asm_i32$0 = $10_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $5_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
          $6_1 = HEAPU32[$0_1 >> 2] | 0;
          $7_1 = $6_1 & 32 | 0;
          label$155 : {
           if (($5_1 | 0) == (0 | 0)) {
            $5_1 = ($7_1 | 0) == (0 | 0);
            $7_1 = $10_1;
            label$157 : do {
             if ($5_1 & 1 | 0) {
              $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
              $6_1 = HEAPU32[$0_1 >> 2] | 0;
             }
             $9_1 = $6_1 & 32 | 0;
             $5_1 = ($9_1 | 0) == (0 | 0);
             $7_1 = $7_1 + 4294967040 | 0;
             if ($7_1 >>> 0 > 255 >>> 0) continue label$157;
             break label$157;
            } while (1);
            if ($9_1) break label$151;
            $10_1 = $10_1 & 255 | 0;
            break label$155;
           }
           if ($7_1) break label$151;
          };
          $11($8_1 + 368 | 0 | 0, $10_1 | 0, $0_1 | 0) | 0;
         };
         $5_1 = (wasm2asm_i32$0 = $15_1, wasm2asm_i32$1 = $11_1, wasm2asm_i32$2 = ($15_1 | 0) > ($11_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
         break label$6;
        };
        i64toi32_i32$2 = $18$hi;
        i64toi32_i32$2 = $14$hi;
        i64toi32_i32$2 = $18$hi;
        i64toi32_i32$5 = $14$hi;
        $16($8_1 + 272 | 0 | 0, $18_1 | 0, i64toi32_i32$2 | 0, $14_1 | 0, i64toi32_i32$5 | 0, $8_1 + 668 | 0 | 0);
        i64toi32_i32$3 = $8_1;
        i64toi32_i32$5 = HEAPU32[($8_1 + 272 | 0) >> 2] | 0;
        i64toi32_i32$2 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 276 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 277 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 278 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 279 | 0) >> 0] | 0 | 0) << 24);
        i64toi32_i32$2 = i64toi32_i32$2;
        $14_1 = i64toi32_i32$5;
        $14$hi = i64toi32_i32$2;
        i64toi32_i32$2 = i64toi32_i32$2;
        i64toi32_i32$3 = $8_1;
        i64toi32_i32$2 = HEAPU32[($8_1 + 280 | 0) >> 2] | 0;
        i64toi32_i32$5 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 284 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 285 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 286 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 287 | 0) >> 0] | 0 | 0) << 24);
        i64toi32_i32$5 = i64toi32_i32$5;
        $18_1 = i64toi32_i32$2;
        $18$hi = i64toi32_i32$5;
        i64toi32_i32$5 = i64toi32_i32$5;
        i64toi32_i32$5 = $14$hi;
        i64toi32_i32$5 = $18$hi;
        i64toi32_i32$5 = $14$hi;
        i64toi32_i32$2 = $18$hi;
        i64toi32_i32$3 = i64toi32_i32$5;
        i64toi32_i32$4 = i64toi32_i32$2;
        $30($8_1 + 256 | 0 | 0, $14_1 | 0, i64toi32_i32$3 | 0, $18_1 | 0, i64toi32_i32$4 | 0, $14_1 | 0, i64toi32_i32$3 | 0, $18_1 | 0, i64toi32_i32$4 | 0);
        i64toi32_i32$2 = $8_1;
        i64toi32_i32$4 = HEAPU32[($8_1 + 256 | 0) >> 2] | 0;
        i64toi32_i32$3 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 260 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 261 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 262 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 263 | 0) >> 0] | 0 | 0) << 24);
        i64toi32_i32$3 = i64toi32_i32$3;
        $14_1 = i64toi32_i32$4;
        $14$hi = i64toi32_i32$3;
        i64toi32_i32$3 = i64toi32_i32$3;
        i64toi32_i32$2 = $8_1 + 264 | 0;
        i64toi32_i32$3 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
        i64toi32_i32$4 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
        i64toi32_i32$4 = i64toi32_i32$4;
        $18_1 = i64toi32_i32$3;
        $18$hi = i64toi32_i32$4;
        i64toi32_i32$4 = i64toi32_i32$4;
        i64toi32_i32$4 = $14$hi;
        i64toi32_i32$3 = $18$hi;
        i64toi32_i32$2 = 0;
        i64toi32_i32$5 = 0;
        if ($24($14_1 | 0, i64toi32_i32$4 | 0, $18_1 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$5 | 0) | 0) {
         wasm2asm_i32$0 = $8_1;
         wasm2asm_i32$1 = (HEAPU32[($8_1 + 668 | 0) >> 2] | 0) + 4294967295 | 0;
         HEAP32[(wasm2asm_i32$0 + 668 | 0) >> 2] = wasm2asm_i32$1;
        }
        label$160 : {
         label$161 : {
          label$162 : {
           label$163 : {
            label$164 : {
             label$165 : {
              label$166 : {
               label$167 : {
                label$168 : {
                 label$169 : {
                  $26_1 = $20_1 | 32 | 0;
                  if (($26_1 | 0) == (97 | 0)) {
                   $10_1 = $20_1 & 32 | 0;
                   $13_1 = (wasm2asm_i32$0 = $30_1 + 9 | 0, wasm2asm_i32$1 = $30_1, wasm2asm_i32$2 = $10_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                   if ($11_1 >>> 0 > 14 >>> 0 | (15 - $11_1 | 0 | 0) == (0 | 0) | 0) break label$168;
                   $5_1 = $11_1 + 4294967281 | 0;
                   i64toi32_i32$5 = 1073872896;
                   $24_1 = 0;
                   $24$hi = i64toi32_i32$5;
                   i64toi32_i32$5 = 0;
                   $32_1 = 0;
                   $32$hi = i64toi32_i32$5;
                   label$171 : do {
                    i64toi32_i32$5 = $32$hi;
                    i64toi32_i32$5 = $24$hi;
                    i64toi32_i32$5 = $32$hi;
                    i64toi32_i32$2 = $24$hi;
                    i64toi32_i32$3 = 0;
                    i64toi32_i32$4 = 1073938432;
                    $33($8_1 + 160 | 0 | 0, $32_1 | 0, i64toi32_i32$5 | 0, $24_1 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$4 | 0);
                    i64toi32_i32$2 = $8_1 + 168 | 0;
                    i64toi32_i32$4 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
                    i64toi32_i32$3 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                    i64toi32_i32$3 = i64toi32_i32$3;
                    $24_1 = i64toi32_i32$4;
                    $24$hi = i64toi32_i32$3;
                    i64toi32_i32$2 = $8_1;
                    i64toi32_i32$3 = HEAPU32[($8_1 + 160 | 0) >> 2] | 0;
                    i64toi32_i32$4 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 164 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 165 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 166 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 167 | 0) >> 0] | 0 | 0) << 24);
                    i64toi32_i32$4 = i64toi32_i32$4;
                    $32_1 = i64toi32_i32$3;
                    $32$hi = i64toi32_i32$4;
                    $5_1 = $5_1 + 1 | 0;
                    if ($5_1) continue label$171;
                    break label$171;
                   } while (1);
                   if ((HEAPU8[$13_1 >> 0] | 0 | 0) != (45 | 0)) break label$169;
                   i64toi32_i32$4 = $14$hi;
                   i64toi32_i32$4 = $18$hi;
                   i64toi32_i32$4 = i64toi32_i32$4;
                   i64toi32_i32$2 = $18_1;
                   i64toi32_i32$3 = 2147483648;
                   i64toi32_i32$5 = 0;
                   i64toi32_i32$3 = i64toi32_i32$4 ^ i64toi32_i32$3 | 0;
                   $1474 = i64toi32_i32$2 ^ i64toi32_i32$5 | 0;
                   $1474$hi = i64toi32_i32$3;
                   i64toi32_i32$3 = $32$hi;
                   i64toi32_i32$3 = $24$hi;
                   i64toi32_i32$3 = $14$hi;
                   i64toi32_i32$2 = $1474$hi;
                   i64toi32_i32$4 = $32$hi;
                   i64toi32_i32$5 = $24$hi;
                   $34($8_1 + 112 | 0 | 0, $14_1 | 0, i64toi32_i32$3 | 0, $1474 | 0, i64toi32_i32$2 | 0, $32_1 | 0, i64toi32_i32$4 | 0, $24_1 | 0, i64toi32_i32$5 | 0);
                   i64toi32_i32$5 = i64toi32_i32$4;
                   i64toi32_i32$5 = $24$hi;
                   i64toi32_i32$2 = $8_1;
                   i64toi32_i32$5 = HEAPU32[($8_1 + 112 | 0) >> 2] | 0;
                   i64toi32_i32$4 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 116 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 117 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 118 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 119 | 0) >> 0] | 0 | 0) << 24);
                   $1482 = i64toi32_i32$5;
                   $1482$hi = i64toi32_i32$4;
                   i64toi32_i32$2 = $8_1 + 120 | 0;
                   i64toi32_i32$4 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
                   i64toi32_i32$5 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                   $1485 = i64toi32_i32$4;
                   $1485$hi = i64toi32_i32$5;
                   i64toi32_i32$5 = $32$hi;
                   i64toi32_i32$4 = $24$hi;
                   i64toi32_i32$2 = $1482$hi;
                   i64toi32_i32$3 = $1485$hi;
                   $30($8_1 + 96 | 0 | 0, $32_1 | 0, i64toi32_i32$5 | 0, $24_1 | 0, i64toi32_i32$4 | 0, $1482 | 0, i64toi32_i32$2 | 0, $1485 | 0, i64toi32_i32$3 | 0);
                   i64toi32_i32$4 = $8_1 + 104 | 0;
                   i64toi32_i32$3 = HEAPU32[i64toi32_i32$4 >> 2] | 0;
                   i64toi32_i32$2 = (wasm2asm_i32$0 = i64toi32_i32$4, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                   i64toi32_i32$2 = i64toi32_i32$2;
                   i64toi32_i32$4 = i64toi32_i32$3;
                   i64toi32_i32$3 = 2147483648;
                   i64toi32_i32$5 = 0;
                   i64toi32_i32$3 = i64toi32_i32$2 ^ i64toi32_i32$3 | 0;
                   i64toi32_i32$3 = i64toi32_i32$3;
                   $18_1 = i64toi32_i32$4 ^ i64toi32_i32$5 | 0;
                   $18$hi = i64toi32_i32$3;
                   i64toi32_i32$2 = $8_1;
                   i64toi32_i32$3 = HEAPU32[($8_1 + 96 | 0) >> 2] | 0;
                   i64toi32_i32$4 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 100 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 101 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 102 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 103 | 0) >> 0] | 0 | 0) << 24);
                   i64toi32_i32$4 = i64toi32_i32$4;
                   $14_1 = i64toi32_i32$3;
                   $14$hi = i64toi32_i32$4;
                   break label$168;
                  }
                  i64toi32_i32$4 = $14$hi;
                  i64toi32_i32$4 = $18$hi;
                  i64toi32_i32$4 = $14$hi;
                  i64toi32_i32$3 = $18$hi;
                  i64toi32_i32$2 = 0;
                  i64toi32_i32$5 = 0;
                  $5_1 = $24($14_1 | 0, i64toi32_i32$4 | 0, $18_1 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$5 | 0) | 0;
                  $7_1 = ($11_1 | 0) < (0 | 0);
                  $9_1 = HEAPU32[($8_1 + 668 | 0) >> 2] | 0;
                  if ($5_1) {
                   i64toi32_i32$5 = $14$hi;
                   i64toi32_i32$5 = $18$hi;
                   i64toi32_i32$5 = $14$hi;
                   i64toi32_i32$2 = $18$hi;
                   i64toi32_i32$3 = 0;
                   i64toi32_i32$4 = 1075511296;
                   $33($8_1 + 240 | 0 | 0, $14_1 | 0, i64toi32_i32$5 | 0, $18_1 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$4 | 0);
                   $9_1 = $9_1 + 4294967268 | 0;
                   wasm2asm_i32$0 = $8_1;
                   wasm2asm_i32$1 = $9_1;
                   HEAP32[(wasm2asm_i32$0 + 668 | 0) >> 2] = wasm2asm_i32$1;
                   i64toi32_i32$2 = $8_1 + 248 | 0;
                   i64toi32_i32$4 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
                   i64toi32_i32$3 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                   i64toi32_i32$3 = i64toi32_i32$3;
                   $18_1 = i64toi32_i32$4;
                   $18$hi = i64toi32_i32$3;
                   i64toi32_i32$2 = $8_1;
                   i64toi32_i32$3 = HEAPU32[($8_1 + 240 | 0) >> 2] | 0;
                   i64toi32_i32$4 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 244 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 245 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 246 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 247 | 0) >> 0] | 0 | 0) << 24);
                   i64toi32_i32$4 = i64toi32_i32$4;
                   $14_1 = i64toi32_i32$3;
                   $14$hi = i64toi32_i32$4;
                  }
                  $13_1 = (wasm2asm_i32$0 = 6, wasm2asm_i32$1 = $11_1, wasm2asm_i32$2 = $7_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                  $22_1 = (wasm2asm_i32$0 = $8_1 + 672 | 0, wasm2asm_i32$1 = $36, wasm2asm_i32$2 = ($9_1 | 0) < (0 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                  $6_1 = $22_1;
                  label$173 : do {
                   i64toi32_i32$4 = $14$hi;
                   i64toi32_i32$4 = $18$hi;
                   i64toi32_i32$4 = $14$hi;
                   i64toi32_i32$3 = $18$hi;
                   $5_1 = $27($14_1 | 0, i64toi32_i32$4 | 0, $18_1 | 0, i64toi32_i32$3 | 0) | 0;
                   $29($8_1 + 224 | 0 | 0, $5_1 | 0);
                   i64toi32_i32$3 = i64toi32_i32$4;
                   i64toi32_i32$3 = $18$hi;
                   i64toi32_i32$2 = $8_1;
                   i64toi32_i32$3 = HEAPU32[($8_1 + 224 | 0) >> 2] | 0;
                   i64toi32_i32$4 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 228 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 229 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 230 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 231 | 0) >> 0] | 0 | 0) << 24);
                   $1534 = i64toi32_i32$3;
                   $1534$hi = i64toi32_i32$4;
                   i64toi32_i32$2 = $8_1 + 232 | 0;
                   i64toi32_i32$4 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
                   i64toi32_i32$3 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                   $1537 = i64toi32_i32$4;
                   $1537$hi = i64toi32_i32$3;
                   i64toi32_i32$3 = $14$hi;
                   i64toi32_i32$4 = $18$hi;
                   i64toi32_i32$2 = $1534$hi;
                   i64toi32_i32$5 = $1537$hi;
                   $34($8_1 + 208 | 0 | 0, $14_1 | 0, i64toi32_i32$3 | 0, $18_1 | 0, i64toi32_i32$4 | 0, $1534 | 0, i64toi32_i32$2 | 0, $1537 | 0, i64toi32_i32$5 | 0);
                   i64toi32_i32$4 = $8_1;
                   i64toi32_i32$5 = HEAPU32[($8_1 + 208 | 0) >> 2] | 0;
                   i64toi32_i32$2 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 212 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 213 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 214 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 215 | 0) >> 0] | 0 | 0) << 24);
                   $1541 = i64toi32_i32$5;
                   $1541$hi = i64toi32_i32$2;
                   i64toi32_i32$4 = $8_1 + 216 | 0;
                   i64toi32_i32$2 = HEAPU32[i64toi32_i32$4 >> 2] | 0;
                   i64toi32_i32$5 = (wasm2asm_i32$0 = i64toi32_i32$4, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                   $1544 = i64toi32_i32$2;
                   $1544$hi = i64toi32_i32$5;
                   i64toi32_i32$5 = $1541$hi;
                   i64toi32_i32$2 = $1544$hi;
                   i64toi32_i32$4 = 0;
                   i64toi32_i32$3 = 1075633366;
                   $33($8_1 + 192 | 0 | 0, $1541 | 0, i64toi32_i32$5 | 0, $1544 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$4 | 0, 1342177280 | 0, i64toi32_i32$3 | 0);
                   wasm2asm_i32$0 = $6_1;
                   wasm2asm_i32$1 = $5_1;
                   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                   $6_1 = $6_1 + 4 | 0;
                   i64toi32_i32$2 = $8_1;
                   i64toi32_i32$3 = HEAPU32[($8_1 + 192 | 0) >> 2] | 0;
                   i64toi32_i32$4 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 196 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 197 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 198 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 199 | 0) >> 0] | 0 | 0) << 24);
                   i64toi32_i32$4 = i64toi32_i32$4;
                   $14_1 = i64toi32_i32$3;
                   $14$hi = i64toi32_i32$4;
                   i64toi32_i32$4 = i64toi32_i32$4;
                   i64toi32_i32$2 = $8_1 + 200 | 0;
                   i64toi32_i32$4 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
                   i64toi32_i32$3 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                   i64toi32_i32$3 = i64toi32_i32$3;
                   $18_1 = i64toi32_i32$4;
                   $18$hi = i64toi32_i32$3;
                   i64toi32_i32$3 = i64toi32_i32$3;
                   i64toi32_i32$3 = $14$hi;
                   i64toi32_i32$4 = $18$hi;
                   i64toi32_i32$2 = 0;
                   i64toi32_i32$5 = 0;
                   if ($24($14_1 | 0, i64toi32_i32$3 | 0, $18_1 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$5 | 0) | 0) continue label$173;
                   break label$173;
                  } while (1);
                  label$174 : {
                   if (($9_1 | 0) >= (1 | 0)) {
                    $7_1 = $22_1;
                    label$176 : do {
                     $9_1 = (wasm2asm_i32$0 = $9_1, wasm2asm_i32$1 = 29, wasm2asm_i32$2 = ($9_1 | 0) < (29 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                     label$177 : {
                      $5_1 = $6_1 + 4294967292 | 0;
                      if ($5_1 >>> 0 < $7_1 >>> 0) break label$177;
                      i64toi32_i32$5 = 0;
                      i64toi32_i32$5 = i64toi32_i32$5;
                      $18_1 = $9_1;
                      $18$hi = i64toi32_i32$5;
                      i64toi32_i32$5 = 0;
                      $14_1 = 0;
                      $14$hi = i64toi32_i32$5;
                      label$178 : do {
                       $1571 = $5_1;
                       i64toi32_i32$4 = $5_1;
                       i64toi32_i32$5 = HEAPU32[$5_1 >> 2] | 0;
                       i64toi32_i32$2 = 0;
                       $1573$hi = i64toi32_i32$2;
                       i64toi32_i32$2 = $18$hi;
                       i64toi32_i32$2 = $1573$hi;
                       i64toi32_i32$4 = i64toi32_i32$5;
                       i64toi32_i32$5 = $18$hi;
                       i64toi32_i32$3 = $18_1;
                       i64toi32_i32$1 = i64toi32_i32$3 & 31 | 0;
                       if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
                        i64toi32_i32$5 = i64toi32_i32$4 << i64toi32_i32$1 | 0;
                        $108 = 0;
                       } else {
                        i64toi32_i32$5 = ((1 << i64toi32_i32$1 | 0) - 1 | 0) & (i64toi32_i32$4 >>> (32 - i64toi32_i32$1 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$1 | 0) | 0;
                        $108 = i64toi32_i32$4 << i64toi32_i32$1 | 0;
                       }
                       $1575$hi = i64toi32_i32$5;
                       i64toi32_i32$5 = $14$hi;
                       i64toi32_i32$5 = i64toi32_i32$5;
                       i64toi32_i32$2 = $14_1;
                       i64toi32_i32$4 = 0;
                       i64toi32_i32$3 = 4294967295;
                       i64toi32_i32$4 = i64toi32_i32$5 & i64toi32_i32$4 | 0;
                       $1577 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
                       $1577$hi = i64toi32_i32$4;
                       i64toi32_i32$4 = $1575$hi;
                       i64toi32_i32$5 = $108;
                       i64toi32_i32$2 = $1577$hi;
                       i64toi32_i32$3 = $1577;
                       i64toi32_i32$1 = i64toi32_i32$5 + i64toi32_i32$3 | 0;
                       i64toi32_i32$0 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
                       if (i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0) i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0;
                       i64toi32_i32$0 = i64toi32_i32$0;
                       $14_1 = i64toi32_i32$1;
                       $14$hi = i64toi32_i32$0;
                       i64toi32_i32$0 = i64toi32_i32$0;
                       $1579$hi = i64toi32_i32$0;
                       i64toi32_i32$0 = i64toi32_i32$0;
                       i64toi32_i32$0 = i64toi32_i32$0;
                       i64toi32_i32$5 = 0;
                       i64toi32_i32$5 = __wasm_i64_udiv(i64toi32_i32$1 | 0, i64toi32_i32$0 | 0, 1e9 | 0, i64toi32_i32$5 | 0) | 0;
                       i64toi32_i32$0 = i64toi32_i32$HIGH_BITS;
                       i64toi32_i32$0 = i64toi32_i32$0;
                       $14_1 = i64toi32_i32$5;
                       $14$hi = i64toi32_i32$0;
                       i64toi32_i32$0 = i64toi32_i32$0;
                       i64toi32_i32$0 = i64toi32_i32$0;
                       i64toi32_i32$5 = 0;
                       i64toi32_i32$5 = __wasm_i64_mul($14_1 | 0, i64toi32_i32$0 | 0, 1e9 | 0, i64toi32_i32$5 | 0) | 0;
                       i64toi32_i32$0 = i64toi32_i32$HIGH_BITS;
                       $1583 = i64toi32_i32$5;
                       $1583$hi = i64toi32_i32$0;
                       i64toi32_i32$0 = $1579$hi;
                       i64toi32_i32$4 = i64toi32_i32$1;
                       i64toi32_i32$5 = $1583$hi;
                       i64toi32_i32$3 = $1583;
                       i64toi32_i32$2 = i64toi32_i32$4 - i64toi32_i32$3 | 0;
                       i64toi32_i32$6 = i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0;
                       i64toi32_i32$1 = i64toi32_i32$6 + i64toi32_i32$5 | 0;
                       i64toi32_i32$1 = i64toi32_i32$0 - i64toi32_i32$1 | 0;
                       i64toi32_i32$1 = i64toi32_i32$1;
                       wasm2asm_i32$0 = $1571;
                       wasm2asm_i32$1 = i64toi32_i32$2;
                       HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                       $5_1 = $5_1 + 4294967292 | 0;
                       if ($5_1 >>> 0 >= $7_1 >>> 0) continue label$178;
                       break label$178;
                      } while (1);
                      i64toi32_i32$1 = $14$hi;
                      i64toi32_i32$1 = i64toi32_i32$1;
                      $5_1 = $14_1;
                      if (($5_1 | 0) == (0 | 0)) break label$177;
                      $7_1 = $7_1 + 4294967292 | 0;
                      wasm2asm_i32$0 = $7_1;
                      wasm2asm_i32$1 = $5_1;
                      HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                     };
                     label$179 : {
                      label$180 : do {
                       $5_1 = $6_1;
                       if ($5_1 >>> 0 <= $7_1 >>> 0) break label$179;
                       $6_1 = $5_1 + 4294967292 | 0;
                       if ((HEAPU32[$6_1 >> 2] | 0 | 0) == (0 | 0)) continue label$180;
                       break label$180;
                      } while (1);
                     };
                     $9_1 = (HEAPU32[($8_1 + 668 | 0) >> 2] | 0) - $9_1 | 0;
                     wasm2asm_i32$0 = $8_1;
                     wasm2asm_i32$1 = $9_1;
                     HEAP32[(wasm2asm_i32$0 + 668 | 0) >> 2] = wasm2asm_i32$1;
                     $6_1 = $5_1;
                     if (($9_1 | 0) > (0 | 0)) continue label$176;
                     break label$176;
                    } while (1);
                    break label$174;
                   }
                   $5_1 = $6_1;
                   $7_1 = $22_1;
                  };
                  label$181 : {
                   if (($9_1 | 0) > (4294967295 | 0)) break label$181;
                   $19_1 = ((($13_1 + 29 | 0) >>> 0) / (9 >>> 0) | 0) + 1 | 0;
                   if (($26_1 | 0) == (102 | 0)) {
                    $31_1 = $22_1 + ($19_1 << 2 | 0) | 0;
                    label$183 : do {
                     $6_1 = 0 - $9_1 | 0;
                     $10_1 = (wasm2asm_i32$0 = $6_1, wasm2asm_i32$1 = 9, wasm2asm_i32$2 = ($6_1 | 0) < (9 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                     label$184 : {
                      if ($7_1 >>> 0 < $5_1 >>> 0) {
                       $12_1 = 1e9 >>> $10_1 | 0;
                       $16_1 = (4294967295 << $10_1 | 0) ^ 4294967295 | 0;
                       $9_1 = 0;
                       $6_1 = $7_1;
                       label$186 : do {
                        $11_1 = HEAPU32[$6_1 >> 2] | 0;
                        wasm2asm_i32$0 = $6_1;
                        wasm2asm_i32$1 = ($11_1 >>> $10_1 | 0) + $9_1 | 0;
                        HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                        $9_1 = Math_imul($11_1 & $16_1 | 0, $12_1);
                        $6_1 = $6_1 + 4 | 0;
                        if ($6_1 >>> 0 < $5_1 >>> 0) continue label$186;
                        break label$186;
                       } while (1);
                       $7_1 = (wasm2asm_i32$0 = $7_1, wasm2asm_i32$1 = $7_1 + 4 | 0, wasm2asm_i32$2 = HEAPU32[$7_1 >> 2] | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                       if (($9_1 | 0) == (0 | 0)) break label$184;
                       wasm2asm_i32$0 = $5_1;
                       wasm2asm_i32$1 = $9_1;
                       HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                       $5_1 = $5_1 + 4 | 0;
                       break label$184;
                      }
                      $7_1 = (wasm2asm_i32$0 = $7_1, wasm2asm_i32$1 = $7_1 + 4 | 0, wasm2asm_i32$2 = HEAPU32[$7_1 >> 2] | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                     };
                     $9_1 = (HEAPU32[($8_1 + 668 | 0) >> 2] | 0) + $10_1 | 0;
                     wasm2asm_i32$0 = $8_1;
                     wasm2asm_i32$1 = $9_1;
                     HEAP32[(wasm2asm_i32$0 + 668 | 0) >> 2] = wasm2asm_i32$1;
                     $5_1 = (wasm2asm_i32$0 = $31_1, wasm2asm_i32$1 = $5_1, wasm2asm_i32$2 = (($5_1 - $22_1 | 0) >> 2 | 0 | 0) > ($19_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                     if (($9_1 | 0) < (0 | 0)) continue label$183;
                     break label$183;
                    } while (1);
                    break label$181;
                   }
                   label$187 : do {
                    $6_1 = 0 - $9_1 | 0;
                    $10_1 = (wasm2asm_i32$0 = $6_1, wasm2asm_i32$1 = 9, wasm2asm_i32$2 = ($6_1 | 0) < (9 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                    label$188 : {
                     if ($7_1 >>> 0 < $5_1 >>> 0) {
                      $12_1 = 1e9 >>> $10_1 | 0;
                      $16_1 = (4294967295 << $10_1 | 0) ^ 4294967295 | 0;
                      $9_1 = 0;
                      $6_1 = $7_1;
                      label$190 : do {
                       $11_1 = HEAPU32[$6_1 >> 2] | 0;
                       wasm2asm_i32$0 = $6_1;
                       wasm2asm_i32$1 = ($11_1 >>> $10_1 | 0) + $9_1 | 0;
                       HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                       $9_1 = Math_imul($11_1 & $16_1 | 0, $12_1);
                       $6_1 = $6_1 + 4 | 0;
                       if ($6_1 >>> 0 < $5_1 >>> 0) continue label$190;
                       break label$190;
                      } while (1);
                      $7_1 = (wasm2asm_i32$0 = $7_1, wasm2asm_i32$1 = $7_1 + 4 | 0, wasm2asm_i32$2 = HEAPU32[$7_1 >> 2] | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                      if (($9_1 | 0) == (0 | 0)) break label$188;
                      wasm2asm_i32$0 = $5_1;
                      wasm2asm_i32$1 = $9_1;
                      HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                      $5_1 = $5_1 + 4 | 0;
                      break label$188;
                     }
                     $7_1 = (wasm2asm_i32$0 = $7_1, wasm2asm_i32$1 = $7_1 + 4 | 0, wasm2asm_i32$2 = HEAPU32[$7_1 >> 2] | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                    };
                    $9_1 = (HEAPU32[($8_1 + 668 | 0) >> 2] | 0) + $10_1 | 0;
                    wasm2asm_i32$0 = $8_1;
                    wasm2asm_i32$1 = $9_1;
                    HEAP32[(wasm2asm_i32$0 + 668 | 0) >> 2] = wasm2asm_i32$1;
                    $5_1 = (wasm2asm_i32$0 = $7_1 + ($19_1 << 2 | 0) | 0, wasm2asm_i32$1 = $5_1, wasm2asm_i32$2 = (($5_1 - $7_1 | 0) >> 2 | 0 | 0) > ($19_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                    if (($9_1 | 0) < (0 | 0)) continue label$187;
                    break label$187;
                   } while (1);
                  };
                  $6_1 = 0;
                  label$191 : {
                   if ($7_1 >>> 0 >= $5_1 >>> 0) break label$191;
                   $6_1 = Math_imul(($22_1 - $7_1 | 0) >> 2 | 0, 9);
                   $11_1 = HEAPU32[$7_1 >> 2] | 0;
                   if ($11_1 >>> 0 < 10 >>> 0) break label$191;
                   $9_1 = 10;
                   label$192 : do {
                    $6_1 = $6_1 + 1 | 0;
                    $9_1 = Math_imul($9_1, 10);
                    if ($11_1 >>> 0 >= $9_1 >>> 0) continue label$192;
                    break label$192;
                   } while (1);
                  };
                  $11_1 = (wasm2asm_i32$0 = 0, wasm2asm_i32$1 = $6_1, wasm2asm_i32$2 = ($26_1 | 0) == (102 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                  $12_1 = ($13_1 | 0) != (0 | 0) & ($26_1 | 0) == (103 | 0) | 0;
                  $9_1 = ($13_1 - $11_1 | 0) - $12_1 | 0;
                  if (($9_1 | 0) < (Math_imul(($5_1 - $22_1 | 0) >> 2 | 0, 9) + 4294967287 | 0 | 0)) {
                   $16_1 = $9_1 + 147456 | 0;
                   $19_1 = ($16_1 | 0) / (9 | 0) | 0;
                   $31_1 = $22_1 + ($19_1 << 2 | 0) | 0;
                   $10_1 = $31_1 + 4294901764 | 0;
                   $9_1 = 10;
                   $19_1 = Math_imul($19_1, 9);
                   if ((($16_1 - $19_1 | 0) + 1 | 0 | 0) <= (8 | 0)) {
                    $11_1 = ((($11_1 + $19_1 | 0) + 4294819848 | 0) - $13_1 | 0) - (0 - $12_1 | 0) | 0;
                    label$195 : do {
                     $9_1 = Math_imul($9_1, 10);
                     $11_1 = $11_1 + 4294967295 | 0;
                     if ($11_1) continue label$195;
                     break label$195;
                    } while (1);
                   }
                   $12_1 = HEAPU32[$10_1 >> 2] | 0;
                   $16_1 = ($12_1 >>> 0) / ($9_1 >>> 0) | 0;
                   $11_1 = $12_1 - Math_imul($16_1, $9_1) | 0;
                   label$196 : {
                    $19_1 = $10_1 + 4 | 0;
                    if (($19_1 | 0) == ($5_1 | 0)) if (($11_1 | 0) == (0 | 0)) break label$196;;
                    label$198 : {
                     if (($16_1 & 1 | 0 | 0) == (0 | 0)) {
                      i64toi32_i32$1 = 1077149695;
                      $14_1 = 4294967295;
                      $14$hi = i64toi32_i32$1;
                      i64toi32_i32$1 = 4294964316;
                      $18_1 = 158857740;
                      $18$hi = i64toi32_i32$1;
                      if ($10_1 >>> 0 <= $7_1 >>> 0 | ($9_1 | 0) != (1e9 | 0) | 0) break label$198;
                      if (((HEAPU8[($10_1 + 4294967292 | 0) >> 0] | 0) & 1 | 0 | 0) == (0 | 0)) break label$198;
                     }
                     i64toi32_i32$1 = 1077149696;
                     $14_1 = 0;
                     $14$hi = i64toi32_i32$1;
                     i64toi32_i32$1 = 268433966;
                     $18_1 = 79428870;
                     $18$hi = i64toi32_i32$1;
                    };
                    i64toi32_i32$1 = 1073610752;
                    $24_1 = 0;
                    $24$hi = i64toi32_i32$1;
                    $16_1 = $9_1 >>> 1 | 0;
                    if ($11_1 >>> 0 >= $16_1 >>> 0) {
                     i64toi32_i32$1 = 1073676288;
                     i64toi32_i32$4 = 1073709056;
                     i64toi32_i32$0 = 0;
                     i64toi32_i32$1 = i64toi32_i32$4;
                     i64toi32_i32$1 = i64toi32_i32$4;
                     $109 = (wasm2asm_i32$0 = 0, wasm2asm_i32$1 = i64toi32_i32$0, wasm2asm_i32$2 = ($11_1 | 0) == ($16_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                     i64toi32_i32$4 = 1073709056;
                     i64toi32_i32$0 = 0;
                     i64toi32_i32$1 = i64toi32_i32$4;
                     i64toi32_i32$1 = i64toi32_i32$4;
                     $24_1 = (wasm2asm_i32$0 = $109, wasm2asm_i32$1 = i64toi32_i32$0, wasm2asm_i32$2 = ($19_1 | 0) == ($5_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                     $24$hi = i64toi32_i32$4;
                    }
                    label$201 : {
                     if (($23_1 | 0) == (0 | 0)) break label$201;
                     if ((HEAPU8[$30_1 >> 0] | 0 | 0) != (45 | 0)) break label$201;
                     i64toi32_i32$1 = $24$hi;
                     i64toi32_i32$1 = i64toi32_i32$1;
                     i64toi32_i32$0 = $24_1;
                     i64toi32_i32$4 = 2147483648;
                     i64toi32_i32$3 = 0;
                     i64toi32_i32$4 = i64toi32_i32$1 ^ i64toi32_i32$4 | 0;
                     i64toi32_i32$4 = i64toi32_i32$4;
                     $24_1 = i64toi32_i32$0 ^ i64toi32_i32$3 | 0;
                     $24$hi = i64toi32_i32$4;
                     i64toi32_i32$4 = $14$hi;
                     i64toi32_i32$4 = i64toi32_i32$4;
                     i64toi32_i32$1 = $14_1;
                     i64toi32_i32$0 = 2147483648;
                     i64toi32_i32$3 = 0;
                     i64toi32_i32$0 = i64toi32_i32$4 ^ i64toi32_i32$0 | 0;
                     i64toi32_i32$0 = i64toi32_i32$0;
                     $14_1 = i64toi32_i32$1 ^ i64toi32_i32$3 | 0;
                     $14$hi = i64toi32_i32$0;
                    };
                    i64toi32_i32$0 = $18$hi;
                    i64toi32_i32$0 = $14$hi;
                    i64toi32_i32$0 = $24$hi;
                    i64toi32_i32$0 = $18$hi;
                    i64toi32_i32$1 = $14$hi;
                    i64toi32_i32$4 = 0;
                    i64toi32_i32$3 = $24$hi;
                    $30($8_1 + 176 | 0 | 0, $18_1 | 0, i64toi32_i32$0 | 0, $14_1 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$4 | 0, $24_1 | 0, i64toi32_i32$3 | 0);
                    $11_1 = $12_1 - $11_1 | 0;
                    wasm2asm_i32$0 = $10_1;
                    wasm2asm_i32$1 = $11_1;
                    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                    i64toi32_i32$1 = $8_1;
                    i64toi32_i32$3 = HEAPU32[($8_1 + 176 | 0) >> 2] | 0;
                    i64toi32_i32$4 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 180 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 181 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 182 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 183 | 0) >> 0] | 0 | 0) << 24);
                    $1905 = i64toi32_i32$3;
                    $1905$hi = i64toi32_i32$4;
                    i64toi32_i32$1 = $8_1 + 184 | 0;
                    i64toi32_i32$4 = HEAPU32[i64toi32_i32$1 >> 2] | 0;
                    i64toi32_i32$3 = (wasm2asm_i32$0 = i64toi32_i32$1, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                    $1908 = i64toi32_i32$4;
                    $1908$hi = i64toi32_i32$3;
                    i64toi32_i32$3 = i64toi32_i32$0;
                    i64toi32_i32$3 = $14$hi;
                    i64toi32_i32$3 = $1905$hi;
                    i64toi32_i32$4 = $1908$hi;
                    i64toi32_i32$1 = i64toi32_i32$0;
                    i64toi32_i32$0 = $14$hi;
                    if (($24($1905 | 0, i64toi32_i32$3 | 0, $1908 | 0, i64toi32_i32$4 | 0, $18_1 | 0, i64toi32_i32$1 | 0, $14_1 | 0, i64toi32_i32$0 | 0) | 0 | 0) == (0 | 0)) break label$196;
                    $6_1 = $11_1 + $9_1 | 0;
                    wasm2asm_i32$0 = $10_1;
                    wasm2asm_i32$1 = $6_1;
                    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                    if ($6_1 >>> 0 >= 1e9 >>> 0) {
                     $6_1 = $31_1 + 4294901760 | 0;
                     label$203 : do {
                      wasm2asm_i32$0 = $6_1 + 4 | 0;
                      wasm2asm_i32$1 = 0;
                      HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                      if ($6_1 >>> 0 < $7_1 >>> 0) {
                       $7_1 = $7_1 + 4294967292 | 0;
                       wasm2asm_i32$0 = $7_1;
                       wasm2asm_i32$1 = 0;
                       HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                      }
                      $9_1 = (HEAPU32[$6_1 >> 2] | 0) + 1 | 0;
                      wasm2asm_i32$0 = $6_1;
                      wasm2asm_i32$1 = $9_1;
                      HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                      $6_1 = $6_1 + 4294967292 | 0;
                      if ($9_1 >>> 0 > 999999999 >>> 0) continue label$203;
                      break label$203;
                     } while (1);
                     $10_1 = $6_1 + 4 | 0;
                    }
                    $6_1 = Math_imul(($22_1 - $7_1 | 0) >> 2 | 0, 9);
                    $11_1 = HEAPU32[$7_1 >> 2] | 0;
                    if ($11_1 >>> 0 < 10 >>> 0) break label$196;
                    $9_1 = 10;
                    label$205 : do {
                     $6_1 = $6_1 + 1 | 0;
                     $9_1 = Math_imul($9_1, 10);
                     if ($11_1 >>> 0 >= $9_1 >>> 0) continue label$205;
                     break label$205;
                    } while (1);
                   };
                   $9_1 = $10_1 + 4 | 0;
                   $5_1 = (wasm2asm_i32$0 = $9_1, wasm2asm_i32$1 = $5_1, wasm2asm_i32$2 = $5_1 >>> 0 > $9_1 >>> 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                  }
                  label$206 : {
                   label$207 : {
                    label$208 : do {
                     $11_1 = $5_1;
                     if ($5_1 >>> 0 <= $7_1 >>> 0) break label$207;
                     $5_1 = $11_1 + 4294967292 | 0;
                     if ((HEAPU32[$5_1 >> 2] | 0 | 0) == (0 | 0)) continue label$208;
                     break label$208;
                    } while (1);
                    $31_1 = 1;
                    $16_1 = $17_1 & 8 | 0;
                    if (($26_1 | 0) == (103 | 0)) break label$206;
                    break label$166;
                   };
                   $31_1 = 0;
                   $16_1 = $17_1 & 8 | 0;
                   if (($26_1 | 0) != (103 | 0)) break label$166;
                  };
                  $5_1 = (wasm2asm_i32$0 = $13_1, wasm2asm_i32$1 = 1, wasm2asm_i32$2 = $13_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                  $9_1 = ($5_1 | 0) > ($6_1 | 0) & ($6_1 | 0) > (4294967291 | 0) | 0;
                  $13_1 = (wasm2asm_i32$0 = $6_1 ^ 4294967295 | 0, wasm2asm_i32$1 = 4294967295, wasm2asm_i32$2 = $9_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) + $5_1 | 0;
                  $20_1 = (wasm2asm_i32$0 = 4294967295, wasm2asm_i32$1 = 4294967294, wasm2asm_i32$2 = $9_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) + $20_1 | 0;
                  if ($16_1) break label$166;
                  $5_1 = 9;
                  label$209 : {
                   if (($31_1 | 0) == (0 | 0)) break label$209;
                   $10_1 = HEAPU32[($11_1 + 4294967292 | 0) >> 2] | 0;
                   if (($10_1 | 0) == (0 | 0)) break label$209;
                   $5_1 = 0;
                   if (($10_1 >>> 0) % (10 >>> 0) | 0) break label$209;
                   $9_1 = 10;
                   label$210 : do {
                    $5_1 = $5_1 + 1 | 0;
                    $9_1 = Math_imul($9_1, 10);
                    if ((($10_1 >>> 0) % ($9_1 >>> 0) | 0 | 0) == (0 | 0)) continue label$210;
                    break label$210;
                   } while (1);
                  };
                  $9_1 = Math_imul(($11_1 - $22_1 | 0) >> 2 | 0, 9) + 4294967287 | 0;
                  if (($20_1 | 32 | 0 | 0) != (102 | 0)) break label$167;
                  $16_1 = 0;
                  $5_1 = $9_1 - $5_1 | 0;
                  $5_1 = (wasm2asm_i32$0 = $5_1, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = ($5_1 | 0) > (0 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                  $13_1 = (wasm2asm_i32$0 = $13_1, wasm2asm_i32$1 = $5_1, wasm2asm_i32$2 = ($13_1 | 0) < ($5_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                  break label$166;
                 };
                 i64toi32_i32$0 = $14$hi;
                 i64toi32_i32$0 = $18$hi;
                 i64toi32_i32$0 = $32$hi;
                 i64toi32_i32$0 = $24$hi;
                 i64toi32_i32$0 = $14$hi;
                 i64toi32_i32$1 = $18$hi;
                 i64toi32_i32$4 = $32$hi;
                 i64toi32_i32$3 = $24$hi;
                 $30($8_1 + 144 | 0 | 0, $14_1 | 0, i64toi32_i32$0 | 0, $18_1 | 0, i64toi32_i32$1 | 0, $32_1 | 0, i64toi32_i32$4 | 0, $24_1 | 0, i64toi32_i32$3 | 0);
                 i64toi32_i32$1 = $8_1;
                 i64toi32_i32$3 = HEAPU32[($8_1 + 144 | 0) >> 2] | 0;
                 i64toi32_i32$4 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 148 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 149 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 150 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 151 | 0) >> 0] | 0 | 0) << 24);
                 $2050 = i64toi32_i32$3;
                 $2050$hi = i64toi32_i32$4;
                 i64toi32_i32$1 = $8_1 + 152 | 0;
                 i64toi32_i32$4 = HEAPU32[i64toi32_i32$1 >> 2] | 0;
                 i64toi32_i32$3 = (wasm2asm_i32$0 = i64toi32_i32$1, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                 $2053 = i64toi32_i32$4;
                 $2053$hi = i64toi32_i32$3;
                 i64toi32_i32$3 = $32$hi;
                 i64toi32_i32$3 = $24$hi;
                 i64toi32_i32$3 = $2050$hi;
                 i64toi32_i32$4 = $2053$hi;
                 i64toi32_i32$1 = $32$hi;
                 i64toi32_i32$0 = $24$hi;
                 $34($8_1 + 128 | 0 | 0, $2050 | 0, i64toi32_i32$3 | 0, $2053 | 0, i64toi32_i32$4 | 0, $32_1 | 0, i64toi32_i32$1 | 0, $24_1 | 0, i64toi32_i32$0 | 0);
                 i64toi32_i32$4 = $8_1 + 136 | 0;
                 i64toi32_i32$0 = HEAPU32[i64toi32_i32$4 >> 2] | 0;
                 i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$4, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                 i64toi32_i32$1 = i64toi32_i32$1;
                 $18_1 = i64toi32_i32$0;
                 $18$hi = i64toi32_i32$1;
                 i64toi32_i32$4 = $8_1;
                 i64toi32_i32$1 = HEAPU32[($8_1 + 128 | 0) >> 2] | 0;
                 i64toi32_i32$0 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 132 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 133 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 134 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 135 | 0) >> 0] | 0 | 0) << 24);
                 i64toi32_i32$0 = i64toi32_i32$0;
                 $14_1 = i64toi32_i32$1;
                 $14$hi = i64toi32_i32$0;
                };
                $6_1 = $28_1;
                label$211 : {
                 $12_1 = HEAPU32[($8_1 + 668 | 0) >> 2] | 0;
                 $5_1 = $12_1 >> 31 | 0;
                 $5_1 = ($12_1 + $5_1 | 0) ^ $5_1 | 0;
                 if ($5_1) {
                  $7_1 = 0;
                  label$213 : do {
                   $6_1 = ($5_1 >>> 0) / (10 >>> 0) | 0;
                   wasm2asm_i32$0 = ($8_1 + $7_1 | 0) + 639 | 0;
                   wasm2asm_i32$1 = $5_1 - Math_imul($6_1, 10) | 0 | 48 | 0;
                   HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                   $7_1 = $7_1 + 4294967295 | 0;
                   $9_1 = $5_1 >>> 0 > 9 >>> 0;
                   $5_1 = $6_1;
                   if ($9_1) continue label$213;
                   break label$213;
                  } while (1);
                  $6_1 = ($8_1 + $7_1 | 0) + 640 | 0;
                  if ($7_1) break label$211;
                 }
                 $6_1 = $6_1 + 4294967295 | 0;
                 wasm2asm_i32$0 = $6_1;
                 wasm2asm_i32$1 = 48;
                 HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                };
                $16_1 = $23_1 | 2 | 0;
                $19_1 = $6_1 + 4294967294 | 0;
                wasm2asm_i32$0 = $19_1;
                wasm2asm_i32$1 = $20_1 + 15 | 0;
                HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                wasm2asm_i32$0 = $6_1 + 4294967295 | 0;
                wasm2asm_i32$1 = (wasm2asm_i32$2 = 45, wasm2asm_i32$3 = 43, wasm2asm_i32$4 = ($12_1 | 0) < (0 | 0), wasm2asm_i32$4 ? wasm2asm_i32$2 : wasm2asm_i32$3);
                HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                label$214 : {
                 if (($17_1 & 8 | 0 | 0) == (0 | 0)) {
                  $7_1 = $8_1 + 640 | 0;
                  label$216 : do {
                   i64toi32_i32$0 = $14$hi;
                   i64toi32_i32$0 = $18$hi;
                   i64toi32_i32$0 = $14$hi;
                   i64toi32_i32$1 = $18$hi;
                   $6_1 = $26($14_1 | 0, i64toi32_i32$0 | 0, $18_1 | 0, i64toi32_i32$1 | 0) | 0;
                   $28($8_1 + 32 | 0 | 0, $6_1 | 0);
                   i64toi32_i32$1 = i64toi32_i32$0;
                   i64toi32_i32$1 = $18$hi;
                   i64toi32_i32$4 = $8_1;
                   i64toi32_i32$1 = HEAPU32[($8_1 + 32 | 0) >> 2] | 0;
                   i64toi32_i32$0 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 36 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 37 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 38 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 39 | 0) >> 0] | 0 | 0) << 24);
                   $2125 = i64toi32_i32$1;
                   $2125$hi = i64toi32_i32$0;
                   i64toi32_i32$4 = $8_1 + 40 | 0;
                   i64toi32_i32$0 = HEAPU32[i64toi32_i32$4 >> 2] | 0;
                   i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$4, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                   $2128 = i64toi32_i32$0;
                   $2128$hi = i64toi32_i32$1;
                   i64toi32_i32$1 = $14$hi;
                   i64toi32_i32$0 = $18$hi;
                   i64toi32_i32$4 = $2125$hi;
                   i64toi32_i32$3 = $2128$hi;
                   $34($8_1 + 16 | 0 | 0, $14_1 | 0, i64toi32_i32$1 | 0, $18_1 | 0, i64toi32_i32$0 | 0, $2125 | 0, i64toi32_i32$4 | 0, $2128 | 0, i64toi32_i32$3 | 0);
                   i64toi32_i32$0 = $8_1;
                   i64toi32_i32$3 = HEAPU32[($8_1 + 16 | 0) >> 2] | 0;
                   i64toi32_i32$4 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 20 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 21 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 22 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 23 | 0) >> 0] | 0 | 0) << 24);
                   $2131 = i64toi32_i32$3;
                   $2131$hi = i64toi32_i32$4;
                   i64toi32_i32$0 = $8_1 + 24 | 0;
                   i64toi32_i32$4 = HEAPU32[i64toi32_i32$0 >> 2] | 0;
                   i64toi32_i32$3 = (wasm2asm_i32$0 = i64toi32_i32$0, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                   $2134 = i64toi32_i32$4;
                   $2134$hi = i64toi32_i32$3;
                   i64toi32_i32$3 = $2131$hi;
                   i64toi32_i32$4 = $2134$hi;
                   i64toi32_i32$0 = 0;
                   i64toi32_i32$1 = 1073938432;
                   $33($8_1 | 0, $2131 | 0, i64toi32_i32$3 | 0, $2134 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$1 | 0);
                   $5_1 = $7_1;
                   wasm2asm_i32$0 = $5_1;
                   wasm2asm_i32$1 = HEAPU8[($6_1 + 3424 | 0) >> 0] | 0 | $10_1 | 0;
                   HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                   $7_1 = $5_1 + 1 | 0;
                   i64toi32_i32$4 = $8_1;
                   i64toi32_i32$1 = HEAPU32[$8_1 >> 2] | 0;
                   i64toi32_i32$0 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                   i64toi32_i32$0 = i64toi32_i32$0;
                   $14_1 = i64toi32_i32$1;
                   $14$hi = i64toi32_i32$0;
                   i64toi32_i32$0 = i64toi32_i32$0;
                   i64toi32_i32$4 = $8_1 + 8 | 0;
                   i64toi32_i32$0 = HEAPU32[i64toi32_i32$4 >> 2] | 0;
                   i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$4, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                   i64toi32_i32$1 = i64toi32_i32$1;
                   $18_1 = i64toi32_i32$0;
                   $18$hi = i64toi32_i32$1;
                   i64toi32_i32$1 = i64toi32_i32$1;
                   i64toi32_i32$1 = $14$hi;
                   i64toi32_i32$0 = $18$hi;
                   i64toi32_i32$4 = 0;
                   i64toi32_i32$3 = 0;
                   if ((($7_1 - ($8_1 + 640 | 0) | 0 | 0) != (1 | 0) | (($11_1 | 0) > (0 | 0) | ($24($14_1 | 0, i64toi32_i32$1 | 0, $18_1 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$3 | 0) | 0 | 0) != (0 | 0) | 0 | 0) == (0 | 0) | 0 | 0) == (0 | 0)) {
                    wasm2asm_i32$0 = $5_1 + 1 | 0;
                    wasm2asm_i32$1 = 46;
                    HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                    $7_1 = $5_1 + 2 | 0;
                   }
                   i64toi32_i32$3 = $14$hi;
                   i64toi32_i32$3 = $18$hi;
                   i64toi32_i32$3 = $14$hi;
                   i64toi32_i32$4 = $18$hi;
                   i64toi32_i32$0 = 0;
                   i64toi32_i32$1 = 0;
                   if ($24($14_1 | 0, i64toi32_i32$3 | 0, $18_1 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$1 | 0) | 0) continue label$216;
                   break label$216;
                  } while (1);
                  break label$214;
                 }
                 $5_1 = $8_1 + 640 | 0;
                 label$218 : do {
                  i64toi32_i32$1 = $14$hi;
                  i64toi32_i32$1 = $18$hi;
                  i64toi32_i32$1 = $14$hi;
                  i64toi32_i32$0 = $18$hi;
                  $7_1 = $26($14_1 | 0, i64toi32_i32$1 | 0, $18_1 | 0, i64toi32_i32$0 | 0) | 0;
                  $28($8_1 + 80 | 0 | 0, $7_1 | 0);
                  i64toi32_i32$0 = i64toi32_i32$1;
                  i64toi32_i32$0 = $18$hi;
                  i64toi32_i32$4 = $8_1;
                  i64toi32_i32$0 = HEAPU32[($8_1 + 80 | 0) >> 2] | 0;
                  i64toi32_i32$1 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 84 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 85 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 86 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 87 | 0) >> 0] | 0 | 0) << 24);
                  $2184 = i64toi32_i32$0;
                  $2184$hi = i64toi32_i32$1;
                  i64toi32_i32$4 = $8_1 + 88 | 0;
                  i64toi32_i32$1 = HEAPU32[i64toi32_i32$4 >> 2] | 0;
                  i64toi32_i32$0 = (wasm2asm_i32$0 = i64toi32_i32$4, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                  $2187 = i64toi32_i32$1;
                  $2187$hi = i64toi32_i32$0;
                  i64toi32_i32$0 = $14$hi;
                  i64toi32_i32$1 = $18$hi;
                  i64toi32_i32$4 = $2184$hi;
                  i64toi32_i32$3 = $2187$hi;
                  $34($8_1 - 4294967232 | 0 | 0, $14_1 | 0, i64toi32_i32$0 | 0, $18_1 | 0, i64toi32_i32$1 | 0, $2184 | 0, i64toi32_i32$4 | 0, $2187 | 0, i64toi32_i32$3 | 0);
                  i64toi32_i32$1 = $8_1;
                  i64toi32_i32$3 = HEAPU32[($8_1 + 64 | 0) >> 2] | 0;
                  i64toi32_i32$4 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 68 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 69 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 70 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 71 | 0) >> 0] | 0 | 0) << 24);
                  $2191 = i64toi32_i32$3;
                  $2191$hi = i64toi32_i32$4;
                  i64toi32_i32$1 = $8_1 + 72 | 0;
                  i64toi32_i32$4 = HEAPU32[i64toi32_i32$1 >> 2] | 0;
                  i64toi32_i32$3 = (wasm2asm_i32$0 = i64toi32_i32$1, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                  $2194 = i64toi32_i32$4;
                  $2194$hi = i64toi32_i32$3;
                  i64toi32_i32$3 = $2191$hi;
                  i64toi32_i32$4 = $2194$hi;
                  i64toi32_i32$1 = 0;
                  i64toi32_i32$0 = 1073938432;
                  $33($8_1 + 48 | 0 | 0, $2191 | 0, i64toi32_i32$3 | 0, $2194 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$0 | 0);
                  wasm2asm_i32$0 = $5_1;
                  wasm2asm_i32$1 = HEAPU8[($7_1 + 3424 | 0) >> 0] | 0 | $10_1 | 0;
                  HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                  i64toi32_i32$4 = $8_1 + 56 | 0;
                  i64toi32_i32$0 = HEAPU32[i64toi32_i32$4 >> 2] | 0;
                  i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$4, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
                  i64toi32_i32$1 = i64toi32_i32$1;
                  $18_1 = i64toi32_i32$0;
                  $18$hi = i64toi32_i32$1;
                  i64toi32_i32$4 = $8_1;
                  i64toi32_i32$1 = HEAPU32[($8_1 + 48 | 0) >> 2] | 0;
                  i64toi32_i32$0 = (wasm2asm_i32$0 = $8_1, HEAPU8[(wasm2asm_i32$0 + 52 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 53 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 54 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 55 | 0) >> 0] | 0 | 0) << 24);
                  i64toi32_i32$0 = i64toi32_i32$0;
                  $14_1 = i64toi32_i32$1;
                  $14$hi = i64toi32_i32$0;
                  $7_1 = $5_1 + 1 | 0;
                  if (($7_1 - ($8_1 + 640 | 0) | 0 | 0) == (1 | 0)) {
                   wasm2asm_i32$0 = $5_1 + 1 | 0;
                   wasm2asm_i32$1 = 46;
                   HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                   $7_1 = $5_1 + 2 | 0;
                  }
                  $5_1 = $7_1;
                  i64toi32_i32$0 = $14$hi;
                  i64toi32_i32$0 = $18$hi;
                  i64toi32_i32$0 = $14$hi;
                  i64toi32_i32$1 = $18$hi;
                  i64toi32_i32$4 = 0;
                  i64toi32_i32$3 = 0;
                  if ($24($14_1 | 0, i64toi32_i32$0 | 0, $18_1 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$3 | 0) | 0) continue label$218;
                  break label$218;
                 } while (1);
                };
                $5_1 = 4294967295;
                $20_1 = $28_1 - $19_1 | 0;
                $6_1 = $20_1 + $16_1 | 0;
                if ((2147483645 - $6_1 | 0 | 0) < ($11_1 | 0)) break label$6;
                $12_1 = $17_1 & 73728 | 0;
                $10_1 = $7_1 - ($8_1 + 640 | 0) | 0;
                $22_1 = (wasm2asm_i32$0 = (wasm2asm_i32$0 = $11_1 + 2 | 0, wasm2asm_i32$1 = $10_1, wasm2asm_i32$2 = ($10_1 + 4294967294 | 0 | 0) < ($11_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1), wasm2asm_i32$1 = $10_1, wasm2asm_i32$2 = $11_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                $11_1 = $22_1 + $6_1 | 0;
                if ($12_1 | ($15_1 | 0) <= ($11_1 | 0) | 0) break label$163;
                $17_1 = $15_1 - $11_1 | 0;
                $5_1 = $17_1 >>> 0 < 256 >>> 0;
                $21($8_1 + 368 | 0 | 0, 32 | 0, (wasm2asm_i32$0 = $17_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $5_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
                $6_1 = HEAPU32[$0_1 >> 2] | 0;
                $7_1 = $6_1 & 32 | 0;
                if ($5_1) break label$165;
                $5_1 = ($7_1 | 0) == (0 | 0);
                $7_1 = $17_1;
                label$220 : do {
                 if ($5_1 & 1 | 0) {
                  $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
                  $6_1 = HEAPU32[$0_1 >> 2] | 0;
                 }
                 $9_1 = $6_1 & 32 | 0;
                 $5_1 = ($9_1 | 0) == (0 | 0);
                 $7_1 = $7_1 + 4294967040 | 0;
                 if ($7_1 >>> 0 > 255 >>> 0) continue label$220;
                 break label$220;
                } while (1);
                if ($9_1) break label$163;
                $17_1 = $17_1 & 255 | 0;
                break label$164;
               };
               $16_1 = 0;
               $5_1 = ($9_1 + $6_1 | 0) - $5_1 | 0;
               $5_1 = (wasm2asm_i32$0 = $5_1, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = ($5_1 | 0) > (0 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
               $13_1 = (wasm2asm_i32$0 = $13_1, wasm2asm_i32$1 = $5_1, wasm2asm_i32$2 = ($13_1 | 0) < ($5_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
              };
              $5_1 = 4294967295;
              $19_1 = $13_1 | $16_1 | 0;
              if (($13_1 | 0) > ((wasm2asm_i32$0 = 2147483645, wasm2asm_i32$1 = 2147483646, wasm2asm_i32$2 = $19_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0)) break label$6;
              $26_1 = ($13_1 + (($19_1 | 0) != (0 | 0)) | 0) + 1 | 0;
              label$222 : {
               $38 = ($20_1 | 32 | 0 | 0) != (102 | 0);
               if (($38 | 0) == (0 | 0)) {
                if (($6_1 | 0) > (2147483647 - $26_1 | 0 | 0)) break label$6;
                $6_1 = (wasm2asm_i32$0 = $6_1, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = ($6_1 | 0) > (0 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                break label$222;
               }
               $9_1 = $28_1;
               $5_1 = $6_1 >> 31 | 0;
               $5_1 = ($6_1 + $5_1 | 0) ^ $5_1 | 0;
               if ($5_1) label$225 : do {
                $9_1 = $9_1 + 4294967295 | 0;
                $10_1 = ($5_1 >>> 0) / (10 >>> 0) | 0;
                wasm2asm_i32$0 = $9_1;
                wasm2asm_i32$1 = $5_1 - Math_imul($10_1, 10) | 0 | 48 | 0;
                HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                $12_1 = $5_1 >>> 0 > 9 >>> 0;
                $5_1 = $10_1;
                if ($12_1) continue label$225;
                break label$225;
               } while (1);
               if (($28_1 - $9_1 | 0 | 0) <= (1 | 0)) {
                $5_1 = $9_1 + 4294967295 | 0;
                label$227 : do {
                 wasm2asm_i32$0 = $5_1;
                 wasm2asm_i32$1 = 48;
                 HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                 $9_1 = $28_1 - $5_1 | 0;
                 $10_1 = $5_1 + 4294967295 | 0;
                 $5_1 = $10_1;
                 if (($9_1 | 0) < (2 | 0)) continue label$227;
                 break label$227;
                } while (1);
                $9_1 = $10_1 + 1 | 0;
               }
               $34_1 = $9_1 + 4294967294 | 0;
               wasm2asm_i32$0 = $34_1;
               wasm2asm_i32$1 = $20_1;
               HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
               $5_1 = 4294967295;
               wasm2asm_i32$0 = $9_1 + 4294967295 | 0;
               wasm2asm_i32$1 = (wasm2asm_i32$2 = 45, wasm2asm_i32$3 = 43, wasm2asm_i32$4 = ($6_1 | 0) < (0 | 0), wasm2asm_i32$4 ? wasm2asm_i32$2 : wasm2asm_i32$3);
               HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
               $6_1 = $28_1 - $34_1 | 0;
               if (($6_1 | 0) > (2147483647 - $26_1 | 0 | 0)) break label$6;
              };
              $6_1 = $6_1 + $26_1 | 0;
              if (($6_1 | 0) > ($23_1 ^ 2147483647 | 0 | 0)) break label$6;
              $17_1 = $17_1 & 73728 | 0;
              $20_1 = $6_1 + $23_1 | 0;
              if ($17_1 | ($15_1 | 0) <= ($20_1 | 0) | 0) break label$160;
              $12_1 = $15_1 - $20_1 | 0;
              $5_1 = $12_1 >>> 0 < 256 >>> 0;
              $21($8_1 + 368 | 0 | 0, 32 | 0, (wasm2asm_i32$0 = $12_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $5_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
              $9_1 = HEAPU32[$0_1 >> 2] | 0;
              $6_1 = $9_1 & 32 | 0;
              if ($5_1) break label$162;
              $5_1 = ($6_1 | 0) == (0 | 0);
              $6_1 = $12_1;
              label$228 : do {
               if ($5_1 & 1 | 0) {
                $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
                $9_1 = HEAPU32[$0_1 >> 2] | 0;
               }
               $10_1 = $9_1 & 32 | 0;
               $5_1 = ($10_1 | 0) == (0 | 0);
               $6_1 = $6_1 + 4294967040 | 0;
               if ($6_1 >>> 0 > 255 >>> 0) continue label$228;
               break label$228;
              } while (1);
              if ($10_1) break label$160;
              $12_1 = $12_1 & 255 | 0;
              break label$161;
             };
             if ($7_1) break label$163;
            };
            $11($8_1 + 368 | 0 | 0, $17_1 | 0, $0_1 | 0) | 0;
           };
           if (((HEAPU8[$0_1 >> 0] | 0) & 32 | 0 | 0) == (0 | 0)) $11($13_1 | 0, $16_1 | 0, $0_1 | 0) | 0;
           label$231 : {
            if (($12_1 | 0) != (65536 | 0) | ($15_1 | 0) <= ($11_1 | 0) | 0) break label$231;
            $16_1 = $15_1 - $11_1 | 0;
            $5_1 = $16_1 >>> 0 < 256 >>> 0;
            $21($8_1 + 368 | 0 | 0, 48 | 0, (wasm2asm_i32$0 = $16_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $5_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
            $6_1 = HEAPU32[$0_1 >> 2] | 0;
            $7_1 = $6_1 & 32 | 0;
            label$232 : {
             if (($5_1 | 0) == (0 | 0)) {
              $5_1 = ($7_1 | 0) == (0 | 0);
              $7_1 = $16_1;
              label$234 : do {
               if ($5_1 & 1 | 0) {
                $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
                $6_1 = HEAPU32[$0_1 >> 2] | 0;
               }
               $9_1 = $6_1 & 32 | 0;
               $5_1 = ($9_1 | 0) == (0 | 0);
               $7_1 = $7_1 + 4294967040 | 0;
               if ($7_1 >>> 0 > 255 >>> 0) continue label$234;
               break label$234;
              } while (1);
              if ($9_1) break label$231;
              $16_1 = $16_1 & 255 | 0;
              break label$232;
             }
             if ($7_1) break label$231;
            };
            $11($8_1 + 368 | 0 | 0, $16_1 | 0, $0_1 | 0) | 0;
           };
           if (((HEAPU8[$0_1 >> 0] | 0) & 32 | 0 | 0) == (0 | 0)) $11($8_1 + 640 | 0 | 0, $10_1 | 0, $0_1 | 0) | 0;
           label$237 : {
            $10_1 = $22_1 - $10_1 | 0;
            if (($10_1 | 0) < (1 | 0)) break label$237;
            $5_1 = $10_1 >>> 0 < 256 >>> 0;
            $21($8_1 + 368 | 0 | 0, 48 | 0, (wasm2asm_i32$0 = $10_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $5_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
            $6_1 = HEAPU32[$0_1 >> 2] | 0;
            $7_1 = $6_1 & 32 | 0;
            label$238 : {
             if (($5_1 | 0) == (0 | 0)) {
              $5_1 = ($7_1 | 0) == (0 | 0);
              $7_1 = $10_1;
              label$240 : do {
               if ($5_1 & 1 | 0) {
                $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
                $6_1 = HEAPU32[$0_1 >> 2] | 0;
               }
               $9_1 = $6_1 & 32 | 0;
               $5_1 = ($9_1 | 0) == (0 | 0);
               $7_1 = $7_1 + 4294967040 | 0;
               if ($7_1 >>> 0 > 255 >>> 0) continue label$240;
               break label$240;
              } while (1);
              if ($9_1) break label$237;
              $10_1 = $10_1 & 255 | 0;
              break label$238;
             }
             if ($7_1) break label$237;
            };
            $11($8_1 + 368 | 0 | 0, $10_1 | 0, $0_1 | 0) | 0;
           };
           if (((HEAPU8[$0_1 >> 0] | 0) & 32 | 0 | 0) == (0 | 0)) $11($19_1 | 0, $20_1 | 0, $0_1 | 0) | 0;
           label$243 : {
            if (($12_1 | 0) != (8192 | 0) | ($15_1 | 0) <= ($11_1 | 0) | 0) break label$243;
            $10_1 = $15_1 - $11_1 | 0;
            $5_1 = $10_1 >>> 0 < 256 >>> 0;
            $21($8_1 + 368 | 0 | 0, 32 | 0, (wasm2asm_i32$0 = $10_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $5_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
            $6_1 = HEAPU32[$0_1 >> 2] | 0;
            $7_1 = $6_1 & 32 | 0;
            label$244 : {
             if (($5_1 | 0) == (0 | 0)) {
              $5_1 = ($7_1 | 0) == (0 | 0);
              $7_1 = $10_1;
              label$246 : do {
               if ($5_1 & 1 | 0) {
                $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
                $6_1 = HEAPU32[$0_1 >> 2] | 0;
               }
               $9_1 = $6_1 & 32 | 0;
               $5_1 = ($9_1 | 0) == (0 | 0);
               $7_1 = $7_1 + 4294967040 | 0;
               if ($7_1 >>> 0 > 255 >>> 0) continue label$246;
               break label$246;
              } while (1);
              if ($9_1) break label$243;
              $10_1 = $10_1 & 255 | 0;
              break label$244;
             }
             if ($7_1) break label$243;
            };
            $11($8_1 + 368 | 0 | 0, $10_1 | 0, $0_1 | 0) | 0;
           };
           $5_1 = (wasm2asm_i32$0 = $15_1, wasm2asm_i32$1 = $11_1, wasm2asm_i32$2 = ($15_1 | 0) > ($11_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
           if (($5_1 | 0) >= (0 | 0)) continue label$5;
           break label$4;
          };
          if ($6_1) break label$160;
         };
         $11($8_1 + 368 | 0 | 0, $12_1 | 0, $0_1 | 0) | 0;
        };
        if (((HEAPU8[$0_1 >> 0] | 0) & 32 | 0 | 0) == (0 | 0)) $11($30_1 | 0, $23_1 | 0, $0_1 | 0) | 0;
        label$249 : {
         if (($17_1 | 0) != (65536 | 0) | ($15_1 | 0) <= ($20_1 | 0) | 0) break label$249;
         $12_1 = $15_1 - $20_1 | 0;
         $5_1 = $12_1 >>> 0 < 256 >>> 0;
         $21($8_1 + 368 | 0 | 0, 48 | 0, (wasm2asm_i32$0 = $12_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $5_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
         $9_1 = HEAPU32[$0_1 >> 2] | 0;
         $6_1 = $9_1 & 32 | 0;
         label$250 : {
          if (($5_1 | 0) == (0 | 0)) {
           $5_1 = ($6_1 | 0) == (0 | 0);
           $6_1 = $12_1;
           label$252 : do {
            if ($5_1 & 1 | 0) {
             $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
             $9_1 = HEAPU32[$0_1 >> 2] | 0;
            }
            $10_1 = $9_1 & 32 | 0;
            $5_1 = ($10_1 | 0) == (0 | 0);
            $6_1 = $6_1 + 4294967040 | 0;
            if ($6_1 >>> 0 > 255 >>> 0) continue label$252;
            break label$252;
           } while (1);
           if ($10_1) break label$249;
           $12_1 = $12_1 & 255 | 0;
           break label$250;
          }
          if ($6_1) break label$249;
         };
         $11($8_1 + 368 | 0 | 0, $12_1 | 0, $0_1 | 0) | 0;
        };
        label$254 : {
         label$255 : {
          label$256 : {
           label$257 : {
            label$258 : {
             label$259 : {
              label$260 : {
               label$261 : {
                if (($38 | 0) == (0 | 0)) {
                 $12_1 = (wasm2asm_i32$0 = $22_1, wasm2asm_i32$1 = $7_1, wasm2asm_i32$2 = $7_1 >>> 0 > $22_1 >>> 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                 $10_1 = $12_1;
                 label$263 : do {
                  label$264 : {
                   $5_1 = HEAPU32[$10_1 >> 2] | 0;
                   if ($5_1) {
                    $7_1 = 0;
                    label$266 : do {
                     $6_1 = ($5_1 >>> 0) / (10 >>> 0) | 0;
                     wasm2asm_i32$0 = $35 + $7_1 | 0;
                     wasm2asm_i32$1 = $5_1 - Math_imul($6_1, 10) | 0 | 48 | 0;
                     HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                     $7_1 = $7_1 + 4294967295 | 0;
                     $9_1 = $5_1 >>> 0 > 9 >>> 0;
                     $5_1 = $6_1;
                     if ($9_1) continue label$266;
                     break label$266;
                    } while (1);
                    break label$264;
                   }
                   $7_1 = 0;
                  };
                  $5_1 = $27_1 + $7_1 | 0;
                  label$267 : {
                   label$268 : {
                    label$269 : {
                     if (($10_1 | 0) != ($12_1 | 0)) {
                      if ($5_1 >>> 0 <= ($8_1 + 640 | 0) >>> 0) break label$269;
                      $21($8_1 + 640 | 0 | 0, 48 | 0, $7_1 + 9 | 0 | 0) | 0;
                      $5_1 = $8_1 + 640 | 0;
                      if (((HEAPU8[$0_1 >> 0] | 0) & 32 | 0 | 0) == (0 | 0)) break label$268;
                      break label$267;
                     }
                     if ($7_1) break label$269;
                     $5_1 = $5_1 + 4294967295 | 0;
                     wasm2asm_i32$0 = $5_1;
                     wasm2asm_i32$1 = 48;
                     HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                    };
                    if ((HEAPU8[$0_1 >> 0] | 0) & 32 | 0) break label$267;
                   };
                   $11($5_1 | 0, $27_1 - $5_1 | 0 | 0, $0_1 | 0) | 0;
                  };
                  $10_1 = $10_1 + 4 | 0;
                  if ($10_1 >>> 0 <= $22_1 >>> 0) continue label$263;
                  break label$263;
                 } while (1);
                 label$271 : {
                  if (($19_1 | 0) == (0 | 0)) break label$271;
                  if ((HEAPU8[$0_1 >> 0] | 0) & 32 | 0) break label$271;
                  $11(3475 | 0, 1 | 0, $0_1 | 0) | 0;
                 };
                 label$272 : {
                  if (($13_1 | 0) < (1 | 0) | $10_1 >>> 0 >= $11_1 >>> 0 | 0) break label$272;
                  label$273 : do {
                   $5_1 = $27_1;
                   label$274 : {
                    $7_1 = HEAPU32[$10_1 >> 2] | 0;
                    if ($7_1) {
                     label$276 : do {
                      $5_1 = $5_1 + 4294967295 | 0;
                      $6_1 = ($7_1 >>> 0) / (10 >>> 0) | 0;
                      wasm2asm_i32$0 = $5_1;
                      wasm2asm_i32$1 = $7_1 - Math_imul($6_1, 10) | 0 | 48 | 0;
                      HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                      $9_1 = $7_1 >>> 0 > 9 >>> 0;
                      $7_1 = $6_1;
                      if ($9_1) continue label$276;
                      break label$276;
                     } while (1);
                     if ($5_1 >>> 0 <= ($8_1 + 640 | 0) >>> 0) break label$274;
                    }
                    $21($8_1 + 640 | 0 | 0, 48 | 0, $5_1 + $33_1 | 0 | 0) | 0;
                    label$277 : do {
                     $5_1 = $5_1 + 4294967295 | 0;
                     if ($5_1 >>> 0 > ($8_1 + 640 | 0) >>> 0) continue label$277;
                     break label$277;
                    } while (1);
                   };
                   if (((HEAPU8[$0_1 >> 0] | 0) & 32 | 0 | 0) == (0 | 0)) $11($5_1 | 0, (wasm2asm_i32$0 = $13_1, wasm2asm_i32$1 = 9, wasm2asm_i32$2 = ($13_1 | 0) < (9 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0, $0_1 | 0) | 0;
                   $13_1 = $13_1 + 4294967287 | 0;
                   if (($13_1 | 0) < (1 | 0)) break label$272;
                   $10_1 = $10_1 + 4 | 0;
                   if ($10_1 >>> 0 < $11_1 >>> 0) continue label$273;
                   break label$273;
                  } while (1);
                 };
                 if (($13_1 | 0) < (1 | 0)) break label$256;
                 $5_1 = $13_1 >>> 0 < 256 >>> 0;
                 $21($8_1 + 368 | 0 | 0, 48 | 0, (wasm2asm_i32$0 = $13_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $5_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
                 $6_1 = HEAPU32[$0_1 >> 2] | 0;
                 $7_1 = $6_1 & 32 | 0;
                 if ($5_1) break label$261;
                 $5_1 = ($7_1 | 0) == (0 | 0);
                 $7_1 = $13_1;
                 label$279 : do {
                  if ($5_1 & 1 | 0) {
                   $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
                   $6_1 = HEAPU32[$0_1 >> 2] | 0;
                  }
                  $9_1 = $6_1 & 32 | 0;
                  $5_1 = ($9_1 | 0) == (0 | 0);
                  $7_1 = $7_1 + 4294967040 | 0;
                  if ($7_1 >>> 0 > 255 >>> 0) continue label$279;
                  break label$279;
                 } while (1);
                 if ($9_1) break label$256;
                 $13_1 = $13_1 & 255 | 0;
                 break label$260;
                }
                if (($13_1 | 0) <= (4294967295 | 0)) break label$257;
                $12_1 = (wasm2asm_i32$0 = $11_1, wasm2asm_i32$1 = $7_1 + 4 | 0, wasm2asm_i32$2 = $31_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
                if (($16_1 | 0) == (0 | 0)) break label$259;
                $10_1 = $7_1;
                label$281 : do {
                 $9_1 = $27_1;
                 label$282 : {
                  $5_1 = HEAPU32[$10_1 >> 2] | 0;
                  if ($5_1) {
                   $6_1 = 0;
                   label$284 : do {
                    $9_1 = ($5_1 >>> 0) / (10 >>> 0) | 0;
                    wasm2asm_i32$0 = ($8_1 + $6_1 | 0) + 648 | 0;
                    wasm2asm_i32$1 = $5_1 - Math_imul($9_1, 10) | 0 | 48 | 0;
                    HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                    $6_1 = $6_1 + 4294967295 | 0;
                    $11_1 = $5_1 >>> 0 > 9 >>> 0;
                    $5_1 = $9_1;
                    if ($11_1) continue label$284;
                    break label$284;
                   } while (1);
                   $9_1 = ($8_1 + $6_1 | 0) + 649 | 0;
                   if ($6_1) break label$282;
                  }
                  $9_1 = $9_1 + 4294967295 | 0;
                  wasm2asm_i32$0 = $9_1;
                  wasm2asm_i32$1 = 48;
                  HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                 };
                 label$285 : {
                  if (($10_1 | 0) != ($7_1 | 0)) {
                   if ($9_1 >>> 0 <= ($8_1 + 640 | 0) >>> 0) break label$285;
                   $21($8_1 + 640 | 0 | 0, 48 | 0, $9_1 + $33_1 | 0 | 0) | 0;
                   label$287 : do {
                    $9_1 = $9_1 + 4294967295 | 0;
                    if ($9_1 >>> 0 > ($8_1 + 640 | 0) >>> 0) continue label$287;
                    break label$287;
                   } while (1);
                   break label$285;
                  }
                  $5_1 = HEAPU32[$0_1 >> 2] | 0;
                  if (($5_1 & 32 | 0 | 0) == (0 | 0)) {
                   $11($9_1 | 0, 1 | 0, $0_1 | 0) | 0;
                   $5_1 = HEAPU32[$0_1 >> 2] | 0;
                  }
                  $9_1 = $9_1 + 1 | 0;
                  if ($5_1 & 32 | 0) break label$285;
                  $11(3475 | 0, 1 | 0, $0_1 | 0) | 0;
                 };
                 $5_1 = $27_1 - $9_1 | 0;
                 if (((HEAPU8[$0_1 >> 0] | 0) & 32 | 0 | 0) == (0 | 0)) $11($9_1 | 0, (wasm2asm_i32$0 = $5_1, wasm2asm_i32$1 = $13_1, wasm2asm_i32$2 = ($13_1 | 0) > ($5_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0, $0_1 | 0) | 0;
                 $13_1 = $13_1 - $5_1 | 0;
                 $10_1 = $10_1 + 4 | 0;
                 if ($10_1 >>> 0 >= $12_1 >>> 0) break label$258;
                 if (($13_1 | 0) > (4294967295 | 0)) continue label$281;
                 break label$281;
                } while (1);
                break label$258;
               };
               if ($7_1) break label$256;
              };
              $11($8_1 + 368 | 0 | 0, $13_1 | 0, $0_1 | 0) | 0;
              if (($17_1 | 0) == (8192 | 0)) break label$255;
              break label$254;
             };
             $10_1 = $7_1;
             label$290 : do {
              $9_1 = $27_1;
              label$291 : {
               $5_1 = HEAPU32[$10_1 >> 2] | 0;
               if ($5_1) {
                $6_1 = 0;
                label$293 : do {
                 $9_1 = ($5_1 >>> 0) / (10 >>> 0) | 0;
                 wasm2asm_i32$0 = ($8_1 + $6_1 | 0) + 648 | 0;
                 wasm2asm_i32$1 = $5_1 - Math_imul($9_1, 10) | 0 | 48 | 0;
                 HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
                 $6_1 = $6_1 + 4294967295 | 0;
                 $11_1 = $5_1 >>> 0 > 9 >>> 0;
                 $5_1 = $9_1;
                 if ($11_1) continue label$293;
                 break label$293;
                } while (1);
                $9_1 = ($8_1 + $6_1 | 0) + 649 | 0;
                if ($6_1) break label$291;
               }
               $9_1 = $9_1 + 4294967295 | 0;
               wasm2asm_i32$0 = $9_1;
               wasm2asm_i32$1 = 48;
               HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
              };
              label$294 : {
               if (($10_1 | 0) != ($7_1 | 0)) {
                if ($9_1 >>> 0 <= ($8_1 + 640 | 0) >>> 0) break label$294;
                $21($8_1 + 640 | 0 | 0, 48 | 0, $9_1 + $33_1 | 0 | 0) | 0;
                label$296 : do {
                 $9_1 = $9_1 + 4294967295 | 0;
                 if ($9_1 >>> 0 > ($8_1 + 640 | 0) >>> 0) continue label$296;
                 break label$296;
                } while (1);
                break label$294;
               }
               if (((HEAPU8[$0_1 >> 0] | 0) & 32 | 0 | 0) == (0 | 0)) $11($9_1 | 0, 1 | 0, $0_1 | 0) | 0;
               $9_1 = $9_1 + 1 | 0;
               if (($13_1 | 0) < (1 | 0)) break label$294;
               if ((HEAPU8[$0_1 >> 0] | 0) & 32 | 0) break label$294;
               $11(3475 | 0, 1 | 0, $0_1 | 0) | 0;
              };
              $5_1 = $27_1 - $9_1 | 0;
              if (((HEAPU8[$0_1 >> 0] | 0) & 32 | 0 | 0) == (0 | 0)) $11($9_1 | 0, (wasm2asm_i32$0 = $5_1, wasm2asm_i32$1 = $13_1, wasm2asm_i32$2 = ($13_1 | 0) > ($5_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0, $0_1 | 0) | 0;
              $13_1 = $13_1 - $5_1 | 0;
              $10_1 = $10_1 + 4 | 0;
              if ($10_1 >>> 0 >= $12_1 >>> 0) break label$258;
              if (($13_1 | 0) > (4294967295 | 0)) continue label$290;
              break label$290;
             } while (1);
            };
            if (($13_1 | 0) < (1 | 0)) break label$257;
            $7_1 = $13_1 >>> 0 < 256 >>> 0;
            $21($8_1 + 368 | 0 | 0, 48 | 0, (wasm2asm_i32$0 = $13_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $7_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
            $6_1 = HEAPU32[$0_1 >> 2] | 0;
            $5_1 = $6_1 & 32 | 0;
            label$299 : {
             if (($7_1 | 0) == (0 | 0)) {
              $5_1 = ($5_1 | 0) == (0 | 0);
              $7_1 = $13_1;
              label$301 : do {
               if ($5_1 & 1 | 0) {
                $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
                $6_1 = HEAPU32[$0_1 >> 2] | 0;
               }
               $9_1 = $6_1 & 32 | 0;
               $5_1 = ($9_1 | 0) == (0 | 0);
               $7_1 = $7_1 + 4294967040 | 0;
               if ($7_1 >>> 0 > 255 >>> 0) continue label$301;
               break label$301;
              } while (1);
              if ($9_1) break label$257;
              $13_1 = $13_1 & 255 | 0;
              break label$299;
             }
             if ($5_1) break label$257;
            };
            $11($8_1 + 368 | 0 | 0, $13_1 | 0, $0_1 | 0) | 0;
           };
           if ((HEAPU8[$0_1 >> 0] | 0) & 32 | 0) break label$256;
           $11($34_1 | 0, $28_1 - $34_1 | 0 | 0, $0_1 | 0) | 0;
          };
          if (($17_1 | 0) != (8192 | 0)) break label$254;
         };
         if (($15_1 | 0) <= ($20_1 | 0)) break label$254;
         $11_1 = $15_1 - $20_1 | 0;
         $5_1 = $11_1 >>> 0 < 256 >>> 0;
         $21($8_1 + 368 | 0 | 0, 32 | 0, (wasm2asm_i32$0 = $11_1, wasm2asm_i32$1 = 256, wasm2asm_i32$2 = $5_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) | 0;
         $6_1 = HEAPU32[$0_1 >> 2] | 0;
         $7_1 = $6_1 & 32 | 0;
         label$303 : {
          if (($5_1 | 0) == (0 | 0)) {
           $5_1 = ($7_1 | 0) == (0 | 0);
           $7_1 = $11_1;
           label$305 : do {
            if ($5_1 & 1 | 0) {
             $11($8_1 + 368 | 0 | 0, 256 | 0, $0_1 | 0) | 0;
             $6_1 = HEAPU32[$0_1 >> 2] | 0;
            }
            $9_1 = $6_1 & 32 | 0;
            $5_1 = ($9_1 | 0) == (0 | 0);
            $7_1 = $7_1 + 4294967040 | 0;
            if ($7_1 >>> 0 > 255 >>> 0) continue label$305;
            break label$305;
           } while (1);
           if ($9_1) break label$254;
           $11_1 = $11_1 & 255 | 0;
           break label$303;
          }
          if ($7_1) break label$254;
         };
         $11($8_1 + 368 | 0 | 0, $11_1 | 0, $0_1 | 0) | 0;
        };
        $5_1 = (wasm2asm_i32$0 = $15_1, wasm2asm_i32$1 = $20_1, wasm2asm_i32$2 = ($15_1 | 0) > ($20_1 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
        if (($5_1 | 0) >= (0 | 0)) continue label$5;
        break label$4;
       };
       if (($5_1 | 0) >= (0 | 0)) continue label$5;
       break label$5;
      } while (1);
     };
     wasm2asm_i32$0 = 31;
     wasm2asm_i32$1 = 75;
     HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    };
    $21_1 = 4294967295;
   };
   global$0 = $8_1 + 8016 | 0;
   return $21_1 | 0;
  };
  global$0 = $8_1 + 8016 | 0;
  return 0 | 0;
 }
 
 function $19($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, i64toi32_i32$2 = 0, $3_1 = 0, $29_1 = 0, $37 = 0, $45 = 0, $53 = 0, $67 = 0, $70 = 0, $4_1 = 0, $4$hi = 0, $82 = 0, $94 = 0, $102 = 0, $112 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  label$1 : {
   label$2 : {
    label$3 : {
     label$4 : {
      $3_1 = global$0 - 16 | 0;
      global$0 = $3_1;
      label$5 : {
       label$6 : {
        label$7 : {
         label$8 : {
          label$9 : {
           label$10 : {
            label$11 : {
             label$12 : {
              label$13 : {
               label$14 : {
                label$15 : {
                 label$16 : {
                  label$17 : {
                   label$18 : {
                    label$19 : {
                     label$20 : {
                      label$21 : {
                       $1_1 = $1_1 + 4294967287 | 0;
                       if ($1_1 >>> 0 <= 17 >>> 0) {
                        label$23 : {
                         switch ($1_1 - 1 | 0 | 0) {
                         case 0:
                          break label$21;
                         case 1:
                          break label$20;
                         case 2:
                          break label$19;
                         case 3:
                          break label$18;
                         case 4:
                          break label$17;
                         case 5:
                          break label$16;
                         case 6:
                          break label$15;
                         case 7:
                          break label$14;
                         case 8:
                          break label$13;
                         case 9:
                          break label$12;
                         case 10:
                          break label$11;
                         case 11:
                          break label$10;
                         case 12:
                          break label$9;
                         case 13:
                          break label$8;
                         case 14:
                          break label$7;
                         case 15:
                          break label$6;
                         case 16:
                          break label$5;
                         default:
                          break label$23;
                         };
                        };
                        $1_1 = HEAPU32[$2_1 >> 2] | 0;
                        wasm2asm_i32$0 = $2_1;
                        wasm2asm_i32$1 = $1_1 + 4 | 0;
                        HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                        wasm2asm_i32$0 = $0_1;
                        wasm2asm_i32$1 = HEAPU32[$1_1 >> 2] | 0;
                        HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                       }
                       break label$1;
                      };
                      break label$4;
                     };
                     break label$3;
                    };
                    break label$2;
                   };
                   break label$4;
                  };
                  break label$3;
                 };
                 $1_1 = HEAPU32[$2_1 >> 2] | 0;
                 wasm2asm_i32$0 = $2_1;
                 wasm2asm_i32$1 = $1_1 + 4 | 0;
                 HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                 i64toi32_i32$2 = $1_1;
                 i64toi32_i32$0 = HEAP16[$1_1 >> 1] | 0;
                 i64toi32_i32$1 = i64toi32_i32$0 >> 31 | 0;
                 $29_1 = i64toi32_i32$0;
                 i64toi32_i32$0 = $0_1;
                 i64toi32_i32$1 = i64toi32_i32$1;
                 wasm2asm_i32$0 = i64toi32_i32$0;
                 wasm2asm_i32$1 = $29_1;
                 HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                 wasm2asm_i32$0 = i64toi32_i32$0;
                 wasm2asm_i32$1 = i64toi32_i32$1;
                 (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
                 break label$1;
                };
                $1_1 = HEAPU32[$2_1 >> 2] | 0;
                wasm2asm_i32$0 = $2_1;
                wasm2asm_i32$1 = $1_1 + 4 | 0;
                HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                i64toi32_i32$2 = $1_1;
                i64toi32_i32$1 = HEAPU16[$1_1 >> 1] | 0;
                i64toi32_i32$0 = 0;
                $37 = i64toi32_i32$1;
                i64toi32_i32$1 = $0_1;
                i64toi32_i32$0 = i64toi32_i32$0;
                wasm2asm_i32$0 = i64toi32_i32$1;
                wasm2asm_i32$1 = $37;
                HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                wasm2asm_i32$0 = i64toi32_i32$1;
                wasm2asm_i32$1 = i64toi32_i32$0;
                (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
                break label$1;
               };
               $1_1 = HEAPU32[$2_1 >> 2] | 0;
               wasm2asm_i32$0 = $2_1;
               wasm2asm_i32$1 = $1_1 + 4 | 0;
               HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
               i64toi32_i32$2 = $1_1;
               i64toi32_i32$0 = HEAP8[$1_1 >> 0] | 0;
               i64toi32_i32$1 = i64toi32_i32$0 >> 31 | 0;
               $45 = i64toi32_i32$0;
               i64toi32_i32$0 = $0_1;
               i64toi32_i32$1 = i64toi32_i32$1;
               wasm2asm_i32$0 = i64toi32_i32$0;
               wasm2asm_i32$1 = $45;
               HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
               wasm2asm_i32$0 = i64toi32_i32$0;
               wasm2asm_i32$1 = i64toi32_i32$1;
               (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
               break label$1;
              };
              $1_1 = HEAPU32[$2_1 >> 2] | 0;
              wasm2asm_i32$0 = $2_1;
              wasm2asm_i32$1 = $1_1 + 4 | 0;
              HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
              i64toi32_i32$2 = $1_1;
              i64toi32_i32$1 = HEAPU8[$1_1 >> 0] | 0;
              i64toi32_i32$0 = 0;
              $53 = i64toi32_i32$1;
              i64toi32_i32$1 = $0_1;
              i64toi32_i32$0 = i64toi32_i32$0;
              wasm2asm_i32$0 = i64toi32_i32$1;
              wasm2asm_i32$1 = $53;
              HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
              wasm2asm_i32$0 = i64toi32_i32$1;
              wasm2asm_i32$1 = i64toi32_i32$0;
              (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
              break label$1;
             };
             break label$2;
            };
            break label$3;
           };
           break label$2;
          };
          break label$2;
         };
         break label$4;
        };
        break label$3;
       };
       $1_1 = ((HEAPU32[$2_1 >> 2] | 0) + 7 | 0) & 4294967288 | 0;
       wasm2asm_i32$0 = $2_1;
       wasm2asm_i32$1 = $1_1 + 8 | 0;
       HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
       $25($3_1 | 0, +(+HEAPF64[$1_1 >> 3]));
       i64toi32_i32$2 = $3_1 + 8 | 0;
       i64toi32_i32$0 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
       i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
       $67 = i64toi32_i32$0;
       i64toi32_i32$0 = $0_1;
       i64toi32_i32$1 = i64toi32_i32$1;
       wasm2asm_i32$0 = i64toi32_i32$0;
       wasm2asm_i32$1 = $67;
       HEAP32[(wasm2asm_i32$0 + 8 | 0) >> 2] = wasm2asm_i32$1;
       wasm2asm_i32$0 = i64toi32_i32$0;
       wasm2asm_i32$1 = i64toi32_i32$1;
       (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 12 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 13 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 14 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 15 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
       i64toi32_i32$2 = $3_1;
       i64toi32_i32$1 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
       i64toi32_i32$0 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
       $70 = i64toi32_i32$1;
       i64toi32_i32$1 = $0_1;
       i64toi32_i32$0 = i64toi32_i32$0;
       wasm2asm_i32$0 = i64toi32_i32$1;
       wasm2asm_i32$1 = $70;
       HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
       wasm2asm_i32$0 = i64toi32_i32$1;
       wasm2asm_i32$1 = i64toi32_i32$0;
       (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
       break label$1;
      };
      $1_1 = ((HEAPU32[$2_1 >> 2] | 0) + 15 | 0) & 4294967280 | 0;
      wasm2asm_i32$0 = $2_1;
      wasm2asm_i32$1 = $1_1 + 16 | 0;
      HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
      i64toi32_i32$2 = $1_1;
      i64toi32_i32$0 = HEAPU32[$1_1 >> 2] | 0;
      i64toi32_i32$1 = (wasm2asm_i32$0 = $1_1, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
      i64toi32_i32$1 = i64toi32_i32$1;
      $4_1 = i64toi32_i32$0;
      $4$hi = i64toi32_i32$1;
      i64toi32_i32$2 = $1_1;
      i64toi32_i32$1 = HEAPU32[($1_1 + 8 | 0) >> 2] | 0;
      i64toi32_i32$0 = (wasm2asm_i32$0 = $1_1, HEAPU8[(wasm2asm_i32$0 + 12 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 13 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 14 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 15 | 0) >> 0] | 0 | 0) << 24);
      $82 = i64toi32_i32$1;
      i64toi32_i32$1 = $0_1;
      i64toi32_i32$0 = i64toi32_i32$0;
      wasm2asm_i32$0 = i64toi32_i32$1;
      wasm2asm_i32$1 = $82;
      HEAP32[(wasm2asm_i32$0 + 8 | 0) >> 2] = wasm2asm_i32$1;
      wasm2asm_i32$0 = i64toi32_i32$1;
      wasm2asm_i32$1 = i64toi32_i32$0;
      (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 12 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 13 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 14 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 15 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
      i64toi32_i32$0 = $4$hi;
      i64toi32_i32$1 = i64toi32_i32$1;
      i64toi32_i32$0 = i64toi32_i32$0;
      wasm2asm_i32$0 = i64toi32_i32$1;
      wasm2asm_i32$1 = $4_1;
      HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
      wasm2asm_i32$0 = i64toi32_i32$1;
      wasm2asm_i32$1 = i64toi32_i32$0;
      (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
      global$0 = $3_1 + 16 | 0;
      return;
     };
     $1_1 = HEAPU32[$2_1 >> 2] | 0;
     wasm2asm_i32$0 = $2_1;
     wasm2asm_i32$1 = $1_1 + 4 | 0;
     HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
     i64toi32_i32$2 = $1_1;
     i64toi32_i32$0 = HEAP32[$1_1 >> 2] | 0;
     i64toi32_i32$1 = i64toi32_i32$0 >> 31 | 0;
     $94 = i64toi32_i32$0;
     i64toi32_i32$0 = $0_1;
     i64toi32_i32$1 = i64toi32_i32$1;
     wasm2asm_i32$0 = i64toi32_i32$0;
     wasm2asm_i32$1 = $94;
     HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
     wasm2asm_i32$0 = i64toi32_i32$0;
     wasm2asm_i32$1 = i64toi32_i32$1;
     (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
     break label$1;
    };
    $1_1 = HEAPU32[$2_1 >> 2] | 0;
    wasm2asm_i32$0 = $2_1;
    wasm2asm_i32$1 = $1_1 + 4 | 0;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    i64toi32_i32$2 = $1_1;
    i64toi32_i32$1 = HEAPU32[$1_1 >> 2] | 0;
    i64toi32_i32$0 = 0;
    $102 = i64toi32_i32$1;
    i64toi32_i32$1 = $0_1;
    i64toi32_i32$0 = i64toi32_i32$0;
    wasm2asm_i32$0 = i64toi32_i32$1;
    wasm2asm_i32$1 = $102;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    wasm2asm_i32$0 = i64toi32_i32$1;
    wasm2asm_i32$1 = i64toi32_i32$0;
    (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
    break label$1;
   };
   $1_1 = ((HEAPU32[$2_1 >> 2] | 0) + 7 | 0) & 4294967288 | 0;
   wasm2asm_i32$0 = $2_1;
   wasm2asm_i32$1 = $1_1 + 8 | 0;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   i64toi32_i32$2 = $1_1;
   i64toi32_i32$0 = HEAPU32[$1_1 >> 2] | 0;
   i64toi32_i32$1 = (wasm2asm_i32$0 = $1_1, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
   $112 = i64toi32_i32$0;
   i64toi32_i32$0 = $0_1;
   i64toi32_i32$1 = i64toi32_i32$1;
   wasm2asm_i32$0 = i64toi32_i32$0;
   wasm2asm_i32$1 = $112;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = i64toi32_i32$0;
   wasm2asm_i32$1 = i64toi32_i32$1;
   (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  };
  global$0 = $3_1 + 16 | 0;
 }
 
 function $20($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var $3_1 = 0, $4_1 = 0, $5_1 = 0, $6_1 = 0, $7_1 = 0, $8_1 = 0, $9_1 = 0, $10_1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0;
  label$1 : {
   label$2 : {
    label$3 : {
     if ((($2_1 | 0) == (0 | 0) | ($1_1 & 3 | 0 | 0) == (0 | 0) | 0 | 0) == (0 | 0)) {
      $3_1 = $0_1;
      label$5 : {
       label$6 : do {
        wasm2asm_i32$0 = $3_1;
        wasm2asm_i32$1 = HEAPU8[$1_1 >> 0] | 0;
        HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
        $4_1 = $2_1 + 4294967295 | 0;
        $3_1 = $3_1 + 1 | 0;
        $1_1 = $1_1 + 1 | 0;
        if (($2_1 | 0) == (1 | 0)) break label$5;
        $2_1 = $4_1;
        if ($1_1 & 3 | 0) continue label$6;
        break label$6;
       } while (1);
      };
      if (($3_1 & 3 | 0 | 0) == (0 | 0)) break label$3;
      break label$2;
     }
     $4_1 = $2_1;
     $3_1 = $0_1;
     if ($3_1 & 3 | 0) break label$2;
    };
    label$7 : {
     label$8 : {
      if ($4_1 >>> 0 >= 16 >>> 0) {
       $6_1 = $4_1 + 4294967280 | 0;
       $7_1 = $6_1 & 4294967280 | 0;
       $8_1 = $7_1 + 16 | 0;
       $5_1 = $3_1 + $8_1 | 0;
       $2_1 = $1_1;
       label$10 : do {
        wasm2asm_i32$0 = $3_1;
        wasm2asm_i32$1 = HEAPU32[$2_1 >> 2] | 0;
        HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3_1 + 4 | 0;
        wasm2asm_i32$1 = HEAPU32[($2_1 + 4 | 0) >> 2] | 0;
        HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3_1 + 8 | 0;
        wasm2asm_i32$1 = HEAPU32[($2_1 + 8 | 0) >> 2] | 0;
        HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3_1 + 12 | 0;
        wasm2asm_i32$1 = HEAPU32[($2_1 + 12 | 0) >> 2] | 0;
        HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
        $3_1 = $3_1 + 16 | 0;
        $2_1 = $2_1 + 16 | 0;
        $4_1 = $4_1 + 4294967280 | 0;
        if ($4_1 >>> 0 > 15 >>> 0) continue label$10;
        break label$10;
       } while (1);
       $1_1 = $1_1 + $8_1 | 0;
       $3_1 = 8;
       $4_1 = $6_1 - $7_1 | 0;
       if ($4_1 & 8 | 0) break label$8;
       break label$7;
      }
      $5_1 = $3_1;
      $3_1 = 8;
      if (($4_1 & 8 | 0 | 0) == (0 | 0)) break label$7;
     };
     wasm2asm_i32$0 = $5_1;
     wasm2asm_i32$1 = HEAPU32[$1_1 >> 2] | 0;
     HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
     wasm2asm_i32$0 = $5_1;
     wasm2asm_i32$1 = HEAPU32[($1_1 + 4 | 0) >> 2] | 0;
     HEAP32[(wasm2asm_i32$0 + 4 | 0) >> 2] = wasm2asm_i32$1;
     $1_1 = $1_1 + $3_1 | 0;
     $5_1 = $5_1 + $3_1 | 0;
    };
    label$11 : {
     label$12 : {
      label$13 : {
       if (($4_1 & 4 | 0 | 0) == (0 | 0)) {
        $3_1 = 2;
        if ($4_1 & 2 | 0) break label$13;
        break label$12;
       }
       wasm2asm_i32$0 = $5_1;
       wasm2asm_i32$1 = HEAPU32[$1_1 >> 2] | 0;
       HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
       $1_1 = $1_1 + 4 | 0;
       $5_1 = $5_1 + 4 | 0;
       $3_1 = 2;
       if (($4_1 & 2 | 0 | 0) == (0 | 0)) break label$12;
      };
      wasm2asm_i32$0 = $5_1;
      wasm2asm_i32$1 = HEAPU8[$1_1 >> 0] | 0;
      HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
      wasm2asm_i32$0 = $5_1;
      wasm2asm_i32$1 = HEAPU8[($1_1 + 1 | 0) >> 0] | 0;
      HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
      $5_1 = $5_1 + $3_1 | 0;
      $1_1 = $1_1 + $3_1 | 0;
      if ($4_1 & 1 | 0) break label$11;
      break label$1;
     };
     if (($4_1 & 1 | 0 | 0) == (0 | 0)) break label$1;
    };
    wasm2asm_i32$0 = $5_1;
    wasm2asm_i32$1 = HEAPU8[$1_1 >> 0] | 0;
    HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
    return $0_1 | 0;
   };
   label$15 : {
    label$16 : {
     label$17 : {
      label$18 : {
       label$19 : {
        label$20 : {
         label$21 : {
          label$22 : {
           label$23 : {
            label$24 : {
             label$25 : {
              label$26 : {
               if ($4_1 >>> 0 < 32 >>> 0) break label$26;
               $2_1 = $3_1 & 3 | 0;
               if (($2_1 | 0) == (3 | 0)) break label$25;
               if (($2_1 | 0) == (2 | 0)) break label$24;
               if (($2_1 | 0) != (1 | 0)) break label$26;
               wasm2asm_i32$0 = $3_1;
               wasm2asm_i32$1 = HEAPU8[($1_1 + 1 | 0) >> 0] | 0;
               HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
               $6_1 = HEAPU32[$1_1 >> 2] | 0;
               wasm2asm_i32$0 = $3_1;
               wasm2asm_i32$1 = $6_1;
               HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
               wasm2asm_i32$0 = $3_1;
               wasm2asm_i32$1 = HEAPU8[($1_1 + 2 | 0) >> 0] | 0;
               HEAP8[(wasm2asm_i32$0 + 2 | 0) >> 0] = wasm2asm_i32$1;
               $2_1 = $1_1 + 16 | 0;
               $8_1 = $4_1 + 4294967277 | 0;
               $7_1 = $4_1 + 4294967293 | 0;
               $5_1 = $3_1 + 3 | 0;
               $9_1 = ($4_1 + 4294967276 | 0) & 4294967280 | 0;
               $10_1 = $9_1 + 19 | 0;
               $1_1 = $1_1 + $10_1 | 0;
               label$27 : do {
                $4_1 = HEAPU32[($2_1 + 4294967284 | 0) >> 2] | 0;
                wasm2asm_i32$0 = $5_1;
                wasm2asm_i32$1 = $4_1 << 8 | 0 | ($6_1 >>> 24 | 0) | 0;
                HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                $6_1 = HEAPU32[($2_1 + 4294967288 | 0) >> 2] | 0;
                wasm2asm_i32$0 = $5_1 + 4 | 0;
                wasm2asm_i32$1 = $6_1 << 8 | 0 | ($4_1 >>> 24 | 0) | 0;
                HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                $4_1 = HEAPU32[($2_1 + 4294967292 | 0) >> 2] | 0;
                wasm2asm_i32$0 = $5_1 + 8 | 0;
                wasm2asm_i32$1 = $4_1 << 8 | 0 | ($6_1 >>> 24 | 0) | 0;
                HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                $6_1 = HEAPU32[$2_1 >> 2] | 0;
                wasm2asm_i32$0 = $5_1 + 12 | 0;
                wasm2asm_i32$1 = $6_1 << 8 | 0 | ($4_1 >>> 24 | 0) | 0;
                HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                $5_1 = $5_1 + 16 | 0;
                $2_1 = $2_1 + 16 | 0;
                $7_1 = $7_1 + 4294967280 | 0;
                if ($7_1 >>> 0 > 16 >>> 0) continue label$27;
                break label$27;
               } while (1);
               $4_1 = $8_1 - $9_1 | 0;
               $3_1 = $3_1 + $10_1 | 0;
              };
              $2_1 = 16;
              if ($4_1 & 16 | 0) break label$23;
              break label$22;
             };
             $6_1 = HEAPU32[$1_1 >> 2] | 0;
             wasm2asm_i32$0 = $3_1;
             wasm2asm_i32$1 = $6_1;
             HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
             $2_1 = $1_1 + 16 | 0;
             $8_1 = $4_1 + 4294967279 | 0;
             $7_1 = $4_1 + 4294967295 | 0;
             $5_1 = $3_1 + 1 | 0;
             $9_1 = ($4_1 + 4294967276 | 0) & 4294967280 | 0;
             $10_1 = $9_1 + 17 | 0;
             $1_1 = $1_1 + $10_1 | 0;
             label$28 : do {
              $4_1 = HEAPU32[($2_1 + 4294967284 | 0) >> 2] | 0;
              wasm2asm_i32$0 = $5_1;
              wasm2asm_i32$1 = $4_1 << 24 | 0 | ($6_1 >>> 8 | 0) | 0;
              HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
              $6_1 = HEAPU32[($2_1 + 4294967288 | 0) >> 2] | 0;
              wasm2asm_i32$0 = $5_1 + 4 | 0;
              wasm2asm_i32$1 = $6_1 << 24 | 0 | ($4_1 >>> 8 | 0) | 0;
              HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
              $4_1 = HEAPU32[($2_1 + 4294967292 | 0) >> 2] | 0;
              wasm2asm_i32$0 = $5_1 + 8 | 0;
              wasm2asm_i32$1 = $4_1 << 24 | 0 | ($6_1 >>> 8 | 0) | 0;
              HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
              $6_1 = HEAPU32[$2_1 >> 2] | 0;
              wasm2asm_i32$0 = $5_1 + 12 | 0;
              wasm2asm_i32$1 = $6_1 << 24 | 0 | ($4_1 >>> 8 | 0) | 0;
              HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
              $5_1 = $5_1 + 16 | 0;
              $2_1 = $2_1 + 16 | 0;
              $7_1 = $7_1 + 4294967280 | 0;
              if ($7_1 >>> 0 > 18 >>> 0) continue label$28;
              break label$28;
             } while (1);
             $3_1 = $3_1 + $10_1 | 0;
             $2_1 = 16;
             $4_1 = $8_1 - $9_1 | 0;
             if (($4_1 & 16 | 0 | 0) == (0 | 0)) break label$22;
             break label$23;
            };
            $6_1 = HEAPU32[$1_1 >> 2] | 0;
            wasm2asm_i32$0 = $3_1;
            wasm2asm_i32$1 = $6_1;
            HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
            wasm2asm_i32$0 = $3_1;
            wasm2asm_i32$1 = HEAPU8[($1_1 + 1 | 0) >> 0] | 0;
            HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
            $2_1 = $1_1 + 16 | 0;
            $8_1 = $4_1 + 4294967278 | 0;
            $7_1 = $4_1 + 4294967294 | 0;
            $5_1 = $3_1 + 2 | 0;
            $9_1 = ($4_1 + 4294967276 | 0) & 4294967280 | 0;
            $10_1 = $9_1 + 18 | 0;
            $1_1 = $1_1 + $10_1 | 0;
            label$29 : do {
             $4_1 = HEAPU32[($2_1 + 4294967284 | 0) >> 2] | 0;
             wasm2asm_i32$0 = $5_1;
             wasm2asm_i32$1 = $4_1 << 16 | 0 | ($6_1 >>> 16 | 0) | 0;
             HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
             $6_1 = HEAPU32[($2_1 + 4294967288 | 0) >> 2] | 0;
             wasm2asm_i32$0 = $5_1 + 4 | 0;
             wasm2asm_i32$1 = $6_1 << 16 | 0 | ($4_1 >>> 16 | 0) | 0;
             HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
             $4_1 = HEAPU32[($2_1 + 4294967292 | 0) >> 2] | 0;
             wasm2asm_i32$0 = $5_1 + 8 | 0;
             wasm2asm_i32$1 = $4_1 << 16 | 0 | ($6_1 >>> 16 | 0) | 0;
             HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
             $6_1 = HEAPU32[$2_1 >> 2] | 0;
             wasm2asm_i32$0 = $5_1 + 12 | 0;
             wasm2asm_i32$1 = $6_1 << 16 | 0 | ($4_1 >>> 16 | 0) | 0;
             HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
             $5_1 = $5_1 + 16 | 0;
             $2_1 = $2_1 + 16 | 0;
             $7_1 = $7_1 + 4294967280 | 0;
             if ($7_1 >>> 0 > 17 >>> 0) continue label$29;
             break label$29;
            } while (1);
            $3_1 = $3_1 + $10_1 | 0;
            $2_1 = 16;
            $4_1 = $8_1 - $9_1 | 0;
            if (($4_1 & 16 | 0 | 0) == (0 | 0)) break label$22;
           };
           wasm2asm_i32$0 = $3_1;
           wasm2asm_i32$1 = HEAPU8[($1_1 + 1 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3_1;
           wasm2asm_i32$1 = HEAPU8[($1_1 + 2 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 2 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3_1;
           wasm2asm_i32$1 = HEAPU8[($1_1 + 3 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 3 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3_1;
           wasm2asm_i32$1 = HEAPU8[($1_1 + 4 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 4 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3_1;
           wasm2asm_i32$1 = HEAPU8[($1_1 + 5 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 5 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3_1;
           wasm2asm_i32$1 = HEAPU8[($1_1 + 6 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 6 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3_1;
           wasm2asm_i32$1 = HEAPU8[($1_1 + 7 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 7 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3_1;
           wasm2asm_i32$1 = HEAPU8[($1_1 + 8 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 8 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3_1;
           wasm2asm_i32$1 = HEAPU8[($1_1 + 9 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 9 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3_1;
           wasm2asm_i32$1 = HEAPU8[($1_1 + 10 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 10 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3_1;
           wasm2asm_i32$1 = HEAPU8[($1_1 + 11 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 11 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3_1;
           wasm2asm_i32$1 = HEAPU8[($1_1 + 12 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 12 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3_1;
           wasm2asm_i32$1 = HEAPU8[($1_1 + 13 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 13 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3_1;
           wasm2asm_i32$1 = HEAPU8[($1_1 + 14 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 14 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3_1;
           wasm2asm_i32$1 = HEAPU8[$1_1 >> 0] | 0;
           HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3_1;
           wasm2asm_i32$1 = HEAPU8[($1_1 + 15 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 15 | 0) >> 0] = wasm2asm_i32$1;
           $3_1 = $3_1 + $2_1 | 0;
           $1_1 = $1_1 + $2_1 | 0;
           $2_1 = 8;
           if (($4_1 & 8 | 0 | 0) == (0 | 0)) break label$21;
           break label$20;
          };
          $2_1 = 8;
          if ($4_1 & 8 | 0) break label$20;
         };
         $2_1 = 4;
         if ($4_1 & 4 | 0) break label$19;
         break label$18;
        };
        wasm2asm_i32$0 = $3_1;
        wasm2asm_i32$1 = HEAPU8[$1_1 >> 0] | 0;
        HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3_1;
        wasm2asm_i32$1 = HEAPU8[($1_1 + 1 | 0) >> 0] | 0;
        HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3_1;
        wasm2asm_i32$1 = HEAPU8[($1_1 + 2 | 0) >> 0] | 0;
        HEAP8[(wasm2asm_i32$0 + 2 | 0) >> 0] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3_1;
        wasm2asm_i32$1 = HEAPU8[($1_1 + 3 | 0) >> 0] | 0;
        HEAP8[(wasm2asm_i32$0 + 3 | 0) >> 0] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3_1;
        wasm2asm_i32$1 = HEAPU8[($1_1 + 4 | 0) >> 0] | 0;
        HEAP8[(wasm2asm_i32$0 + 4 | 0) >> 0] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3_1;
        wasm2asm_i32$1 = HEAPU8[($1_1 + 5 | 0) >> 0] | 0;
        HEAP8[(wasm2asm_i32$0 + 5 | 0) >> 0] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3_1;
        wasm2asm_i32$1 = HEAPU8[($1_1 + 6 | 0) >> 0] | 0;
        HEAP8[(wasm2asm_i32$0 + 6 | 0) >> 0] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3_1;
        wasm2asm_i32$1 = HEAPU8[($1_1 + 7 | 0) >> 0] | 0;
        HEAP8[(wasm2asm_i32$0 + 7 | 0) >> 0] = wasm2asm_i32$1;
        $3_1 = $3_1 + $2_1 | 0;
        $1_1 = $1_1 + $2_1 | 0;
        $2_1 = 4;
        if (($4_1 & 4 | 0 | 0) == (0 | 0)) break label$18;
       };
       wasm2asm_i32$0 = $3_1;
       wasm2asm_i32$1 = HEAPU8[$1_1 >> 0] | 0;
       HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
       wasm2asm_i32$0 = $3_1;
       wasm2asm_i32$1 = HEAPU8[($1_1 + 1 | 0) >> 0] | 0;
       HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
       wasm2asm_i32$0 = $3_1;
       wasm2asm_i32$1 = HEAPU8[($1_1 + 2 | 0) >> 0] | 0;
       HEAP8[(wasm2asm_i32$0 + 2 | 0) >> 0] = wasm2asm_i32$1;
       wasm2asm_i32$0 = $3_1;
       wasm2asm_i32$1 = HEAPU8[($1_1 + 3 | 0) >> 0] | 0;
       HEAP8[(wasm2asm_i32$0 + 3 | 0) >> 0] = wasm2asm_i32$1;
       $3_1 = $3_1 + $2_1 | 0;
       $1_1 = $1_1 + $2_1 | 0;
       $2_1 = 2;
       if (($4_1 & 2 | 0 | 0) == (0 | 0)) break label$17;
       break label$16;
      };
      $2_1 = 2;
      if ($4_1 & 2 | 0) break label$16;
     };
     if ($4_1 & 1 | 0) break label$15;
     break label$1;
    };
    wasm2asm_i32$0 = $3_1;
    wasm2asm_i32$1 = HEAPU8[$1_1 >> 0] | 0;
    HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
    wasm2asm_i32$0 = $3_1;
    wasm2asm_i32$1 = HEAPU8[($1_1 + 1 | 0) >> 0] | 0;
    HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
    $3_1 = $3_1 + $2_1 | 0;
    $1_1 = $1_1 + $2_1 | 0;
    if (($4_1 & 1 | 0 | 0) == (0 | 0)) break label$1;
   };
   wasm2asm_i32$0 = $3_1;
   wasm2asm_i32$1 = HEAPU8[$1_1 >> 0] | 0;
   HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
  };
  return $0_1 | 0;
 }
 
 function $21($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var i64toi32_i32$2 = 0, i64toi32_i32$0 = 0, $3_1 = 0, $4_1 = 0, $5_1 = 0, i64toi32_i32$1 = 0, $5$hi = 0, i64toi32_i32$4 = 0, i64toi32_i32$3 = 0, $14_1 = 0, $92 = 0, $103$hi = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  label$1 : {
   if (($2_1 | 0) == (0 | 0)) break label$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1;
   HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
   $3_1 = $0_1 + $2_1 | 0;
   wasm2asm_i32$0 = $3_1 + 4294967295 | 0;
   wasm2asm_i32$1 = $1_1;
   HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
   if ($2_1 >>> 0 < 3 >>> 0) break label$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1;
   HEAP8[(wasm2asm_i32$0 + 2 | 0) >> 0] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1;
   HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $3_1 + 4294967293 | 0;
   wasm2asm_i32$1 = $1_1;
   HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $3_1 + 4294967294 | 0;
   wasm2asm_i32$1 = $1_1;
   HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
   if ($2_1 >>> 0 < 7 >>> 0) break label$1;
   wasm2asm_i32$0 = $0_1;
   wasm2asm_i32$1 = $1_1;
   HEAP8[(wasm2asm_i32$0 + 3 | 0) >> 0] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $3_1 + 4294967292 | 0;
   wasm2asm_i32$1 = $1_1;
   HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
   if ($2_1 >>> 0 < 9 >>> 0) break label$1;
   $4_1 = (0 - $0_1 | 0) & 3 | 0;
   $3_1 = $0_1 + $4_1 | 0;
   $1_1 = Math_imul($1_1 & 255 | 0, 16843009);
   wasm2asm_i32$0 = $3_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   $4_1 = ($2_1 - $4_1 | 0) & 4294967292 | 0;
   $2_1 = $3_1 + $4_1 | 0;
   wasm2asm_i32$0 = $2_1 + 4294967292 | 0;
   wasm2asm_i32$1 = $1_1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   if ($4_1 >>> 0 < 9 >>> 0) break label$1;
   wasm2asm_i32$0 = $3_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 8 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $3_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 4 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $2_1 + 4294967288 | 0;
   wasm2asm_i32$1 = $1_1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $2_1 + 4294967284 | 0;
   wasm2asm_i32$1 = $1_1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   if ($4_1 >>> 0 < 25 >>> 0) break label$1;
   wasm2asm_i32$0 = $3_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 16 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $3_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 12 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $3_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 20 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $3_1;
   wasm2asm_i32$1 = $1_1;
   HEAP32[(wasm2asm_i32$0 + 24 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $2_1 + 4294967272 | 0;
   wasm2asm_i32$1 = $1_1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $2_1 + 4294967268 | 0;
   wasm2asm_i32$1 = $1_1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $2_1 + 4294967276 | 0;
   wasm2asm_i32$1 = $1_1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $2_1 + 4294967280 | 0;
   wasm2asm_i32$1 = $1_1;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   $92 = $4_1;
   $4_1 = $3_1 & 4 | 0 | 24 | 0;
   $2_1 = $92 - $4_1 | 0;
   if ($2_1 >>> 0 < 32 >>> 0) break label$1;
   i64toi32_i32$0 = 0;
   i64toi32_i32$0 = i64toi32_i32$0;
   $5_1 = $1_1;
   $5$hi = i64toi32_i32$0;
   i64toi32_i32$0 = i64toi32_i32$0;
   i64toi32_i32$0 = i64toi32_i32$0;
   i64toi32_i32$2 = $1_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$3 = 32;
   i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
    $14_1 = 0;
   } else {
    i64toi32_i32$1 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$4 | 0) | 0;
    $14_1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
   }
   $103$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $5$hi;
   i64toi32_i32$1 = $103$hi;
   i64toi32_i32$0 = $14_1;
   i64toi32_i32$2 = $5$hi;
   i64toi32_i32$3 = $5_1;
   i64toi32_i32$2 = i64toi32_i32$1 | i64toi32_i32$2 | 0;
   i64toi32_i32$2 = i64toi32_i32$2;
   $5_1 = i64toi32_i32$0 | $5_1 | 0;
   $5$hi = i64toi32_i32$2;
   $1_1 = $3_1 + $4_1 | 0;
   label$2 : do {
    i64toi32_i32$2 = $5$hi;
    i64toi32_i32$0 = $1_1;
    i64toi32_i32$2 = i64toi32_i32$2;
    wasm2asm_i32$0 = $1_1;
    wasm2asm_i32$1 = $5_1;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    wasm2asm_i32$0 = $1_1;
    wasm2asm_i32$1 = i64toi32_i32$2;
    (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    i64toi32_i32$0 = $1_1 + 8 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    wasm2asm_i32$0 = i64toi32_i32$0;
    wasm2asm_i32$1 = $5_1;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    wasm2asm_i32$0 = i64toi32_i32$0;
    wasm2asm_i32$1 = i64toi32_i32$2;
    (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    i64toi32_i32$0 = $1_1 + 16 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    wasm2asm_i32$0 = i64toi32_i32$0;
    wasm2asm_i32$1 = $5_1;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    wasm2asm_i32$0 = i64toi32_i32$0;
    wasm2asm_i32$1 = i64toi32_i32$2;
    (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    i64toi32_i32$0 = $1_1 + 24 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    wasm2asm_i32$0 = i64toi32_i32$0;
    wasm2asm_i32$1 = $5_1;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    wasm2asm_i32$0 = i64toi32_i32$0;
    wasm2asm_i32$1 = i64toi32_i32$2;
    (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
    $1_1 = $1_1 + 32 | 0;
    $2_1 = $2_1 + 4294967264 | 0;
    if ($2_1 >>> 0 > 31 >>> 0) continue label$2;
    break label$2;
   } while (1);
  };
  return $0_1 | 0;
 }
 
 function $22($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var $3_1 = 0, $4_1 = 0, $5_1 = 0;
  $4_1 = ($2_1 | 0) != (0 | 0);
  label$1 : {
   label$2 : {
    label$3 : {
     label$4 : {
      if ((($2_1 | 0) == (0 | 0) | ($0_1 & 3 | 0 | 0) == (0 | 0) | 0 | 0) == (0 | 0)) {
       $4_1 = $1_1 & 255 | 0;
       label$6 : do {
        if ((HEAPU8[$0_1 >> 0] | 0 | 0) == ($4_1 | 0)) break label$4;
        $5_1 = ($2_1 | 0) != (1 | 0);
        $3_1 = $2_1 + 4294967295 | 0;
        $0_1 = $0_1 + 1 | 0;
        if (($2_1 | 0) != (1 | 0)) {
         $2_1 = $3_1;
         if ($0_1 & 3 | 0) continue label$6;
        }
        break label$6;
       } while (1);
       if ($5_1) break label$3;
       break label$2;
      }
      $3_1 = $2_1;
      if ($4_1) break label$3;
      break label$2;
     };
     $3_1 = $2_1;
    };
    if ((HEAPU8[$0_1 >> 0] | 0 | 0) == ($1_1 & 255 | 0 | 0)) return $0_1 | 0;
    label$9 : {
     if ($3_1 >>> 0 >= 4 >>> 0) {
      $4_1 = Math_imul($1_1 & 255 | 0, 16843009);
      label$11 : do {
       $2_1 = (HEAPU32[$0_1 >> 2] | 0) ^ $4_1 | 0;
       if ((($2_1 ^ 4294967295 | 0) & ($2_1 + 4278124287 | 0) | 0) & 2155905152 | 0) break label$9;
       $0_1 = $0_1 + 4 | 0;
       $3_1 = $3_1 + 4294967292 | 0;
       if ($3_1 >>> 0 > 3 >>> 0) continue label$11;
       break label$11;
      } while (1);
     }
     if (($3_1 | 0) == (0 | 0)) break label$2;
    };
    $2_1 = $1_1 & 255 | 0;
    label$12 : do {
     if ((HEAPU8[$0_1 >> 0] | 0 | 0) == ($2_1 | 0)) break label$1;
     $0_1 = $0_1 + 1 | 0;
     $3_1 = $3_1 + 4294967295 | 0;
     if ($3_1) continue label$12;
     break label$12;
    } while (1);
   };
   return 0 | 0;
  };
  return $0_1 | 0;
 }
 
 function $23($0_1, $0$hi, $1_1, $1$hi, $2_1, $2$hi, $3_1, $3$hi) {
  $0_1 = $0_1 | 0;
  $0$hi = $0$hi | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  $3$hi = $3$hi | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, i64toi32_i32$3 = 0, i64toi32_i32$2 = 0, $5_1 = 0, $9_1 = 0, $12_1 = 0, $14_1 = 0, $18_1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0;
  i64toi32_i32$0 = $0$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$2 = $0_1;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 0;
  $5_1 = (i64toi32_i32$2 | 0) != (i64toi32_i32$3 | 0) | (i64toi32_i32$0 | 0) != (i64toi32_i32$1 | 0) | 0;
  i64toi32_i32$2 = $1$hi;
  i64toi32_i32$2 = i64toi32_i32$2;
  i64toi32_i32$3 = $1_1;
  i64toi32_i32$0 = 2147483647;
  i64toi32_i32$1 = 4294967295;
  i64toi32_i32$0 = i64toi32_i32$2 & i64toi32_i32$0 | 0;
  i64toi32_i32$0 = i64toi32_i32$0;
  $1_1 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
  $1$hi = i64toi32_i32$0;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$2 = $1_1;
  i64toi32_i32$3 = 2147418112;
  i64toi32_i32$1 = 0;
  $9_1 = i64toi32_i32$0 >>> 0 > i64toi32_i32$3 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$2 >>> 0 > i64toi32_i32$1 >>> 0 | 0) | 0;
  i64toi32_i32$2 = i64toi32_i32$0;
  i64toi32_i32$2 = i64toi32_i32$0;
  i64toi32_i32$1 = $1_1;
  i64toi32_i32$0 = 2147418112;
  i64toi32_i32$3 = 0;
  $12_1 = (wasm2asm_i32$0 = $5_1, wasm2asm_i32$1 = $9_1, wasm2asm_i32$2 = (i64toi32_i32$1 | 0) == (i64toi32_i32$3 | 0) & (i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
  i64toi32_i32$1 = $2$hi;
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$3 = $2_1;
  i64toi32_i32$2 = 0;
  i64toi32_i32$0 = 0;
  $14_1 = (i64toi32_i32$3 | 0) != (i64toi32_i32$0 | 0) | (i64toi32_i32$1 | 0) != (i64toi32_i32$2 | 0) | 0;
  i64toi32_i32$3 = $3$hi;
  i64toi32_i32$3 = i64toi32_i32$3;
  i64toi32_i32$0 = $3_1;
  i64toi32_i32$1 = 2147483647;
  i64toi32_i32$2 = 4294967295;
  i64toi32_i32$1 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
  i64toi32_i32$1 = i64toi32_i32$1;
  $1_1 = i64toi32_i32$0 & i64toi32_i32$2 | 0;
  $1$hi = i64toi32_i32$1;
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$3 = $1_1;
  i64toi32_i32$0 = 2147418112;
  i64toi32_i32$2 = 0;
  $18_1 = i64toi32_i32$1 >>> 0 > i64toi32_i32$0 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$3 >>> 0 > i64toi32_i32$2 >>> 0 | 0) | 0;
  i64toi32_i32$3 = i64toi32_i32$1;
  i64toi32_i32$3 = i64toi32_i32$1;
  i64toi32_i32$2 = $1_1;
  i64toi32_i32$1 = 2147418112;
  i64toi32_i32$0 = 0;
  return $12_1 | (wasm2asm_i32$0 = $14_1, wasm2asm_i32$1 = $18_1, wasm2asm_i32$2 = (i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) & (i64toi32_i32$3 | 0) == (i64toi32_i32$1 | 0) | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0 | 0;
 }
 
 function $24($0_1, $0$hi, $1_1, $1$hi, $2_1, $2$hi, $3_1, $3$hi) {
  $0_1 = $0_1 | 0;
  $0$hi = $0$hi | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  $3$hi = $3$hi | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$3 = 0, i64toi32_i32$1 = 0, $4_1 = 0, $5_1 = 0, $6_1 = 0, $5$hi = 0, $6$hi = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $8_1 = 0, $12_1 = 0, $17_1 = 0, $21_1 = 0, $27_1 = 0, $27$hi = 0, $30_1 = 0, $30$hi = 0, $40 = 0, $50 = 0, $50$hi = 0, $53 = 0, $53$hi = 0, $58 = 0, $68 = 0, $68$hi = 0, $71 = 0, $71$hi = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0;
  $4_1 = 1;
  label$1 : {
   i64toi32_i32$0 = $0$hi;
   i64toi32_i32$0 = i64toi32_i32$0;
   i64toi32_i32$2 = $0_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$3 = 0;
   $8_1 = (i64toi32_i32$2 | 0) != (i64toi32_i32$3 | 0) | (i64toi32_i32$0 | 0) != (i64toi32_i32$1 | 0) | 0;
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$2 = i64toi32_i32$2;
   i64toi32_i32$3 = $1_1;
   i64toi32_i32$0 = 2147483647;
   i64toi32_i32$1 = 4294967295;
   i64toi32_i32$0 = i64toi32_i32$2 & i64toi32_i32$0 | 0;
   i64toi32_i32$0 = i64toi32_i32$0;
   $5_1 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
   $5$hi = i64toi32_i32$0;
   i64toi32_i32$0 = i64toi32_i32$0;
   i64toi32_i32$0 = i64toi32_i32$0;
   i64toi32_i32$2 = $5_1;
   i64toi32_i32$3 = 2147418112;
   i64toi32_i32$1 = 0;
   $12_1 = i64toi32_i32$0 >>> 0 > i64toi32_i32$3 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$2 >>> 0 > i64toi32_i32$1 >>> 0 | 0) | 0;
   i64toi32_i32$2 = i64toi32_i32$0;
   i64toi32_i32$2 = i64toi32_i32$0;
   i64toi32_i32$1 = $5_1;
   i64toi32_i32$0 = 2147418112;
   i64toi32_i32$3 = 0;
   if (wasm2asm_i32$0 = $8_1, wasm2asm_i32$1 = $12_1, wasm2asm_i32$2 = (i64toi32_i32$1 | 0) == (i64toi32_i32$3 | 0) & (i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) break label$1;
   i64toi32_i32$1 = $2$hi;
   i64toi32_i32$1 = i64toi32_i32$1;
   i64toi32_i32$3 = $2_1;
   i64toi32_i32$2 = 0;
   i64toi32_i32$0 = 0;
   $17_1 = (i64toi32_i32$3 | 0) != (i64toi32_i32$0 | 0) | (i64toi32_i32$1 | 0) != (i64toi32_i32$2 | 0) | 0;
   i64toi32_i32$3 = $3$hi;
   i64toi32_i32$3 = i64toi32_i32$3;
   i64toi32_i32$0 = $3_1;
   i64toi32_i32$1 = 2147483647;
   i64toi32_i32$2 = 4294967295;
   i64toi32_i32$1 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
   i64toi32_i32$1 = i64toi32_i32$1;
   $6_1 = i64toi32_i32$0 & i64toi32_i32$2 | 0;
   $6$hi = i64toi32_i32$1;
   i64toi32_i32$1 = i64toi32_i32$1;
   i64toi32_i32$1 = i64toi32_i32$1;
   i64toi32_i32$3 = $6_1;
   i64toi32_i32$0 = 2147418112;
   i64toi32_i32$2 = 0;
   $21_1 = i64toi32_i32$1 >>> 0 > i64toi32_i32$0 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$3 >>> 0 > i64toi32_i32$2 >>> 0 | 0) | 0;
   i64toi32_i32$3 = i64toi32_i32$1;
   i64toi32_i32$3 = i64toi32_i32$3;
   i64toi32_i32$2 = $6_1;
   i64toi32_i32$1 = 2147418112;
   i64toi32_i32$0 = 0;
   if (wasm2asm_i32$0 = $17_1, wasm2asm_i32$1 = $21_1, wasm2asm_i32$2 = (i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) & (i64toi32_i32$3 | 0) == (i64toi32_i32$1 | 0) | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) break label$1;
   label$2 : {
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$2 = $0$hi;
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$0 = $2_1;
    i64toi32_i32$3 = $0$hi;
    i64toi32_i32$1 = $0_1;
    i64toi32_i32$3 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
    $27_1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
    $27$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $6$hi;
    i64toi32_i32$3 = $5$hi;
    i64toi32_i32$3 = $6$hi;
    i64toi32_i32$2 = $6_1;
    i64toi32_i32$0 = $5$hi;
    i64toi32_i32$1 = $5_1;
    i64toi32_i32$0 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
    $30_1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
    $30$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $27$hi;
    i64toi32_i32$3 = $27_1;
    i64toi32_i32$2 = $30$hi;
    i64toi32_i32$1 = $30_1;
    i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    if (((i64toi32_i32$3 | i64toi32_i32$1 | 0 | i64toi32_i32$2 | 0 | 0) == (0 | 0) | 0) == (0 | 0)) {
     i64toi32_i32$2 = $3$hi;
     i64toi32_i32$2 = $1$hi;
     i64toi32_i32$2 = $3$hi;
     i64toi32_i32$0 = $3_1;
     i64toi32_i32$3 = $1$hi;
     i64toi32_i32$1 = $1_1;
     i64toi32_i32$3 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
     i64toi32_i32$3 = i64toi32_i32$3;
     i64toi32_i32$2 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
     i64toi32_i32$0 = 0;
     i64toi32_i32$1 = 0;
     if ((i64toi32_i32$3 | 0) < (i64toi32_i32$0 | 0)) $35 = 1; else {
      if ((i64toi32_i32$3 | 0) <= (i64toi32_i32$0 | 0)) {
       if (i64toi32_i32$2 >>> 0 >= i64toi32_i32$1 >>> 0) $36 = 0; else $36 = 1;
       $37 = $36;
      } else $37 = 0;
      $35 = $37;
     }
     if ($35) break label$2;
     $4_1 = 4294967295;
     i64toi32_i32$2 = $0$hi;
     i64toi32_i32$2 = $2$hi;
     i64toi32_i32$2 = $0$hi;
     i64toi32_i32$1 = $0_1;
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$0 = $2_1;
     $40 = i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$1 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0;
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$0 = $1_1;
     i64toi32_i32$2 = $3$hi;
     i64toi32_i32$3 = $3_1;
     if ((i64toi32_i32$1 | 0) < (i64toi32_i32$2 | 0)) $38 = 1; else {
      if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$2 | 0)) {
       if (i64toi32_i32$0 >>> 0 >= i64toi32_i32$3 >>> 0) $39 = 0; else $39 = 1;
       $41 = $39;
      } else $41 = 0;
      $38 = $41;
     }
     i64toi32_i32$0 = $1$hi;
     i64toi32_i32$0 = $3$hi;
     i64toi32_i32$0 = $1$hi;
     i64toi32_i32$3 = $1_1;
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$2 = $3_1;
     if (wasm2asm_i32$0 = $40, wasm2asm_i32$1 = $38, wasm2asm_i32$2 = (i64toi32_i32$3 | 0) == (i64toi32_i32$2 | 0) & (i64toi32_i32$0 | 0) == (i64toi32_i32$1 | 0) | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) break label$1;
     i64toi32_i32$3 = $0$hi;
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$3 = $0$hi;
     i64toi32_i32$2 = $0_1;
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$1 = $2_1;
     i64toi32_i32$0 = i64toi32_i32$3 ^ i64toi32_i32$0 | 0;
     $50 = i64toi32_i32$2 ^ i64toi32_i32$1 | 0;
     $50$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $1$hi;
     i64toi32_i32$0 = $3$hi;
     i64toi32_i32$0 = $1$hi;
     i64toi32_i32$3 = $1_1;
     i64toi32_i32$2 = $3$hi;
     i64toi32_i32$1 = $3_1;
     i64toi32_i32$2 = i64toi32_i32$0 ^ i64toi32_i32$2 | 0;
     $53 = i64toi32_i32$3 ^ i64toi32_i32$1 | 0;
     $53$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $50$hi;
     i64toi32_i32$0 = $50;
     i64toi32_i32$3 = $53$hi;
     i64toi32_i32$1 = $53;
     i64toi32_i32$3 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
     i64toi32_i32$3 = i64toi32_i32$3;
     i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
     i64toi32_i32$0 = 0;
     i64toi32_i32$1 = 0;
     return (i64toi32_i32$2 | 0) != (i64toi32_i32$1 | 0) | (i64toi32_i32$3 | 0) != (i64toi32_i32$0 | 0) | 0 | 0;
    }
    return 0 | 0;
   };
   $4_1 = 4294967295;
   i64toi32_i32$2 = $0$hi;
   i64toi32_i32$2 = $2$hi;
   i64toi32_i32$2 = $0$hi;
   i64toi32_i32$1 = $0_1;
   i64toi32_i32$3 = $2$hi;
   i64toi32_i32$0 = $2_1;
   $58 = i64toi32_i32$2 >>> 0 > i64toi32_i32$3 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$1 >>> 0 > i64toi32_i32$0 >>> 0 | 0) | 0;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$1 = $3$hi;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$0 = $1_1;
   i64toi32_i32$2 = $3$hi;
   i64toi32_i32$3 = $3_1;
   if ((i64toi32_i32$1 | 0) > (i64toi32_i32$2 | 0)) $42 = 1; else {
    if ((i64toi32_i32$1 | 0) >= (i64toi32_i32$2 | 0)) {
     if (i64toi32_i32$0 >>> 0 <= i64toi32_i32$3 >>> 0) $43 = 0; else $43 = 1;
     $44 = $43;
    } else $44 = 0;
    $42 = $44;
   }
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$0 = $3$hi;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$3 = $1_1;
   i64toi32_i32$1 = $3$hi;
   i64toi32_i32$2 = $3_1;
   if (wasm2asm_i32$0 = $58, wasm2asm_i32$1 = $42, wasm2asm_i32$2 = (i64toi32_i32$3 | 0) == (i64toi32_i32$2 | 0) & (i64toi32_i32$0 | 0) == (i64toi32_i32$1 | 0) | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) break label$1;
   i64toi32_i32$3 = $0$hi;
   i64toi32_i32$3 = $2$hi;
   i64toi32_i32$3 = $0$hi;
   i64toi32_i32$2 = $0_1;
   i64toi32_i32$0 = $2$hi;
   i64toi32_i32$1 = $2_1;
   i64toi32_i32$0 = i64toi32_i32$3 ^ i64toi32_i32$0 | 0;
   $68 = i64toi32_i32$2 ^ i64toi32_i32$1 | 0;
   $68$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$0 = $3$hi;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$3 = $1_1;
   i64toi32_i32$2 = $3$hi;
   i64toi32_i32$1 = $3_1;
   i64toi32_i32$2 = i64toi32_i32$0 ^ i64toi32_i32$2 | 0;
   $71 = i64toi32_i32$3 ^ i64toi32_i32$1 | 0;
   $71$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $68$hi;
   i64toi32_i32$0 = $68;
   i64toi32_i32$3 = $71$hi;
   i64toi32_i32$1 = $71;
   i64toi32_i32$3 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
   i64toi32_i32$3 = i64toi32_i32$3;
   i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
   i64toi32_i32$0 = 0;
   i64toi32_i32$1 = 0;
   $4_1 = (i64toi32_i32$2 | 0) != (i64toi32_i32$1 | 0) | (i64toi32_i32$3 | 0) != (i64toi32_i32$0 | 0) | 0;
  };
  return $4_1 | 0;
 }
 
 function $25($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = +$1_1;
  var i64toi32_i32$3 = 0, i64toi32_i32$1 = 0, i64toi32_i32$5 = 0, i64toi32_i32$2 = 0, i64toi32_i32$4 = 0, i64toi32_i32$0 = 0, $2_1 = 0, $2$hi = 0, $3_1 = 0, $4_1 = 0, $25_1 = 0, $25$hi = 0, $4$hi = 0, $5_1 = 0, $5$hi = 0, $7$hi = 0, $26_1 = 0, $27_1 = 0, $28_1 = 0, $29_1 = 0, $42 = 0, $30_1 = 0, $6_1 = 0, $31_1 = 0, $7_1 = 0, $57 = 0, $57$hi = 0, $61$hi = 0, $69 = 0, wasm2asm_i32$0 = 0, wasm2asm_f64$0 = 0.0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  $3_1 = global$0 - 16 | 0;
  global$0 = $3_1;
  wasm2asm_i32$0 = 0;
  wasm2asm_f64$0 = $1_1;
  HEAPF64[wasm2asm_i32$0 >> 3] = wasm2asm_f64$0;
  i64toi32_i32$0 = HEAP32[(0 + 4 | 0) >> 2] | 0;
  i64toi32_i32$0 = i64toi32_i32$0;
  $4_1 = HEAP32[0 >> 2] | 0;
  $4$hi = i64toi32_i32$0;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$2 = $4_1;
  i64toi32_i32$1 = 2147483648;
  i64toi32_i32$3 = 0;
  i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
  i64toi32_i32$1 = i64toi32_i32$1;
  $7_1 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
  $7$hi = i64toi32_i32$1;
  label$1 : {
   i64toi32_i32$1 = i64toi32_i32$0;
   i64toi32_i32$1 = i64toi32_i32$1;
   i64toi32_i32$0 = i64toi32_i32$2;
   i64toi32_i32$2 = 2147483647;
   i64toi32_i32$3 = 4294967295;
   i64toi32_i32$2 = i64toi32_i32$1 & i64toi32_i32$2 | 0;
   i64toi32_i32$2 = i64toi32_i32$2;
   $2_1 = i64toi32_i32$0 & i64toi32_i32$3 | 0;
   $2$hi = i64toi32_i32$2;
   i64toi32_i32$2 = i64toi32_i32$2;
   i64toi32_i32$2 = i64toi32_i32$2;
   i64toi32_i32$1 = $2_1;
   i64toi32_i32$0 = 4293918720;
   i64toi32_i32$3 = 0;
   i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
   i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$0 | 0;
   if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0;
   i64toi32_i32$5 = i64toi32_i32$5;
   i64toi32_i32$2 = i64toi32_i32$4;
   i64toi32_i32$1 = 2145386495;
   i64toi32_i32$3 = 4294967295;
   if (i64toi32_i32$5 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$2 >>> 0 <= i64toi32_i32$3 >>> 0 | 0) | 0) {
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$2 = i64toi32_i32$2;
    i64toi32_i32$3 = $2_1;
    i64toi32_i32$5 = 0;
    i64toi32_i32$1 = 60;
    i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
     i64toi32_i32$5 = i64toi32_i32$3 << i64toi32_i32$0 | 0;
     $26_1 = 0;
    } else {
     i64toi32_i32$5 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$0 | 0) | 0;
     $26_1 = i64toi32_i32$3 << i64toi32_i32$0 | 0;
    }
    i64toi32_i32$5 = i64toi32_i32$5;
    $5_1 = $26_1;
    $5$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $2$hi;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$2 = $2_1;
    i64toi32_i32$3 = 0;
    i64toi32_i32$1 = 4;
    i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
     i64toi32_i32$3 = 0;
     $27_1 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
    } else {
     i64toi32_i32$3 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
     $27_1 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$0 | 0) | 0;
    }
    i64toi32_i32$3 = i64toi32_i32$3;
    i64toi32_i32$5 = $27_1;
    i64toi32_i32$2 = 1006632960;
    i64toi32_i32$1 = 0;
    i64toi32_i32$0 = i64toi32_i32$5 + i64toi32_i32$1 | 0;
    i64toi32_i32$4 = i64toi32_i32$3 + i64toi32_i32$2 | 0;
    if (i64toi32_i32$0 >>> 0 < i64toi32_i32$1 >>> 0) i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0;
    i64toi32_i32$4 = i64toi32_i32$4;
    $25_1 = i64toi32_i32$0;
    $25$hi = i64toi32_i32$4;
    break label$1;
   }
   i64toi32_i32$4 = $2$hi;
   i64toi32_i32$4 = i64toi32_i32$4;
   i64toi32_i32$3 = $2_1;
   i64toi32_i32$5 = 2146435072;
   i64toi32_i32$1 = 0;
   if (i64toi32_i32$4 >>> 0 > i64toi32_i32$5 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$3 >>> 0 >= i64toi32_i32$1 >>> 0 | 0) | 0) {
    i64toi32_i32$3 = $4$hi;
    i64toi32_i32$3 = i64toi32_i32$3;
    i64toi32_i32$1 = $4_1;
    i64toi32_i32$4 = 0;
    i64toi32_i32$5 = 60;
    i64toi32_i32$2 = i64toi32_i32$5 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
     i64toi32_i32$4 = i64toi32_i32$1 << i64toi32_i32$2 | 0;
     $28_1 = 0;
    } else {
     i64toi32_i32$4 = ((1 << i64toi32_i32$2 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$2 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$2 | 0) | 0;
     $28_1 = i64toi32_i32$1 << i64toi32_i32$2 | 0;
    }
    i64toi32_i32$4 = i64toi32_i32$4;
    $5_1 = $28_1;
    $5$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $4$hi;
    i64toi32_i32$4 = i64toi32_i32$4;
    i64toi32_i32$3 = $4_1;
    i64toi32_i32$1 = 0;
    i64toi32_i32$5 = 4;
    i64toi32_i32$2 = i64toi32_i32$5 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
     i64toi32_i32$1 = 0;
     $29_1 = i64toi32_i32$4 >>> i64toi32_i32$2 | 0;
    } else {
     i64toi32_i32$1 = i64toi32_i32$4 >>> i64toi32_i32$2 | 0;
     $29_1 = (((1 << i64toi32_i32$2 | 0) - 1 | 0) & i64toi32_i32$4 | 0) << (32 - i64toi32_i32$2 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$2 | 0) | 0;
    }
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$4 = $29_1;
    i64toi32_i32$3 = 2147418112;
    i64toi32_i32$5 = 0;
    i64toi32_i32$3 = i64toi32_i32$1 | i64toi32_i32$3 | 0;
    i64toi32_i32$3 = i64toi32_i32$3;
    $25_1 = i64toi32_i32$4 | i64toi32_i32$5 | 0;
    $25$hi = i64toi32_i32$3;
    break label$1;
   }
   label$4 : {
    label$5 : {
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$3 = i64toi32_i32$3;
     if ((($2_1 | i64toi32_i32$3 | 0 | 0) == (0 | 0) | 0) == (0 | 0)) {
      i64toi32_i32$3 = $2$hi;
      i64toi32_i32$3 = i64toi32_i32$3;
      i64toi32_i32$1 = $2_1;
      i64toi32_i32$4 = 1;
      i64toi32_i32$5 = 0;
      if (i64toi32_i32$3 >>> 0 > i64toi32_i32$4 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$1 >>> 0 >= i64toi32_i32$5 >>> 0 | 0) | 0) break label$5;
      i64toi32_i32$1 = $4$hi;
      i64toi32_i32$1 = i64toi32_i32$1;
      $42 = Math_clz32($4_1) + 32 | 0;
      break label$4;
     }
     i64toi32_i32$1 = 0;
     $25_1 = 0;
     $25$hi = i64toi32_i32$1;
     break label$1;
    };
    i64toi32_i32$1 = $2$hi;
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$5 = $2_1;
    i64toi32_i32$3 = 0;
    i64toi32_i32$4 = 32;
    i64toi32_i32$2 = i64toi32_i32$4 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
     i64toi32_i32$3 = 0;
     $30_1 = i64toi32_i32$1 >>> i64toi32_i32$2 | 0;
    } else {
     i64toi32_i32$3 = i64toi32_i32$1 >>> i64toi32_i32$2 | 0;
     $30_1 = (((1 << i64toi32_i32$2 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$2 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$2 | 0) | 0;
    }
    i64toi32_i32$3 = i64toi32_i32$3;
    $42 = Math_clz32($30_1);
   };
   $6_1 = $42;
   i64toi32_i32$3 = $2$hi;
   i64toi32_i32$3 = i64toi32_i32$3;
   i64toi32_i32$5 = 0;
   $31($3_1 | 0, $2_1 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$5 | 0, $6_1 + 49 | 0 | 0);
   i64toi32_i32$1 = $3_1;
   i64toi32_i32$5 = HEAPU32[i64toi32_i32$1 >> 2] | 0;
   i64toi32_i32$3 = (wasm2asm_i32$0 = i64toi32_i32$1, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
   i64toi32_i32$3 = i64toi32_i32$3;
   $5_1 = i64toi32_i32$5;
   $5$hi = i64toi32_i32$3;
   i64toi32_i32$1 = i64toi32_i32$1 + 8 | 0;
   i64toi32_i32$3 = HEAPU32[i64toi32_i32$1 >> 2] | 0;
   i64toi32_i32$5 = (wasm2asm_i32$0 = i64toi32_i32$1, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
   i64toi32_i32$5 = i64toi32_i32$5;
   i64toi32_i32$1 = i64toi32_i32$3;
   i64toi32_i32$3 = 65536;
   i64toi32_i32$4 = 0;
   i64toi32_i32$3 = i64toi32_i32$5 ^ i64toi32_i32$3 | 0;
   $57 = i64toi32_i32$1 ^ i64toi32_i32$4 | 0;
   $57$hi = i64toi32_i32$3;
   i64toi32_i32$3 = 0;
   i64toi32_i32$3 = i64toi32_i32$3;
   i64toi32_i32$5 = 15372 - $6_1 | 0;
   i64toi32_i32$1 = 0;
   i64toi32_i32$4 = 48;
   i64toi32_i32$2 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$1 = i64toi32_i32$5 << i64toi32_i32$2 | 0;
    $31_1 = 0;
   } else {
    i64toi32_i32$1 = ((1 << i64toi32_i32$2 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$2 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$2 | 0) | 0;
    $31_1 = i64toi32_i32$5 << i64toi32_i32$2 | 0;
   }
   $61$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $57$hi;
   i64toi32_i32$3 = $57;
   i64toi32_i32$5 = $61$hi;
   i64toi32_i32$4 = $31_1;
   i64toi32_i32$5 = i64toi32_i32$1 | i64toi32_i32$5 | 0;
   i64toi32_i32$5 = i64toi32_i32$5;
   $25_1 = i64toi32_i32$3 | i64toi32_i32$4 | 0;
   $25$hi = i64toi32_i32$5;
  };
  i64toi32_i32$5 = $25$hi;
  i64toi32_i32$5 = i64toi32_i32$5;
  $2_1 = $25_1;
  $2$hi = i64toi32_i32$5;
  i64toi32_i32$5 = $5$hi;
  i64toi32_i32$3 = $0_1;
  i64toi32_i32$5 = i64toi32_i32$5;
  wasm2asm_i32$0 = i64toi32_i32$3;
  wasm2asm_i32$1 = $5_1;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$3;
  wasm2asm_i32$1 = i64toi32_i32$5;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  i64toi32_i32$5 = $2$hi;
  i64toi32_i32$5 = $7$hi;
  i64toi32_i32$5 = $2$hi;
  i64toi32_i32$1 = $2_1;
  i64toi32_i32$3 = $7$hi;
  i64toi32_i32$4 = $7_1;
  i64toi32_i32$3 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
  $69 = i64toi32_i32$1 | i64toi32_i32$4 | 0;
  i64toi32_i32$1 = $0_1;
  i64toi32_i32$3 = i64toi32_i32$3;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = $69;
  HEAP32[(wasm2asm_i32$0 + 8 | 0) >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = i64toi32_i32$3;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 12 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 13 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 14 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 15 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  global$0 = $3_1 + 16 | 0;
 }
 
 function $26($0_1, $0$hi, $1_1, $1$hi) {
  $0_1 = $0_1 | 0;
  $0$hi = $0$hi | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, i64toi32_i32$3 = 0, i64toi32_i32$2 = 0, $16_1 = 0, i64toi32_i32$4 = 0, $2_1 = 0, $3_1 = 0, $15_1 = 0, $4_1 = 0, $17_1 = 0, $18_1 = 0, $19_1 = 0, $20_1 = 0, $21_1 = 0, $22_1 = 0, $28_1 = 0, $28$hi = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0;
  $2_1 = global$0 - 16 | 0;
  global$0 = $2_1;
  label$1 : {
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$0 = i64toi32_i32$0;
   i64toi32_i32$2 = $1_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$3 = 48;
   i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$1 = 0;
    $15_1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
   } else {
    i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
    $15_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
   }
   i64toi32_i32$1 = i64toi32_i32$1;
   $3_1 = $15_1 & 32767 | 0;
   $4_1 = $3_1 + 4294950913 | 0;
   $16_1 = 0;
   if (($4_1 | 0) < (0 | 0)) break label$1;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$1 = i64toi32_i32$1;
   i64toi32_i32$0 = $1_1;
   i64toi32_i32$2 = 0;
   i64toi32_i32$3 = 0;
   if ((i64toi32_i32$1 | 0) < (i64toi32_i32$2 | 0)) $17_1 = 1; else {
    if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$2 | 0)) {
     if (i64toi32_i32$0 >>> 0 >= i64toi32_i32$3 >>> 0) $18_1 = 0; else $18_1 = 1;
     $19_1 = $18_1;
    } else $19_1 = 0;
    $17_1 = $19_1;
   }
   $16_1 = (wasm2asm_i32$0 = 2147483648, wasm2asm_i32$1 = 2147483647, wasm2asm_i32$2 = $17_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
   if ($4_1 >>> 0 >= 32 >>> 0) break label$1;
   i64toi32_i32$0 = $0$hi;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$0 = i64toi32_i32$0;
   i64toi32_i32$3 = $1_1;
   i64toi32_i32$1 = 65535;
   i64toi32_i32$2 = 4294967295;
   i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
   i64toi32_i32$1 = i64toi32_i32$1;
   i64toi32_i32$0 = i64toi32_i32$3 & i64toi32_i32$2 | 0;
   i64toi32_i32$3 = 65536;
   i64toi32_i32$2 = 0;
   i64toi32_i32$3 = i64toi32_i32$1 | i64toi32_i32$3 | 0;
   $28_1 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
   $28$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $0$hi;
   i64toi32_i32$0 = $28$hi;
   $32($2_1 | 0, $0_1 | 0, i64toi32_i32$3 | 0, $28_1 | 0, i64toi32_i32$0 | 0, 16495 - $3_1 | 0 | 0);
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$0 = i64toi32_i32$0;
   i64toi32_i32$1 = $1_1;
   i64toi32_i32$3 = 0;
   i64toi32_i32$2 = 0;
   if ((i64toi32_i32$0 | 0) < (i64toi32_i32$3 | 0)) $20_1 = 1; else {
    if ((i64toi32_i32$0 | 0) <= (i64toi32_i32$3 | 0)) {
     if (i64toi32_i32$1 >>> 0 >= i64toi32_i32$2 >>> 0) $21_1 = 0; else $21_1 = 1;
     $22_1 = $21_1;
    } else $22_1 = 0;
    $20_1 = $22_1;
   }
   $16_1 = Math_imul((wasm2asm_i32$0 = 4294967295, wasm2asm_i32$1 = 1, wasm2asm_i32$2 = $20_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1), HEAPU32[$2_1 >> 2] | 0);
  };
  $3_1 = $16_1;
  global$0 = $2_1 + 16 | 0;
  return $16_1 | 0;
 }
 
 function $27($0_1, $0$hi, $1_1, $1$hi) {
  $0_1 = $0_1 | 0;
  $0$hi = $0$hi | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$1 = 0, i64toi32_i32$3 = 0, i64toi32_i32$4 = 0, $2_1 = 0, $15_1 = 0, $16_1 = 0, $17_1 = 0, $18_1 = 0, $4_1 = 0, $5_1 = 0, $3_1 = 0, $25_1 = 0, $25$hi = 0;
  $2_1 = global$0 - 16 | 0;
  global$0 = $2_1;
  label$1 : {
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$0 = i64toi32_i32$0;
   i64toi32_i32$2 = $1_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$3 = 0;
   if ((i64toi32_i32$0 | 0) < (i64toi32_i32$1 | 0)) $15_1 = 1; else {
    if ((i64toi32_i32$0 | 0) <= (i64toi32_i32$1 | 0)) {
     if (i64toi32_i32$2 >>> 0 >= i64toi32_i32$3 >>> 0) $16_1 = 0; else $16_1 = 1;
     $17_1 = $16_1;
    } else $17_1 = 0;
    $15_1 = $17_1;
   }
   if ($15_1) break label$1;
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$2 = i64toi32_i32$2;
   i64toi32_i32$3 = $1_1;
   i64toi32_i32$0 = 0;
   i64toi32_i32$1 = 48;
   i64toi32_i32$4 = i64toi32_i32$1 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = 0;
    $18_1 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
   } else {
    i64toi32_i32$0 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
    $18_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$4 | 0) | 0;
   }
   i64toi32_i32$0 = i64toi32_i32$0;
   $4_1 = $18_1 & 32767 | 0;
   $5_1 = $4_1 + 4294950913 | 0;
   if (($5_1 | 0) < (0 | 0)) break label$1;
   $3_1 = 4294967295;
   if ($5_1 >>> 0 > 31 >>> 0) break label$1;
   i64toi32_i32$0 = $0$hi;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$0 = i64toi32_i32$0;
   i64toi32_i32$2 = $1_1;
   i64toi32_i32$3 = 65535;
   i64toi32_i32$1 = 4294967295;
   i64toi32_i32$3 = i64toi32_i32$0 & i64toi32_i32$3 | 0;
   i64toi32_i32$3 = i64toi32_i32$3;
   i64toi32_i32$0 = i64toi32_i32$2 & i64toi32_i32$1 | 0;
   i64toi32_i32$2 = 65536;
   i64toi32_i32$1 = 0;
   i64toi32_i32$2 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
   $25_1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
   $25$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $0$hi;
   i64toi32_i32$0 = $25$hi;
   $32($2_1 | 0, $0_1 | 0, i64toi32_i32$2 | 0, $25_1 | 0, i64toi32_i32$0 | 0, 16495 - $4_1 | 0 | 0);
   $3_1 = HEAPU32[$2_1 >> 2] | 0;
  };
  global$0 = $2_1 + 16 | 0;
  return $3_1 | 0;
 }
 
 function $28($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  var i64toi32_i32$2 = 0, i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, i64toi32_i32$5 = 0, i64toi32_i32$3 = 0, $2_1 = 0, i64toi32_i32$4 = 0, $3_1 = 0, $40$hi = 0, $21_1 = 0, $22_1 = 0, $40 = 0, $19_1 = 0, $4_1 = 0, $4$hi = 0, $29_1 = 0, $29$hi = 0, $33$hi = 0, $34_1 = 0, $34$hi = 0, $38$hi = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  $3_1 = global$0 - 16 | 0;
  global$0 = $3_1;
  label$1 : {
   if ($1_1) {
    $2_1 = $1_1 >> 31 | 0;
    $2_1 = ($1_1 + $2_1 | 0) ^ $2_1 | 0;
    i64toi32_i32$0 = 0;
    $19_1 = $2_1;
    $2_1 = Math_clz32($2_1);
    i64toi32_i32$0 = i64toi32_i32$0;
    i64toi32_i32$1 = 0;
    $31($3_1 | 0, $19_1 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$1 | 0, $2_1 + 81 | 0 | 0);
    i64toi32_i32$2 = $3_1;
    i64toi32_i32$1 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
    i64toi32_i32$0 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
    i64toi32_i32$0 = i64toi32_i32$0;
    $4_1 = i64toi32_i32$1;
    $4$hi = i64toi32_i32$0;
    i64toi32_i32$2 = i64toi32_i32$2 + 8 | 0;
    i64toi32_i32$0 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
    i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$2 = i64toi32_i32$0;
    i64toi32_i32$0 = 65536;
    i64toi32_i32$3 = 0;
    i64toi32_i32$0 = i64toi32_i32$1 ^ i64toi32_i32$0 | 0;
    $29_1 = i64toi32_i32$2 ^ i64toi32_i32$3 | 0;
    $29$hi = i64toi32_i32$0;
    i64toi32_i32$0 = 0;
    i64toi32_i32$0 = i64toi32_i32$0;
    i64toi32_i32$1 = 16414 - $2_1 | 0;
    i64toi32_i32$2 = 0;
    i64toi32_i32$3 = 48;
    i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
     i64toi32_i32$2 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
     $21_1 = 0;
    } else {
     i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$4 | 0) | 0;
     $21_1 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
    }
    $33$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $29$hi;
    i64toi32_i32$0 = $29_1;
    i64toi32_i32$1 = $33$hi;
    i64toi32_i32$3 = $21_1;
    i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
    i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$1 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0;
    $34_1 = i64toi32_i32$4;
    $34$hi = i64toi32_i32$5;
    i64toi32_i32$5 = 0;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$2 = $1_1 & 2147483648 | 0;
    i64toi32_i32$0 = 0;
    i64toi32_i32$3 = 32;
    i64toi32_i32$1 = i64toi32_i32$3 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
     i64toi32_i32$0 = i64toi32_i32$2 << i64toi32_i32$1 | 0;
     $22_1 = 0;
    } else {
     i64toi32_i32$0 = ((1 << i64toi32_i32$1 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$1 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$1 | 0) | 0;
     $22_1 = i64toi32_i32$2 << i64toi32_i32$1 | 0;
    }
    $38$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $34$hi;
    i64toi32_i32$5 = $34_1;
    i64toi32_i32$2 = $38$hi;
    i64toi32_i32$3 = $22_1;
    i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    $40 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
    $40$hi = i64toi32_i32$2;
    break label$1;
   }
   i64toi32_i32$2 = 0;
   $40 = 0;
   $40$hi = i64toi32_i32$2;
  };
  i64toi32_i32$2 = $40$hi;
  i64toi32_i32$2 = i64toi32_i32$2;
  i64toi32_i32$2 = $4$hi;
  i64toi32_i32$5 = $0_1;
  i64toi32_i32$2 = i64toi32_i32$2;
  wasm2asm_i32$0 = i64toi32_i32$5;
  wasm2asm_i32$1 = $4_1;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$5;
  wasm2asm_i32$1 = i64toi32_i32$2;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  i64toi32_i32$2 = $40$hi;
  i64toi32_i32$5 = i64toi32_i32$5;
  i64toi32_i32$2 = i64toi32_i32$2;
  wasm2asm_i32$0 = i64toi32_i32$5;
  wasm2asm_i32$1 = $40;
  HEAP32[(wasm2asm_i32$0 + 8 | 0) >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$5;
  wasm2asm_i32$1 = i64toi32_i32$2;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 12 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 13 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 14 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 15 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  global$0 = $3_1 + 16 | 0;
 }
 
 function $29($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$5 = 0, i64toi32_i32$2 = 0, i64toi32_i32$1 = 0, i64toi32_i32$4 = 0, i64toi32_i32$3 = 0, $2_1 = 0, $27$hi = 0, $17_1 = 0, $27_1 = 0, $11_1 = 0, $3_1 = 0, $3$hi = 0, $21_1 = 0, $21$hi = 0, $25$hi = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  $2_1 = global$0 - 16 | 0;
  global$0 = $2_1;
  label$1 : {
   if ($1_1) {
    i64toi32_i32$0 = 0;
    $11_1 = $1_1;
    $1_1 = Math_clz32($1_1);
    i64toi32_i32$0 = i64toi32_i32$0;
    i64toi32_i32$1 = 0;
    $31($2_1 | 0, $11_1 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$1 | 0, $1_1 + 81 | 0 | 0);
    i64toi32_i32$2 = $2_1;
    i64toi32_i32$1 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
    i64toi32_i32$0 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
    i64toi32_i32$0 = i64toi32_i32$0;
    $3_1 = i64toi32_i32$1;
    $3$hi = i64toi32_i32$0;
    i64toi32_i32$2 = i64toi32_i32$2 + 8 | 0;
    i64toi32_i32$0 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
    i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$2 = i64toi32_i32$0;
    i64toi32_i32$0 = 65536;
    i64toi32_i32$3 = 0;
    i64toi32_i32$0 = i64toi32_i32$1 ^ i64toi32_i32$0 | 0;
    $21_1 = i64toi32_i32$2 ^ i64toi32_i32$3 | 0;
    $21$hi = i64toi32_i32$0;
    i64toi32_i32$0 = 0;
    i64toi32_i32$0 = i64toi32_i32$0;
    i64toi32_i32$1 = 16414 - $1_1 | 0;
    i64toi32_i32$2 = 0;
    i64toi32_i32$3 = 48;
    i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
     i64toi32_i32$2 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
     $17_1 = 0;
    } else {
     i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$4 | 0) | 0;
     $17_1 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
    }
    $25$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $21$hi;
    i64toi32_i32$0 = $21_1;
    i64toi32_i32$1 = $25$hi;
    i64toi32_i32$3 = $17_1;
    i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
    i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$1 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0;
    i64toi32_i32$5 = i64toi32_i32$5;
    $27_1 = i64toi32_i32$4;
    $27$hi = i64toi32_i32$5;
    break label$1;
   }
   i64toi32_i32$5 = 0;
   $27_1 = 0;
   $27$hi = i64toi32_i32$5;
  };
  i64toi32_i32$5 = $27$hi;
  i64toi32_i32$5 = i64toi32_i32$5;
  i64toi32_i32$5 = $3$hi;
  i64toi32_i32$0 = $0_1;
  i64toi32_i32$5 = i64toi32_i32$5;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = $3_1;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = i64toi32_i32$5;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  i64toi32_i32$5 = $27$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$5 = i64toi32_i32$5;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = $27_1;
  HEAP32[(wasm2asm_i32$0 + 8 | 0) >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = i64toi32_i32$5;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 12 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 13 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 14 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 15 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  global$0 = $2_1 + 16 | 0;
 }
 
 function $30($0_1, $1_1, $1$hi, $2_1, $2$hi, $3_1, $3$hi, $4_1, $4$hi) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  $3$hi = $3$hi | 0;
  $4_1 = $4_1 | 0;
  $4$hi = $4$hi | 0;
  var i64toi32_i32$2 = 0, i64toi32_i32$0 = 0, i64toi32_i32$4 = 0, i64toi32_i32$5 = 0, i64toi32_i32$1 = 0, i64toi32_i32$3 = 0, $6_1 = 0, $7_1 = 0, $5_1 = 0, $9$hi = 0, $9_1 = 0, $8$hi = 0, $10_1 = 0, $10$hi = 0, $8_1 = 0, i64toi32_i32$6 = 0, $234 = 0, $234$hi = 0, $12$hi = 0, $11_1 = 0, $125 = 0, $126 = 0, $128 = 0, $129 = 0, $130 = 0, $131 = 0, $132 = 0, $133 = 0, $134 = 0, $12_1 = 0, $135 = 0, $136 = 0, $137 = 0, $138 = 0, $139 = 0, $140 = 0, $141 = 0, $142 = 0, $143 = 0, $144 = 0, $145 = 0, $146 = 0, $21_1 = 0, $27_1 = 0, $28$hi = 0, $32_1 = 0, $40 = 0, $44 = 0, $45$hi = 0, $49 = 0, $54 = 0, $56 = 0, $65 = 0, $67 = 0, $76 = 0, $76$hi = 0, $82 = 0, $82$hi = 0, $86 = 0, $86$hi = 0, $96 = 0, $96$hi = 0, $124 = 0, $127 = 0, $155 = 0, $156 = 0, $156$hi = 0, $157 = 0, $157$hi = 0, $164$hi = 0, $167$hi = 0, $188 = 0, $189 = 0, $189$hi = 0, $190 = 0, $190$hi = 0, $197$hi = 0, $200$hi = 0, $213 = 0, $213$hi = 0, $215$hi = 0, $219 = 0, $219$hi = 0, $221$hi = 0, $253 = 0, $253$hi = 0, $255 = 0, $255$hi = 0, $258 = 0, $258$hi = 0, $260 = 0, $261$hi = 0, $272 = 0, $272$hi = 0, $278 = 0, $279$hi = 0, $285 = 0, $285$hi = 0, $287$hi = 0, $288 = 0, $288$hi = 0, $290 = 0, $290$hi = 0, $302$hi = 0, $305 = 0, $306$hi = 0, $314 = 0, $315 = 0, $315$hi = 0, $316 = 0, $316$hi = 0, $323$hi = 0, $326$hi = 0, $361 = 0, $361$hi = 0, $363 = 0, $363$hi = 0, $366 = 0, $366$hi = 0, $368 = 0, $369$hi = 0, $376$hi = 0, $378 = 0, $378$hi = 0, $381$hi = 0, $382 = 0, $382$hi = 0, $384 = 0, $384$hi = 0, $386$hi = 0, $394$hi = 0, $398 = 0, $399$hi = 0, $400 = 0, $400$hi = 0, $147 = 0, $411 = 0, $412$hi = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  $5_1 = global$0 - 112 | 0;
  global$0 = $5_1;
  i64toi32_i32$0 = $4$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$2 = $4_1;
  i64toi32_i32$1 = 2147483647;
  i64toi32_i32$3 = 4294967295;
  i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
  i64toi32_i32$1 = i64toi32_i32$1;
  $9_1 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
  $9$hi = i64toi32_i32$1;
  label$1 : {
   label$2 : {
    i64toi32_i32$1 = $1$hi;
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$0 = $1_1;
    i64toi32_i32$2 = 4294967295;
    i64toi32_i32$3 = 4294967295;
    i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
    i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0;
    i64toi32_i32$5 = i64toi32_i32$5;
    $8_1 = i64toi32_i32$4;
    $8$hi = i64toi32_i32$5;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$1 = i64toi32_i32$4;
    i64toi32_i32$0 = 4294967295;
    i64toi32_i32$3 = 4294967295;
    $21_1 = (i64toi32_i32$4 | 0) == (i64toi32_i32$3 | 0) & (i64toi32_i32$5 | 0) == (i64toi32_i32$0 | 0) | 0;
    i64toi32_i32$1 = $2$hi;
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$3 = $2_1;
    i64toi32_i32$5 = 2147483647;
    i64toi32_i32$0 = 4294967295;
    i64toi32_i32$5 = i64toi32_i32$1 & i64toi32_i32$5 | 0;
    i64toi32_i32$5 = i64toi32_i32$5;
    $10_1 = i64toi32_i32$3 & i64toi32_i32$0 | 0;
    $10$hi = i64toi32_i32$5;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$5 = $8$hi;
    i64toi32_i32$5 = $1$hi;
    i64toi32_i32$5 = $8$hi;
    i64toi32_i32$1 = i64toi32_i32$4;
    i64toi32_i32$3 = $1$hi;
    i64toi32_i32$0 = $1_1;
    $27_1 = i64toi32_i32$5 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$4 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0;
    i64toi32_i32$1 = 0;
    $28$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $10$hi;
    i64toi32_i32$0 = $10_1;
    i64toi32_i32$5 = $28$hi;
    i64toi32_i32$3 = $27_1;
    i64toi32_i32$2 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
    i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
    if (i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0) i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0;
    i64toi32_i32$4 = i64toi32_i32$4;
    i64toi32_i32$1 = i64toi32_i32$2;
    i64toi32_i32$0 = 4294967295;
    i64toi32_i32$3 = 4294967295;
    i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$3 | 0;
    i64toi32_i32$2 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
    if (i64toi32_i32$5 >>> 0 < i64toi32_i32$3 >>> 0) i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    $8_1 = i64toi32_i32$5;
    $8$hi = i64toi32_i32$2;
    i64toi32_i32$2 = i64toi32_i32$2;
    i64toi32_i32$2 = i64toi32_i32$2;
    i64toi32_i32$4 = i64toi32_i32$5;
    i64toi32_i32$1 = 2147418111;
    i64toi32_i32$3 = 4294967295;
    $32_1 = i64toi32_i32$2 >>> 0 > i64toi32_i32$1 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$4 >>> 0 > i64toi32_i32$3 >>> 0 | 0) | 0;
    i64toi32_i32$4 = i64toi32_i32$2;
    i64toi32_i32$4 = i64toi32_i32$2;
    i64toi32_i32$3 = i64toi32_i32$5;
    i64toi32_i32$2 = 2147418111;
    i64toi32_i32$1 = 4294967295;
    if (((wasm2asm_i32$0 = $21_1, wasm2asm_i32$1 = $32_1, wasm2asm_i32$2 = (i64toi32_i32$5 | 0) == (i64toi32_i32$1 | 0) & (i64toi32_i32$4 | 0) == (i64toi32_i32$2 | 0) | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) == (0 | 0)) {
     i64toi32_i32$3 = $3$hi;
     i64toi32_i32$3 = i64toi32_i32$3;
     i64toi32_i32$1 = $3_1;
     i64toi32_i32$4 = 4294967295;
     i64toi32_i32$2 = 4294967295;
     i64toi32_i32$0 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
     i64toi32_i32$5 = i64toi32_i32$3 + i64toi32_i32$4 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$2 >>> 0) i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0;
     i64toi32_i32$5 = i64toi32_i32$5;
     $8_1 = i64toi32_i32$0;
     $8$hi = i64toi32_i32$5;
     i64toi32_i32$5 = i64toi32_i32$5;
     i64toi32_i32$5 = i64toi32_i32$5;
     i64toi32_i32$3 = i64toi32_i32$0;
     i64toi32_i32$1 = 4294967295;
     i64toi32_i32$2 = 4294967295;
     $40 = (i64toi32_i32$0 | 0) != (i64toi32_i32$2 | 0) | (i64toi32_i32$5 | 0) != (i64toi32_i32$1 | 0) | 0;
     i64toi32_i32$3 = $9$hi;
     i64toi32_i32$3 = i64toi32_i32$5;
     i64toi32_i32$3 = $3$hi;
     i64toi32_i32$3 = i64toi32_i32$5;
     i64toi32_i32$2 = i64toi32_i32$0;
     i64toi32_i32$5 = $3$hi;
     i64toi32_i32$1 = $3_1;
     $44 = i64toi32_i32$3 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
     i64toi32_i32$2 = 0;
     $45$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $9$hi;
     i64toi32_i32$1 = $9_1;
     i64toi32_i32$3 = $45$hi;
     i64toi32_i32$5 = $44;
     i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
     i64toi32_i32$0 = i64toi32_i32$2 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$4 >>> 0 < i64toi32_i32$5 >>> 0) i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0;
     i64toi32_i32$0 = i64toi32_i32$0;
     i64toi32_i32$2 = i64toi32_i32$4;
     i64toi32_i32$1 = 4294967295;
     i64toi32_i32$5 = 4294967295;
     i64toi32_i32$3 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
     i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$1 | 0;
     if (i64toi32_i32$3 >>> 0 < i64toi32_i32$5 >>> 0) i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0;
     i64toi32_i32$4 = i64toi32_i32$4;
     $8_1 = i64toi32_i32$3;
     $8$hi = i64toi32_i32$4;
     i64toi32_i32$4 = i64toi32_i32$4;
     i64toi32_i32$4 = i64toi32_i32$4;
     i64toi32_i32$0 = i64toi32_i32$3;
     i64toi32_i32$2 = 2147418111;
     i64toi32_i32$5 = 4294967295;
     $49 = i64toi32_i32$4 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$0 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
     i64toi32_i32$0 = i64toi32_i32$4;
     i64toi32_i32$0 = i64toi32_i32$4;
     i64toi32_i32$5 = i64toi32_i32$3;
     i64toi32_i32$4 = 2147418111;
     i64toi32_i32$2 = 4294967295;
     if (wasm2asm_i32$0 = $40, wasm2asm_i32$1 = $49, wasm2asm_i32$2 = (i64toi32_i32$5 | 0) == (i64toi32_i32$2 | 0) & (i64toi32_i32$0 | 0) == (i64toi32_i32$4 | 0) | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) break label$2;
    }
    i64toi32_i32$5 = $1$hi;
    i64toi32_i32$5 = i64toi32_i32$5;
    $54 = ($1_1 | i64toi32_i32$5 | 0 | 0) == (0 | 0);
    i64toi32_i32$5 = $10$hi;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$2 = $10_1;
    i64toi32_i32$0 = 2147418112;
    i64toi32_i32$4 = 0;
    $56 = i64toi32_i32$5 >>> 0 < i64toi32_i32$0 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$4 >>> 0 | 0) | 0;
    i64toi32_i32$2 = i64toi32_i32$5;
    i64toi32_i32$2 = i64toi32_i32$2;
    i64toi32_i32$4 = $10_1;
    i64toi32_i32$5 = 2147418112;
    i64toi32_i32$0 = 0;
    if (((wasm2asm_i32$0 = $54, wasm2asm_i32$1 = $56, wasm2asm_i32$2 = (i64toi32_i32$4 | 0) == (i64toi32_i32$0 | 0) & (i64toi32_i32$2 | 0) == (i64toi32_i32$5 | 0) | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) == (0 | 0)) {
     i64toi32_i32$4 = $2$hi;
     i64toi32_i32$4 = i64toi32_i32$4;
     i64toi32_i32$0 = $2_1;
     i64toi32_i32$2 = 32768;
     i64toi32_i32$5 = 0;
     i64toi32_i32$2 = i64toi32_i32$4 | i64toi32_i32$2 | 0;
     i64toi32_i32$2 = i64toi32_i32$2;
     $4_1 = i64toi32_i32$0 | i64toi32_i32$5 | 0;
     $4$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $1$hi;
     i64toi32_i32$2 = i64toi32_i32$2;
     $3_1 = $1_1;
     $3$hi = i64toi32_i32$2;
     break label$1;
    }
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$2 = i64toi32_i32$2;
    $65 = ($3_1 | i64toi32_i32$2 | 0 | 0) == (0 | 0);
    i64toi32_i32$2 = $9$hi;
    i64toi32_i32$2 = i64toi32_i32$2;
    i64toi32_i32$4 = $9_1;
    i64toi32_i32$0 = 2147418112;
    i64toi32_i32$5 = 0;
    $67 = i64toi32_i32$2 >>> 0 < i64toi32_i32$0 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$4 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
    i64toi32_i32$4 = i64toi32_i32$2;
    i64toi32_i32$4 = i64toi32_i32$2;
    i64toi32_i32$5 = $9_1;
    i64toi32_i32$2 = 2147418112;
    i64toi32_i32$0 = 0;
    if (((wasm2asm_i32$0 = $65, wasm2asm_i32$1 = $67, wasm2asm_i32$2 = (i64toi32_i32$5 | 0) == (i64toi32_i32$0 | 0) & (i64toi32_i32$4 | 0) == (i64toi32_i32$2 | 0) | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) == (0 | 0)) {
     i64toi32_i32$5 = $4$hi;
     i64toi32_i32$5 = i64toi32_i32$5;
     i64toi32_i32$0 = $4_1;
     i64toi32_i32$4 = 32768;
     i64toi32_i32$2 = 0;
     i64toi32_i32$4 = i64toi32_i32$5 | i64toi32_i32$4 | 0;
     i64toi32_i32$4 = i64toi32_i32$4;
     $4_1 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
     $4$hi = i64toi32_i32$4;
     break label$1;
    }
    i64toi32_i32$4 = $1$hi;
    i64toi32_i32$4 = $10$hi;
    i64toi32_i32$4 = i64toi32_i32$4;
    i64toi32_i32$5 = $10_1;
    i64toi32_i32$0 = 2147418112;
    i64toi32_i32$2 = 0;
    i64toi32_i32$0 = i64toi32_i32$4 ^ i64toi32_i32$0 | 0;
    $76 = i64toi32_i32$5 ^ i64toi32_i32$2 | 0;
    $76$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$4 = $1_1;
    i64toi32_i32$5 = $76$hi;
    i64toi32_i32$2 = $76;
    i64toi32_i32$5 = i64toi32_i32$0 | i64toi32_i32$5 | 0;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$0 = i64toi32_i32$4 | i64toi32_i32$2 | 0;
    i64toi32_i32$4 = 0;
    i64toi32_i32$2 = 0;
    if ((i64toi32_i32$0 | 0) == (i64toi32_i32$2 | 0) & (i64toi32_i32$5 | 0) == (i64toi32_i32$4 | 0) | 0) {
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$0 = $3$hi;
     i64toi32_i32$0 = $1$hi;
     i64toi32_i32$0 = $3$hi;
     i64toi32_i32$2 = $3_1;
     i64toi32_i32$5 = $1$hi;
     i64toi32_i32$4 = $1_1;
     i64toi32_i32$5 = i64toi32_i32$0 ^ i64toi32_i32$5 | 0;
     $82 = i64toi32_i32$2 ^ i64toi32_i32$4 | 0;
     $82$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $4$hi;
     i64toi32_i32$5 = $2$hi;
     i64toi32_i32$5 = $4$hi;
     i64toi32_i32$0 = $4_1;
     i64toi32_i32$2 = $2$hi;
     i64toi32_i32$4 = $2_1;
     i64toi32_i32$2 = i64toi32_i32$5 ^ i64toi32_i32$2 | 0;
     i64toi32_i32$2 = i64toi32_i32$2;
     i64toi32_i32$5 = i64toi32_i32$0 ^ i64toi32_i32$4 | 0;
     i64toi32_i32$0 = 2147483648;
     i64toi32_i32$4 = 0;
     i64toi32_i32$0 = i64toi32_i32$2 ^ i64toi32_i32$0 | 0;
     $86 = i64toi32_i32$5 ^ i64toi32_i32$4 | 0;
     $86$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $82$hi;
     i64toi32_i32$2 = $82;
     i64toi32_i32$5 = $86$hi;
     i64toi32_i32$4 = $86;
     i64toi32_i32$5 = i64toi32_i32$0 | i64toi32_i32$5 | 0;
     i64toi32_i32$5 = i64toi32_i32$5;
     $6_1 = (i64toi32_i32$2 | i64toi32_i32$4 | 0 | i64toi32_i32$5 | 0 | 0) == (0 | 0);
     i64toi32_i32$5 = 2147450880;
     i64toi32_i32$2 = $2$hi;
     i64toi32_i32$0 = $2_1;
     i64toi32_i32$5 = i64toi32_i32$2;
     i64toi32_i32$5 = i64toi32_i32$2;
     $4_1 = (wasm2asm_i32$0 = 0, wasm2asm_i32$1 = i64toi32_i32$0, wasm2asm_i32$2 = $6_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
     $4$hi = i64toi32_i32$2;
     i64toi32_i32$5 = $1$hi;
     i64toi32_i32$5 = 0;
     i64toi32_i32$2 = $1$hi;
     i64toi32_i32$0 = $1_1;
     i64toi32_i32$5 = i64toi32_i32$2;
     i64toi32_i32$5 = i64toi32_i32$2;
     $3_1 = (wasm2asm_i32$0 = 0, wasm2asm_i32$1 = i64toi32_i32$0, wasm2asm_i32$2 = $6_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
     $3$hi = i64toi32_i32$2;
     break label$1;
    }
    i64toi32_i32$5 = $3$hi;
    i64toi32_i32$5 = $9$hi;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$0 = $9_1;
    i64toi32_i32$2 = 2147418112;
    i64toi32_i32$4 = 0;
    i64toi32_i32$2 = i64toi32_i32$5 ^ i64toi32_i32$2 | 0;
    $96 = i64toi32_i32$0 ^ i64toi32_i32$4 | 0;
    $96$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$5 = $3_1;
    i64toi32_i32$0 = $96$hi;
    i64toi32_i32$4 = $96;
    i64toi32_i32$0 = i64toi32_i32$2 | i64toi32_i32$0 | 0;
    i64toi32_i32$0 = i64toi32_i32$0;
    if ((i64toi32_i32$5 | i64toi32_i32$4 | 0 | i64toi32_i32$0 | 0 | 0) == (0 | 0)) break label$1;
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$0 = $10$hi;
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$2 = $1_1;
    i64toi32_i32$5 = $10$hi;
    i64toi32_i32$4 = $10_1;
    i64toi32_i32$5 = i64toi32_i32$0 | i64toi32_i32$5 | 0;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$0 = i64toi32_i32$2 | i64toi32_i32$4 | 0;
    i64toi32_i32$2 = 0;
    i64toi32_i32$4 = 0;
    if ((i64toi32_i32$0 | 0) != (i64toi32_i32$4 | 0) | (i64toi32_i32$5 | 0) != (i64toi32_i32$2 | 0) | 0) {
     i64toi32_i32$0 = $3$hi;
     i64toi32_i32$0 = $9$hi;
     i64toi32_i32$0 = $3$hi;
     i64toi32_i32$4 = $3_1;
     i64toi32_i32$5 = $9$hi;
     i64toi32_i32$2 = $9_1;
     i64toi32_i32$5 = i64toi32_i32$0 | i64toi32_i32$5 | 0;
     i64toi32_i32$5 = i64toi32_i32$5;
     if (((i64toi32_i32$4 | i64toi32_i32$2 | 0 | i64toi32_i32$5 | 0 | 0) == (0 | 0) | 0) == (0 | 0)) break label$2;
     i64toi32_i32$5 = $1$hi;
     i64toi32_i32$5 = i64toi32_i32$5;
     $3_1 = $1_1;
     $3$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $2$hi;
     i64toi32_i32$5 = i64toi32_i32$5;
     $4_1 = $2_1;
     $4$hi = i64toi32_i32$5;
     break label$1;
    }
    i64toi32_i32$5 = $3$hi;
    i64toi32_i32$5 = $9$hi;
    i64toi32_i32$5 = $3$hi;
    i64toi32_i32$0 = $3_1;
    i64toi32_i32$4 = $9$hi;
    i64toi32_i32$2 = $9_1;
    i64toi32_i32$4 = i64toi32_i32$5 | i64toi32_i32$4 | 0;
    i64toi32_i32$4 = i64toi32_i32$4;
    i64toi32_i32$5 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
    i64toi32_i32$0 = 0;
    i64toi32_i32$2 = 0;
    if ((i64toi32_i32$5 | 0) != (i64toi32_i32$2 | 0) | (i64toi32_i32$4 | 0) != (i64toi32_i32$0 | 0) | 0) break label$1;
    i64toi32_i32$5 = $3$hi;
    i64toi32_i32$5 = $1$hi;
    i64toi32_i32$5 = $3$hi;
    i64toi32_i32$2 = $3_1;
    i64toi32_i32$4 = $1$hi;
    i64toi32_i32$0 = $1_1;
    i64toi32_i32$4 = i64toi32_i32$5 & i64toi32_i32$4 | 0;
    i64toi32_i32$4 = i64toi32_i32$4;
    $3_1 = i64toi32_i32$2 & i64toi32_i32$0 | 0;
    $3$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $4$hi;
    i64toi32_i32$4 = $2$hi;
    i64toi32_i32$4 = $4$hi;
    i64toi32_i32$5 = $4_1;
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$0 = $2_1;
    i64toi32_i32$2 = i64toi32_i32$4 & i64toi32_i32$2 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    $4_1 = i64toi32_i32$5 & i64toi32_i32$0 | 0;
    $4$hi = i64toi32_i32$2;
    break label$1;
   };
   i64toi32_i32$2 = $3$hi;
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$2 = $3$hi;
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$2 = $3$hi;
   i64toi32_i32$4 = $3_1;
   i64toi32_i32$5 = $1$hi;
   i64toi32_i32$0 = $1_1;
   $124 = i64toi32_i32$2 >>> 0 > i64toi32_i32$5 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$4 >>> 0 > i64toi32_i32$0 >>> 0 | 0) | 0;
   i64toi32_i32$4 = $9$hi;
   i64toi32_i32$4 = $10$hi;
   i64toi32_i32$4 = $9$hi;
   i64toi32_i32$0 = $9_1;
   i64toi32_i32$2 = $10$hi;
   i64toi32_i32$5 = $10_1;
   $127 = i64toi32_i32$4 >>> 0 > i64toi32_i32$2 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$0 >>> 0 > i64toi32_i32$5 >>> 0 | 0) | 0;
   i64toi32_i32$0 = i64toi32_i32$4;
   i64toi32_i32$0 = i64toi32_i32$2;
   i64toi32_i32$0 = i64toi32_i32$4;
   i64toi32_i32$5 = $9_1;
   i64toi32_i32$4 = i64toi32_i32$2;
   i64toi32_i32$2 = $10_1;
   $7_1 = (wasm2asm_i32$0 = $124, wasm2asm_i32$1 = $127, wasm2asm_i32$2 = (i64toi32_i32$5 | 0) == (i64toi32_i32$2 | 0) & (i64toi32_i32$0 | 0) == (i64toi32_i32$4 | 0) | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
   i64toi32_i32$5 = $3$hi;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$2 = $1_1;
   i64toi32_i32$5 = i64toi32_i32$0;
   i64toi32_i32$5 = i64toi32_i32$0;
   $9_1 = (wasm2asm_i32$0 = $3_1, wasm2asm_i32$1 = i64toi32_i32$2, wasm2asm_i32$2 = $7_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
   $9$hi = i64toi32_i32$0;
   i64toi32_i32$5 = $4$hi;
   i64toi32_i32$5 = $2$hi;
   i64toi32_i32$5 = $4$hi;
   i64toi32_i32$0 = $2$hi;
   i64toi32_i32$2 = $2_1;
   i64toi32_i32$5 = i64toi32_i32$0;
   i64toi32_i32$5 = i64toi32_i32$0;
   $10_1 = (wasm2asm_i32$0 = $4_1, wasm2asm_i32$1 = i64toi32_i32$2, wasm2asm_i32$2 = $7_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
   $10$hi = i64toi32_i32$0;
   i64toi32_i32$5 = i64toi32_i32$0;
   i64toi32_i32$5 = i64toi32_i32$0;
   i64toi32_i32$2 = $10_1;
   i64toi32_i32$0 = 65535;
   i64toi32_i32$4 = 4294967295;
   i64toi32_i32$0 = i64toi32_i32$5 & i64toi32_i32$0 | 0;
   i64toi32_i32$0 = i64toi32_i32$0;
   $8_1 = i64toi32_i32$2 & i64toi32_i32$4 | 0;
   $8$hi = i64toi32_i32$0;
   i64toi32_i32$0 = i64toi32_i32$5;
   i64toi32_i32$0 = $4$hi;
   i64toi32_i32$0 = i64toi32_i32$5;
   i64toi32_i32$2 = $4$hi;
   i64toi32_i32$5 = $4_1;
   i64toi32_i32$0 = i64toi32_i32$2;
   i64toi32_i32$0 = i64toi32_i32$2;
   $2_1 = (wasm2asm_i32$0 = $2_1, wasm2asm_i32$1 = i64toi32_i32$5, wasm2asm_i32$2 = $7_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
   $2$hi = i64toi32_i32$2;
   i64toi32_i32$0 = i64toi32_i32$2;
   i64toi32_i32$0 = i64toi32_i32$2;
   i64toi32_i32$5 = $2_1;
   i64toi32_i32$2 = 0;
   i64toi32_i32$4 = 48;
   i64toi32_i32$1 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = 0;
    $125 = i64toi32_i32$0 >>> i64toi32_i32$1 | 0;
   } else {
    i64toi32_i32$2 = i64toi32_i32$0 >>> i64toi32_i32$1 | 0;
    $125 = (((1 << i64toi32_i32$1 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$1 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$1 | 0) | 0;
   }
   i64toi32_i32$2 = i64toi32_i32$2;
   $11_1 = $125 & 32767 | 0;
   i64toi32_i32$2 = $10$hi;
   i64toi32_i32$2 = i64toi32_i32$2;
   i64toi32_i32$0 = $10_1;
   i64toi32_i32$5 = 0;
   i64toi32_i32$4 = 48;
   i64toi32_i32$1 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$5 = 0;
    $126 = i64toi32_i32$2 >>> i64toi32_i32$1 | 0;
   } else {
    i64toi32_i32$5 = i64toi32_i32$2 >>> i64toi32_i32$1 | 0;
    $126 = (((1 << i64toi32_i32$1 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$1 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$1 | 0) | 0;
   }
   i64toi32_i32$5 = i64toi32_i32$5;
   $6_1 = $126 & 32767 | 0;
   if (($6_1 | 0) == (0 | 0)) {
    $155 = $5_1 + 96 | 0;
    i64toi32_i32$5 = $9$hi;
    $156 = $9_1;
    $156$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $8$hi;
    $157 = $8_1;
    $157$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $9$hi;
    i64toi32_i32$5 = $8$hi;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$5 = i64toi32_i32$5;
    $6_1 = ($8_1 | i64toi32_i32$5 | 0 | 0) == (0 | 0);
    i64toi32_i32$5 = $9$hi;
    i64toi32_i32$0 = $8$hi;
    i64toi32_i32$2 = $8_1;
    i64toi32_i32$5 = i64toi32_i32$0;
    i64toi32_i32$5 = i64toi32_i32$0;
    i64toi32_i32$0 = (wasm2asm_i32$0 = $9_1, wasm2asm_i32$1 = i64toi32_i32$2, wasm2asm_i32$2 = $6_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
    i64toi32_i32$4 = Math_clz32(i64toi32_i32$5);
    i64toi32_i32$2 = 0;
    if ((i64toi32_i32$4 | 0) == (32 | 0)) $128 = Math_clz32(i64toi32_i32$0) + 32 | 0; else $128 = i64toi32_i32$4;
    $164$hi = i64toi32_i32$2;
    i64toi32_i32$2 = 0;
    $167$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $164$hi;
    i64toi32_i32$0 = $128;
    i64toi32_i32$5 = $167$hi;
    i64toi32_i32$4 = $6_1 << 6 | 0;
    i64toi32_i32$1 = i64toi32_i32$0 + i64toi32_i32$4 | 0;
    i64toi32_i32$3 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
    if (i64toi32_i32$1 >>> 0 < i64toi32_i32$4 >>> 0) i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0;
    i64toi32_i32$3 = i64toi32_i32$3;
    $6_1 = i64toi32_i32$1;
    i64toi32_i32$3 = $156$hi;
    i64toi32_i32$0 = $157$hi;
    $31($155 | 0, $156 | 0, i64toi32_i32$3 | 0, $157 | 0, i64toi32_i32$0 | 0, i64toi32_i32$1 + 4294967281 | 0 | 0);
    $6_1 = 16 - i64toi32_i32$1 | 0;
    i64toi32_i32$2 = $5_1 + 104 | 0;
    i64toi32_i32$0 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
    i64toi32_i32$3 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
    i64toi32_i32$3 = i64toi32_i32$3;
    $8_1 = i64toi32_i32$0;
    $8$hi = i64toi32_i32$3;
    i64toi32_i32$2 = $5_1;
    i64toi32_i32$3 = HEAPU32[(i64toi32_i32$2 + 96 | 0) >> 2] | 0;
    i64toi32_i32$0 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 100 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 101 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 102 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 103 | 0) >> 0] | 0 | 0) << 24);
    i64toi32_i32$0 = i64toi32_i32$0;
    $9_1 = i64toi32_i32$3;
    $9$hi = i64toi32_i32$0;
   }
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$0 = $3$hi;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$3 = $3$hi;
   i64toi32_i32$2 = $3_1;
   i64toi32_i32$0 = i64toi32_i32$3;
   i64toi32_i32$0 = i64toi32_i32$0;
   $3_1 = (wasm2asm_i32$0 = $1_1, wasm2asm_i32$1 = i64toi32_i32$2, wasm2asm_i32$2 = $7_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
   $3$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $2$hi;
   i64toi32_i32$0 = i64toi32_i32$0;
   i64toi32_i32$2 = $2_1;
   i64toi32_i32$3 = 65535;
   i64toi32_i32$4 = 4294967295;
   i64toi32_i32$3 = i64toi32_i32$0 & i64toi32_i32$3 | 0;
   i64toi32_i32$3 = i64toi32_i32$3;
   $1_1 = i64toi32_i32$2 & i64toi32_i32$4 | 0;
   $1$hi = i64toi32_i32$3;
   if (($11_1 | 0) == (0 | 0)) {
    $188 = $5_1 + 80 | 0;
    i64toi32_i32$3 = $3$hi;
    $189 = $3_1;
    $189$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $1$hi;
    $190 = $1_1;
    $190$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $3$hi;
    i64toi32_i32$3 = $1$hi;
    i64toi32_i32$3 = i64toi32_i32$3;
    i64toi32_i32$3 = i64toi32_i32$3;
    $7_1 = ($1_1 | i64toi32_i32$3 | 0 | 0) == (0 | 0);
    i64toi32_i32$3 = $3$hi;
    i64toi32_i32$2 = $1$hi;
    i64toi32_i32$0 = $1_1;
    i64toi32_i32$3 = i64toi32_i32$2;
    i64toi32_i32$3 = i64toi32_i32$2;
    i64toi32_i32$2 = (wasm2asm_i32$0 = $3_1, wasm2asm_i32$1 = i64toi32_i32$0, wasm2asm_i32$2 = $7_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
    i64toi32_i32$4 = Math_clz32(i64toi32_i32$3);
    i64toi32_i32$0 = 0;
    if ((i64toi32_i32$4 | 0) == (32 | 0)) $129 = Math_clz32(i64toi32_i32$2) + 32 | 0; else $129 = i64toi32_i32$4;
    $197$hi = i64toi32_i32$0;
    i64toi32_i32$0 = 0;
    $200$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $197$hi;
    i64toi32_i32$2 = $129;
    i64toi32_i32$3 = $200$hi;
    i64toi32_i32$4 = $7_1 << 6 | 0;
    i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$4 | 0;
    i64toi32_i32$1 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
    if (i64toi32_i32$5 >>> 0 < i64toi32_i32$4 >>> 0) i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0;
    i64toi32_i32$1 = i64toi32_i32$1;
    $7_1 = i64toi32_i32$5;
    i64toi32_i32$1 = $189$hi;
    i64toi32_i32$2 = $190$hi;
    $31($188 | 0, $189 | 0, i64toi32_i32$1 | 0, $190 | 0, i64toi32_i32$2 | 0, i64toi32_i32$5 + 4294967281 | 0 | 0);
    $11_1 = 16 - i64toi32_i32$5 | 0;
    i64toi32_i32$0 = $5_1 + 88 | 0;
    i64toi32_i32$2 = HEAPU32[i64toi32_i32$0 >> 2] | 0;
    i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$0, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
    i64toi32_i32$1 = i64toi32_i32$1;
    $1_1 = i64toi32_i32$2;
    $1$hi = i64toi32_i32$1;
    i64toi32_i32$0 = $5_1;
    i64toi32_i32$1 = HEAPU32[(i64toi32_i32$0 + 80 | 0) >> 2] | 0;
    i64toi32_i32$2 = (wasm2asm_i32$0 = i64toi32_i32$0, HEAPU8[(wasm2asm_i32$0 + 84 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 85 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 86 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 87 | 0) >> 0] | 0 | 0) << 24);
    i64toi32_i32$2 = i64toi32_i32$2;
    $3_1 = i64toi32_i32$1;
    $3$hi = i64toi32_i32$2;
   }
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$2 = i64toi32_i32$2;
   i64toi32_i32$0 = $1_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$4 = 3;
   i64toi32_i32$3 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$1 = i64toi32_i32$0 << i64toi32_i32$3 | 0;
    $130 = 0;
   } else {
    i64toi32_i32$1 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$3 | 0) | 0;
    $130 = i64toi32_i32$0 << i64toi32_i32$3 | 0;
   }
   $213 = $130;
   $213$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $3$hi;
   i64toi32_i32$1 = i64toi32_i32$1;
   i64toi32_i32$2 = $3_1;
   i64toi32_i32$0 = 0;
   i64toi32_i32$4 = 61;
   i64toi32_i32$3 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = 0;
    $131 = i64toi32_i32$1 >>> i64toi32_i32$3 | 0;
   } else {
    i64toi32_i32$0 = i64toi32_i32$1 >>> i64toi32_i32$3 | 0;
    $131 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$3 | 0) | 0;
   }
   $215$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $213$hi;
   i64toi32_i32$1 = $213;
   i64toi32_i32$2 = $215$hi;
   i64toi32_i32$4 = $131;
   i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
   i64toi32_i32$2 = i64toi32_i32$2;
   i64toi32_i32$0 = i64toi32_i32$1 | i64toi32_i32$4 | 0;
   i64toi32_i32$1 = 524288;
   i64toi32_i32$4 = 0;
   i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
   i64toi32_i32$1 = i64toi32_i32$1;
   $4_1 = i64toi32_i32$0 | i64toi32_i32$4 | 0;
   $4$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $8$hi;
   i64toi32_i32$1 = i64toi32_i32$1;
   i64toi32_i32$2 = $8_1;
   i64toi32_i32$0 = 0;
   i64toi32_i32$4 = 3;
   i64toi32_i32$3 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
    $132 = 0;
   } else {
    i64toi32_i32$0 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$3 | 0) | 0;
    $132 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
   }
   $219 = $132;
   $219$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $9$hi;
   i64toi32_i32$0 = i64toi32_i32$0;
   i64toi32_i32$1 = $9_1;
   i64toi32_i32$2 = 0;
   i64toi32_i32$4 = 61;
   i64toi32_i32$3 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = 0;
    $133 = i64toi32_i32$0 >>> i64toi32_i32$3 | 0;
   } else {
    i64toi32_i32$2 = i64toi32_i32$0 >>> i64toi32_i32$3 | 0;
    $133 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$3 | 0) | 0;
   }
   $221$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $219$hi;
   i64toi32_i32$0 = $219;
   i64toi32_i32$1 = $221$hi;
   i64toi32_i32$4 = $133;
   i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
   i64toi32_i32$1 = i64toi32_i32$1;
   $1_1 = i64toi32_i32$0 | i64toi32_i32$4 | 0;
   $1$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $10$hi;
   i64toi32_i32$1 = $2$hi;
   i64toi32_i32$1 = $10$hi;
   i64toi32_i32$2 = $10_1;
   i64toi32_i32$0 = $2$hi;
   i64toi32_i32$4 = $2_1;
   i64toi32_i32$0 = i64toi32_i32$1 ^ i64toi32_i32$0 | 0;
   i64toi32_i32$0 = i64toi32_i32$0;
   $8_1 = i64toi32_i32$2 ^ i64toi32_i32$4 | 0;
   $8$hi = i64toi32_i32$0;
   label$10 : {
    i64toi32_i32$0 = $3$hi;
    i64toi32_i32$0 = i64toi32_i32$0;
    i64toi32_i32$1 = $3_1;
    i64toi32_i32$2 = 0;
    i64toi32_i32$4 = 3;
    i64toi32_i32$3 = i64toi32_i32$4 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
     i64toi32_i32$2 = i64toi32_i32$1 << i64toi32_i32$3 | 0;
     $134 = 0;
    } else {
     i64toi32_i32$2 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$3 | 0) | 0;
     $134 = i64toi32_i32$1 << i64toi32_i32$3 | 0;
    }
    i64toi32_i32$2 = i64toi32_i32$2;
    $3_1 = $134;
    $3$hi = i64toi32_i32$2;
    i64toi32_i32$2 = i64toi32_i32$2;
    $7_1 = $6_1 - $11_1 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    $234 = $3_1;
    $234$hi = i64toi32_i32$2;
    if (($7_1 | 0) == (0 | 0)) break label$10;
    i64toi32_i32$2 = $234$hi;
    i64toi32_i32$2 = i64toi32_i32$2;
    if ($7_1 >>> 0 <= 127 >>> 0) {
     i64toi32_i32$2 = $3$hi;
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$2 = $3$hi;
     i64toi32_i32$1 = $4$hi;
     $31($5_1 - 4294967232 | 0 | 0, $3_1 | 0, i64toi32_i32$2 | 0, $4_1 | 0, i64toi32_i32$1 | 0, 128 - $7_1 | 0 | 0);
     i64toi32_i32$1 = i64toi32_i32$2;
     i64toi32_i32$1 = $4$hi;
     i64toi32_i32$1 = i64toi32_i32$2;
     i64toi32_i32$2 = $4$hi;
     $32($5_1 + 48 | 0 | 0, $3_1 | 0, i64toi32_i32$1 | 0, $4_1 | 0, i64toi32_i32$2 | 0, $7_1 | 0);
     i64toi32_i32$0 = $5_1 + 56 | 0;
     i64toi32_i32$2 = HEAPU32[i64toi32_i32$0 >> 2] | 0;
     i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$0, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
     i64toi32_i32$1 = i64toi32_i32$1;
     $4_1 = i64toi32_i32$2;
     $4$hi = i64toi32_i32$1;
     i64toi32_i32$0 = $5_1;
     i64toi32_i32$1 = HEAPU32[(i64toi32_i32$0 + 48 | 0) >> 2] | 0;
     i64toi32_i32$2 = (wasm2asm_i32$0 = i64toi32_i32$0, HEAPU8[(wasm2asm_i32$0 + 52 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 53 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 54 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 55 | 0) >> 0] | 0 | 0) << 24);
     $253 = i64toi32_i32$1;
     $253$hi = i64toi32_i32$2;
     i64toi32_i32$0 = i64toi32_i32$0;
     i64toi32_i32$2 = HEAPU32[(i64toi32_i32$0 + 64 | 0) >> 2] | 0;
     i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$0, HEAPU8[(wasm2asm_i32$0 + 68 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 69 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 70 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 71 | 0) >> 0] | 0 | 0) << 24);
     $255 = i64toi32_i32$2;
     $255$hi = i64toi32_i32$1;
     i64toi32_i32$0 = i64toi32_i32$0 + 72 | 0;
     i64toi32_i32$1 = HEAPU32[i64toi32_i32$0 >> 2] | 0;
     i64toi32_i32$2 = (wasm2asm_i32$0 = i64toi32_i32$0, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
     $258 = i64toi32_i32$1;
     $258$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $255$hi;
     i64toi32_i32$0 = $255;
     i64toi32_i32$1 = $258$hi;
     i64toi32_i32$4 = $258;
     i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
     i64toi32_i32$1 = i64toi32_i32$1;
     i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$4 | 0;
     i64toi32_i32$0 = 0;
     i64toi32_i32$4 = 0;
     $260 = (i64toi32_i32$2 | 0) != (i64toi32_i32$4 | 0) | (i64toi32_i32$1 | 0) != (i64toi32_i32$0 | 0) | 0;
     i64toi32_i32$2 = 0;
     $261$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $253$hi;
     i64toi32_i32$4 = $253;
     i64toi32_i32$1 = $261$hi;
     i64toi32_i32$0 = $260;
     i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
     i64toi32_i32$1 = i64toi32_i32$1;
     $234 = i64toi32_i32$4 | i64toi32_i32$0 | 0;
     $234$hi = i64toi32_i32$1;
     break label$10;
    }
    i64toi32_i32$1 = 0;
    $4_1 = 0;
    $4$hi = i64toi32_i32$1;
    i64toi32_i32$1 = 0;
    $234 = 1;
    $234$hi = i64toi32_i32$1;
   };
   i64toi32_i32$1 = $234$hi;
   i64toi32_i32$1 = i64toi32_i32$1;
   $3_1 = $234;
   $3$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$1 = i64toi32_i32$1;
   i64toi32_i32$2 = $1_1;
   i64toi32_i32$4 = 524288;
   i64toi32_i32$0 = 0;
   i64toi32_i32$4 = i64toi32_i32$1 | i64toi32_i32$4 | 0;
   i64toi32_i32$4 = i64toi32_i32$4;
   $12_1 = i64toi32_i32$2 | i64toi32_i32$0 | 0;
   $12$hi = i64toi32_i32$4;
   i64toi32_i32$4 = $9$hi;
   i64toi32_i32$4 = i64toi32_i32$4;
   i64toi32_i32$1 = $9_1;
   i64toi32_i32$2 = 0;
   i64toi32_i32$0 = 3;
   i64toi32_i32$3 = i64toi32_i32$0 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = i64toi32_i32$1 << i64toi32_i32$3 | 0;
    $135 = 0;
   } else {
    i64toi32_i32$2 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$3 | 0) | 0;
    $135 = i64toi32_i32$1 << i64toi32_i32$3 | 0;
   }
   i64toi32_i32$2 = i64toi32_i32$2;
   $2_1 = $135;
   $2$hi = i64toi32_i32$2;
   label$12 : {
    label$13 : {
     i64toi32_i32$2 = $8$hi;
     i64toi32_i32$2 = i64toi32_i32$2;
     i64toi32_i32$4 = $8_1;
     i64toi32_i32$1 = 4294967295;
     i64toi32_i32$0 = 4294967295;
     if ((i64toi32_i32$2 | 0) > (i64toi32_i32$1 | 0)) $136 = 1; else {
      if ((i64toi32_i32$2 | 0) >= (i64toi32_i32$1 | 0)) {
       if (i64toi32_i32$4 >>> 0 <= i64toi32_i32$0 >>> 0) $137 = 0; else $137 = 1;
       $138 = $137;
      } else $138 = 0;
      $136 = $138;
     }
     if ($136) {
      i64toi32_i32$4 = $4$hi;
      i64toi32_i32$4 = $12$hi;
      i64toi32_i32$4 = $4$hi;
      i64toi32_i32$0 = $4_1;
      i64toi32_i32$2 = $12$hi;
      i64toi32_i32$1 = $12_1;
      i64toi32_i32$3 = i64toi32_i32$0 + i64toi32_i32$1 | 0;
      i64toi32_i32$5 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
      if (i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0) i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0;
      $272 = i64toi32_i32$3;
      $272$hi = i64toi32_i32$5;
      i64toi32_i32$5 = $3$hi;
      i64toi32_i32$5 = $2$hi;
      i64toi32_i32$5 = $3$hi;
      i64toi32_i32$4 = $3_1;
      i64toi32_i32$0 = $2$hi;
      i64toi32_i32$1 = $2_1;
      i64toi32_i32$2 = i64toi32_i32$4 + i64toi32_i32$1 | 0;
      i64toi32_i32$3 = i64toi32_i32$5 + i64toi32_i32$0 | 0;
      if (i64toi32_i32$2 >>> 0 < i64toi32_i32$1 >>> 0) i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0;
      i64toi32_i32$3 = i64toi32_i32$3;
      $1_1 = i64toi32_i32$2;
      $1$hi = i64toi32_i32$3;
      i64toi32_i32$3 = i64toi32_i32$3;
      i64toi32_i32$3 = $3$hi;
      i64toi32_i32$3 = $1$hi;
      i64toi32_i32$5 = i64toi32_i32$2;
      i64toi32_i32$4 = $3$hi;
      i64toi32_i32$1 = $3_1;
      $278 = i64toi32_i32$3 >>> 0 < i64toi32_i32$4 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
      i64toi32_i32$5 = 0;
      $279$hi = i64toi32_i32$5;
      i64toi32_i32$5 = $272$hi;
      i64toi32_i32$1 = $272;
      i64toi32_i32$3 = $279$hi;
      i64toi32_i32$4 = $278;
      i64toi32_i32$0 = i64toi32_i32$1 + i64toi32_i32$4 | 0;
      i64toi32_i32$2 = i64toi32_i32$5 + i64toi32_i32$3 | 0;
      if (i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0) i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0;
      i64toi32_i32$2 = i64toi32_i32$2;
      $3_1 = i64toi32_i32$0;
      $3$hi = i64toi32_i32$2;
      i64toi32_i32$2 = i64toi32_i32$2;
      i64toi32_i32$2 = i64toi32_i32$2;
      i64toi32_i32$5 = i64toi32_i32$0;
      i64toi32_i32$1 = 1048576;
      i64toi32_i32$4 = 0;
      i64toi32_i32$1 = i64toi32_i32$2 & i64toi32_i32$1 | 0;
      i64toi32_i32$1 = i64toi32_i32$1;
      if ((i64toi32_i32$0 & i64toi32_i32$4 | 0 | i64toi32_i32$1 | 0 | 0) == (0 | 0)) break label$13;
      i64toi32_i32$1 = $1$hi;
      i64toi32_i32$1 = i64toi32_i32$1;
      i64toi32_i32$2 = $1_1;
      i64toi32_i32$5 = 0;
      i64toi32_i32$4 = 1;
      i64toi32_i32$3 = i64toi32_i32$4 & 31 | 0;
      if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
       i64toi32_i32$5 = 0;
       $139 = i64toi32_i32$1 >>> i64toi32_i32$3 | 0;
      } else {
       i64toi32_i32$5 = i64toi32_i32$1 >>> i64toi32_i32$3 | 0;
       $139 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$3 | 0) | 0;
      }
      $285 = $139;
      $285$hi = i64toi32_i32$5;
      i64toi32_i32$5 = $3$hi;
      i64toi32_i32$5 = i64toi32_i32$5;
      i64toi32_i32$1 = $3_1;
      i64toi32_i32$2 = 0;
      i64toi32_i32$4 = 63;
      i64toi32_i32$3 = i64toi32_i32$4 & 31 | 0;
      if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
       i64toi32_i32$2 = i64toi32_i32$1 << i64toi32_i32$3 | 0;
       $140 = 0;
      } else {
       i64toi32_i32$2 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$3 | 0) | 0;
       $140 = i64toi32_i32$1 << i64toi32_i32$3 | 0;
      }
      $287$hi = i64toi32_i32$2;
      i64toi32_i32$2 = $285$hi;
      i64toi32_i32$5 = $285;
      i64toi32_i32$1 = $287$hi;
      i64toi32_i32$4 = $140;
      i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
      $288 = i64toi32_i32$5 | i64toi32_i32$4 | 0;
      $288$hi = i64toi32_i32$1;
      i64toi32_i32$1 = $1$hi;
      i64toi32_i32$1 = i64toi32_i32$1;
      i64toi32_i32$2 = $1_1;
      i64toi32_i32$5 = 0;
      i64toi32_i32$4 = 1;
      i64toi32_i32$5 = i64toi32_i32$1 & i64toi32_i32$5 | 0;
      $290 = i64toi32_i32$2 & i64toi32_i32$4 | 0;
      $290$hi = i64toi32_i32$5;
      i64toi32_i32$5 = $288$hi;
      i64toi32_i32$1 = $288;
      i64toi32_i32$2 = $290$hi;
      i64toi32_i32$4 = $290;
      i64toi32_i32$2 = i64toi32_i32$5 | i64toi32_i32$2 | 0;
      i64toi32_i32$2 = i64toi32_i32$2;
      $1_1 = i64toi32_i32$1 | i64toi32_i32$4 | 0;
      $1$hi = i64toi32_i32$2;
      $6_1 = $6_1 + 1 | 0;
      i64toi32_i32$2 = $3$hi;
      i64toi32_i32$2 = i64toi32_i32$2;
      i64toi32_i32$5 = $3_1;
      i64toi32_i32$1 = 0;
      i64toi32_i32$4 = 1;
      i64toi32_i32$3 = i64toi32_i32$4 & 31 | 0;
      if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
       i64toi32_i32$1 = 0;
       $141 = i64toi32_i32$2 >>> i64toi32_i32$3 | 0;
      } else {
       i64toi32_i32$1 = i64toi32_i32$2 >>> i64toi32_i32$3 | 0;
       $141 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$3 | 0) | 0;
      }
      i64toi32_i32$1 = i64toi32_i32$1;
      $3_1 = $141;
      $3$hi = i64toi32_i32$1;
      break label$13;
     }
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$2 = $2_1;
     i64toi32_i32$5 = $3$hi;
     i64toi32_i32$4 = $3_1;
     i64toi32_i32$3 = i64toi32_i32$2 - i64toi32_i32$4 | 0;
     i64toi32_i32$6 = i64toi32_i32$2 >>> 0 < i64toi32_i32$4 >>> 0;
     i64toi32_i32$0 = i64toi32_i32$6 + i64toi32_i32$5 | 0;
     i64toi32_i32$0 = i64toi32_i32$1 - i64toi32_i32$0 | 0;
     i64toi32_i32$0 = i64toi32_i32$0;
     $1_1 = i64toi32_i32$3;
     $1$hi = i64toi32_i32$0;
     i64toi32_i32$0 = i64toi32_i32$0;
     i64toi32_i32$0 = $12$hi;
     i64toi32_i32$0 = $4$hi;
     i64toi32_i32$0 = $12$hi;
     i64toi32_i32$1 = $12_1;
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$4 = $4_1;
     i64toi32_i32$5 = i64toi32_i32$1 - i64toi32_i32$4 | 0;
     i64toi32_i32$6 = i64toi32_i32$1 >>> 0 < i64toi32_i32$4 >>> 0;
     i64toi32_i32$3 = i64toi32_i32$6 + i64toi32_i32$2 | 0;
     i64toi32_i32$3 = i64toi32_i32$0 - i64toi32_i32$3 | 0;
     $302$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$3 = $3$hi;
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$0 = $2_1;
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$4 = $3_1;
     $305 = i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0 | 0) | 0;
     i64toi32_i32$0 = 0;
     $306$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $302$hi;
     i64toi32_i32$4 = i64toi32_i32$5;
     i64toi32_i32$3 = $306$hi;
     i64toi32_i32$1 = $305;
     i64toi32_i32$2 = i64toi32_i32$4 - i64toi32_i32$1 | 0;
     i64toi32_i32$6 = i64toi32_i32$4 >>> 0 < i64toi32_i32$1 >>> 0;
     i64toi32_i32$5 = i64toi32_i32$6 + i64toi32_i32$3 | 0;
     i64toi32_i32$5 = i64toi32_i32$0 - i64toi32_i32$5 | 0;
     i64toi32_i32$5 = i64toi32_i32$5;
     $3_1 = i64toi32_i32$2;
     $3$hi = i64toi32_i32$5;
     i64toi32_i32$5 = i64toi32_i32$5;
     i64toi32_i32$5 = $1$hi;
     i64toi32_i32$0 = $1_1;
     i64toi32_i32$4 = $3$hi;
     i64toi32_i32$1 = i64toi32_i32$2;
     i64toi32_i32$4 = i64toi32_i32$5 | i64toi32_i32$4 | 0;
     i64toi32_i32$4 = i64toi32_i32$4;
     if ((i64toi32_i32$0 | i64toi32_i32$2 | 0 | i64toi32_i32$4 | 0 | 0) == (0 | 0)) break label$12;
     i64toi32_i32$4 = $3$hi;
     i64toi32_i32$4 = i64toi32_i32$4;
     i64toi32_i32$5 = $3_1;
     i64toi32_i32$0 = 524287;
     i64toi32_i32$1 = 4294967295;
     if (i64toi32_i32$4 >>> 0 > i64toi32_i32$0 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$5 >>> 0 > i64toi32_i32$1 >>> 0 | 0) | 0) break label$13;
     $314 = $5_1 + 32 | 0;
     i64toi32_i32$5 = $1$hi;
     $315 = $1_1;
     $315$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $3$hi;
     $316 = $3_1;
     $316$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $1$hi;
     i64toi32_i32$5 = $3$hi;
     i64toi32_i32$5 = i64toi32_i32$5;
     i64toi32_i32$5 = i64toi32_i32$5;
     $7_1 = ($3_1 | i64toi32_i32$5 | 0 | 0) == (0 | 0);
     i64toi32_i32$5 = $1$hi;
     i64toi32_i32$4 = $3$hi;
     i64toi32_i32$1 = $3_1;
     i64toi32_i32$5 = i64toi32_i32$4;
     i64toi32_i32$5 = i64toi32_i32$4;
     i64toi32_i32$4 = (wasm2asm_i32$0 = $1_1, wasm2asm_i32$1 = i64toi32_i32$1, wasm2asm_i32$2 = $7_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
     i64toi32_i32$0 = Math_clz32(i64toi32_i32$5);
     i64toi32_i32$1 = 0;
     if ((i64toi32_i32$0 | 0) == (32 | 0)) $142 = Math_clz32(i64toi32_i32$4) + 32 | 0; else $142 = i64toi32_i32$0;
     $323$hi = i64toi32_i32$1;
     i64toi32_i32$1 = 0;
     $326$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $323$hi;
     i64toi32_i32$4 = $142;
     i64toi32_i32$5 = $326$hi;
     i64toi32_i32$0 = $7_1 << 6 | 0;
     i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
     i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
     if (i64toi32_i32$3 >>> 0 < i64toi32_i32$0 >>> 0) i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0;
     i64toi32_i32$2 = i64toi32_i32$2;
     $7_1 = i64toi32_i32$3 + 4294967284 | 0;
     i64toi32_i32$2 = $315$hi;
     i64toi32_i32$4 = $316$hi;
     $31($314 | 0, $315 | 0, i64toi32_i32$2 | 0, $316 | 0, i64toi32_i32$4 | 0, $7_1 | 0);
     $6_1 = $6_1 - $7_1 | 0;
     i64toi32_i32$1 = $5_1 + 40 | 0;
     i64toi32_i32$4 = HEAPU32[i64toi32_i32$1 >> 2] | 0;
     i64toi32_i32$2 = (wasm2asm_i32$0 = i64toi32_i32$1, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
     i64toi32_i32$2 = i64toi32_i32$2;
     $3_1 = i64toi32_i32$4;
     $3$hi = i64toi32_i32$2;
     i64toi32_i32$1 = $5_1;
     i64toi32_i32$2 = HEAPU32[(i64toi32_i32$1 + 32 | 0) >> 2] | 0;
     i64toi32_i32$4 = (wasm2asm_i32$0 = i64toi32_i32$1, HEAPU8[(wasm2asm_i32$0 + 36 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 37 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 38 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 39 | 0) >> 0] | 0 | 0) << 24);
     i64toi32_i32$4 = i64toi32_i32$4;
     $1_1 = i64toi32_i32$2;
     $1$hi = i64toi32_i32$4;
    };
    i64toi32_i32$4 = $10$hi;
    i64toi32_i32$4 = i64toi32_i32$4;
    i64toi32_i32$1 = $10_1;
    i64toi32_i32$2 = 2147483648;
    i64toi32_i32$0 = 0;
    i64toi32_i32$2 = i64toi32_i32$4 & i64toi32_i32$2 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    $4_1 = i64toi32_i32$1 & i64toi32_i32$0 | 0;
    $4$hi = i64toi32_i32$2;
    if (($6_1 | 0) >= (32767 | 0)) {
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$2 = i64toi32_i32$2;
     i64toi32_i32$4 = $4_1;
     i64toi32_i32$1 = 2147418112;
     i64toi32_i32$0 = 0;
     i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
     i64toi32_i32$1 = i64toi32_i32$1;
     $4_1 = i64toi32_i32$4 | i64toi32_i32$0 | 0;
     $4$hi = i64toi32_i32$1;
     i64toi32_i32$1 = 0;
     $3_1 = 0;
     $3$hi = i64toi32_i32$1;
     break label$1;
    }
    $7_1 = 0;
    label$16 : {
     if (($6_1 | 0) > (0 | 0)) {
      $7_1 = $6_1;
      break label$16;
     }
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$1 = $3$hi;
     $6_1 = 1 - $6_1 | 0;
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$4 = $3$hi;
     $31($5_1 + 16 | 0 | 0, $1_1 | 0, i64toi32_i32$1 | 0, $3_1 | 0, i64toi32_i32$4 | 0, 128 - $6_1 | 0 | 0);
     i64toi32_i32$4 = i64toi32_i32$1;
     i64toi32_i32$4 = $3$hi;
     i64toi32_i32$4 = i64toi32_i32$1;
     i64toi32_i32$1 = $3$hi;
     $32($5_1 | 0, $1_1 | 0, i64toi32_i32$4 | 0, $3_1 | 0, i64toi32_i32$1 | 0, $6_1 | 0);
     i64toi32_i32$2 = $5_1;
     i64toi32_i32$1 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
     i64toi32_i32$4 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
     $361 = i64toi32_i32$1;
     $361$hi = i64toi32_i32$4;
     i64toi32_i32$2 = i64toi32_i32$2;
     i64toi32_i32$4 = HEAPU32[(i64toi32_i32$2 + 16 | 0) >> 2] | 0;
     i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 20 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 21 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 22 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 23 | 0) >> 0] | 0 | 0) << 24);
     $363 = i64toi32_i32$4;
     $363$hi = i64toi32_i32$1;
     i64toi32_i32$2 = i64toi32_i32$2 + 24 | 0;
     i64toi32_i32$1 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
     i64toi32_i32$4 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
     $366 = i64toi32_i32$1;
     $366$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $363$hi;
     i64toi32_i32$2 = $363;
     i64toi32_i32$1 = $366$hi;
     i64toi32_i32$0 = $366;
     i64toi32_i32$1 = i64toi32_i32$4 | i64toi32_i32$1 | 0;
     i64toi32_i32$1 = i64toi32_i32$1;
     i64toi32_i32$4 = i64toi32_i32$2 | i64toi32_i32$0 | 0;
     i64toi32_i32$2 = 0;
     i64toi32_i32$0 = 0;
     $368 = (i64toi32_i32$4 | 0) != (i64toi32_i32$0 | 0) | (i64toi32_i32$1 | 0) != (i64toi32_i32$2 | 0) | 0;
     i64toi32_i32$4 = 0;
     $369$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $361$hi;
     i64toi32_i32$0 = $361;
     i64toi32_i32$1 = $369$hi;
     i64toi32_i32$2 = $368;
     i64toi32_i32$1 = i64toi32_i32$4 | i64toi32_i32$1 | 0;
     i64toi32_i32$1 = i64toi32_i32$1;
     $1_1 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
     $1$hi = i64toi32_i32$1;
     i64toi32_i32$4 = $5_1 + 8 | 0;
     i64toi32_i32$1 = HEAPU32[i64toi32_i32$4 >> 2] | 0;
     i64toi32_i32$0 = (wasm2asm_i32$0 = i64toi32_i32$4, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
     i64toi32_i32$0 = i64toi32_i32$0;
     $3_1 = i64toi32_i32$1;
     $3$hi = i64toi32_i32$0;
    };
    i64toi32_i32$0 = $3$hi;
    i64toi32_i32$0 = i64toi32_i32$0;
    i64toi32_i32$4 = $3_1;
    i64toi32_i32$1 = 0;
    i64toi32_i32$2 = 3;
    i64toi32_i32$5 = i64toi32_i32$2 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
     i64toi32_i32$1 = 0;
     $143 = i64toi32_i32$0 >>> i64toi32_i32$5 | 0;
    } else {
     i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$5 | 0;
     $143 = (((1 << i64toi32_i32$5 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$5 | 0) | 0 | (i64toi32_i32$4 >>> i64toi32_i32$5 | 0) | 0;
    }
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$0 = $143;
    i64toi32_i32$4 = 65535;
    i64toi32_i32$2 = 4294967295;
    i64toi32_i32$4 = i64toi32_i32$1 & i64toi32_i32$4 | 0;
    $376$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $4$hi;
    i64toi32_i32$4 = $376$hi;
    i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$2 | 0;
    i64toi32_i32$0 = $4$hi;
    i64toi32_i32$2 = $4_1;
    i64toi32_i32$0 = i64toi32_i32$4 | i64toi32_i32$0 | 0;
    $378 = i64toi32_i32$1 | i64toi32_i32$2 | 0;
    $378$hi = i64toi32_i32$0;
    i64toi32_i32$0 = 0;
    i64toi32_i32$0 = i64toi32_i32$0;
    i64toi32_i32$4 = $7_1;
    i64toi32_i32$1 = 0;
    i64toi32_i32$2 = 48;
    i64toi32_i32$5 = i64toi32_i32$2 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
     i64toi32_i32$1 = i64toi32_i32$4 << i64toi32_i32$5 | 0;
     $144 = 0;
    } else {
     i64toi32_i32$1 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$4 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$5 | 0) | 0;
     $144 = i64toi32_i32$4 << i64toi32_i32$5 | 0;
    }
    $381$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $378$hi;
    i64toi32_i32$0 = $378;
    i64toi32_i32$4 = $381$hi;
    i64toi32_i32$2 = $144;
    i64toi32_i32$4 = i64toi32_i32$1 | i64toi32_i32$4 | 0;
    $382 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
    $382$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $1$hi;
    i64toi32_i32$4 = i64toi32_i32$4;
    i64toi32_i32$1 = $1_1;
    i64toi32_i32$0 = 0;
    i64toi32_i32$2 = 3;
    i64toi32_i32$5 = i64toi32_i32$2 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
     i64toi32_i32$0 = 0;
     $145 = i64toi32_i32$4 >>> i64toi32_i32$5 | 0;
    } else {
     i64toi32_i32$0 = i64toi32_i32$4 >>> i64toi32_i32$5 | 0;
     $145 = (((1 << i64toi32_i32$5 | 0) - 1 | 0) & i64toi32_i32$4 | 0) << (32 - i64toi32_i32$5 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$5 | 0) | 0;
    }
    $384 = $145;
    $384$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $3$hi;
    i64toi32_i32$0 = i64toi32_i32$0;
    i64toi32_i32$4 = $3_1;
    i64toi32_i32$1 = 0;
    i64toi32_i32$2 = 61;
    i64toi32_i32$5 = i64toi32_i32$2 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
     i64toi32_i32$1 = i64toi32_i32$4 << i64toi32_i32$5 | 0;
     $146 = 0;
    } else {
     i64toi32_i32$1 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$4 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$5 | 0) | 0;
     $146 = i64toi32_i32$4 << i64toi32_i32$5 | 0;
    }
    $386$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $384$hi;
    i64toi32_i32$0 = $384;
    i64toi32_i32$4 = $386$hi;
    i64toi32_i32$2 = $146;
    i64toi32_i32$4 = i64toi32_i32$1 | i64toi32_i32$4 | 0;
    i64toi32_i32$4 = i64toi32_i32$4;
    $4_1 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
    $4$hi = i64toi32_i32$4;
    i64toi32_i32$4 = i64toi32_i32$4;
    i64toi32_i32$4 = $1$hi;
    i64toi32_i32$4 = i64toi32_i32$4;
    $6_1 = $1_1 & 7 | 0;
    i64toi32_i32$4 = 0;
    $394$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $4$hi;
    i64toi32_i32$1 = $4_1;
    i64toi32_i32$0 = $394$hi;
    i64toi32_i32$2 = $6_1 >>> 0 > 4 >>> 0;
    i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
    i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
    if (i64toi32_i32$5 >>> 0 < i64toi32_i32$2 >>> 0) i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0;
    i64toi32_i32$3 = i64toi32_i32$3;
    $3_1 = i64toi32_i32$5;
    $3$hi = i64toi32_i32$3;
    i64toi32_i32$3 = i64toi32_i32$3;
    i64toi32_i32$3 = $4$hi;
    i64toi32_i32$3 = $3$hi;
    i64toi32_i32$4 = i64toi32_i32$5;
    i64toi32_i32$1 = $4$hi;
    i64toi32_i32$2 = $4_1;
    $398 = i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$4 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0;
    i64toi32_i32$4 = 0;
    $399$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $382$hi;
    i64toi32_i32$2 = $382;
    i64toi32_i32$3 = $399$hi;
    i64toi32_i32$1 = $398;
    i64toi32_i32$0 = i64toi32_i32$2 + i64toi32_i32$1 | 0;
    i64toi32_i32$5 = i64toi32_i32$4 + i64toi32_i32$3 | 0;
    if (i64toi32_i32$0 >>> 0 < i64toi32_i32$1 >>> 0) i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0;
    $400 = i64toi32_i32$0;
    $400$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $3$hi;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$4 = $3_1;
    i64toi32_i32$2 = 0;
    i64toi32_i32$1 = 1;
    i64toi32_i32$2 = i64toi32_i32$5 & i64toi32_i32$2 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    $147 = i64toi32_i32$4 & i64toi32_i32$1 | 0;
    i64toi32_i32$4 = 0;
    i64toi32_i32$5 = 0;
    i64toi32_i32$2 = i64toi32_i32$4;
    i64toi32_i32$2 = i64toi32_i32$2;
    $1_1 = (wasm2asm_i32$0 = $147, wasm2asm_i32$1 = i64toi32_i32$5, wasm2asm_i32$2 = ($6_1 | 0) == (4 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
    $1$hi = i64toi32_i32$2;
    i64toi32_i32$2 = i64toi32_i32$2;
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$2 = i64toi32_i32$4;
    i64toi32_i32$5 = $1_1;
    i64toi32_i32$4 = $3$hi;
    i64toi32_i32$1 = $3_1;
    i64toi32_i32$3 = i64toi32_i32$5 + i64toi32_i32$1 | 0;
    i64toi32_i32$0 = i64toi32_i32$2 + i64toi32_i32$4 | 0;
    if (i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0) i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0;
    i64toi32_i32$0 = i64toi32_i32$0;
    $3_1 = i64toi32_i32$3;
    $3$hi = i64toi32_i32$0;
    i64toi32_i32$0 = i64toi32_i32$0;
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$0 = $3$hi;
    i64toi32_i32$2 = i64toi32_i32$3;
    i64toi32_i32$5 = $1$hi;
    i64toi32_i32$1 = $1_1;
    $411 = i64toi32_i32$0 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
    i64toi32_i32$2 = 0;
    $412$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $400$hi;
    i64toi32_i32$1 = $400;
    i64toi32_i32$0 = $412$hi;
    i64toi32_i32$5 = $411;
    i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
    i64toi32_i32$3 = i64toi32_i32$2 + i64toi32_i32$0 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$5 >>> 0) i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0;
    i64toi32_i32$3 = i64toi32_i32$3;
    $4_1 = i64toi32_i32$4;
    $4$hi = i64toi32_i32$3;
    break label$1;
   };
   i64toi32_i32$3 = 0;
   $3_1 = 0;
   $3$hi = i64toi32_i32$3;
   i64toi32_i32$3 = 0;
   $4_1 = 0;
   $4$hi = i64toi32_i32$3;
  };
  i64toi32_i32$3 = $3$hi;
  i64toi32_i32$1 = $0_1;
  i64toi32_i32$3 = i64toi32_i32$3;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = $3_1;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = i64toi32_i32$3;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  i64toi32_i32$3 = $4$hi;
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$3 = i64toi32_i32$3;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = $4_1;
  HEAP32[(wasm2asm_i32$0 + 8 | 0) >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = i64toi32_i32$3;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 12 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 13 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 14 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 15 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  global$0 = $5_1 + 112 | 0;
 }
 
 function $31($0_1, $1_1, $1$hi, $2_1, $2$hi, $3_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$1 = 0, i64toi32_i32$4 = 0, i64toi32_i32$3 = 0, $4$hi = 0, $20_1 = 0, $21_1 = 0, $22_1 = 0, $24_1 = 0, $24$hi = 0, $23_1 = 0, $13$hi = 0, $14_1 = 0, $14$hi = 0, $4_1 = 0, $19$hi = 0, $28$hi = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  label$1 : {
   label$2 : {
    if (($3_1 & 64 | 0 | 0) == (0 | 0)) {
     if (($3_1 | 0) == (0 | 0)) break label$1;
     i64toi32_i32$0 = $1$hi;
     i64toi32_i32$0 = 0;
     $13$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $1$hi;
     i64toi32_i32$2 = $1_1;
     i64toi32_i32$1 = $13$hi;
     i64toi32_i32$3 = 64 - $3_1 | 0;
     i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
      i64toi32_i32$1 = 0;
      $20_1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
     } else {
      i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
      $20_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
     }
     $14_1 = $20_1;
     $14$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$1 = 0;
     i64toi32_i32$1 = i64toi32_i32$1;
     $4_1 = $3_1;
     $4$hi = i64toi32_i32$1;
     i64toi32_i32$1 = i64toi32_i32$1;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$0 = $2_1;
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$3 = $3_1;
     i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
      i64toi32_i32$2 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
      $21_1 = 0;
     } else {
      i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$4 | 0) | 0;
      $21_1 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
     }
     $19$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $14$hi;
     i64toi32_i32$1 = $14_1;
     i64toi32_i32$0 = $19$hi;
     i64toi32_i32$3 = $21_1;
     i64toi32_i32$0 = i64toi32_i32$2 | i64toi32_i32$0 | 0;
     i64toi32_i32$0 = i64toi32_i32$0;
     $2_1 = i64toi32_i32$1 | i64toi32_i32$3 | 0;
     $2$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $1$hi;
     i64toi32_i32$0 = $4$hi;
     i64toi32_i32$0 = $1$hi;
     i64toi32_i32$2 = $1_1;
     i64toi32_i32$1 = $4$hi;
     i64toi32_i32$3 = $4_1;
     i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
      i64toi32_i32$1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
      $22_1 = 0;
     } else {
      i64toi32_i32$1 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$4 | 0) | 0;
      $22_1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
     }
     i64toi32_i32$1 = i64toi32_i32$1;
     $24_1 = $22_1;
     $24$hi = i64toi32_i32$1;
     break label$2;
    }
    i64toi32_i32$1 = $1$hi;
    i64toi32_i32$1 = 0;
    $28$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $1$hi;
    i64toi32_i32$0 = $1_1;
    i64toi32_i32$2 = $28$hi;
    i64toi32_i32$3 = $3_1 + 4294967232 | 0;
    i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
     i64toi32_i32$2 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
     $23_1 = 0;
    } else {
     i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$4 | 0) | 0;
     $23_1 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
    }
    i64toi32_i32$2 = i64toi32_i32$2;
    $2_1 = $23_1;
    $2$hi = i64toi32_i32$2;
    i64toi32_i32$2 = 0;
    $24_1 = 0;
    $24$hi = i64toi32_i32$2;
   };
   i64toi32_i32$2 = $24$hi;
   i64toi32_i32$2 = i64toi32_i32$2;
   $1_1 = $24_1;
   $1$hi = i64toi32_i32$2;
  };
  i64toi32_i32$2 = $1$hi;
  i64toi32_i32$0 = $0_1;
  i64toi32_i32$2 = i64toi32_i32$2;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = $1_1;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = i64toi32_i32$2;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  i64toi32_i32$2 = $2$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$2 = i64toi32_i32$2;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = $2_1;
  HEAP32[(wasm2asm_i32$0 + 8 | 0) >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = i64toi32_i32$2;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 12 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 13 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 14 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 15 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
 }
 
 function $32($0_1, $1_1, $1$hi, $2_1, $2$hi, $3_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  var i64toi32_i32$1 = 0, i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$4 = 0, i64toi32_i32$3 = 0, $4$hi = 0, $24$hi = 0, $20_1 = 0, $21_1 = 0, $22_1 = 0, $24_1 = 0, $23_1 = 0, $13$hi = 0, $14_1 = 0, $14$hi = 0, $4_1 = 0, $19$hi = 0, $28$hi = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  label$1 : {
   label$2 : {
    if (($3_1 & 64 | 0 | 0) == (0 | 0)) {
     if (($3_1 | 0) == (0 | 0)) break label$1;
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$0 = 0;
     $13$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$2 = $2_1;
     i64toi32_i32$1 = $13$hi;
     i64toi32_i32$3 = 64 - $3_1 | 0;
     i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
      i64toi32_i32$1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
      $20_1 = 0;
     } else {
      i64toi32_i32$1 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$4 | 0) | 0;
      $20_1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
     }
     $14_1 = $20_1;
     $14$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$1 = 0;
     i64toi32_i32$1 = i64toi32_i32$1;
     $4_1 = $3_1;
     $4$hi = i64toi32_i32$1;
     i64toi32_i32$1 = i64toi32_i32$1;
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$0 = $1_1;
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$3 = $3_1;
     i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
      i64toi32_i32$2 = 0;
      $21_1 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
     } else {
      i64toi32_i32$2 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
      $21_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$4 | 0) | 0;
     }
     $19$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $14$hi;
     i64toi32_i32$1 = $14_1;
     i64toi32_i32$0 = $19$hi;
     i64toi32_i32$3 = $21_1;
     i64toi32_i32$0 = i64toi32_i32$2 | i64toi32_i32$0 | 0;
     i64toi32_i32$0 = i64toi32_i32$0;
     $1_1 = i64toi32_i32$1 | i64toi32_i32$3 | 0;
     $1$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$0 = $4$hi;
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$2 = $2_1;
     i64toi32_i32$1 = $4$hi;
     i64toi32_i32$3 = $4_1;
     i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
      i64toi32_i32$1 = 0;
      $22_1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
     } else {
      i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
      $22_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
     }
     i64toi32_i32$1 = i64toi32_i32$1;
     $2_1 = $22_1;
     $2$hi = i64toi32_i32$1;
     i64toi32_i32$1 = 0;
     $24_1 = 0;
     $24$hi = i64toi32_i32$1;
     break label$2;
    }
    i64toi32_i32$1 = $2$hi;
    i64toi32_i32$1 = 0;
    $28$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $2$hi;
    i64toi32_i32$0 = $2_1;
    i64toi32_i32$2 = $28$hi;
    i64toi32_i32$3 = $3_1 + 4294967232 | 0;
    i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
     i64toi32_i32$2 = 0;
     $23_1 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
    } else {
     i64toi32_i32$2 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
     $23_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$4 | 0) | 0;
    }
    i64toi32_i32$2 = i64toi32_i32$2;
    $1_1 = $23_1;
    $1$hi = i64toi32_i32$2;
    i64toi32_i32$2 = 0;
    $2_1 = 0;
    $2$hi = i64toi32_i32$2;
    i64toi32_i32$2 = 0;
    $24_1 = 0;
    $24$hi = i64toi32_i32$2;
   };
   i64toi32_i32$2 = $24$hi;
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$2 = $24$hi;
   i64toi32_i32$1 = $24_1;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$3 = $1_1;
   i64toi32_i32$0 = i64toi32_i32$2 | i64toi32_i32$0 | 0;
   i64toi32_i32$0 = i64toi32_i32$0;
   $1_1 = i64toi32_i32$1 | i64toi32_i32$3 | 0;
   $1$hi = i64toi32_i32$0;
  };
  i64toi32_i32$0 = $1$hi;
  i64toi32_i32$1 = $0_1;
  i64toi32_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = $1_1;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = i64toi32_i32$0;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  i64toi32_i32$0 = $2$hi;
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = $2_1;
  HEAP32[(wasm2asm_i32$0 + 8 | 0) >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$1;
  wasm2asm_i32$1 = i64toi32_i32$0;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 12 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 13 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 14 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 15 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
 }
 
 function $33($0_1, $1_1, $1$hi, $2_1, $2$hi, $3_1, $3$hi, $4_1, $4$hi) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  $3$hi = $3$hi | 0;
  $4_1 = $4_1 | 0;
  $4$hi = $4$hi | 0;
  var i64toi32_i32$2 = 0, i64toi32_i32$1 = 0, i64toi32_i32$3 = 0, i64toi32_i32$4 = 0, i64toi32_i32$0 = 0, i64toi32_i32$5 = 0, $8$hi = 0, $6$hi = 0, $5_1 = 0, $6_1 = 0, $10$hi = 0, $9$hi = 0, $11$hi = 0, $7_1 = 0, $8_1 = 0, $10_1 = 0, $12$hi = 0, $11_1 = 0, $9_1 = 0, $12_1 = 0, $14$hi = 0, $14_1 = 0, $15$hi = 0, $13_1 = 0, $16$hi = 0, $15_1 = 0, $16_1 = 0, $17_1 = 0, $20$hi = 0, $436$hi = 0, $18_1 = 0, $23$hi = 0, $19$hi = 0, $24$hi = 0, $436 = 0, $227 = 0, $229 = 0, $230 = 0, $231 = 0, $232 = 0, $233 = 0, $234 = 0, $235 = 0, $236 = 0, $238 = 0, $239 = 0, $240 = 0, $241 = 0, $242 = 0, $243 = 0, $245 = 0, $247 = 0, $248 = 0, $249 = 0, $250 = 0, $22$hi = 0, $251 = 0, $252 = 0, $23_1 = 0, $19_1 = 0, $24_1 = 0, $20_1 = 0, $253 = 0, $21_1 = 0, $21$hi = 0, $254 = 0, $256 = 0, $257 = 0, $258 = 0, $259 = 0, $261 = 0, $262 = 0, $263 = 0, $264 = 0, $265 = 0, $266 = 0, $267 = 0, $269 = 0, $270 = 0, $271 = 0, $272 = 0, $274 = 0, $276 = 0, $29_1 = 0, $29$hi = 0, $31$hi = 0, $34_1 = 0, $34$hi = 0, $36$hi = 0, $39 = 0, $39$hi = 0, $43$hi = 0, $70 = 0, $74 = 0, $82 = 0, $86 = 0, $96 = 0, $96$hi = 0, $107 = 0, $107$hi = 0, $120 = 0, $129 = 0, $130 = 0, $130$hi = 0, $131 = 0, $131$hi = 0, $138$hi = 0, $141$hi = 0, $151 = 0, $151$hi = 0, $156$hi = 0, $163 = 0, $164 = 0, $164$hi = 0, $165 = 0, $165$hi = 0, $172$hi = 0, $175$hi = 0, $187 = 0, $187$hi = 0, $192$hi = 0, $195 = 0, $195$hi = 0, $197$hi = 0, $22_1 = 0, $208 = 0, $208$hi = 0, $216 = 0, $216$hi = 0, $223 = 0, $223$hi = 0, $228 = 0, $228$hi = 0, $237 = 0, $237$hi = 0, $244 = 0, $244$hi = 0, $246 = 0, $246$hi = 0, $255 = 0, $255$hi = 0, $260 = 0, $260$hi = 0, $268 = 0, $268$hi = 0, $271$hi = 0, $273 = 0, $273$hi = 0, $275 = 0, $275$hi = 0, $278 = 0, $280$hi = 0, $281 = 0, $281$hi = 0, $292 = 0, $292$hi = 0, $295 = 0, $296$hi = 0, $299 = 0, $300$hi = 0, $301$hi = 0, $304 = 0, $305$hi = 0, $307$hi = 0, $309 = 0, $309$hi = 0, $312 = 0, $313$hi = 0, $316 = 0, $317$hi = 0, $318$hi = 0, $322 = 0, $323 = 0, $323$hi = 0, $330 = 0, $330$hi = 0, $334 = 0, $335 = 0, $335$hi = 0, $339 = 0, $339$hi = 0, $343 = 0, $344$hi = 0, $345 = 0, $345$hi = 0, $346 = 0, $346$hi = 0, $349 = 0, $350$hi = 0, $353 = 0, $354$hi = 0, $355$hi = 0, $359 = 0, $360$hi = 0, $361$hi = 0, $364 = 0, $364$hi = 0, $365 = 0, $365$hi = 0, $372 = 0, $372$hi = 0, $378 = 0, $378$hi = 0, $380$hi = 0, $381 = 0, $381$hi = 0, $382 = 0, $382$hi = 0, $383 = 0, $383$hi = 0, $385$hi = 0, $389 = 0, $390$hi = 0, $391$hi = 0, $392 = 0, $392$hi = 0, $398 = 0, $399$hi = 0, $407 = 0, $407$hi = 0, $409$hi = 0, $412 = 0, $412$hi = 0, $414$hi = 0, $418 = 0, $418$hi = 0, $420$hi = 0, $430$hi = 0, $432 = 0, $432$hi = 0, $464 = 0, $464$hi = 0, $466 = 0, $466$hi = 0, $467 = 0, $467$hi = 0, $469 = 0, $469$hi = 0, $472 = 0, $472$hi = 0, $474 = 0, $475$hi = 0, $479 = 0, $479$hi = 0, $482 = 0, $482$hi = 0, $493 = 0, $500 = 0, $500$hi = 0, $505 = 0, $506$hi = 0, $510 = 0, $510$hi = 0, $513 = 0, $513$hi = 0, $516 = 0, $516$hi = 0, $520 = 0, $521$hi = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  $5_1 = global$0 - 96 | 0;
  global$0 = $5_1;
  i64toi32_i32$0 = $3$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$2 = $3_1;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 17;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$1 = 0;
   $227 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
   $227 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
  }
  $29_1 = $227;
  $29$hi = i64toi32_i32$1;
  i64toi32_i32$1 = $4$hi;
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$0 = $4_1;
  i64toi32_i32$2 = 0;
  i64toi32_i32$3 = 47;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$2 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
   $229 = 0;
  } else {
   i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$4 | 0) | 0;
   $229 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
  }
  $31$hi = i64toi32_i32$2;
  i64toi32_i32$2 = $29$hi;
  i64toi32_i32$1 = $29_1;
  i64toi32_i32$0 = $31$hi;
  i64toi32_i32$3 = $229;
  i64toi32_i32$0 = i64toi32_i32$2 | i64toi32_i32$0 | 0;
  i64toi32_i32$0 = i64toi32_i32$0;
  $14_1 = i64toi32_i32$1 | i64toi32_i32$3 | 0;
  $14$hi = i64toi32_i32$0;
  i64toi32_i32$0 = $1$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$2 = $1_1;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$1 = 0;
   $230 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
   $230 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
  }
  $34_1 = $230;
  $34$hi = i64toi32_i32$1;
  i64toi32_i32$1 = $2$hi;
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$0 = $2_1;
  i64toi32_i32$2 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$2 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
   $231 = 0;
  } else {
   i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$4 | 0) | 0;
   $231 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
  }
  $36$hi = i64toi32_i32$2;
  i64toi32_i32$2 = $34$hi;
  i64toi32_i32$1 = $34_1;
  i64toi32_i32$0 = $36$hi;
  i64toi32_i32$3 = $231;
  i64toi32_i32$0 = i64toi32_i32$2 | i64toi32_i32$0 | 0;
  i64toi32_i32$0 = i64toi32_i32$0;
  $9_1 = i64toi32_i32$1 | i64toi32_i32$3 | 0;
  $9$hi = i64toi32_i32$0;
  i64toi32_i32$0 = $3$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$2 = $3_1;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 49;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$1 = 0;
   $232 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
   $232 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
  }
  $39 = $232;
  $39$hi = i64toi32_i32$1;
  i64toi32_i32$1 = $4$hi;
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$0 = $4_1;
  i64toi32_i32$2 = 65535;
  i64toi32_i32$3 = 4294967295;
  i64toi32_i32$2 = i64toi32_i32$1 & i64toi32_i32$2 | 0;
  i64toi32_i32$2 = i64toi32_i32$2;
  $10_1 = i64toi32_i32$0 & i64toi32_i32$3 | 0;
  $10$hi = i64toi32_i32$2;
  i64toi32_i32$2 = i64toi32_i32$2;
  i64toi32_i32$2 = i64toi32_i32$2;
  i64toi32_i32$1 = $10_1;
  i64toi32_i32$0 = 0;
  i64toi32_i32$3 = 15;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$0 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
   $233 = 0;
  } else {
   i64toi32_i32$0 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$4 | 0) | 0;
   $233 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
  }
  $43$hi = i64toi32_i32$0;
  i64toi32_i32$0 = $39$hi;
  i64toi32_i32$2 = $39;
  i64toi32_i32$1 = $43$hi;
  i64toi32_i32$3 = $233;
  i64toi32_i32$1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
  i64toi32_i32$1 = i64toi32_i32$1;
  $15_1 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
  $15$hi = i64toi32_i32$1;
  i64toi32_i32$1 = $4$hi;
  i64toi32_i32$1 = $2$hi;
  i64toi32_i32$1 = $4$hi;
  i64toi32_i32$0 = $4_1;
  i64toi32_i32$2 = $2$hi;
  i64toi32_i32$3 = $2_1;
  i64toi32_i32$2 = i64toi32_i32$1 ^ i64toi32_i32$2 | 0;
  i64toi32_i32$2 = i64toi32_i32$2;
  i64toi32_i32$1 = i64toi32_i32$0 ^ i64toi32_i32$3 | 0;
  i64toi32_i32$0 = 2147483648;
  i64toi32_i32$3 = 0;
  i64toi32_i32$0 = i64toi32_i32$2 & i64toi32_i32$0 | 0;
  i64toi32_i32$0 = i64toi32_i32$0;
  $6_1 = i64toi32_i32$1 & i64toi32_i32$3 | 0;
  $6$hi = i64toi32_i32$0;
  i64toi32_i32$0 = $10$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$2 = $10_1;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 17;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$1 = 0;
   $234 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
   $234 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
  }
  i64toi32_i32$1 = i64toi32_i32$1;
  $16_1 = $234;
  $16$hi = i64toi32_i32$1;
  i64toi32_i32$1 = $2$hi;
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$0 = $2_1;
  i64toi32_i32$2 = 65535;
  i64toi32_i32$3 = 4294967295;
  i64toi32_i32$2 = i64toi32_i32$1 & i64toi32_i32$2 | 0;
  i64toi32_i32$2 = i64toi32_i32$2;
  $11_1 = i64toi32_i32$0 & i64toi32_i32$3 | 0;
  $11$hi = i64toi32_i32$2;
  i64toi32_i32$2 = i64toi32_i32$2;
  i64toi32_i32$2 = i64toi32_i32$2;
  i64toi32_i32$1 = $11_1;
  i64toi32_i32$0 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$0 = 0;
   $235 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$0 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
   $235 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$4 | 0) | 0;
  }
  i64toi32_i32$0 = i64toi32_i32$0;
  $12_1 = $235;
  $12$hi = i64toi32_i32$0;
  i64toi32_i32$0 = $4$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$2 = $4_1;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 48;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$1 = 0;
   $236 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
   $236 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
  }
  i64toi32_i32$1 = i64toi32_i32$1;
  $7_1 = $236 & 32767 | 0;
  label$1 : {
   label$2 : {
    label$3 : {
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$1 = i64toi32_i32$1;
     i64toi32_i32$0 = $2_1;
     i64toi32_i32$2 = 0;
     i64toi32_i32$3 = 48;
     i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
      i64toi32_i32$2 = 0;
      $238 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
     } else {
      i64toi32_i32$2 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
      $238 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$4 | 0) | 0;
     }
     i64toi32_i32$2 = i64toi32_i32$2;
     $17_1 = $238 & 32767 | 0;
     if (($17_1 + 4294967295 | 0) >>> 0 <= 32765 >>> 0) if (($7_1 + 4294967295 | 0) >>> 0 < 32766 >>> 0) break label$3;;
     i64toi32_i32$2 = $1$hi;
     i64toi32_i32$2 = i64toi32_i32$2;
     $70 = ($1_1 | i64toi32_i32$2 | 0 | 0) == (0 | 0);
     i64toi32_i32$2 = $2$hi;
     i64toi32_i32$2 = i64toi32_i32$2;
     i64toi32_i32$1 = $2_1;
     i64toi32_i32$0 = 2147483647;
     i64toi32_i32$3 = 4294967295;
     i64toi32_i32$0 = i64toi32_i32$2 & i64toi32_i32$0 | 0;
     i64toi32_i32$0 = i64toi32_i32$0;
     $8_1 = i64toi32_i32$1 & i64toi32_i32$3 | 0;
     $8$hi = i64toi32_i32$0;
     i64toi32_i32$0 = i64toi32_i32$0;
     i64toi32_i32$0 = i64toi32_i32$0;
     i64toi32_i32$2 = $8_1;
     i64toi32_i32$1 = 2147418112;
     i64toi32_i32$3 = 0;
     $74 = i64toi32_i32$0 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0 | 0) | 0;
     i64toi32_i32$2 = i64toi32_i32$0;
     i64toi32_i32$2 = i64toi32_i32$2;
     i64toi32_i32$3 = $8_1;
     i64toi32_i32$0 = 2147418112;
     i64toi32_i32$1 = 0;
     if (((wasm2asm_i32$0 = $70, wasm2asm_i32$1 = $74, wasm2asm_i32$2 = (i64toi32_i32$3 | 0) == (i64toi32_i32$1 | 0) & (i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) == (0 | 0)) {
      i64toi32_i32$3 = $2$hi;
      i64toi32_i32$3 = i64toi32_i32$3;
      i64toi32_i32$1 = $2_1;
      i64toi32_i32$2 = 32768;
      i64toi32_i32$0 = 0;
      i64toi32_i32$2 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
      i64toi32_i32$2 = i64toi32_i32$2;
      $6_1 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
      $6$hi = i64toi32_i32$2;
      break label$1;
     }
     i64toi32_i32$2 = $3$hi;
     i64toi32_i32$2 = i64toi32_i32$2;
     $82 = ($3_1 | i64toi32_i32$2 | 0 | 0) == (0 | 0);
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$2 = i64toi32_i32$2;
     i64toi32_i32$3 = $4_1;
     i64toi32_i32$1 = 2147483647;
     i64toi32_i32$0 = 4294967295;
     i64toi32_i32$1 = i64toi32_i32$2 & i64toi32_i32$1 | 0;
     i64toi32_i32$1 = i64toi32_i32$1;
     $2_1 = i64toi32_i32$3 & i64toi32_i32$0 | 0;
     $2$hi = i64toi32_i32$1;
     i64toi32_i32$1 = i64toi32_i32$1;
     i64toi32_i32$1 = i64toi32_i32$1;
     i64toi32_i32$2 = $2_1;
     i64toi32_i32$3 = 2147418112;
     i64toi32_i32$0 = 0;
     $86 = i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0;
     i64toi32_i32$2 = i64toi32_i32$1;
     i64toi32_i32$2 = i64toi32_i32$2;
     i64toi32_i32$0 = $2_1;
     i64toi32_i32$1 = 2147418112;
     i64toi32_i32$3 = 0;
     if (((wasm2asm_i32$0 = $82, wasm2asm_i32$1 = $86, wasm2asm_i32$2 = (i64toi32_i32$0 | 0) == (i64toi32_i32$3 | 0) & (i64toi32_i32$2 | 0) == (i64toi32_i32$1 | 0) | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) == (0 | 0)) {
      i64toi32_i32$0 = $4$hi;
      i64toi32_i32$0 = i64toi32_i32$0;
      i64toi32_i32$3 = $4_1;
      i64toi32_i32$2 = 32768;
      i64toi32_i32$1 = 0;
      i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
      i64toi32_i32$2 = i64toi32_i32$2;
      $6_1 = i64toi32_i32$3 | i64toi32_i32$1 | 0;
      $6$hi = i64toi32_i32$2;
      i64toi32_i32$2 = $3$hi;
      i64toi32_i32$2 = i64toi32_i32$2;
      $1_1 = $3_1;
      $1$hi = i64toi32_i32$2;
      break label$1;
     }
     label$7 : {
      label$8 : {
       i64toi32_i32$2 = $1$hi;
       i64toi32_i32$2 = $8$hi;
       i64toi32_i32$2 = i64toi32_i32$2;
       i64toi32_i32$0 = $8_1;
       i64toi32_i32$3 = 2147418112;
       i64toi32_i32$1 = 0;
       i64toi32_i32$3 = i64toi32_i32$2 ^ i64toi32_i32$3 | 0;
       $96 = i64toi32_i32$0 ^ i64toi32_i32$1 | 0;
       $96$hi = i64toi32_i32$3;
       i64toi32_i32$3 = $1$hi;
       i64toi32_i32$2 = $1_1;
       i64toi32_i32$0 = $96$hi;
       i64toi32_i32$1 = $96;
       i64toi32_i32$0 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
       i64toi32_i32$0 = i64toi32_i32$0;
       i64toi32_i32$3 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
       i64toi32_i32$2 = 0;
       i64toi32_i32$1 = 0;
       if ((i64toi32_i32$3 | 0) == (i64toi32_i32$1 | 0) & (i64toi32_i32$0 | 0) == (i64toi32_i32$2 | 0) | 0) {
        i64toi32_i32$3 = $3$hi;
        i64toi32_i32$3 = $2$hi;
        i64toi32_i32$3 = $3$hi;
        i64toi32_i32$1 = $3_1;
        i64toi32_i32$0 = $2$hi;
        i64toi32_i32$2 = $2_1;
        i64toi32_i32$0 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
        i64toi32_i32$0 = i64toi32_i32$0;
        if ((i64toi32_i32$1 | i64toi32_i32$2 | 0 | i64toi32_i32$0 | 0 | 0) == (0 | 0)) break label$8;
        i64toi32_i32$0 = $6$hi;
        i64toi32_i32$0 = i64toi32_i32$0;
        i64toi32_i32$3 = $6_1;
        i64toi32_i32$1 = 2147418112;
        i64toi32_i32$2 = 0;
        i64toi32_i32$1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
        i64toi32_i32$1 = i64toi32_i32$1;
        $6_1 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
        $6$hi = i64toi32_i32$1;
        break label$2;
       }
       i64toi32_i32$1 = $3$hi;
       i64toi32_i32$1 = $2$hi;
       i64toi32_i32$1 = i64toi32_i32$1;
       i64toi32_i32$0 = $2_1;
       i64toi32_i32$3 = 2147418112;
       i64toi32_i32$2 = 0;
       i64toi32_i32$3 = i64toi32_i32$1 ^ i64toi32_i32$3 | 0;
       $107 = i64toi32_i32$0 ^ i64toi32_i32$2 | 0;
       $107$hi = i64toi32_i32$3;
       i64toi32_i32$3 = $3$hi;
       i64toi32_i32$1 = $3_1;
       i64toi32_i32$0 = $107$hi;
       i64toi32_i32$2 = $107;
       i64toi32_i32$0 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
       i64toi32_i32$0 = i64toi32_i32$0;
       i64toi32_i32$3 = i64toi32_i32$1 | i64toi32_i32$2 | 0;
       i64toi32_i32$1 = 0;
       i64toi32_i32$2 = 0;
       if ((i64toi32_i32$3 | 0) == (i64toi32_i32$2 | 0) & (i64toi32_i32$0 | 0) == (i64toi32_i32$1 | 0) | 0) {
        i64toi32_i32$3 = $1$hi;
        i64toi32_i32$3 = $8$hi;
        i64toi32_i32$3 = $1$hi;
        i64toi32_i32$2 = $1_1;
        i64toi32_i32$0 = $8$hi;
        i64toi32_i32$1 = $8_1;
        i64toi32_i32$0 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
        i64toi32_i32$0 = i64toi32_i32$0;
        $2_1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
        $2$hi = i64toi32_i32$0;
        i64toi32_i32$0 = 0;
        $1_1 = 0;
        $1$hi = i64toi32_i32$0;
        i64toi32_i32$0 = $2$hi;
        i64toi32_i32$0 = i64toi32_i32$0;
        if (($2_1 | i64toi32_i32$0 | 0 | 0) == (0 | 0)) break label$7;
        i64toi32_i32$0 = $6$hi;
        i64toi32_i32$0 = i64toi32_i32$0;
        i64toi32_i32$3 = $6_1;
        i64toi32_i32$2 = 2147418112;
        i64toi32_i32$1 = 0;
        i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
        i64toi32_i32$2 = i64toi32_i32$2;
        $6_1 = i64toi32_i32$3 | i64toi32_i32$1 | 0;
        $6$hi = i64toi32_i32$2;
        break label$1;
       }
       i64toi32_i32$2 = $1$hi;
       i64toi32_i32$2 = $8$hi;
       i64toi32_i32$2 = $1$hi;
       i64toi32_i32$0 = $1_1;
       i64toi32_i32$3 = $8$hi;
       i64toi32_i32$1 = $8_1;
       i64toi32_i32$3 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
       i64toi32_i32$3 = i64toi32_i32$3;
       i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
       i64toi32_i32$0 = 0;
       i64toi32_i32$1 = 0;
       $120 = (i64toi32_i32$2 | 0) == (i64toi32_i32$1 | 0) & (i64toi32_i32$3 | 0) == (i64toi32_i32$0 | 0) | 0;
       i64toi32_i32$2 = $3$hi;
       i64toi32_i32$2 = $2$hi;
       i64toi32_i32$2 = $3$hi;
       i64toi32_i32$1 = $3_1;
       i64toi32_i32$3 = $2$hi;
       i64toi32_i32$0 = $2_1;
       i64toi32_i32$3 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
       i64toi32_i32$3 = i64toi32_i32$3;
       i64toi32_i32$2 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
       i64toi32_i32$1 = 0;
       i64toi32_i32$0 = 0;
       if ($120 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) & (i64toi32_i32$3 | 0) == (i64toi32_i32$1 | 0) | 0) | 0) break label$2;
       i64toi32_i32$2 = $8$hi;
       i64toi32_i32$2 = i64toi32_i32$2;
       i64toi32_i32$0 = $8_1;
       i64toi32_i32$3 = 65535;
       i64toi32_i32$1 = 4294967295;
       if (i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$0 >>> 0 <= i64toi32_i32$1 >>> 0 | 0) | 0) {
        $129 = $5_1 + 80 | 0;
        i64toi32_i32$0 = $1$hi;
        $130 = $1_1;
        $130$hi = i64toi32_i32$0;
        i64toi32_i32$0 = $11$hi;
        $131 = $11_1;
        $131$hi = i64toi32_i32$0;
        i64toi32_i32$0 = $1$hi;
        i64toi32_i32$0 = $11$hi;
        i64toi32_i32$0 = i64toi32_i32$0;
        i64toi32_i32$0 = i64toi32_i32$0;
        $13_1 = ($11_1 | i64toi32_i32$0 | 0 | 0) == (0 | 0);
        i64toi32_i32$0 = $1$hi;
        i64toi32_i32$2 = $11$hi;
        i64toi32_i32$1 = $11_1;
        i64toi32_i32$0 = i64toi32_i32$2;
        i64toi32_i32$0 = i64toi32_i32$2;
        i64toi32_i32$2 = (wasm2asm_i32$0 = $1_1, wasm2asm_i32$1 = i64toi32_i32$1, wasm2asm_i32$2 = $13_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
        i64toi32_i32$3 = Math_clz32(i64toi32_i32$0);
        i64toi32_i32$1 = 0;
        if ((i64toi32_i32$3 | 0) == (32 | 0)) $239 = Math_clz32(i64toi32_i32$2) + 32 | 0; else $239 = i64toi32_i32$3;
        $138$hi = i64toi32_i32$1;
        i64toi32_i32$1 = 0;
        $141$hi = i64toi32_i32$1;
        i64toi32_i32$1 = $138$hi;
        i64toi32_i32$2 = $239;
        i64toi32_i32$0 = $141$hi;
        i64toi32_i32$3 = $13_1 << 6 | 0;
        i64toi32_i32$4 = i64toi32_i32$2 + i64toi32_i32$3 | 0;
        i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$0 | 0;
        if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0;
        i64toi32_i32$5 = i64toi32_i32$5;
        $13_1 = i64toi32_i32$4;
        i64toi32_i32$5 = $130$hi;
        i64toi32_i32$2 = $131$hi;
        $31($129 | 0, $130 | 0, i64toi32_i32$5 | 0, $131 | 0, i64toi32_i32$2 | 0, i64toi32_i32$4 + 4294967281 | 0 | 0);
        $13_1 = 16 - i64toi32_i32$4 | 0;
        i64toi32_i32$1 = $5_1;
        i64toi32_i32$2 = HEAPU32[(i64toi32_i32$1 + 80 | 0) >> 2] | 0;
        i64toi32_i32$5 = (wasm2asm_i32$0 = i64toi32_i32$1, HEAPU8[(wasm2asm_i32$0 + 84 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 85 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 86 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 87 | 0) >> 0] | 0 | 0) << 24);
        i64toi32_i32$5 = i64toi32_i32$5;
        $1_1 = i64toi32_i32$2;
        $1$hi = i64toi32_i32$5;
        i64toi32_i32$5 = i64toi32_i32$5;
        i64toi32_i32$5 = i64toi32_i32$5;
        i64toi32_i32$1 = i64toi32_i32$2;
        i64toi32_i32$2 = 0;
        i64toi32_i32$3 = 32;
        i64toi32_i32$0 = i64toi32_i32$3 & 31 | 0;
        if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
         i64toi32_i32$2 = 0;
         $240 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
        } else {
         i64toi32_i32$2 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
         $240 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$0 | 0) | 0;
        }
        $151 = $240;
        $151$hi = i64toi32_i32$2;
        i64toi32_i32$5 = $5_1 + 88 | 0;
        i64toi32_i32$2 = HEAPU32[i64toi32_i32$5 >> 2] | 0;
        i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$5, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
        i64toi32_i32$1 = i64toi32_i32$1;
        $11_1 = i64toi32_i32$2;
        $11$hi = i64toi32_i32$1;
        i64toi32_i32$1 = i64toi32_i32$1;
        i64toi32_i32$1 = i64toi32_i32$1;
        i64toi32_i32$5 = i64toi32_i32$2;
        i64toi32_i32$2 = 0;
        i64toi32_i32$3 = 32;
        i64toi32_i32$0 = i64toi32_i32$3 & 31 | 0;
        if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
         i64toi32_i32$2 = i64toi32_i32$5 << i64toi32_i32$0 | 0;
         $241 = 0;
        } else {
         i64toi32_i32$2 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$0 | 0) | 0;
         $241 = i64toi32_i32$5 << i64toi32_i32$0 | 0;
        }
        $156$hi = i64toi32_i32$2;
        i64toi32_i32$2 = $151$hi;
        i64toi32_i32$1 = $151;
        i64toi32_i32$5 = $156$hi;
        i64toi32_i32$3 = $241;
        i64toi32_i32$5 = i64toi32_i32$2 | i64toi32_i32$5 | 0;
        i64toi32_i32$5 = i64toi32_i32$5;
        $9_1 = i64toi32_i32$1 | i64toi32_i32$3 | 0;
        $9$hi = i64toi32_i32$5;
        i64toi32_i32$5 = $11$hi;
        i64toi32_i32$5 = i64toi32_i32$5;
        i64toi32_i32$2 = $11_1;
        i64toi32_i32$1 = 0;
        i64toi32_i32$3 = 32;
        i64toi32_i32$0 = i64toi32_i32$3 & 31 | 0;
        if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
         i64toi32_i32$1 = 0;
         $242 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
        } else {
         i64toi32_i32$1 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
         $242 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$0 | 0) | 0;
        }
        i64toi32_i32$1 = i64toi32_i32$1;
        $12_1 = $242;
        $12$hi = i64toi32_i32$1;
       }
       i64toi32_i32$1 = $2$hi;
       i64toi32_i32$1 = i64toi32_i32$1;
       i64toi32_i32$5 = $2_1;
       i64toi32_i32$2 = 65535;
       i64toi32_i32$3 = 4294967295;
       if (i64toi32_i32$1 >>> 0 > i64toi32_i32$2 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$5 >>> 0 > i64toi32_i32$3 >>> 0 | 0) | 0) break label$3;
       $163 = $5_1 - 4294967232 | 0;
       i64toi32_i32$5 = $3$hi;
       $164 = $3_1;
       $164$hi = i64toi32_i32$5;
       i64toi32_i32$5 = $10$hi;
       $165 = $10_1;
       $165$hi = i64toi32_i32$5;
       i64toi32_i32$5 = $3$hi;
       i64toi32_i32$5 = $10$hi;
       i64toi32_i32$5 = i64toi32_i32$5;
       i64toi32_i32$5 = i64toi32_i32$5;
       $18_1 = ($10_1 | i64toi32_i32$5 | 0 | 0) == (0 | 0);
       i64toi32_i32$5 = $3$hi;
       i64toi32_i32$1 = $10$hi;
       i64toi32_i32$3 = $10_1;
       i64toi32_i32$5 = i64toi32_i32$1;
       i64toi32_i32$5 = i64toi32_i32$1;
       i64toi32_i32$1 = (wasm2asm_i32$0 = $3_1, wasm2asm_i32$1 = i64toi32_i32$3, wasm2asm_i32$2 = $18_1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
       i64toi32_i32$2 = Math_clz32(i64toi32_i32$5);
       i64toi32_i32$3 = 0;
       if ((i64toi32_i32$2 | 0) == (32 | 0)) $243 = Math_clz32(i64toi32_i32$1) + 32 | 0; else $243 = i64toi32_i32$2;
       $172$hi = i64toi32_i32$3;
       i64toi32_i32$3 = 0;
       $175$hi = i64toi32_i32$3;
       i64toi32_i32$3 = $172$hi;
       i64toi32_i32$1 = $243;
       i64toi32_i32$5 = $175$hi;
       i64toi32_i32$2 = $18_1 << 6 | 0;
       i64toi32_i32$0 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
       i64toi32_i32$4 = i64toi32_i32$3 + i64toi32_i32$5 | 0;
       if (i64toi32_i32$0 >>> 0 < i64toi32_i32$2 >>> 0) i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0;
       i64toi32_i32$4 = i64toi32_i32$4;
       $18_1 = i64toi32_i32$0;
       i64toi32_i32$4 = $164$hi;
       i64toi32_i32$1 = $165$hi;
       $31($163 | 0, $164 | 0, i64toi32_i32$4 | 0, $165 | 0, i64toi32_i32$1 | 0, i64toi32_i32$0 + 4294967281 | 0 | 0);
       $13_1 = (16 - i64toi32_i32$0 | 0) + $13_1 | 0;
       i64toi32_i32$3 = $5_1;
       i64toi32_i32$1 = HEAPU32[(i64toi32_i32$3 + 64 | 0) >> 2] | 0;
       i64toi32_i32$4 = (wasm2asm_i32$0 = i64toi32_i32$3, HEAPU8[(wasm2asm_i32$0 + 68 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 69 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 70 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 71 | 0) >> 0] | 0 | 0) << 24);
       i64toi32_i32$4 = i64toi32_i32$4;
       $3_1 = i64toi32_i32$1;
       $3$hi = i64toi32_i32$4;
       i64toi32_i32$4 = i64toi32_i32$4;
       i64toi32_i32$4 = i64toi32_i32$4;
       i64toi32_i32$3 = i64toi32_i32$1;
       i64toi32_i32$1 = 0;
       i64toi32_i32$2 = 49;
       i64toi32_i32$5 = i64toi32_i32$2 & 31 | 0;
       if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
        i64toi32_i32$1 = 0;
        $245 = i64toi32_i32$4 >>> i64toi32_i32$5 | 0;
       } else {
        i64toi32_i32$1 = i64toi32_i32$4 >>> i64toi32_i32$5 | 0;
        $245 = (((1 << i64toi32_i32$5 | 0) - 1 | 0) & i64toi32_i32$4 | 0) << (32 - i64toi32_i32$5 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$5 | 0) | 0;
       }
       $187 = $245;
       $187$hi = i64toi32_i32$1;
       i64toi32_i32$4 = $5_1 + 72 | 0;
       i64toi32_i32$1 = HEAPU32[i64toi32_i32$4 >> 2] | 0;
       i64toi32_i32$3 = (wasm2asm_i32$0 = i64toi32_i32$4, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
       i64toi32_i32$3 = i64toi32_i32$3;
       $2_1 = i64toi32_i32$1;
       $2$hi = i64toi32_i32$3;
       i64toi32_i32$3 = i64toi32_i32$3;
       i64toi32_i32$3 = i64toi32_i32$3;
       i64toi32_i32$4 = i64toi32_i32$1;
       i64toi32_i32$1 = 0;
       i64toi32_i32$2 = 15;
       i64toi32_i32$5 = i64toi32_i32$2 & 31 | 0;
       if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
        i64toi32_i32$1 = i64toi32_i32$4 << i64toi32_i32$5 | 0;
        $247 = 0;
       } else {
        i64toi32_i32$1 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$4 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$5 | 0) | 0;
        $247 = i64toi32_i32$4 << i64toi32_i32$5 | 0;
       }
       $192$hi = i64toi32_i32$1;
       i64toi32_i32$1 = $187$hi;
       i64toi32_i32$3 = $187;
       i64toi32_i32$4 = $192$hi;
       i64toi32_i32$2 = $247;
       i64toi32_i32$4 = i64toi32_i32$1 | i64toi32_i32$4 | 0;
       i64toi32_i32$4 = i64toi32_i32$4;
       $15_1 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
       $15$hi = i64toi32_i32$4;
       i64toi32_i32$4 = $3$hi;
       i64toi32_i32$4 = i64toi32_i32$4;
       i64toi32_i32$1 = $3_1;
       i64toi32_i32$3 = 0;
       i64toi32_i32$2 = 17;
       i64toi32_i32$5 = i64toi32_i32$2 & 31 | 0;
       if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
        i64toi32_i32$3 = 0;
        $248 = i64toi32_i32$4 >>> i64toi32_i32$5 | 0;
       } else {
        i64toi32_i32$3 = i64toi32_i32$4 >>> i64toi32_i32$5 | 0;
        $248 = (((1 << i64toi32_i32$5 | 0) - 1 | 0) & i64toi32_i32$4 | 0) << (32 - i64toi32_i32$5 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$5 | 0) | 0;
       }
       $195 = $248;
       $195$hi = i64toi32_i32$3;
       i64toi32_i32$3 = $2$hi;
       i64toi32_i32$3 = i64toi32_i32$3;
       i64toi32_i32$4 = $2_1;
       i64toi32_i32$1 = 0;
       i64toi32_i32$2 = 47;
       i64toi32_i32$5 = i64toi32_i32$2 & 31 | 0;
       if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
        i64toi32_i32$1 = i64toi32_i32$4 << i64toi32_i32$5 | 0;
        $249 = 0;
       } else {
        i64toi32_i32$1 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$4 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$5 | 0) | 0;
        $249 = i64toi32_i32$4 << i64toi32_i32$5 | 0;
       }
       $197$hi = i64toi32_i32$1;
       i64toi32_i32$1 = $195$hi;
       i64toi32_i32$3 = $195;
       i64toi32_i32$4 = $197$hi;
       i64toi32_i32$2 = $249;
       i64toi32_i32$4 = i64toi32_i32$1 | i64toi32_i32$4 | 0;
       i64toi32_i32$4 = i64toi32_i32$4;
       $14_1 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
       $14$hi = i64toi32_i32$4;
       i64toi32_i32$4 = $2$hi;
       i64toi32_i32$4 = i64toi32_i32$4;
       i64toi32_i32$1 = $2_1;
       i64toi32_i32$3 = 0;
       i64toi32_i32$2 = 17;
       i64toi32_i32$5 = i64toi32_i32$2 & 31 | 0;
       if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
        i64toi32_i32$3 = 0;
        $250 = i64toi32_i32$4 >>> i64toi32_i32$5 | 0;
       } else {
        i64toi32_i32$3 = i64toi32_i32$4 >>> i64toi32_i32$5 | 0;
        $250 = (((1 << i64toi32_i32$5 | 0) - 1 | 0) & i64toi32_i32$4 | 0) << (32 - i64toi32_i32$5 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$5 | 0) | 0;
       }
       i64toi32_i32$3 = i64toi32_i32$3;
       $16_1 = $250;
       $16$hi = i64toi32_i32$3;
       break label$3;
      };
      i64toi32_i32$3 = 2147450880;
      $6_1 = 0;
      $6$hi = i64toi32_i32$3;
      break label$2;
     };
     i64toi32_i32$3 = 2147450880;
     $6_1 = 0;
     $6$hi = i64toi32_i32$3;
     break label$1;
    };
    i64toi32_i32$3 = $14$hi;
    i64toi32_i32$3 = i64toi32_i32$3;
    i64toi32_i32$4 = $14_1;
    i64toi32_i32$1 = 0;
    i64toi32_i32$2 = 4294967295;
    i64toi32_i32$1 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
    i64toi32_i32$1 = i64toi32_i32$1;
    $2_1 = i64toi32_i32$4 & i64toi32_i32$2 | 0;
    $2$hi = i64toi32_i32$1;
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$1 = $1$hi;
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$3 = $1_1;
    i64toi32_i32$4 = 0;
    i64toi32_i32$2 = 4294967295;
    i64toi32_i32$4 = i64toi32_i32$1 & i64toi32_i32$4 | 0;
    i64toi32_i32$4 = i64toi32_i32$4;
    $4_1 = i64toi32_i32$3 & i64toi32_i32$2 | 0;
    $4$hi = i64toi32_i32$4;
    i64toi32_i32$4 = i64toi32_i32$4;
    i64toi32_i32$4 = $2$hi;
    i64toi32_i32$3 = $4$hi;
    i64toi32_i32$3 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$4 | 0, $4_1 | 0, i64toi32_i32$3 | 0) | 0;
    i64toi32_i32$4 = i64toi32_i32$HIGH_BITS;
    i64toi32_i32$4 = i64toi32_i32$4;
    $22_1 = i64toi32_i32$3;
    $22$hi = i64toi32_i32$4;
    i64toi32_i32$4 = i64toi32_i32$4;
    $208 = i64toi32_i32$3;
    $208$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $3$hi;
    i64toi32_i32$4 = i64toi32_i32$4;
    i64toi32_i32$1 = $3_1;
    i64toi32_i32$3 = 0;
    i64toi32_i32$2 = 15;
    i64toi32_i32$5 = i64toi32_i32$2 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
     i64toi32_i32$3 = i64toi32_i32$1 << i64toi32_i32$5 | 0;
     $251 = 0;
    } else {
     i64toi32_i32$3 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$5 | 0) | 0;
     $251 = i64toi32_i32$1 << i64toi32_i32$5 | 0;
    }
    i64toi32_i32$3 = i64toi32_i32$3;
    i64toi32_i32$4 = $251;
    i64toi32_i32$1 = 0;
    i64toi32_i32$2 = 4294934528;
    i64toi32_i32$1 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
    i64toi32_i32$1 = i64toi32_i32$1;
    $1_1 = i64toi32_i32$4 & i64toi32_i32$2 | 0;
    $1$hi = i64toi32_i32$1;
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$1 = $9$hi;
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$3 = $9_1;
    i64toi32_i32$4 = 0;
    i64toi32_i32$2 = 4294967295;
    i64toi32_i32$4 = i64toi32_i32$1 & i64toi32_i32$4 | 0;
    i64toi32_i32$4 = i64toi32_i32$4;
    $3_1 = i64toi32_i32$3 & i64toi32_i32$2 | 0;
    $3$hi = i64toi32_i32$4;
    i64toi32_i32$4 = i64toi32_i32$4;
    i64toi32_i32$4 = $1$hi;
    i64toi32_i32$3 = $3$hi;
    i64toi32_i32$3 = __wasm_i64_mul($1_1 | 0, i64toi32_i32$4 | 0, $3_1 | 0, i64toi32_i32$3 | 0) | 0;
    i64toi32_i32$4 = i64toi32_i32$HIGH_BITS;
    $216 = i64toi32_i32$3;
    $216$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $208$hi;
    i64toi32_i32$1 = $208;
    i64toi32_i32$3 = $216$hi;
    i64toi32_i32$2 = $216;
    i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
    i64toi32_i32$0 = i64toi32_i32$4 + i64toi32_i32$3 | 0;
    if (i64toi32_i32$5 >>> 0 < i64toi32_i32$2 >>> 0) i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0;
    i64toi32_i32$0 = i64toi32_i32$0;
    $8_1 = i64toi32_i32$5;
    $8$hi = i64toi32_i32$0;
    i64toi32_i32$0 = i64toi32_i32$0;
    i64toi32_i32$0 = i64toi32_i32$0;
    i64toi32_i32$4 = i64toi32_i32$5;
    i64toi32_i32$1 = 0;
    i64toi32_i32$2 = 32;
    i64toi32_i32$3 = i64toi32_i32$2 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
     i64toi32_i32$1 = i64toi32_i32$4 << i64toi32_i32$3 | 0;
     $252 = 0;
    } else {
     i64toi32_i32$1 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$4 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$3 | 0) | 0;
     $252 = i64toi32_i32$4 << i64toi32_i32$3 | 0;
    }
    i64toi32_i32$1 = i64toi32_i32$1;
    $10_1 = $252;
    $10$hi = i64toi32_i32$1;
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$1 = $1$hi;
    i64toi32_i32$1 = $4$hi;
    i64toi32_i32$1 = $1$hi;
    i64toi32_i32$4 = $4$hi;
    i64toi32_i32$4 = __wasm_i64_mul($1_1 | 0, i64toi32_i32$1 | 0, $4_1 | 0, i64toi32_i32$4 | 0) | 0;
    i64toi32_i32$1 = i64toi32_i32$HIGH_BITS;
    $223 = i64toi32_i32$4;
    $223$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $10$hi;
    i64toi32_i32$0 = $10_1;
    i64toi32_i32$4 = $223$hi;
    i64toi32_i32$2 = $223;
    i64toi32_i32$3 = i64toi32_i32$0 + i64toi32_i32$2 | 0;
    i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$4 | 0;
    if (i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0) i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0;
    i64toi32_i32$5 = i64toi32_i32$5;
    $9_1 = i64toi32_i32$3;
    $9$hi = i64toi32_i32$5;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$5 = $10$hi;
    i64toi32_i32$5 = $9$hi;
    i64toi32_i32$1 = i64toi32_i32$3;
    i64toi32_i32$0 = $10$hi;
    i64toi32_i32$2 = $10_1;
    i64toi32_i32$1 = 0;
    $228 = i64toi32_i32$5 >>> 0 < i64toi32_i32$0 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0;
    $228$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $2$hi;
    i64toi32_i32$1 = $3$hi;
    i64toi32_i32$1 = $2$hi;
    i64toi32_i32$5 = $3$hi;
    i64toi32_i32$5 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$1 | 0, $3_1 | 0, i64toi32_i32$5 | 0) | 0;
    i64toi32_i32$1 = i64toi32_i32$HIGH_BITS;
    i64toi32_i32$1 = i64toi32_i32$1;
    $23_1 = i64toi32_i32$5;
    $23$hi = i64toi32_i32$1;
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$1 = $1$hi;
    i64toi32_i32$1 = $11$hi;
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$2 = $11_1;
    i64toi32_i32$5 = 0;
    i64toi32_i32$0 = 4294967295;
    i64toi32_i32$5 = i64toi32_i32$1 & i64toi32_i32$5 | 0;
    i64toi32_i32$5 = i64toi32_i32$5;
    $10_1 = i64toi32_i32$2 & i64toi32_i32$0 | 0;
    $10$hi = i64toi32_i32$5;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$5 = $1$hi;
    i64toi32_i32$2 = $10$hi;
    i64toi32_i32$2 = __wasm_i64_mul($1_1 | 0, i64toi32_i32$5 | 0, $10_1 | 0, i64toi32_i32$2 | 0) | 0;
    i64toi32_i32$5 = i64toi32_i32$HIGH_BITS;
    $237 = i64toi32_i32$2;
    $237$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $23$hi;
    i64toi32_i32$1 = $23_1;
    i64toi32_i32$2 = $237$hi;
    i64toi32_i32$0 = $237;
    i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$0 | 0;
    i64toi32_i32$3 = i64toi32_i32$5 + i64toi32_i32$2 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$0 >>> 0) i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0;
    i64toi32_i32$3 = i64toi32_i32$3;
    $19_1 = i64toi32_i32$4;
    $19$hi = i64toi32_i32$3;
    i64toi32_i32$3 = i64toi32_i32$3;
    i64toi32_i32$3 = $15$hi;
    i64toi32_i32$3 = i64toi32_i32$3;
    i64toi32_i32$5 = $15_1;
    i64toi32_i32$1 = 0;
    i64toi32_i32$0 = 4294967295;
    i64toi32_i32$1 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
    i64toi32_i32$1 = i64toi32_i32$1;
    $11_1 = i64toi32_i32$5 & i64toi32_i32$0 | 0;
    $11$hi = i64toi32_i32$1;
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$1 = $4$hi;
    i64toi32_i32$1 = $11$hi;
    i64toi32_i32$5 = $4$hi;
    i64toi32_i32$5 = __wasm_i64_mul($11_1 | 0, i64toi32_i32$1 | 0, $4_1 | 0, i64toi32_i32$5 | 0) | 0;
    i64toi32_i32$1 = i64toi32_i32$HIGH_BITS;
    $244 = i64toi32_i32$5;
    $244$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $19$hi;
    i64toi32_i32$3 = i64toi32_i32$4;
    i64toi32_i32$5 = $244$hi;
    i64toi32_i32$0 = $244;
    i64toi32_i32$2 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
    i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
    if (i64toi32_i32$2 >>> 0 < i64toi32_i32$0 >>> 0) i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0;
    i64toi32_i32$4 = i64toi32_i32$4;
    $15_1 = i64toi32_i32$2;
    $15$hi = i64toi32_i32$4;
    i64toi32_i32$4 = i64toi32_i32$4;
    $246 = i64toi32_i32$2;
    $246$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $2$hi;
    i64toi32_i32$4 = $10$hi;
    i64toi32_i32$4 = $2$hi;
    i64toi32_i32$3 = $10$hi;
    i64toi32_i32$3 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$4 | 0, $10_1 | 0, i64toi32_i32$3 | 0) | 0;
    i64toi32_i32$4 = i64toi32_i32$HIGH_BITS;
    i64toi32_i32$4 = i64toi32_i32$4;
    $24_1 = i64toi32_i32$3;
    $24$hi = i64toi32_i32$4;
    i64toi32_i32$4 = i64toi32_i32$4;
    i64toi32_i32$4 = $1$hi;
    i64toi32_i32$4 = $12$hi;
    i64toi32_i32$4 = i64toi32_i32$4;
    i64toi32_i32$1 = $12_1;
    i64toi32_i32$3 = 0;
    i64toi32_i32$0 = 65536;
    i64toi32_i32$3 = i64toi32_i32$4 | i64toi32_i32$3 | 0;
    i64toi32_i32$3 = i64toi32_i32$3;
    $14_1 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
    $14$hi = i64toi32_i32$3;
    i64toi32_i32$3 = i64toi32_i32$3;
    i64toi32_i32$3 = $1$hi;
    i64toi32_i32$1 = $14$hi;
    i64toi32_i32$1 = __wasm_i64_mul($1_1 | 0, i64toi32_i32$3 | 0, $14_1 | 0, i64toi32_i32$1 | 0) | 0;
    i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
    $255 = i64toi32_i32$1;
    $255$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $24$hi;
    i64toi32_i32$4 = $24_1;
    i64toi32_i32$1 = $255$hi;
    i64toi32_i32$0 = $255;
    i64toi32_i32$5 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
    i64toi32_i32$2 = i64toi32_i32$3 + i64toi32_i32$1 | 0;
    if (i64toi32_i32$5 >>> 0 < i64toi32_i32$0 >>> 0) i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    $12_1 = i64toi32_i32$5;
    $12$hi = i64toi32_i32$2;
    i64toi32_i32$2 = i64toi32_i32$2;
    i64toi32_i32$2 = $11$hi;
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$2 = $11$hi;
    i64toi32_i32$4 = $3$hi;
    i64toi32_i32$4 = __wasm_i64_mul($11_1 | 0, i64toi32_i32$2 | 0, $3_1 | 0, i64toi32_i32$4 | 0) | 0;
    i64toi32_i32$2 = i64toi32_i32$HIGH_BITS;
    $260 = i64toi32_i32$4;
    $260$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $12$hi;
    i64toi32_i32$3 = i64toi32_i32$5;
    i64toi32_i32$4 = $260$hi;
    i64toi32_i32$0 = $260;
    i64toi32_i32$1 = i64toi32_i32$3 + i64toi32_i32$0 | 0;
    i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$4 | 0;
    if (i64toi32_i32$1 >>> 0 < i64toi32_i32$0 >>> 0) i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0;
    i64toi32_i32$5 = i64toi32_i32$5;
    $20_1 = i64toi32_i32$1;
    $20$hi = i64toi32_i32$5;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$5 = $16$hi;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$2 = $16_1;
    i64toi32_i32$3 = 0;
    i64toi32_i32$0 = 2147483647;
    i64toi32_i32$3 = i64toi32_i32$5 & i64toi32_i32$3 | 0;
    i64toi32_i32$3 = i64toi32_i32$3;
    i64toi32_i32$5 = i64toi32_i32$2 & i64toi32_i32$0 | 0;
    i64toi32_i32$2 = 0;
    i64toi32_i32$0 = 2147483648;
    i64toi32_i32$2 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    $1_1 = i64toi32_i32$5 | i64toi32_i32$0 | 0;
    $1$hi = i64toi32_i32$2;
    i64toi32_i32$2 = i64toi32_i32$2;
    i64toi32_i32$2 = $4$hi;
    i64toi32_i32$2 = $1$hi;
    i64toi32_i32$5 = $4$hi;
    i64toi32_i32$5 = __wasm_i64_mul($1_1 | 0, i64toi32_i32$2 | 0, $4_1 | 0, i64toi32_i32$5 | 0) | 0;
    i64toi32_i32$2 = i64toi32_i32$HIGH_BITS;
    $268 = i64toi32_i32$5;
    $268$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $20$hi;
    i64toi32_i32$3 = i64toi32_i32$1;
    i64toi32_i32$5 = $268$hi;
    i64toi32_i32$0 = $268;
    i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$0 | 0;
    i64toi32_i32$1 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$0 >>> 0) i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0;
    i64toi32_i32$1 = i64toi32_i32$1;
    $16_1 = i64toi32_i32$4;
    $16$hi = i64toi32_i32$1;
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$2 = i64toi32_i32$4;
    i64toi32_i32$3 = 0;
    i64toi32_i32$0 = 32;
    i64toi32_i32$5 = i64toi32_i32$0 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
     i64toi32_i32$3 = i64toi32_i32$2 << i64toi32_i32$5 | 0;
     $253 = 0;
    } else {
     i64toi32_i32$3 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$5 | 0) | 0;
     $253 = i64toi32_i32$2 << i64toi32_i32$5 | 0;
    }
    $271$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $246$hi;
    i64toi32_i32$1 = $246;
    i64toi32_i32$2 = $271$hi;
    i64toi32_i32$0 = $253;
    i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$0 | 0;
    i64toi32_i32$4 = i64toi32_i32$3 + i64toi32_i32$2 | 0;
    if (i64toi32_i32$5 >>> 0 < i64toi32_i32$0 >>> 0) i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0;
    i64toi32_i32$4 = i64toi32_i32$4;
    $21_1 = i64toi32_i32$5;
    $21$hi = i64toi32_i32$4;
    i64toi32_i32$4 = i64toi32_i32$4;
    $273 = i64toi32_i32$5;
    $273$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $8$hi;
    i64toi32_i32$4 = i64toi32_i32$4;
    i64toi32_i32$3 = $8_1;
    i64toi32_i32$1 = 0;
    i64toi32_i32$0 = 32;
    i64toi32_i32$2 = i64toi32_i32$0 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
     i64toi32_i32$1 = 0;
     $254 = i64toi32_i32$4 >>> i64toi32_i32$2 | 0;
    } else {
     i64toi32_i32$1 = i64toi32_i32$4 >>> i64toi32_i32$2 | 0;
     $254 = (((1 << i64toi32_i32$2 | 0) - 1 | 0) & i64toi32_i32$4 | 0) << (32 - i64toi32_i32$2 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$2 | 0) | 0;
    }
    $275 = $254;
    $275$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $8$hi;
    i64toi32_i32$1 = $22$hi;
    i64toi32_i32$1 = $8$hi;
    i64toi32_i32$4 = $8_1;
    i64toi32_i32$3 = $22$hi;
    i64toi32_i32$0 = $22_1;
    $278 = i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$4 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0;
    i64toi32_i32$4 = 0;
    i64toi32_i32$4 = i64toi32_i32$4;
    i64toi32_i32$0 = $278;
    i64toi32_i32$1 = 0;
    i64toi32_i32$3 = 32;
    i64toi32_i32$2 = i64toi32_i32$3 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
     i64toi32_i32$1 = i64toi32_i32$0 << i64toi32_i32$2 | 0;
     $256 = 0;
    } else {
     i64toi32_i32$1 = ((1 << i64toi32_i32$2 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$2 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$2 | 0) | 0;
     $256 = i64toi32_i32$0 << i64toi32_i32$2 | 0;
    }
    $280$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $275$hi;
    i64toi32_i32$4 = $275;
    i64toi32_i32$0 = $280$hi;
    i64toi32_i32$3 = $256;
    i64toi32_i32$0 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
    $281 = i64toi32_i32$4 | i64toi32_i32$3 | 0;
    $281$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $273$hi;
    i64toi32_i32$1 = $273;
    i64toi32_i32$4 = $281$hi;
    i64toi32_i32$3 = $281;
    i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
    i64toi32_i32$5 = i64toi32_i32$0 + i64toi32_i32$4 | 0;
    if (i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0) i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0;
    i64toi32_i32$5 = i64toi32_i32$5;
    $8_1 = i64toi32_i32$2;
    $8$hi = i64toi32_i32$5;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$5 = $228$hi;
    i64toi32_i32$0 = $228;
    i64toi32_i32$1 = $8$hi;
    i64toi32_i32$3 = i64toi32_i32$2;
    i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$2 | 0;
    i64toi32_i32$2 = i64toi32_i32$5 + i64toi32_i32$1 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    $4_1 = i64toi32_i32$4;
    $4$hi = i64toi32_i32$2;
    $7_1 = (($17_1 + $7_1 | 0) + $13_1 | 0) + 4294950913 | 0;
    label$12 : {
     i64toi32_i32$2 = $16$hi;
     i64toi32_i32$2 = i64toi32_i32$2;
     i64toi32_i32$5 = $16_1;
     i64toi32_i32$0 = 0;
     i64toi32_i32$3 = 32;
     i64toi32_i32$1 = i64toi32_i32$3 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
      i64toi32_i32$0 = 0;
      $257 = i64toi32_i32$2 >>> i64toi32_i32$1 | 0;
     } else {
      i64toi32_i32$0 = i64toi32_i32$2 >>> i64toi32_i32$1 | 0;
      $257 = (((1 << i64toi32_i32$1 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$1 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$1 | 0) | 0;
     }
     $292 = $257;
     $292$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $12$hi;
     i64toi32_i32$0 = $24$hi;
     i64toi32_i32$0 = $12$hi;
     i64toi32_i32$2 = $12_1;
     i64toi32_i32$5 = $24$hi;
     i64toi32_i32$3 = $24_1;
     $295 = i64toi32_i32$0 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0 | 0) | 0;
     i64toi32_i32$2 = 0;
     $296$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $20$hi;
     i64toi32_i32$2 = i64toi32_i32$0;
     i64toi32_i32$2 = $20$hi;
     i64toi32_i32$3 = $20_1;
     i64toi32_i32$0 = i64toi32_i32$0;
     i64toi32_i32$5 = $12_1;
     $299 = i64toi32_i32$2 >>> 0 < i64toi32_i32$0 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
     i64toi32_i32$3 = 0;
     $300$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $296$hi;
     i64toi32_i32$5 = $295;
     i64toi32_i32$2 = $300$hi;
     i64toi32_i32$0 = $299;
     i64toi32_i32$1 = i64toi32_i32$5 + i64toi32_i32$0 | 0;
     i64toi32_i32$4 = i64toi32_i32$3 + i64toi32_i32$2 | 0;
     if (i64toi32_i32$1 >>> 0 < i64toi32_i32$0 >>> 0) i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0;
     $301$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $16$hi;
     i64toi32_i32$4 = $20$hi;
     i64toi32_i32$4 = $16$hi;
     i64toi32_i32$3 = $16_1;
     i64toi32_i32$5 = $20$hi;
     i64toi32_i32$0 = $20_1;
     $304 = i64toi32_i32$4 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0;
     i64toi32_i32$3 = 0;
     $305$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $301$hi;
     i64toi32_i32$0 = i64toi32_i32$1;
     i64toi32_i32$4 = $305$hi;
     i64toi32_i32$5 = $304;
     i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
     i64toi32_i32$1 = i64toi32_i32$3 + i64toi32_i32$4 | 0;
     if (i64toi32_i32$2 >>> 0 < i64toi32_i32$5 >>> 0) i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0;
     i64toi32_i32$1 = i64toi32_i32$1;
     i64toi32_i32$3 = i64toi32_i32$2;
     i64toi32_i32$0 = 0;
     i64toi32_i32$5 = 32;
     i64toi32_i32$4 = i64toi32_i32$5 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
      i64toi32_i32$0 = i64toi32_i32$3 << i64toi32_i32$4 | 0;
      $258 = 0;
     } else {
      i64toi32_i32$0 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$4 | 0) | 0;
      $258 = i64toi32_i32$3 << i64toi32_i32$4 | 0;
     }
     $307$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $292$hi;
     i64toi32_i32$1 = $292;
     i64toi32_i32$3 = $307$hi;
     i64toi32_i32$5 = $258;
     i64toi32_i32$3 = i64toi32_i32$0 | i64toi32_i32$3 | 0;
     i64toi32_i32$3 = i64toi32_i32$3;
     $12_1 = i64toi32_i32$1 | i64toi32_i32$5 | 0;
     $12$hi = i64toi32_i32$3;
     i64toi32_i32$3 = i64toi32_i32$3;
     $309 = $12_1;
     $309$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $21$hi;
     i64toi32_i32$3 = $15$hi;
     i64toi32_i32$3 = $21$hi;
     i64toi32_i32$0 = $21_1;
     i64toi32_i32$1 = $15$hi;
     i64toi32_i32$5 = $15_1;
     $312 = i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$0 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
     i64toi32_i32$0 = 0;
     $313$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $8$hi;
     i64toi32_i32$0 = i64toi32_i32$3;
     i64toi32_i32$0 = $8$hi;
     i64toi32_i32$5 = $8_1;
     i64toi32_i32$3 = i64toi32_i32$3;
     i64toi32_i32$1 = $21_1;
     $316 = i64toi32_i32$0 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$5 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
     i64toi32_i32$5 = 0;
     $317$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $313$hi;
     i64toi32_i32$1 = $312;
     i64toi32_i32$0 = $317$hi;
     i64toi32_i32$3 = $316;
     i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
     i64toi32_i32$2 = i64toi32_i32$5 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0;
     $318$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $309$hi;
     i64toi32_i32$5 = $309;
     i64toi32_i32$1 = $318$hi;
     i64toi32_i32$3 = i64toi32_i32$4;
     i64toi32_i32$0 = i64toi32_i32$5 + i64toi32_i32$4 | 0;
     i64toi32_i32$4 = i64toi32_i32$2 + i64toi32_i32$1 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$3 >>> 0) i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0;
     i64toi32_i32$4 = i64toi32_i32$4;
     $8_1 = i64toi32_i32$0;
     $8$hi = i64toi32_i32$4;
     i64toi32_i32$4 = i64toi32_i32$4;
     i64toi32_i32$4 = $12$hi;
     i64toi32_i32$4 = $8$hi;
     i64toi32_i32$2 = i64toi32_i32$0;
     i64toi32_i32$5 = $12$hi;
     i64toi32_i32$3 = $12_1;
     $322 = i64toi32_i32$4 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0 | 0) | 0;
     i64toi32_i32$2 = 0;
     $323 = $322;
     $323$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $11$hi;
     i64toi32_i32$2 = $10$hi;
     i64toi32_i32$2 = $11$hi;
     i64toi32_i32$4 = $10$hi;
     i64toi32_i32$4 = __wasm_i64_mul($11_1 | 0, i64toi32_i32$2 | 0, $10_1 | 0, i64toi32_i32$4 | 0) | 0;
     i64toi32_i32$2 = i64toi32_i32$HIGH_BITS;
     i64toi32_i32$2 = i64toi32_i32$2;
     $12_1 = i64toi32_i32$4;
     $12$hi = i64toi32_i32$2;
     i64toi32_i32$2 = i64toi32_i32$2;
     i64toi32_i32$2 = $2$hi;
     i64toi32_i32$2 = $14$hi;
     i64toi32_i32$2 = $2$hi;
     i64toi32_i32$4 = $14$hi;
     i64toi32_i32$4 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$2 | 0, $14_1 | 0, i64toi32_i32$4 | 0) | 0;
     i64toi32_i32$2 = i64toi32_i32$HIGH_BITS;
     $330 = i64toi32_i32$4;
     $330$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $12$hi;
     i64toi32_i32$3 = $12_1;
     i64toi32_i32$4 = $330$hi;
     i64toi32_i32$5 = $330;
     i64toi32_i32$1 = i64toi32_i32$3 + i64toi32_i32$5 | 0;
     i64toi32_i32$0 = i64toi32_i32$2 + i64toi32_i32$4 | 0;
     if (i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0) i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0;
     i64toi32_i32$0 = i64toi32_i32$0;
     $2_1 = i64toi32_i32$1;
     $2$hi = i64toi32_i32$0;
     i64toi32_i32$0 = i64toi32_i32$0;
     i64toi32_i32$0 = $12$hi;
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$2 = i64toi32_i32$1;
     i64toi32_i32$3 = $12$hi;
     i64toi32_i32$5 = $12_1;
     $334 = i64toi32_i32$0 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
     i64toi32_i32$2 = 0;
     $335 = $334;
     $335$hi = i64toi32_i32$2;
     i64toi32_i32$2 = i64toi32_i32$0;
     i64toi32_i32$2 = $1$hi;
     i64toi32_i32$2 = $3$hi;
     i64toi32_i32$2 = $1$hi;
     i64toi32_i32$0 = $3$hi;
     i64toi32_i32$0 = __wasm_i64_mul($1_1 | 0, i64toi32_i32$2 | 0, $3_1 | 0, i64toi32_i32$0 | 0) | 0;
     i64toi32_i32$2 = i64toi32_i32$HIGH_BITS;
     $339 = i64toi32_i32$0;
     $339$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $2$hi;
     i64toi32_i32$5 = i64toi32_i32$1;
     i64toi32_i32$0 = $339$hi;
     i64toi32_i32$3 = $339;
     i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
     i64toi32_i32$1 = i64toi32_i32$2 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0;
     i64toi32_i32$1 = i64toi32_i32$1;
     $3_1 = i64toi32_i32$4;
     $3$hi = i64toi32_i32$1;
     i64toi32_i32$1 = i64toi32_i32$1;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$2 = i64toi32_i32$4;
     i64toi32_i32$5 = $2$hi;
     i64toi32_i32$3 = $2_1;
     $343 = i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0 | 0) | 0;
     i64toi32_i32$2 = 0;
     $344$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $335$hi;
     i64toi32_i32$3 = $335;
     i64toi32_i32$1 = $344$hi;
     i64toi32_i32$5 = $343;
     i64toi32_i32$0 = i64toi32_i32$3 + i64toi32_i32$5 | 0;
     i64toi32_i32$4 = i64toi32_i32$2 + i64toi32_i32$1 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$5 >>> 0) i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0;
     $345 = i64toi32_i32$0;
     $345$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $3$hi;
     $346 = $3_1;
     $346$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $19$hi;
     i64toi32_i32$4 = $23$hi;
     i64toi32_i32$4 = $19$hi;
     i64toi32_i32$2 = $19_1;
     i64toi32_i32$3 = $23$hi;
     i64toi32_i32$5 = $23_1;
     $349 = i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
     i64toi32_i32$2 = 0;
     $350$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $15$hi;
     i64toi32_i32$2 = i64toi32_i32$4;
     i64toi32_i32$2 = $15$hi;
     i64toi32_i32$5 = $15_1;
     i64toi32_i32$4 = i64toi32_i32$4;
     i64toi32_i32$3 = $19_1;
     $353 = i64toi32_i32$2 >>> 0 < i64toi32_i32$4 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$5 >>> 0 < i64toi32_i32$3 >>> 0 | 0) | 0;
     i64toi32_i32$5 = 0;
     $354$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $350$hi;
     i64toi32_i32$3 = $349;
     i64toi32_i32$2 = $354$hi;
     i64toi32_i32$4 = $353;
     i64toi32_i32$1 = i64toi32_i32$3 + i64toi32_i32$4 | 0;
     i64toi32_i32$0 = i64toi32_i32$5 + i64toi32_i32$2 | 0;
     if (i64toi32_i32$1 >>> 0 < i64toi32_i32$4 >>> 0) i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0;
     $355$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $346$hi;
     i64toi32_i32$5 = $346;
     i64toi32_i32$3 = $355$hi;
     i64toi32_i32$4 = i64toi32_i32$1;
     i64toi32_i32$2 = i64toi32_i32$5 + i64toi32_i32$4 | 0;
     i64toi32_i32$1 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$2 >>> 0 < i64toi32_i32$4 >>> 0) i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0;
     i64toi32_i32$1 = i64toi32_i32$1;
     $2_1 = i64toi32_i32$2;
     $2$hi = i64toi32_i32$1;
     i64toi32_i32$1 = i64toi32_i32$1;
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$0 = i64toi32_i32$2;
     i64toi32_i32$5 = $3$hi;
     i64toi32_i32$4 = $3_1;
     $359 = i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$4 >>> 0 | 0) | 0;
     i64toi32_i32$0 = 0;
     $360$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $345$hi;
     i64toi32_i32$4 = $345;
     i64toi32_i32$1 = $360$hi;
     i64toi32_i32$5 = $359;
     i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$5 | 0;
     i64toi32_i32$2 = i64toi32_i32$0 + i64toi32_i32$1 | 0;
     if (i64toi32_i32$3 >>> 0 < i64toi32_i32$5 >>> 0) i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0;
     $361$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $1$hi;
     i64toi32_i32$2 = $14$hi;
     i64toi32_i32$2 = $1$hi;
     i64toi32_i32$4 = $14$hi;
     i64toi32_i32$4 = __wasm_i64_mul($1_1 | 0, i64toi32_i32$2 | 0, $14_1 | 0, i64toi32_i32$4 | 0) | 0;
     i64toi32_i32$2 = i64toi32_i32$HIGH_BITS;
     $364 = i64toi32_i32$4;
     $364$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $361$hi;
     i64toi32_i32$0 = i64toi32_i32$3;
     i64toi32_i32$4 = $364$hi;
     i64toi32_i32$5 = $364;
     i64toi32_i32$1 = i64toi32_i32$3 + i64toi32_i32$5 | 0;
     i64toi32_i32$3 = i64toi32_i32$2 + i64toi32_i32$4 | 0;
     if (i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0) i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0;
     $365 = i64toi32_i32$1;
     $365$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $1$hi;
     i64toi32_i32$3 = $10$hi;
     i64toi32_i32$3 = $1$hi;
     i64toi32_i32$0 = $10$hi;
     i64toi32_i32$0 = __wasm_i64_mul($1_1 | 0, i64toi32_i32$3 | 0, $10_1 | 0, i64toi32_i32$0 | 0) | 0;
     i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
     i64toi32_i32$3 = i64toi32_i32$3;
     $3_1 = i64toi32_i32$0;
     $3$hi = i64toi32_i32$3;
     i64toi32_i32$3 = i64toi32_i32$3;
     i64toi32_i32$3 = $11$hi;
     i64toi32_i32$3 = $14$hi;
     i64toi32_i32$3 = $11$hi;
     i64toi32_i32$0 = $14$hi;
     i64toi32_i32$0 = __wasm_i64_mul($11_1 | 0, i64toi32_i32$3 | 0, $14_1 | 0, i64toi32_i32$0 | 0) | 0;
     i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
     $372 = i64toi32_i32$0;
     $372$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $3$hi;
     i64toi32_i32$2 = $3_1;
     i64toi32_i32$0 = $372$hi;
     i64toi32_i32$5 = $372;
     i64toi32_i32$4 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
     i64toi32_i32$1 = i64toi32_i32$3 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$4 >>> 0 < i64toi32_i32$5 >>> 0) i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0;
     i64toi32_i32$1 = i64toi32_i32$1;
     $1_1 = i64toi32_i32$4;
     $1$hi = i64toi32_i32$1;
     i64toi32_i32$1 = i64toi32_i32$1;
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$3 = i64toi32_i32$4;
     i64toi32_i32$2 = $3$hi;
     i64toi32_i32$5 = $3_1;
     i64toi32_i32$3 = 0;
     i64toi32_i32$3 = i64toi32_i32$3;
     i64toi32_i32$5 = i64toi32_i32$1 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$4 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
     i64toi32_i32$1 = 0;
     i64toi32_i32$2 = 32;
     i64toi32_i32$0 = i64toi32_i32$2 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
      i64toi32_i32$1 = i64toi32_i32$5 << i64toi32_i32$0 | 0;
      $259 = 0;
     } else {
      i64toi32_i32$1 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$0 | 0) | 0;
      $259 = i64toi32_i32$5 << i64toi32_i32$0 | 0;
     }
     $378 = $259;
     $378$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$1 = i64toi32_i32$1;
     i64toi32_i32$3 = $1_1;
     i64toi32_i32$5 = 0;
     i64toi32_i32$2 = 32;
     i64toi32_i32$0 = i64toi32_i32$2 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
      i64toi32_i32$5 = 0;
      $261 = i64toi32_i32$1 >>> i64toi32_i32$0 | 0;
     } else {
      i64toi32_i32$5 = i64toi32_i32$1 >>> i64toi32_i32$0 | 0;
      $261 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$0 | 0) | 0;
     }
     $380$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $378$hi;
     i64toi32_i32$1 = $378;
     i64toi32_i32$3 = $380$hi;
     i64toi32_i32$2 = $261;
     i64toi32_i32$3 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
     $381 = i64toi32_i32$1 | i64toi32_i32$2 | 0;
     $381$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $365$hi;
     i64toi32_i32$5 = $365;
     i64toi32_i32$1 = $381$hi;
     i64toi32_i32$2 = $381;
     i64toi32_i32$0 = i64toi32_i32$5 + i64toi32_i32$2 | 0;
     i64toi32_i32$4 = i64toi32_i32$3 + i64toi32_i32$1 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$2 >>> 0) i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0;
     $382 = i64toi32_i32$0;
     $382$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $2$hi;
     $383 = $2_1;
     $383$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $1$hi;
     i64toi32_i32$4 = i64toi32_i32$4;
     i64toi32_i32$3 = $1_1;
     i64toi32_i32$5 = 0;
     i64toi32_i32$2 = 32;
     i64toi32_i32$1 = i64toi32_i32$2 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
      i64toi32_i32$5 = i64toi32_i32$3 << i64toi32_i32$1 | 0;
      $262 = 0;
     } else {
      i64toi32_i32$5 = ((1 << i64toi32_i32$1 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$1 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$1 | 0) | 0;
      $262 = i64toi32_i32$3 << i64toi32_i32$1 | 0;
     }
     $385$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $383$hi;
     i64toi32_i32$4 = $383;
     i64toi32_i32$3 = $385$hi;
     i64toi32_i32$2 = $262;
     i64toi32_i32$1 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
     i64toi32_i32$0 = i64toi32_i32$5 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$1 >>> 0 < i64toi32_i32$2 >>> 0) i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0;
     i64toi32_i32$0 = i64toi32_i32$0;
     $1_1 = i64toi32_i32$1;
     $1$hi = i64toi32_i32$0;
     i64toi32_i32$0 = i64toi32_i32$0;
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$0 = $1$hi;
     i64toi32_i32$5 = i64toi32_i32$1;
     i64toi32_i32$4 = $2$hi;
     i64toi32_i32$2 = $2_1;
     $389 = i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$1 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0;
     i64toi32_i32$5 = 0;
     $390$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $382$hi;
     i64toi32_i32$2 = $382;
     i64toi32_i32$0 = $390$hi;
     i64toi32_i32$4 = $389;
     i64toi32_i32$3 = i64toi32_i32$2 + i64toi32_i32$4 | 0;
     i64toi32_i32$1 = i64toi32_i32$5 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$3 >>> 0 < i64toi32_i32$4 >>> 0) i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0;
     $391$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $323$hi;
     i64toi32_i32$5 = $323;
     i64toi32_i32$2 = $391$hi;
     i64toi32_i32$4 = i64toi32_i32$3;
     i64toi32_i32$0 = i64toi32_i32$5 + i64toi32_i32$4 | 0;
     i64toi32_i32$3 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0) i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0;
     $392 = i64toi32_i32$0;
     $392$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $8$hi;
     i64toi32_i32$3 = $1$hi;
     i64toi32_i32$3 = $8$hi;
     i64toi32_i32$1 = $8_1;
     i64toi32_i32$5 = $1$hi;
     i64toi32_i32$4 = $1_1;
     i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$4 | 0;
     i64toi32_i32$0 = i64toi32_i32$3 + i64toi32_i32$5 | 0;
     if (i64toi32_i32$2 >>> 0 < i64toi32_i32$4 >>> 0) i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0;
     i64toi32_i32$0 = i64toi32_i32$0;
     $2_1 = i64toi32_i32$2;
     $2$hi = i64toi32_i32$0;
     i64toi32_i32$0 = i64toi32_i32$0;
     i64toi32_i32$0 = $8$hi;
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$3 = i64toi32_i32$2;
     i64toi32_i32$1 = $8$hi;
     i64toi32_i32$4 = $8_1;
     $398 = i64toi32_i32$0 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$4 >>> 0 | 0) | 0;
     i64toi32_i32$3 = 0;
     $399$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $392$hi;
     i64toi32_i32$4 = $392;
     i64toi32_i32$0 = $399$hi;
     i64toi32_i32$1 = $398;
     i64toi32_i32$5 = i64toi32_i32$4 + i64toi32_i32$1 | 0;
     i64toi32_i32$2 = i64toi32_i32$3 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$5 >>> 0 < i64toi32_i32$1 >>> 0) i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0;
     i64toi32_i32$2 = i64toi32_i32$2;
     $1_1 = i64toi32_i32$5;
     $1$hi = i64toi32_i32$2;
     i64toi32_i32$2 = i64toi32_i32$2;
     i64toi32_i32$2 = i64toi32_i32$2;
     i64toi32_i32$3 = i64toi32_i32$5;
     i64toi32_i32$4 = 65536;
     i64toi32_i32$1 = 0;
     i64toi32_i32$4 = i64toi32_i32$2 & i64toi32_i32$4 | 0;
     i64toi32_i32$4 = i64toi32_i32$4;
     if ((i64toi32_i32$3 & i64toi32_i32$1 | 0 | i64toi32_i32$4 | 0 | 0) == (0 | 0)) {
      i64toi32_i32$4 = $9$hi;
      i64toi32_i32$4 = i64toi32_i32$4;
      i64toi32_i32$2 = $9_1;
      i64toi32_i32$3 = 0;
      i64toi32_i32$1 = 63;
      i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
      if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
       i64toi32_i32$3 = 0;
       $263 = i64toi32_i32$4 >>> i64toi32_i32$0 | 0;
      } else {
       i64toi32_i32$3 = i64toi32_i32$4 >>> i64toi32_i32$0 | 0;
       $263 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$4 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$0 | 0) | 0;
      }
      i64toi32_i32$3 = i64toi32_i32$3;
      $3_1 = $263;
      $3$hi = i64toi32_i32$3;
      i64toi32_i32$3 = $1$hi;
      i64toi32_i32$3 = i64toi32_i32$3;
      i64toi32_i32$4 = $1_1;
      i64toi32_i32$2 = 0;
      i64toi32_i32$1 = 1;
      i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
      if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
       i64toi32_i32$2 = i64toi32_i32$4 << i64toi32_i32$0 | 0;
       $264 = 0;
      } else {
       i64toi32_i32$2 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$4 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$0 | 0) | 0;
       $264 = i64toi32_i32$4 << i64toi32_i32$0 | 0;
      }
      $407 = $264;
      $407$hi = i64toi32_i32$2;
      i64toi32_i32$2 = $2$hi;
      i64toi32_i32$2 = i64toi32_i32$2;
      i64toi32_i32$3 = $2_1;
      i64toi32_i32$4 = 0;
      i64toi32_i32$1 = 63;
      i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
      if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
       i64toi32_i32$4 = 0;
       $265 = i64toi32_i32$2 >>> i64toi32_i32$0 | 0;
      } else {
       i64toi32_i32$4 = i64toi32_i32$2 >>> i64toi32_i32$0 | 0;
       $265 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$0 | 0) | 0;
      }
      $409$hi = i64toi32_i32$4;
      i64toi32_i32$4 = $407$hi;
      i64toi32_i32$2 = $407;
      i64toi32_i32$3 = $409$hi;
      i64toi32_i32$1 = $265;
      i64toi32_i32$3 = i64toi32_i32$4 | i64toi32_i32$3 | 0;
      i64toi32_i32$3 = i64toi32_i32$3;
      $1_1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
      $1$hi = i64toi32_i32$3;
      i64toi32_i32$3 = $2$hi;
      i64toi32_i32$3 = i64toi32_i32$3;
      i64toi32_i32$4 = $2_1;
      i64toi32_i32$2 = 0;
      i64toi32_i32$1 = 1;
      i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
      if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
       i64toi32_i32$2 = i64toi32_i32$4 << i64toi32_i32$0 | 0;
       $266 = 0;
      } else {
       i64toi32_i32$2 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$4 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$0 | 0) | 0;
       $266 = i64toi32_i32$4 << i64toi32_i32$0 | 0;
      }
      $412 = $266;
      $412$hi = i64toi32_i32$2;
      i64toi32_i32$2 = $4$hi;
      i64toi32_i32$2 = i64toi32_i32$2;
      i64toi32_i32$3 = $4_1;
      i64toi32_i32$4 = 0;
      i64toi32_i32$1 = 63;
      i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
      if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
       i64toi32_i32$4 = 0;
       $267 = i64toi32_i32$2 >>> i64toi32_i32$0 | 0;
      } else {
       i64toi32_i32$4 = i64toi32_i32$2 >>> i64toi32_i32$0 | 0;
       $267 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$0 | 0) | 0;
      }
      $414$hi = i64toi32_i32$4;
      i64toi32_i32$4 = $412$hi;
      i64toi32_i32$2 = $412;
      i64toi32_i32$3 = $414$hi;
      i64toi32_i32$1 = $267;
      i64toi32_i32$3 = i64toi32_i32$4 | i64toi32_i32$3 | 0;
      i64toi32_i32$3 = i64toi32_i32$3;
      $2_1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
      $2$hi = i64toi32_i32$3;
      i64toi32_i32$3 = $9$hi;
      i64toi32_i32$3 = i64toi32_i32$3;
      i64toi32_i32$4 = $9_1;
      i64toi32_i32$2 = 0;
      i64toi32_i32$1 = 1;
      i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
      if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
       i64toi32_i32$2 = i64toi32_i32$4 << i64toi32_i32$0 | 0;
       $269 = 0;
      } else {
       i64toi32_i32$2 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$4 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$0 | 0) | 0;
       $269 = i64toi32_i32$4 << i64toi32_i32$0 | 0;
      }
      i64toi32_i32$2 = i64toi32_i32$2;
      $9_1 = $269;
      $9$hi = i64toi32_i32$2;
      i64toi32_i32$2 = $3$hi;
      $418 = $3_1;
      $418$hi = i64toi32_i32$2;
      i64toi32_i32$2 = $4$hi;
      i64toi32_i32$2 = i64toi32_i32$2;
      i64toi32_i32$3 = $4_1;
      i64toi32_i32$4 = 0;
      i64toi32_i32$1 = 1;
      i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
      if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
       i64toi32_i32$4 = i64toi32_i32$3 << i64toi32_i32$0 | 0;
       $270 = 0;
      } else {
       i64toi32_i32$4 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$0 | 0) | 0;
       $270 = i64toi32_i32$3 << i64toi32_i32$0 | 0;
      }
      $420$hi = i64toi32_i32$4;
      i64toi32_i32$4 = $418$hi;
      i64toi32_i32$2 = $418;
      i64toi32_i32$3 = $420$hi;
      i64toi32_i32$1 = $270;
      i64toi32_i32$3 = i64toi32_i32$4 | i64toi32_i32$3 | 0;
      i64toi32_i32$3 = i64toi32_i32$3;
      $4_1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
      $4$hi = i64toi32_i32$3;
      break label$12;
     }
     $7_1 = $7_1 + 1 | 0;
    };
    if (($7_1 | 0) >= (32767 | 0)) {
     i64toi32_i32$3 = $6$hi;
     i64toi32_i32$3 = i64toi32_i32$3;
     i64toi32_i32$4 = $6_1;
     i64toi32_i32$2 = 2147418112;
     i64toi32_i32$1 = 0;
     i64toi32_i32$2 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
     i64toi32_i32$2 = i64toi32_i32$2;
     $6_1 = i64toi32_i32$4 | i64toi32_i32$1 | 0;
     $6$hi = i64toi32_i32$2;
     break label$2;
    }
    label$15 : {
     i64toi32_i32$2 = 0;
     i64toi32_i32$2 = i64toi32_i32$2;
     i64toi32_i32$3 = $7_1;
     i64toi32_i32$4 = 0;
     i64toi32_i32$1 = 48;
     i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
      i64toi32_i32$4 = i64toi32_i32$3 << i64toi32_i32$0 | 0;
      $271 = 0;
     } else {
      i64toi32_i32$4 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$0 | 0) | 0;
      $271 = i64toi32_i32$3 << i64toi32_i32$0 | 0;
     }
     $430$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $1$hi;
     i64toi32_i32$4 = i64toi32_i32$4;
     i64toi32_i32$2 = $1_1;
     i64toi32_i32$3 = 65535;
     i64toi32_i32$1 = 4294967295;
     i64toi32_i32$3 = i64toi32_i32$4 & i64toi32_i32$3 | 0;
     $432 = i64toi32_i32$2 & i64toi32_i32$1 | 0;
     $432$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $430$hi;
     i64toi32_i32$4 = $271;
     i64toi32_i32$2 = $432$hi;
     i64toi32_i32$1 = $432;
     i64toi32_i32$2 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
     i64toi32_i32$2 = i64toi32_i32$2;
     $436 = i64toi32_i32$4 | i64toi32_i32$1 | 0;
     $436$hi = i64toi32_i32$2;
     if (($7_1 | 0) > (0 | 0)) break label$15;
     i64toi32_i32$2 = $436$hi;
     i64toi32_i32$2 = i64toi32_i32$2;
     $7_1 = 1 - $7_1 | 0;
     if ($7_1 >>> 0 > 127 >>> 0) break label$2;
     i64toi32_i32$2 = $9$hi;
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$2 = $9$hi;
     i64toi32_i32$4 = $4$hi;
     $32($5_1 + 32 | 0 | 0, $9_1 | 0, i64toi32_i32$2 | 0, $4_1 | 0, i64toi32_i32$4 | 0, $7_1 | 0);
     i64toi32_i32$4 = $2$hi;
     i64toi32_i32$4 = $1$hi;
     $17_1 = 128 - $7_1 | 0;
     i64toi32_i32$4 = $2$hi;
     i64toi32_i32$2 = $1$hi;
     $31($5_1 + 16 | 0 | 0, $2_1 | 0, i64toi32_i32$4 | 0, $1_1 | 0, i64toi32_i32$2 | 0, $17_1 | 0);
     i64toi32_i32$2 = $9$hi;
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$2 = $9$hi;
     i64toi32_i32$4 = $4$hi;
     $31($5_1 + 48 | 0 | 0, $9_1 | 0, i64toi32_i32$2 | 0, $4_1 | 0, i64toi32_i32$4 | 0, $17_1 | 0);
     i64toi32_i32$4 = $2$hi;
     i64toi32_i32$4 = $1$hi;
     i64toi32_i32$4 = $2$hi;
     i64toi32_i32$2 = $1$hi;
     $32($5_1 | 0, $2_1 | 0, i64toi32_i32$4 | 0, $1_1 | 0, i64toi32_i32$2 | 0, $7_1 | 0);
     i64toi32_i32$3 = $5_1;
     i64toi32_i32$2 = HEAPU32[(i64toi32_i32$3 + 16 | 0) >> 2] | 0;
     i64toi32_i32$4 = (wasm2asm_i32$0 = i64toi32_i32$3, HEAPU8[(wasm2asm_i32$0 + 20 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 21 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 22 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 23 | 0) >> 0] | 0 | 0) << 24);
     $464 = i64toi32_i32$2;
     $464$hi = i64toi32_i32$4;
     i64toi32_i32$3 = i64toi32_i32$3;
     i64toi32_i32$4 = HEAPU32[(i64toi32_i32$3 + 32 | 0) >> 2] | 0;
     i64toi32_i32$2 = (wasm2asm_i32$0 = i64toi32_i32$3, HEAPU8[(wasm2asm_i32$0 + 36 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 37 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 38 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 39 | 0) >> 0] | 0 | 0) << 24);
     $466 = i64toi32_i32$4;
     $466$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $464$hi;
     i64toi32_i32$3 = $464;
     i64toi32_i32$4 = $466$hi;
     i64toi32_i32$1 = $466;
     i64toi32_i32$4 = i64toi32_i32$2 | i64toi32_i32$4 | 0;
     $467 = i64toi32_i32$3 | i64toi32_i32$1 | 0;
     $467$hi = i64toi32_i32$4;
     i64toi32_i32$2 = $5_1;
     i64toi32_i32$4 = HEAPU32[(i64toi32_i32$2 + 48 | 0) >> 2] | 0;
     i64toi32_i32$3 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 52 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 53 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 54 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 55 | 0) >> 0] | 0 | 0) << 24);
     $469 = i64toi32_i32$4;
     $469$hi = i64toi32_i32$3;
     i64toi32_i32$2 = i64toi32_i32$2 + 56 | 0;
     i64toi32_i32$3 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
     i64toi32_i32$4 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
     $472 = i64toi32_i32$3;
     $472$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $469$hi;
     i64toi32_i32$2 = $469;
     i64toi32_i32$3 = $472$hi;
     i64toi32_i32$1 = $472;
     i64toi32_i32$3 = i64toi32_i32$4 | i64toi32_i32$3 | 0;
     i64toi32_i32$3 = i64toi32_i32$3;
     i64toi32_i32$4 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
     i64toi32_i32$2 = 0;
     i64toi32_i32$1 = 0;
     $474 = (i64toi32_i32$4 | 0) != (i64toi32_i32$1 | 0) | (i64toi32_i32$3 | 0) != (i64toi32_i32$2 | 0) | 0;
     i64toi32_i32$4 = 0;
     $475$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $467$hi;
     i64toi32_i32$1 = $467;
     i64toi32_i32$3 = $475$hi;
     i64toi32_i32$2 = $474;
     i64toi32_i32$3 = i64toi32_i32$4 | i64toi32_i32$3 | 0;
     i64toi32_i32$3 = i64toi32_i32$3;
     $9_1 = i64toi32_i32$1 | i64toi32_i32$2 | 0;
     $9$hi = i64toi32_i32$3;
     i64toi32_i32$4 = $5_1 + 24 | 0;
     i64toi32_i32$3 = HEAPU32[i64toi32_i32$4 >> 2] | 0;
     i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$4, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
     $479 = i64toi32_i32$3;
     $479$hi = i64toi32_i32$1;
     i64toi32_i32$4 = $5_1 + 40 | 0;
     i64toi32_i32$1 = HEAPU32[i64toi32_i32$4 >> 2] | 0;
     i64toi32_i32$3 = (wasm2asm_i32$0 = i64toi32_i32$4, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
     $482 = i64toi32_i32$1;
     $482$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $479$hi;
     i64toi32_i32$4 = $479;
     i64toi32_i32$1 = $482$hi;
     i64toi32_i32$2 = $482;
     i64toi32_i32$1 = i64toi32_i32$3 | i64toi32_i32$1 | 0;
     i64toi32_i32$1 = i64toi32_i32$1;
     $4_1 = i64toi32_i32$4 | i64toi32_i32$2 | 0;
     $4$hi = i64toi32_i32$1;
     i64toi32_i32$3 = $5_1;
     i64toi32_i32$1 = HEAPU32[i64toi32_i32$3 >> 2] | 0;
     i64toi32_i32$4 = (wasm2asm_i32$0 = i64toi32_i32$3, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
     i64toi32_i32$4 = i64toi32_i32$4;
     $2_1 = i64toi32_i32$1;
     $2$hi = i64toi32_i32$4;
     i64toi32_i32$3 = i64toi32_i32$3 + 8 | 0;
     i64toi32_i32$4 = HEAPU32[i64toi32_i32$3 >> 2] | 0;
     i64toi32_i32$1 = (wasm2asm_i32$0 = i64toi32_i32$3, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
     i64toi32_i32$1 = i64toi32_i32$1;
     $436 = i64toi32_i32$4;
     $436$hi = i64toi32_i32$1;
    };
    i64toi32_i32$1 = $436$hi;
    i64toi32_i32$1 = $6$hi;
    i64toi32_i32$1 = $436$hi;
    i64toi32_i32$3 = $436;
    i64toi32_i32$4 = $6$hi;
    i64toi32_i32$2 = $6_1;
    i64toi32_i32$4 = i64toi32_i32$1 | i64toi32_i32$4 | 0;
    i64toi32_i32$4 = i64toi32_i32$4;
    $6_1 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
    $6$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $9$hi;
    i64toi32_i32$4 = i64toi32_i32$4;
    $493 = ($9_1 | i64toi32_i32$4 | 0 | 0) == (0 | 0);
    i64toi32_i32$4 = $4$hi;
    i64toi32_i32$4 = i64toi32_i32$4;
    i64toi32_i32$1 = $4_1;
    i64toi32_i32$3 = 4294967295;
    i64toi32_i32$2 = 4294967295;
    if ((i64toi32_i32$4 | 0) > (i64toi32_i32$3 | 0)) $272 = 1; else {
     if ((i64toi32_i32$4 | 0) >= (i64toi32_i32$3 | 0)) {
      if (i64toi32_i32$1 >>> 0 <= i64toi32_i32$2 >>> 0) $274 = 0; else $274 = 1;
      $276 = $274;
     } else $276 = 0;
     $272 = $276;
    }
    i64toi32_i32$1 = $4$hi;
    i64toi32_i32$1 = i64toi32_i32$1;
    i64toi32_i32$2 = $4_1;
    i64toi32_i32$4 = 2147483648;
    i64toi32_i32$3 = 0;
    if (((wasm2asm_i32$0 = $493, wasm2asm_i32$1 = $272, wasm2asm_i32$2 = (i64toi32_i32$2 | 0) == (i64toi32_i32$3 | 0) & (i64toi32_i32$1 | 0) == (i64toi32_i32$4 | 0) | 0, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) == (0 | 0)) {
     i64toi32_i32$2 = $6$hi;
     $500 = $6_1;
     $500$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $2$hi;
     i64toi32_i32$2 = i64toi32_i32$2;
     i64toi32_i32$3 = $2_1;
     i64toi32_i32$1 = 0;
     i64toi32_i32$4 = 1;
     i64toi32_i32$0 = i64toi32_i32$3 + i64toi32_i32$4 | 0;
     i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$1 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0) i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0;
     i64toi32_i32$5 = i64toi32_i32$5;
     $1_1 = i64toi32_i32$0;
     $1$hi = i64toi32_i32$5;
     i64toi32_i32$5 = i64toi32_i32$5;
     i64toi32_i32$5 = $2$hi;
     i64toi32_i32$5 = $1$hi;
     i64toi32_i32$2 = i64toi32_i32$0;
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$4 = $2_1;
     $505 = i64toi32_i32$5 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$4 >>> 0 | 0) | 0;
     i64toi32_i32$2 = 0;
     $506$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $500$hi;
     i64toi32_i32$4 = $500;
     i64toi32_i32$5 = $506$hi;
     i64toi32_i32$3 = $505;
     i64toi32_i32$1 = i64toi32_i32$4 + i64toi32_i32$3 | 0;
     i64toi32_i32$0 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
     if (i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0) i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0;
     i64toi32_i32$0 = i64toi32_i32$0;
     $6_1 = i64toi32_i32$1;
     $6$hi = i64toi32_i32$0;
     break label$1;
    }
    i64toi32_i32$0 = $9$hi;
    i64toi32_i32$0 = $4$hi;
    i64toi32_i32$0 = i64toi32_i32$0;
    i64toi32_i32$2 = $4_1;
    i64toi32_i32$4 = 2147483648;
    i64toi32_i32$3 = 0;
    i64toi32_i32$4 = i64toi32_i32$0 ^ i64toi32_i32$4 | 0;
    $510 = i64toi32_i32$2 ^ i64toi32_i32$3 | 0;
    $510$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $9$hi;
    i64toi32_i32$0 = $9_1;
    i64toi32_i32$2 = $510$hi;
    i64toi32_i32$3 = $510;
    i64toi32_i32$2 = i64toi32_i32$4 | i64toi32_i32$2 | 0;
    i64toi32_i32$2 = i64toi32_i32$2;
    i64toi32_i32$4 = i64toi32_i32$0 | i64toi32_i32$3 | 0;
    i64toi32_i32$0 = 0;
    i64toi32_i32$3 = 0;
    if ((i64toi32_i32$4 | 0) == (i64toi32_i32$3 | 0) & (i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) | 0) {
     i64toi32_i32$4 = $6$hi;
     $513 = $6_1;
     $513$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $2$hi;
     i64toi32_i32$4 = i64toi32_i32$4;
     i64toi32_i32$4 = i64toi32_i32$4;
     i64toi32_i32$3 = $2_1;
     i64toi32_i32$2 = 0;
     i64toi32_i32$0 = 1;
     i64toi32_i32$2 = i64toi32_i32$4 & i64toi32_i32$2 | 0;
     $516 = i64toi32_i32$3 & i64toi32_i32$0 | 0;
     $516$hi = i64toi32_i32$2;
     i64toi32_i32$2 = i64toi32_i32$4;
     i64toi32_i32$4 = i64toi32_i32$3;
     i64toi32_i32$3 = $516$hi;
     i64toi32_i32$0 = $516;
     i64toi32_i32$5 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
     i64toi32_i32$1 = i64toi32_i32$2 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$5 >>> 0 < i64toi32_i32$0 >>> 0) i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0;
     i64toi32_i32$1 = i64toi32_i32$1;
     $1_1 = i64toi32_i32$5;
     $1$hi = i64toi32_i32$1;
     i64toi32_i32$1 = i64toi32_i32$1;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$2 = i64toi32_i32$5;
     i64toi32_i32$4 = $2$hi;
     i64toi32_i32$0 = $2_1;
     $520 = i64toi32_i32$1 >>> 0 < i64toi32_i32$4 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0;
     i64toi32_i32$2 = 0;
     $521$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $513$hi;
     i64toi32_i32$0 = $513;
     i64toi32_i32$1 = $521$hi;
     i64toi32_i32$4 = $520;
     i64toi32_i32$3 = i64toi32_i32$0 + i64toi32_i32$4 | 0;
     i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$1 | 0;
     if (i64toi32_i32$3 >>> 0 < i64toi32_i32$4 >>> 0) i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0;
     i64toi32_i32$5 = i64toi32_i32$5;
     $6_1 = i64toi32_i32$3;
     $6$hi = i64toi32_i32$5;
     break label$1;
    }
    i64toi32_i32$5 = $2$hi;
    i64toi32_i32$5 = i64toi32_i32$5;
    $1_1 = $2_1;
    $1$hi = i64toi32_i32$5;
    break label$1;
   };
   i64toi32_i32$5 = 0;
   $1_1 = 0;
   $1$hi = i64toi32_i32$5;
  };
  i64toi32_i32$5 = $1$hi;
  i64toi32_i32$0 = $0_1;
  i64toi32_i32$5 = i64toi32_i32$5;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = $1_1;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = i64toi32_i32$5;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  i64toi32_i32$5 = $6$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$5 = i64toi32_i32$5;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = $6_1;
  HEAP32[(wasm2asm_i32$0 + 8 | 0) >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = i64toi32_i32$5;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 12 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 13 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 14 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 15 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  global$0 = $5_1 + 96 | 0;
 }
 
 function $34($0_1, $1_1, $1$hi, $2_1, $2$hi, $3_1, $3$hi, $4_1, $4$hi) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  $3$hi = $3$hi | 0;
  $4_1 = $4_1 | 0;
  $4$hi = $4$hi | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$3 = 0, i64toi32_i32$2 = 0, i64toi32_i32$1 = 0, $5_1 = 0, $14_1 = 0, $14$hi = 0, $19_1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  $5_1 = global$0 - 16 | 0;
  global$0 = $5_1;
  i64toi32_i32$0 = $1$hi;
  i64toi32_i32$0 = $2$hi;
  i64toi32_i32$0 = $3$hi;
  i64toi32_i32$0 = $4$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$2 = $4_1;
  i64toi32_i32$1 = 2147483648;
  i64toi32_i32$3 = 0;
  i64toi32_i32$1 = i64toi32_i32$0 ^ i64toi32_i32$1 | 0;
  $14_1 = i64toi32_i32$2 ^ i64toi32_i32$3 | 0;
  $14$hi = i64toi32_i32$1;
  i64toi32_i32$1 = $1$hi;
  i64toi32_i32$2 = $2$hi;
  i64toi32_i32$0 = $3$hi;
  i64toi32_i32$3 = $14$hi;
  $30($5_1 | 0, $1_1 | 0, $1$hi | 0, $2_1 | 0, i64toi32_i32$2 | 0, $3_1 | 0, i64toi32_i32$0 | 0, $14_1 | 0, i64toi32_i32$3 | 0);
  i64toi32_i32$2 = $5_1;
  i64toi32_i32$3 = HEAPU32[i64toi32_i32$2 >> 2] | 0;
  i64toi32_i32$0 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 4 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 5 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 6 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 7 | 0) >> 0] | 0 | 0) << 24);
  i64toi32_i32$0 = i64toi32_i32$0;
  $1_1 = i64toi32_i32$3;
  $1$hi = i64toi32_i32$0;
  i64toi32_i32$2 = i64toi32_i32$2;
  i64toi32_i32$0 = HEAPU32[(i64toi32_i32$2 + 8 | 0) >> 2] | 0;
  i64toi32_i32$3 = (wasm2asm_i32$0 = i64toi32_i32$2, HEAPU8[(wasm2asm_i32$0 + 12 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 13 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 14 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 15 | 0) >> 0] | 0 | 0) << 24);
  $19_1 = i64toi32_i32$0;
  i64toi32_i32$0 = $0_1;
  i64toi32_i32$3 = i64toi32_i32$3;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = $19_1;
  HEAP32[(wasm2asm_i32$0 + 8 | 0) >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = i64toi32_i32$3;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 12 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 13 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 14 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 15 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  i64toi32_i32$3 = $1$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$3 = i64toi32_i32$3;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = $1_1;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = i64toi32_i32$0;
  wasm2asm_i32$1 = i64toi32_i32$3;
  (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
  global$0 = i64toi32_i32$2 + 16 | 0;
 }
 
 function _ZN17compiler_builtins3int3mul3Mul3mul17h070e9a1c69faec5bE(var$0, var$0$hi, var$1, var$1$hi) {
  var$0 = var$0 | 0;
  var$0$hi = var$0$hi | 0;
  var$1 = var$1 | 0;
  var$1$hi = var$1$hi | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, i64toi32_i32$4 = 0, i64toi32_i32$2 = 0, var$2 = 0, i64toi32_i32$3 = 0, var$3 = 0, var$4 = 0, var$5 = 0, $21_1 = 0, $22_1 = 0, var$6 = 0, $24_1 = 0, $17_1 = 0, $18_1 = 0, $23_1 = 0, $29_1 = 0, $45 = 0, $56$hi = 0, $62$hi = 0;
  i64toi32_i32$0 = var$1$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  var$2 = var$1;
  var$4 = var$2 >>> 16 | 0;
  i64toi32_i32$0 = var$0$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  var$3 = var$0;
  var$5 = var$3 >>> 16 | 0;
  $17_1 = Math_imul(var$4, var$5);
  $18_1 = var$2;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$2 = var$3;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$1 = 0;
   $21_1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
   $21_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
  }
  i64toi32_i32$1 = i64toi32_i32$1;
  $23_1 = $17_1 + Math_imul($18_1, $21_1) | 0;
  i64toi32_i32$1 = var$1$hi;
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$0 = var$1;
  i64toi32_i32$2 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$2 = 0;
   $22_1 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$2 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
   $22_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$4 | 0) | 0;
  }
  i64toi32_i32$2 = i64toi32_i32$2;
  $29_1 = $23_1 + Math_imul($22_1, var$3) | 0;
  var$2 = var$2 & 65535 | 0;
  var$3 = var$3 & 65535 | 0;
  var$6 = Math_imul(var$2, var$3);
  var$2 = (var$6 >>> 16 | 0) + Math_imul(var$2, var$5) | 0;
  $45 = $29_1 + (var$2 >>> 16 | 0) | 0;
  var$2 = (var$2 & 65535 | 0) + Math_imul(var$4, var$3) | 0;
  i64toi32_i32$2 = 0;
  i64toi32_i32$2 = i64toi32_i32$2;
  i64toi32_i32$1 = $45 + (var$2 >>> 16 | 0) | 0;
  i64toi32_i32$0 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$0 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
   $24_1 = 0;
  } else {
   i64toi32_i32$0 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$4 | 0) | 0;
   $24_1 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
  }
  $56$hi = i64toi32_i32$0;
  i64toi32_i32$0 = 0;
  $62$hi = i64toi32_i32$0;
  i64toi32_i32$0 = $56$hi;
  i64toi32_i32$2 = $24_1;
  i64toi32_i32$1 = $62$hi;
  i64toi32_i32$3 = var$2 << 16 | 0 | (var$6 & 65535 | 0) | 0;
  i64toi32_i32$1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$2 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
  i64toi32_i32$HIGH_BITS = i64toi32_i32$1;
  return i64toi32_i32$2 | 0;
 }
 
 function _ZN17compiler_builtins3int4udiv10divmod_u6417h6026910b5ed08e40E(var$0, var$0$hi, var$1, var$1$hi) {
  var$0 = var$0 | 0;
  var$0$hi = var$0$hi | 0;
  var$1 = var$1 | 0;
  var$1$hi = var$1$hi | 0;
  var i64toi32_i32$2 = 0, i64toi32_i32$3 = 0, i64toi32_i32$1 = 0, i64toi32_i32$4 = 0, i64toi32_i32$0 = 0, i64toi32_i32$5 = 0, var$2 = 0, var$3 = 0, var$4 = 0, var$5 = 0, var$5$hi = 0, var$6 = 0, var$6$hi = 0, i64toi32_i32$6 = 0, $38 = 0, $39 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0, var$8$hi = 0, $46 = 0, $47 = 0, $48 = 0, $49 = 0, var$7$hi = 0, $50 = 0, $63$hi = 0, $65 = 0, $65$hi = 0, $66 = 0, $120$hi = 0, $129$hi = 0, $134$hi = 0, var$8 = 0, $140 = 0, $140$hi = 0, $142$hi = 0, $144 = 0, $144$hi = 0, $151 = 0, $151$hi = 0, $154$hi = 0, var$7 = 0, $165$hi = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  label$1 : {
   label$2 : {
    label$3 : {
     label$4 : {
      label$5 : {
       label$6 : {
        label$7 : {
         label$8 : {
          label$9 : {
           label$10 : {
            label$11 : {
             i64toi32_i32$0 = var$0$hi;
             i64toi32_i32$0 = i64toi32_i32$0;
             i64toi32_i32$2 = var$0;
             i64toi32_i32$1 = 0;
             i64toi32_i32$3 = 32;
             i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
             if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
              i64toi32_i32$1 = 0;
              $38 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
             } else {
              i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
              $38 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
             }
             i64toi32_i32$1 = i64toi32_i32$1;
             var$2 = $38;
             if (var$2) block : {
              i64toi32_i32$1 = var$1$hi;
              i64toi32_i32$1 = i64toi32_i32$1;
              var$3 = var$1;
              if ((var$3 | 0) == (0 | 0)) break label$11;
              i64toi32_i32$1 = var$1$hi;
              i64toi32_i32$1 = i64toi32_i32$1;
              i64toi32_i32$0 = var$1;
              i64toi32_i32$2 = 0;
              i64toi32_i32$3 = 32;
              i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
              if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
               i64toi32_i32$2 = 0;
               $39 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
              } else {
               i64toi32_i32$2 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
               $39 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$4 | 0) | 0;
              }
              i64toi32_i32$2 = i64toi32_i32$2;
              var$4 = $39;
              if ((var$4 | 0) == (0 | 0)) break label$9;
              var$2 = Math_clz32(var$4) - Math_clz32(var$2) | 0;
              if (var$2 >>> 0 <= 31 >>> 0) break label$8;
              break label$2;
             };
             i64toi32_i32$2 = var$1$hi;
             i64toi32_i32$2 = i64toi32_i32$2;
             i64toi32_i32$1 = var$1;
             i64toi32_i32$0 = 1;
             i64toi32_i32$3 = 0;
             if (i64toi32_i32$2 >>> 0 > i64toi32_i32$0 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$1 >>> 0 >= i64toi32_i32$3 >>> 0 | 0) | 0) break label$2;
             i64toi32_i32$1 = var$0$hi;
             i64toi32_i32$1 = i64toi32_i32$1;
             var$2 = var$0;
             i64toi32_i32$1 = var$1$hi;
             i64toi32_i32$1 = i64toi32_i32$1;
             var$3 = var$1;
             var$2 = (var$2 >>> 0) / (var$3 >>> 0) | 0;
             i64toi32_i32$1 = 0;
             i64toi32_i32$2 = 1024;
             i64toi32_i32$1 = i64toi32_i32$1;
             wasm2asm_i32$0 = i64toi32_i32$2;
             wasm2asm_i32$1 = var$0 - Math_imul(var$2, var$3) | 0;
             HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
             wasm2asm_i32$0 = i64toi32_i32$2;
             wasm2asm_i32$1 = i64toi32_i32$1;
             (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
             i64toi32_i32$1 = 0;
             i64toi32_i32$1 = i64toi32_i32$1;
             i64toi32_i32$2 = var$2;
             i64toi32_i32$HIGH_BITS = i64toi32_i32$1;
             return i64toi32_i32$2 | 0;
            };
            i64toi32_i32$2 = var$1$hi;
            i64toi32_i32$2 = i64toi32_i32$2;
            i64toi32_i32$3 = var$1;
            i64toi32_i32$1 = 0;
            i64toi32_i32$0 = 32;
            i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
            if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
             i64toi32_i32$1 = 0;
             $40 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
            } else {
             i64toi32_i32$1 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
             $40 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$4 | 0) | 0;
            }
            i64toi32_i32$1 = i64toi32_i32$1;
            var$3 = $40;
            i64toi32_i32$1 = var$0$hi;
            i64toi32_i32$1 = i64toi32_i32$1;
            if ((var$0 | 0) == (0 | 0)) break label$7;
            if ((var$3 | 0) == (0 | 0)) break label$6;
            var$4 = var$3 + 4294967295 | 0;
            if (var$4 & var$3 | 0) break label$6;
            i64toi32_i32$1 = 0;
            i64toi32_i32$1 = i64toi32_i32$1;
            i64toi32_i32$2 = var$4 & var$2 | 0;
            i64toi32_i32$3 = 0;
            i64toi32_i32$0 = 32;
            i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
            if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
             i64toi32_i32$3 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
             $41 = 0;
            } else {
             i64toi32_i32$3 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$4 | 0) | 0;
             $41 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
            }
            $63$hi = i64toi32_i32$3;
            i64toi32_i32$3 = var$0$hi;
            i64toi32_i32$3 = i64toi32_i32$3;
            i64toi32_i32$1 = var$0;
            i64toi32_i32$2 = 0;
            i64toi32_i32$0 = 4294967295;
            i64toi32_i32$2 = i64toi32_i32$3 & i64toi32_i32$2 | 0;
            $65 = i64toi32_i32$1 & i64toi32_i32$0 | 0;
            $65$hi = i64toi32_i32$2;
            i64toi32_i32$2 = $63$hi;
            i64toi32_i32$3 = $41;
            i64toi32_i32$1 = $65$hi;
            i64toi32_i32$0 = $65;
            i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
            $66 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
            i64toi32_i32$3 = 1024;
            i64toi32_i32$1 = i64toi32_i32$1;
            wasm2asm_i32$0 = i64toi32_i32$3;
            wasm2asm_i32$1 = $66;
            HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
            wasm2asm_i32$0 = i64toi32_i32$3;
            wasm2asm_i32$1 = i64toi32_i32$1;
            (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
            i64toi32_i32$1 = 0;
            i64toi32_i32$1 = i64toi32_i32$1;
            i64toi32_i32$3 = var$2 >>> ((__wasm_ctz_i32(var$3 | 0) | 0) & 31 | 0) | 0;
            i64toi32_i32$HIGH_BITS = i64toi32_i32$1;
            return i64toi32_i32$3 | 0;
           };
          };
          var$4 = var$3 + 4294967295 | 0;
          if ((var$4 & var$3 | 0 | 0) == (0 | 0)) break label$5;
          var$2 = (Math_clz32(var$3) + 33 | 0) - Math_clz32(var$2) | 0;
          var$3 = 0 - var$2 | 0;
          break label$3;
         };
         var$3 = 63 - var$2 | 0;
         var$2 = var$2 + 1 | 0;
         break label$3;
        };
        var$4 = (var$2 >>> 0) / (var$3 >>> 0) | 0;
        i64toi32_i32$3 = 0;
        i64toi32_i32$3 = i64toi32_i32$3;
        i64toi32_i32$2 = var$2 - Math_imul(var$4, var$3) | 0;
        i64toi32_i32$1 = 0;
        i64toi32_i32$0 = 32;
        i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
        if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
         i64toi32_i32$1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
         $42 = 0;
        } else {
         i64toi32_i32$1 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$4 | 0) | 0;
         $42 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
        }
        i64toi32_i32$2 = 1024;
        i64toi32_i32$1 = i64toi32_i32$1;
        wasm2asm_i32$0 = i64toi32_i32$2;
        wasm2asm_i32$1 = $42;
        HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
        wasm2asm_i32$0 = i64toi32_i32$2;
        wasm2asm_i32$1 = i64toi32_i32$1;
        (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
        i64toi32_i32$1 = 0;
        i64toi32_i32$1 = i64toi32_i32$1;
        i64toi32_i32$2 = var$4;
        i64toi32_i32$HIGH_BITS = i64toi32_i32$1;
        return i64toi32_i32$2 | 0;
       };
       var$2 = Math_clz32(var$3) - Math_clz32(var$2) | 0;
       if (var$2 >>> 0 < 31 >>> 0) break label$4;
       break label$2;
      };
      i64toi32_i32$2 = var$0$hi;
      i64toi32_i32$2 = i64toi32_i32$2;
      i64toi32_i32$2 = 0;
      i64toi32_i32$1 = 1024;
      i64toi32_i32$2 = i64toi32_i32$2;
      wasm2asm_i32$0 = i64toi32_i32$1;
      wasm2asm_i32$1 = var$4 & var$0 | 0;
      HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
      wasm2asm_i32$0 = i64toi32_i32$1;
      wasm2asm_i32$1 = i64toi32_i32$2;
      (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
      if ((var$3 | 0) == (1 | 0)) break label$1;
      i64toi32_i32$2 = var$0$hi;
      i64toi32_i32$2 = 0;
      $120$hi = i64toi32_i32$2;
      i64toi32_i32$2 = var$0$hi;
      i64toi32_i32$3 = var$0;
      i64toi32_i32$1 = $120$hi;
      i64toi32_i32$0 = __wasm_ctz_i32(var$3 | 0) | 0;
      i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
      if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
       i64toi32_i32$1 = 0;
       $43 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
      } else {
       i64toi32_i32$1 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
       $43 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$4 | 0) | 0;
      }
      i64toi32_i32$1 = i64toi32_i32$1;
      i64toi32_i32$3 = $43;
      i64toi32_i32$HIGH_BITS = i64toi32_i32$1;
      return i64toi32_i32$3 | 0;
     };
     var$3 = 63 - var$2 | 0;
     var$2 = var$2 + 1 | 0;
    };
    i64toi32_i32$3 = var$0$hi;
    i64toi32_i32$3 = 0;
    $129$hi = i64toi32_i32$3;
    i64toi32_i32$3 = var$0$hi;
    i64toi32_i32$2 = var$0;
    i64toi32_i32$1 = $129$hi;
    i64toi32_i32$0 = var$2 & 63 | 0;
    i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
     i64toi32_i32$1 = 0;
     $44 = i64toi32_i32$3 >>> i64toi32_i32$4 | 0;
    } else {
     i64toi32_i32$1 = i64toi32_i32$3 >>> i64toi32_i32$4 | 0;
     $44 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$3 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
    }
    i64toi32_i32$1 = i64toi32_i32$1;
    var$5 = $44;
    var$5$hi = i64toi32_i32$1;
    i64toi32_i32$1 = var$0$hi;
    i64toi32_i32$1 = 0;
    $134$hi = i64toi32_i32$1;
    i64toi32_i32$1 = var$0$hi;
    i64toi32_i32$3 = var$0;
    i64toi32_i32$2 = $134$hi;
    i64toi32_i32$0 = var$3 & 63 | 0;
    i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
     i64toi32_i32$2 = i64toi32_i32$3 << i64toi32_i32$4 | 0;
     $45 = 0;
    } else {
     i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$4 | 0) | 0;
     $45 = i64toi32_i32$3 << i64toi32_i32$4 | 0;
    }
    i64toi32_i32$2 = i64toi32_i32$2;
    var$0 = $45;
    var$0$hi = i64toi32_i32$2;
    label$13 : {
     if (var$2) block3 : {
      i64toi32_i32$2 = var$1$hi;
      i64toi32_i32$2 = i64toi32_i32$2;
      i64toi32_i32$1 = var$1;
      i64toi32_i32$3 = 4294967295;
      i64toi32_i32$0 = 4294967295;
      i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$0 | 0;
      i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$3 | 0;
      if (i64toi32_i32$4 >>> 0 < i64toi32_i32$0 >>> 0) i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0;
      i64toi32_i32$5 = i64toi32_i32$5;
      var$8 = i64toi32_i32$4;
      var$8$hi = i64toi32_i32$5;
      label$15 : do {
       i64toi32_i32$5 = var$5$hi;
       i64toi32_i32$5 = i64toi32_i32$5;
       i64toi32_i32$2 = var$5;
       i64toi32_i32$1 = 0;
       i64toi32_i32$0 = 1;
       i64toi32_i32$3 = i64toi32_i32$0 & 31 | 0;
       if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
        i64toi32_i32$1 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
        $46 = 0;
       } else {
        i64toi32_i32$1 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$3 | 0) | 0;
        $46 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
       }
       $140 = $46;
       $140$hi = i64toi32_i32$1;
       i64toi32_i32$1 = var$0$hi;
       i64toi32_i32$1 = i64toi32_i32$1;
       i64toi32_i32$5 = var$0;
       i64toi32_i32$2 = 0;
       i64toi32_i32$0 = 63;
       i64toi32_i32$3 = i64toi32_i32$0 & 31 | 0;
       if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
        i64toi32_i32$2 = 0;
        $47 = i64toi32_i32$1 >>> i64toi32_i32$3 | 0;
       } else {
        i64toi32_i32$2 = i64toi32_i32$1 >>> i64toi32_i32$3 | 0;
        $47 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$3 | 0) | 0;
       }
       $142$hi = i64toi32_i32$2;
       i64toi32_i32$2 = $140$hi;
       i64toi32_i32$1 = $140;
       i64toi32_i32$5 = $142$hi;
       i64toi32_i32$0 = $47;
       i64toi32_i32$5 = i64toi32_i32$2 | i64toi32_i32$5 | 0;
       i64toi32_i32$5 = i64toi32_i32$5;
       var$5 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
       var$5$hi = i64toi32_i32$5;
       i64toi32_i32$5 = i64toi32_i32$5;
       $144 = var$5;
       $144$hi = i64toi32_i32$5;
       i64toi32_i32$5 = var$8$hi;
       i64toi32_i32$5 = var$5$hi;
       i64toi32_i32$5 = var$8$hi;
       i64toi32_i32$2 = var$8;
       i64toi32_i32$1 = var$5$hi;
       i64toi32_i32$0 = var$5;
       i64toi32_i32$3 = i64toi32_i32$2 - i64toi32_i32$0 | 0;
       i64toi32_i32$6 = i64toi32_i32$2 >>> 0 < i64toi32_i32$0 >>> 0;
       i64toi32_i32$4 = i64toi32_i32$6 + i64toi32_i32$1 | 0;
       i64toi32_i32$4 = i64toi32_i32$5 - i64toi32_i32$4 | 0;
       i64toi32_i32$4 = i64toi32_i32$4;
       i64toi32_i32$5 = i64toi32_i32$3;
       i64toi32_i32$2 = 0;
       i64toi32_i32$0 = 63;
       i64toi32_i32$1 = i64toi32_i32$0 & 31 | 0;
       if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
        i64toi32_i32$2 = i64toi32_i32$4 >> 31 | 0;
        $48 = i64toi32_i32$4 >> i64toi32_i32$1 | 0;
       } else {
        i64toi32_i32$2 = i64toi32_i32$4 >> i64toi32_i32$1 | 0;
        $48 = (((1 << i64toi32_i32$1 | 0) - 1 | 0) & i64toi32_i32$4 | 0) << (32 - i64toi32_i32$1 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$1 | 0) | 0;
       }
       i64toi32_i32$2 = i64toi32_i32$2;
       var$6 = $48;
       var$6$hi = i64toi32_i32$2;
       i64toi32_i32$2 = i64toi32_i32$2;
       i64toi32_i32$2 = var$1$hi;
       i64toi32_i32$2 = var$6$hi;
       i64toi32_i32$4 = var$6;
       i64toi32_i32$5 = var$1$hi;
       i64toi32_i32$0 = var$1;
       i64toi32_i32$5 = i64toi32_i32$2 & i64toi32_i32$5 | 0;
       $151 = i64toi32_i32$4 & i64toi32_i32$0 | 0;
       $151$hi = i64toi32_i32$5;
       i64toi32_i32$5 = $144$hi;
       i64toi32_i32$2 = $144;
       i64toi32_i32$4 = $151$hi;
       i64toi32_i32$0 = $151;
       i64toi32_i32$1 = i64toi32_i32$2 - i64toi32_i32$0 | 0;
       i64toi32_i32$6 = i64toi32_i32$2 >>> 0 < i64toi32_i32$0 >>> 0;
       i64toi32_i32$3 = i64toi32_i32$6 + i64toi32_i32$4 | 0;
       i64toi32_i32$3 = i64toi32_i32$5 - i64toi32_i32$3 | 0;
       i64toi32_i32$3 = i64toi32_i32$3;
       var$5 = i64toi32_i32$1;
       var$5$hi = i64toi32_i32$3;
       i64toi32_i32$3 = var$0$hi;
       i64toi32_i32$3 = i64toi32_i32$3;
       i64toi32_i32$5 = var$0;
       i64toi32_i32$2 = 0;
       i64toi32_i32$0 = 1;
       i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
       if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
        i64toi32_i32$2 = i64toi32_i32$5 << i64toi32_i32$4 | 0;
        $49 = 0;
       } else {
        i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$4 | 0) | 0;
        $49 = i64toi32_i32$5 << i64toi32_i32$4 | 0;
       }
       $154$hi = i64toi32_i32$2;
       i64toi32_i32$2 = var$7$hi;
       i64toi32_i32$2 = $154$hi;
       i64toi32_i32$3 = $49;
       i64toi32_i32$5 = var$7$hi;
       i64toi32_i32$0 = var$7;
       i64toi32_i32$5 = i64toi32_i32$2 | i64toi32_i32$5 | 0;
       i64toi32_i32$5 = i64toi32_i32$5;
       var$0 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
       var$0$hi = i64toi32_i32$5;
       i64toi32_i32$5 = var$6$hi;
       i64toi32_i32$5 = i64toi32_i32$5;
       i64toi32_i32$2 = var$6;
       i64toi32_i32$3 = 0;
       i64toi32_i32$0 = 1;
       i64toi32_i32$3 = i64toi32_i32$5 & i64toi32_i32$3 | 0;
       i64toi32_i32$3 = i64toi32_i32$3;
       var$6 = i64toi32_i32$2 & i64toi32_i32$0 | 0;
       var$6$hi = i64toi32_i32$3;
       i64toi32_i32$3 = i64toi32_i32$3;
       i64toi32_i32$3 = i64toi32_i32$3;
       var$7 = var$6;
       var$7$hi = i64toi32_i32$3;
       var$2 = var$2 + 4294967295 | 0;
       if (var$2) continue label$15;
       break label$15;
      } while (1);
      break label$13;
     };
    };
    i64toi32_i32$3 = var$5$hi;
    i64toi32_i32$2 = 1024;
    i64toi32_i32$3 = i64toi32_i32$3;
    wasm2asm_i32$0 = i64toi32_i32$2;
    wasm2asm_i32$1 = var$5;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    wasm2asm_i32$0 = i64toi32_i32$2;
    wasm2asm_i32$1 = i64toi32_i32$3;
    (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
    i64toi32_i32$3 = var$0$hi;
    i64toi32_i32$3 = i64toi32_i32$3;
    i64toi32_i32$5 = var$0;
    i64toi32_i32$2 = 0;
    i64toi32_i32$0 = 1;
    i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
     i64toi32_i32$2 = i64toi32_i32$5 << i64toi32_i32$4 | 0;
     $50 = 0;
    } else {
     i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$4 | 0) | 0;
     $50 = i64toi32_i32$5 << i64toi32_i32$4 | 0;
    }
    $165$hi = i64toi32_i32$2;
    i64toi32_i32$2 = var$6$hi;
    i64toi32_i32$2 = $165$hi;
    i64toi32_i32$3 = $50;
    i64toi32_i32$5 = var$6$hi;
    i64toi32_i32$0 = var$6;
    i64toi32_i32$5 = i64toi32_i32$2 | i64toi32_i32$5 | 0;
    i64toi32_i32$5 = i64toi32_i32$5;
    i64toi32_i32$3 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
    i64toi32_i32$HIGH_BITS = i64toi32_i32$5;
    return i64toi32_i32$3 | 0;
   };
   i64toi32_i32$3 = var$0$hi;
   i64toi32_i32$5 = 1024;
   i64toi32_i32$3 = i64toi32_i32$3;
   wasm2asm_i32$0 = i64toi32_i32$5;
   wasm2asm_i32$1 = var$0;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = i64toi32_i32$5;
   wasm2asm_i32$1 = i64toi32_i32$3;
   (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 4 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 5 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 6 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 7 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
   i64toi32_i32$3 = 0;
   var$0 = 0;
   var$0$hi = i64toi32_i32$3;
  };
  i64toi32_i32$3 = var$0$hi;
  i64toi32_i32$3 = i64toi32_i32$3;
  i64toi32_i32$3 = i64toi32_i32$3;
  i64toi32_i32$3 = i64toi32_i32$3;
  i64toi32_i32$5 = var$0;
  i64toi32_i32$HIGH_BITS = i64toi32_i32$3;
  return i64toi32_i32$5 | 0;
 }
 
 function __wasm_i64_mul(var$0, var$0$hi, var$1, var$1$hi) {
  var$0 = var$0 | 0;
  var$0$hi = var$0$hi | 0;
  var$1 = var$1 | 0;
  var$1$hi = var$1$hi | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$1 = 0;
  i64toi32_i32$0 = var$0$hi;
  i64toi32_i32$0 = var$1$hi;
  i64toi32_i32$0 = var$0$hi;
  i64toi32_i32$1 = var$1$hi;
  i64toi32_i32$1 = _ZN17compiler_builtins3int3mul3Mul3mul17h070e9a1c69faec5bE(var$0 | 0, i64toi32_i32$0 | 0, var$1 | 0, i64toi32_i32$1 | 0) | 0;
  i64toi32_i32$0 = i64toi32_i32$HIGH_BITS;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$HIGH_BITS = i64toi32_i32$0;
  return i64toi32_i32$1 | 0;
 }
 
 function __wasm_i64_udiv(var$0, var$0$hi, var$1, var$1$hi) {
  var$0 = var$0 | 0;
  var$0$hi = var$0$hi | 0;
  var$1 = var$1 | 0;
  var$1$hi = var$1$hi | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$1 = 0;
  i64toi32_i32$0 = var$0$hi;
  i64toi32_i32$0 = var$1$hi;
  i64toi32_i32$0 = var$0$hi;
  i64toi32_i32$1 = var$1$hi;
  i64toi32_i32$1 = _ZN17compiler_builtins3int4udiv10divmod_u6417h6026910b5ed08e40E(var$0 | 0, i64toi32_i32$0 | 0, var$1 | 0, i64toi32_i32$1 | 0) | 0;
  i64toi32_i32$0 = i64toi32_i32$HIGH_BITS;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$HIGH_BITS = i64toi32_i32$0;
  return i64toi32_i32$1 | 0;
 }
 
 function __wasm_ctz_i32(var$0) {
  var$0 = var$0 | 0;
  if (var$0) return 31 - Math_clz32((var$0 + 4294967295 | 0) ^ var$0 | 0) | 0 | 0;
  return 32 | 0;
 }
 
 var FUNCTION_TABLE_ii = [$4, $4, $4, $4, $4, $4, $4, $4];
 var FUNCTION_TABLE_iiii = [$5, $5, $5, $6, $5, $5, $5, $5];
 var FUNCTION_TABLE_iiiii = [$7, $7, $7, $7, $7, $7, $7, $7];
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
  main: $0, 
  writev_c: $1
 };
}
