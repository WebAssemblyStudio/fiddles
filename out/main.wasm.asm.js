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
 var __syscall3 = env.__syscall3;
 var __syscall1 = env.__syscall1;
 var __syscall5 = env.__syscall5;
 var global$0 = 67760;
 var global$1 = 67760;
 var global$2 = 2216;
 var i64toi32_i32$HIGH_BITS = 0;
 function main() {
  puts(1024 | 0) | 0;
  return 0 | 0;
 }
 
 function writev_c($0, $1, $2) {
  $0 = $0 | 0;
  $1 = $1 | 0;
  $2 = $2 | 0;
  var $4 = 0, $5 = 0, $6 = 0, $3 = 0, $7 = 0;
  if (($2 | 0) >= (1 | 0)) {
   $0 = 0;
   label$2 : do {
    $5 = 0;
    $6 = $1 + ($0 << 3 | 0) | 0;
    if (HEAPU32[($6 + 4 | 0) >> 2] | 0) {
     $7 = $6 + 4 | 0;
     $4 = 0;
     label$4 : do {
      putc_js(HEAP8[((HEAPU32[$6 >> 2] | 0) + $4 | 0) >> 0] | 0 | 0) | 0;
      $4 = $4 + 1 | 0;
      $5 = HEAPU32[$7 >> 2] | 0;
      if ($4 >>> 0 < $5 >>> 0) continue label$4;
      break label$4;
     } while (1);
    }
    $3 = $5 + $3 | 0;
    $0 = $0 + 1 | 0;
    if (($0 | 0) != ($2 | 0)) continue label$2;
    break label$2;
   } while (1);
   return $3 | 0;
  }
  return 0 | 0;
 }
 
 function __lockfile($0) {
  $0 = $0 | 0;
  var $1 = 0, $2 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0;
  $2 = HEAPU32[27 >> 2] | 0;
  if (((HEAPU32[($0 + 76 | 0) >> 2] | 0) & 3221225471 | 0 | 0) != ($2 | 0)) {
   $0 = $0 + 76 | 0;
   label$2 : {
    label$3 : do {
     $1 = HEAPU32[$0 >> 2] | 0;
     if (($1 | 0) == (0 | 0)) break label$2;
     if ((HEAPU32[$0 >> 2] | 0 | 0) != ($1 | 0)) continue label$3;
     break label$3;
    } while (1);
    wasm2asm_i32$0 = $0;
    wasm2asm_i32$1 = $1 | 1073741824 | 0;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    $1 = HEAPU32[$0 >> 2] | 0;
    if ($1) label$5 : do {
     if ((__syscall3(240 | 0, $0 | 0, 128 | 0, $1 | 0) | 0 | 0) == (4294967258 | 0)) __syscall3(240 | 0, $0 | 0, 0 | 0, $1 | 0) | 0;
     $1 = HEAPU32[$0 >> 2] | 0;
     if ($1) continue label$5;
     break label$5;
    } while (1);
    $2 = $2 | 1073741824 | 0;
   };
   wasm2asm_i32$0 = $0;
   wasm2asm_i32$1 = $2;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   $1 = 1;
  }
  return $1 | 0;
 }
 
 function __unlockfile($0) {
  $0 = $0 | 0;
  var $1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0;
  $0 = $0 + 76 | 0;
  label$1 : do {
   $1 = HEAPU32[$0 >> 2] | 0;
   if (($1 | 0) != (HEAPU32[$0 >> 2] | 0 | 0)) continue label$1;
   break label$1;
  } while (1);
  wasm2asm_i32$0 = $0;
  wasm2asm_i32$1 = 0;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  label$2 : {
   if (($1 & 1073741824 | 0 | 0) == (0 | 0)) break label$2;
   if ((__syscall3(240 | 0, $0 | 0, 129 | 0, 1 | 0) | 0 | 0) != (4294967258 | 0)) break label$2;
   __syscall3(240 | 0, $0 | 0, 1 | 0, 1 | 0) | 0;
  };
 }
 
 function __towrite($0) {
  $0 = $0 | 0;
  var $1 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  $1 = HEAPU8[($0 + 74 | 0) >> 0] | 0;
  wasm2asm_i32$0 = $0;
  wasm2asm_i32$1 = $1 + 4294967295 | 0 | $1 | 0;
  HEAP8[(wasm2asm_i32$0 + 74 | 0) >> 0] = wasm2asm_i32$1;
  $1 = HEAPU32[$0 >> 2] | 0;
  if (($1 & 8 | 0 | 0) == (0 | 0)) {
   wasm2asm_i32$0 = $0;
   wasm2asm_i32$1 = 0;
   HEAP32[(wasm2asm_i32$0 + 4 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0;
   wasm2asm_i32$1 = 0;
   (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 8 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 9 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 10 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 11 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
   $1 = HEAPU32[($0 + 44 | 0) >> 2] | 0;
   wasm2asm_i32$0 = $0;
   wasm2asm_i32$1 = $1;
   HEAP32[(wasm2asm_i32$0 + 28 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0;
   wasm2asm_i32$1 = $1;
   HEAP32[(wasm2asm_i32$0 + 20 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0;
   wasm2asm_i32$1 = $1 + (HEAPU32[($0 + 48 | 0) >> 2] | 0) | 0;
   HEAP32[(wasm2asm_i32$0 + 16 | 0) >> 2] = wasm2asm_i32$1;
   return 0 | 0;
  }
  wasm2asm_i32$0 = $0;
  wasm2asm_i32$1 = $1 | 32 | 0;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  return 4294967295 | 0;
 }
 
 function fwrite($0, $1, $2, $3) {
  $0 = $0 | 0;
  $1 = $1 | 0;
  $2 = $2 | 0;
  $3 = $3 | 0;
  var $4 = 0, $5 = 0, $8 = 0, $9 = 0, $10 = 0, $6 = 0, $11 = 0, $84 = 0, $7 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0, wasm2asm_i32$4 = 0;
  if ((HEAPU32[($3 + 76 | 0) >> 2] | 0 | 0) >= (0 | 0)) $7 = (__lockfile($3 | 0) | 0 | 0) != (0 | 0);
  $5 = Math_imul($2, $1);
  label$2 : {
   label$3 : {
    label$4 : {
     label$5 : {
      label$6 : {
       $4 = HEAPU32[($3 + 16 | 0) >> 2] | 0;
       if ($4) {
        $8 = HEAPU32[($3 + 20 | 0) >> 2] | 0;
        if (($4 - $8 | 0) >>> 0 >= $5 >>> 0) break label$6;
        break label$4;
       }
       $4 = 0;
       if (__towrite($3 | 0) | 0) break label$3;
       $8 = HEAPU32[($3 + 20 | 0) >> 2] | 0;
       if (((HEAPU32[($3 + 16 | 0) >> 2] | 0) - $8 | 0) >>> 0 < $5 >>> 0) break label$4;
      };
      label$8 : {
       label$9 : {
        if ((HEAP8[($3 + 75 | 0) >> 0] | 0 | 0) < (0 | 0)) break label$9;
        $11 = $0 + $5 | 0;
        $4 = 0;
        label$10 : do {
         if (($5 + $4 | 0 | 0) == (0 | 0)) break label$9;
         $9 = $11 + $4 | 0;
         $10 = $4 + 4294967295 | 0;
         $4 = $10;
         if ((HEAPU8[($9 + 4294967295 | 0) >> 0] | 0 | 0) != (10 | 0)) continue label$10;
         break label$10;
        } while (1);
        $6 = ($5 + $10 | 0) + 1 | 0;
        wasm2asm_i32$2 = $3;
        wasm2asm_i32$3 = $0;
        wasm2asm_i32$4 = $6;
        wasm2asm_i32$1 = HEAPU32[($3 + 36 | 0) >> 2] | 0;
        wasm2asm_i32$0 = FUNCTION_TABLE_iiii[wasm2asm_i32$1 & 7](wasm2asm_i32$2 | 0, wasm2asm_i32$3 | 0, wasm2asm_i32$4 | 0) | 0;
        $4 = wasm2asm_i32$0;
        if ($4 >>> 0 < $6 >>> 0) break label$3;
        $0 = ($11 + $10 | 0) + 1 | 0;
        $8 = HEAPU32[($3 + 20 | 0) >> 2] | 0;
        $84 = $10 ^ 4294967295 | 0;
        break label$8;
       };
       $84 = $5;
      };
      $4 = $84;
      memcpy($8 | 0, $0 | 0, $4 | 0) | 0;
      $9 = $3 + 20 | 0;
      wasm2asm_i32$0 = $9;
      wasm2asm_i32$1 = (HEAPU32[$9 >> 2] | 0) + $4 | 0;
      HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
      $4 = $6 + $4 | 0;
     };
     break label$3;
    };
    wasm2asm_i32$4 = $3;
    wasm2asm_i32$3 = $0;
    wasm2asm_i32$2 = $5;
    wasm2asm_i32$1 = HEAPU32[($3 + 36 | 0) >> 2] | 0;
    wasm2asm_i32$0 = FUNCTION_TABLE_iiii[wasm2asm_i32$1 & 7](wasm2asm_i32$4 | 0, wasm2asm_i32$3 | 0, wasm2asm_i32$2 | 0) | 0;
    $4 = wasm2asm_i32$0;
   };
   if (($7 | 0) == (0 | 0)) break label$2;
   __unlockfile($3 | 0);
  };
  if (($4 | 0) == ($5 | 0)) return (wasm2asm_i32$0 = $2, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = $1, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0;
  return ($4 >>> 0) / ($1 >>> 0) | 0 | 0;
 }
 
 function __overflow($0, $1) {
  $0 = $0 | 0;
  $1 = $1 | 0;
  var $2 = 0, $3 = 0, $4 = 0, $21 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0, wasm2asm_i32$4 = 0, wasm2asm_i32$5 = 0, wasm2asm_i32$6 = 0;
  $3 = global$0 - 16 | 0;
  global$0 = $3;
  wasm2asm_i32$0 = $3;
  wasm2asm_i32$1 = $1;
  HEAP8[(wasm2asm_i32$0 + 15 | 0) >> 0] = wasm2asm_i32$1;
  label$1 : {
   label$2 : {
    label$3 : {
     $2 = HEAPU32[($0 + 16 | 0) >> 2] | 0;
     if ($2) {
      $4 = HEAPU32[($0 + 20 | 0) >> 2] | 0;
      if ($4 >>> 0 >= $2 >>> 0) break label$2;
      break label$3;
     }
     $2 = 4294967295;
     $21 = $2;
     if (__towrite($0 | 0) | 0) break label$1;
     $4 = HEAPU32[($0 + 20 | 0) >> 2] | 0;
     if ($4 >>> 0 >= (HEAPU32[($0 + 16 | 0) >> 2] | 0) >>> 0) break label$2;
    };
    $2 = $1 & 255 | 0;
    if (($2 | 0) == (HEAP8[($0 + 75 | 0) >> 0] | 0 | 0)) break label$2;
    wasm2asm_i32$0 = $0 + 20 | 0;
    wasm2asm_i32$1 = $4 + 1 | 0;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    wasm2asm_i32$0 = $4;
    wasm2asm_i32$1 = $1;
    HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
    global$0 = $3 + 16 | 0;
    return $2 | 0;
   };
   $2 = 4294967295;
   $21 = $2;
   wasm2asm_i32$4 = $0;
   wasm2asm_i32$5 = $3 + 15 | 0;
   wasm2asm_i32$6 = 1;
   wasm2asm_i32$3 = HEAPU32[($0 + 36 | 0) >> 2] | 0;
   wasm2asm_i32$1 = FUNCTION_TABLE_iiii[wasm2asm_i32$3 & 7](wasm2asm_i32$4 | 0, wasm2asm_i32$5 | 0, wasm2asm_i32$6 | 0) | 0;
   wasm2asm_i32$2 = 1;
   wasm2asm_i32$0 = wasm2asm_i32$1 != wasm2asm_i32$2;
   if (wasm2asm_i32$0) break label$1;
   $21 = HEAPU8[($3 + 15 | 0) >> 0] | 0;
  };
  $2 = $21;
  global$0 = $3 + 16 | 0;
  return $2 | 0;
 }
 
 function puts($0) {
  $0 = $0 | 0;
  var $1 = 0, $2 = 0, $3 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0;
  $1 = HEAPU32[1036 >> 2] | 0;
  if ((HEAPU32[($1 + 76 | 0) >> 2] | 0 | 0) >= (0 | 0)) $2 = __lockfile($1 | 0) | 0;
  label$2 : {
   label$3 : {
    $3 = strlen($0 | 0) | 0;
    if (((wasm2asm_i32$0 = 4294967295, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = ($3 | 0) != (fwrite($0 | 0, 1 | 0, $3 | 0, $1 | 0) | 0 | 0), wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0) >= (0 | 0)) {
     label$5 : {
      if ((HEAPU8[($1 + 75 | 0) >> 0] | 0 | 0) == (10 | 0)) break label$5;
      $0 = HEAPU32[($1 + 20 | 0) >> 2] | 0;
      if ($0 >>> 0 >= (HEAPU32[($1 + 16 | 0) >> 2] | 0) >>> 0) break label$5;
      wasm2asm_i32$0 = $1 + 20 | 0;
      wasm2asm_i32$1 = $0 + 1 | 0;
      HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
      wasm2asm_i32$0 = $0;
      wasm2asm_i32$1 = 10;
      HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
      $0 = 0;
      if ($2) break label$3;
      break label$2;
     };
     $0 = (__overflow($1 | 0, 10 | 0) | 0) >> 31 | 0;
     if (($2 | 0) == (0 | 0)) break label$2;
     break label$3;
    }
    $0 = 4294967295;
    if (($2 | 0) == (0 | 0)) break label$2;
   };
   __unlockfile($1 | 0);
  };
  return $0 | 0;
 }
 
 function __syscall_ret($0) {
  $0 = $0 | 0;
  var wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0;
  if ($0 >>> 0 >= 4294963201 >>> 0) {
   wasm2asm_i32$0 = 31;
   wasm2asm_i32$1 = 0 - $0 | 0;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   $0 = 4294967295;
  }
  return $0 | 0;
 }
 
 function __stdio_close($0) {
  $0 = $0 | 0;
  return __syscall_ret(__syscall1(6 | 0, HEAPU32[($0 + 60 | 0) >> 2] | 0 | 0) | 0 | 0) | 0 | 0;
 }
 
 function __stdio_write($0, $1, $2) {
  $0 = $0 | 0;
  $1 = $1 | 0;
  $2 = $2 | 0;
  var $4 = 0, $3 = 0, $8 = 0, $5 = 0, $6 = 0, $7 = 0, $9 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  $3 = global$0 - 16 | 0;
  global$0 = $3;
  wasm2asm_i32$0 = $3;
  wasm2asm_i32$1 = $1;
  HEAP32[(wasm2asm_i32$0 + 8 | 0) >> 2] = wasm2asm_i32$1;
  wasm2asm_i32$0 = $3;
  wasm2asm_i32$1 = $2;
  HEAP32[(wasm2asm_i32$0 + 12 | 0) >> 2] = wasm2asm_i32$1;
  $1 = HEAPU32[($0 + 28 | 0) >> 2] | 0;
  wasm2asm_i32$0 = $3;
  wasm2asm_i32$1 = $1;
  HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
  $1 = (HEAPU32[($0 + 20 | 0) >> 2] | 0) - $1 | 0;
  wasm2asm_i32$0 = $3;
  wasm2asm_i32$1 = $1;
  HEAP32[(wasm2asm_i32$0 + 4 | 0) >> 2] = wasm2asm_i32$1;
  $6 = 2;
  label$1 : {
   label$2 : {
    $7 = $1 + $2 | 0;
    $4 = __syscall_ret(__syscall3(146 | 0, HEAPU32[($0 + 60 | 0) >> 2] | 0 | 0, $3 | 0, 2 | 0) | 0 | 0) | 0;
    if (($7 | 0) != ($4 | 0)) {
     $1 = $3;
     $9 = $0 + 60 | 0;
     label$4 : do {
      if (($4 | 0) <= (4294967295 | 0)) break label$2;
      $8 = HEAPU32[($1 + 4 | 0) >> 2] | 0;
      $5 = $4 >>> 0 > $8 >>> 0;
      $1 = (wasm2asm_i32$0 = $1 + 8 | 0, wasm2asm_i32$1 = $1, wasm2asm_i32$2 = $5, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1);
      $8 = $4 - (wasm2asm_i32$0 = $8, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = $5, wasm2asm_i32$2 ? wasm2asm_i32$0 : wasm2asm_i32$1) | 0;
      wasm2asm_i32$0 = $1;
      wasm2asm_i32$1 = (HEAPU32[$1 >> 2] | 0) + $8 | 0;
      HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
      wasm2asm_i32$0 = $1;
      wasm2asm_i32$1 = (HEAPU32[($1 + 4 | 0) >> 2] | 0) - $8 | 0;
      HEAP32[(wasm2asm_i32$0 + 4 | 0) >> 2] = wasm2asm_i32$1;
      $7 = $7 - $4 | 0;
      $6 = $6 - $5 | 0;
      $5 = __syscall_ret(__syscall3(146 | 0, HEAPU32[$9 >> 2] | 0 | 0, $1 | 0, $6 | 0) | 0 | 0) | 0;
      $4 = $5;
      if (($7 | 0) != ($4 | 0)) continue label$4;
      break label$4;
     } while (1);
    }
    $1 = HEAPU32[($0 + 44 | 0) >> 2] | 0;
    wasm2asm_i32$0 = $0 + 28 | 0;
    wasm2asm_i32$1 = $1;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    wasm2asm_i32$0 = $0 + 20 | 0;
    wasm2asm_i32$1 = $1;
    HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
    wasm2asm_i32$0 = $0;
    wasm2asm_i32$1 = $1 + (HEAPU32[($0 + 48 | 0) >> 2] | 0) | 0;
    HEAP32[(wasm2asm_i32$0 + 16 | 0) >> 2] = wasm2asm_i32$1;
    $4 = $2;
    break label$1;
   };
   wasm2asm_i32$0 = $0;
   wasm2asm_i32$1 = 0;
   HEAP32[(wasm2asm_i32$0 + 16 | 0) >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0;
   wasm2asm_i32$1 = 0;
   (wasm2asm_i32$2 = wasm2asm_i32$0, wasm2asm_i32$3 = wasm2asm_i32$1), ((HEAP8[(wasm2asm_i32$2 + 20 | 0) >> 0] = wasm2asm_i32$3 & 255 | 0, HEAP8[(wasm2asm_i32$2 + 21 | 0) >> 0] = (wasm2asm_i32$3 >>> 8 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 22 | 0) >> 0] = (wasm2asm_i32$3 >>> 16 | 0) & 255 | 0), HEAP8[(wasm2asm_i32$2 + 23 | 0) >> 0] = (wasm2asm_i32$3 >>> 24 | 0) & 255 | 0;
   $4 = 0;
   wasm2asm_i32$0 = $0 + 28 | 0;
   wasm2asm_i32$1 = 0;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   wasm2asm_i32$0 = $0;
   wasm2asm_i32$1 = HEAPU32[$0 >> 2] | 0 | 32 | 0;
   HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
   if (($6 | 0) == (2 | 0)) break label$1;
   $1 = HEAPU32[($1 + 4 | 0) >> 2] | 0;
   global$0 = $3 + 16 | 0;
   return $2 - $1 | 0 | 0;
  };
  global$0 = $3 + 16 | 0;
  return $4 | 0;
 }
 
 function __stdout_write($0, $1, $2) {
  $0 = $0 | 0;
  $1 = $1 | 0;
  $2 = $2 | 0;
  var $3 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0;
  $3 = global$0 - 16 | 0;
  global$0 = $3;
  wasm2asm_i32$0 = $0;
  wasm2asm_i32$1 = 1;
  HEAP32[(wasm2asm_i32$0 + 36 | 0) >> 2] = wasm2asm_i32$1;
  label$1 : {
   if ((HEAPU8[$0 >> 0] | 0) & 64 | 0) break label$1;
   if ((__syscall3(54 | 0, HEAPU32[($0 + 60 | 0) >> 2] | 0 | 0, 21523 | 0, $3 + 8 | 0 | 0) | 0 | 0) == (0 | 0)) break label$1;
   wasm2asm_i32$0 = $0;
   wasm2asm_i32$1 = 255;
   HEAP8[(wasm2asm_i32$0 + 75 | 0) >> 0] = wasm2asm_i32$1;
  };
  $0 = __stdio_write($0 | 0, $1 | 0, $2 | 0) | 0;
  global$0 = $3 + 16 | 0;
  return $0 | 0;
 }
 
 function __stdio_seek($0, $1, $1$hi, $2) {
  $0 = $0 | 0;
  $1 = $1 | 0;
  $1$hi = $1$hi | 0;
  $2 = $2 | 0;
  var i64toi32_i32$1 = 0, i64toi32_i32$2 = 0, $3 = 0, i64toi32_i32$0 = 0, i64toi32_i32$4 = 0, i64toi32_i32$3 = 0, $11 = 0, $8 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0, wasm2asm_i32$2 = 0, wasm2asm_i32$3 = 0;
  $3 = global$0 - 16 | 0;
  global$0 = $3;
  $8 = HEAPU32[($0 + 60 | 0) >> 2] | 0;
  i64toi32_i32$0 = $1$hi;
  i64toi32_i32$0 = i64toi32_i32$0;
  i64toi32_i32$2 = $1;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$1 = 0;
   $11 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
   $11 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
  }
  i64toi32_i32$1 = i64toi32_i32$1;
  i64toi32_i32$1 = $1$hi;
  i64toi32_i32$1 = i64toi32_i32$1;
  if ((__syscall_ret(__syscall5(140 | 0, $8 | 0, $11 | 0, $1 | 0, $3 + 8 | 0 | 0, $2 | 0) | 0 | 0) | 0 | 0) >= (0 | 0)) {
   i64toi32_i32$0 = $3;
   i64toi32_i32$1 = HEAPU32[($3 + 8 | 0) >> 2] | 0;
   i64toi32_i32$2 = (wasm2asm_i32$0 = $3, HEAPU8[(wasm2asm_i32$0 + 12 | 0) >> 0] | 0 | 0 | (HEAPU8[(wasm2asm_i32$0 + 13 | 0) >> 0] | 0 | 0) << 8 | (HEAPU8[(wasm2asm_i32$0 + 14 | 0) >> 0] | 0 | 0) << 16 | (HEAPU8[(wasm2asm_i32$0 + 15 | 0) >> 0] | 0 | 0) << 24);
   i64toi32_i32$2 = i64toi32_i32$2;
   $1 = i64toi32_i32$1;
   $1$hi = i64toi32_i32$2;
   global$0 = $3 + 16 | 0;
   i64toi32_i32$2 = i64toi32_i32$2;
   i64toi32_i32$2 = i64toi32_i32$2;
   i64toi32_i32$1 = i64toi32_i32$1;
   i64toi32_i32$HIGH_BITS = i64toi32_i32$2;
   return i64toi32_i32$1 | 0;
  }
  i64toi32_i32$2 = $3;
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
 
 function memcpy($0, $1, $2) {
  $0 = $0 | 0;
  $1 = $1 | 0;
  $2 = $2 | 0;
  var $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $10 = 0, wasm2asm_i32$0 = 0, wasm2asm_i32$1 = 0;
  label$1 : {
   label$2 : {
    label$3 : {
     if ((($2 | 0) == (0 | 0) | ($1 & 3 | 0 | 0) == (0 | 0) | 0 | 0) == (0 | 0)) {
      $3 = $0;
      label$5 : {
       label$6 : do {
        wasm2asm_i32$0 = $3;
        wasm2asm_i32$1 = HEAPU8[$1 >> 0] | 0;
        HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
        $4 = $2 + 4294967295 | 0;
        $3 = $3 + 1 | 0;
        $1 = $1 + 1 | 0;
        if (($2 | 0) == (1 | 0)) break label$5;
        $2 = $4;
        if ($1 & 3 | 0) continue label$6;
        break label$6;
       } while (1);
      };
      if (($3 & 3 | 0 | 0) == (0 | 0)) break label$3;
      break label$2;
     }
     $4 = $2;
     $3 = $0;
     if ($3 & 3 | 0) break label$2;
    };
    label$7 : {
     label$8 : {
      if ($4 >>> 0 >= 16 >>> 0) {
       $6 = $4 + 4294967280 | 0;
       $7 = $6 & 4294967280 | 0;
       $8 = $7 + 16 | 0;
       $5 = $3 + $8 | 0;
       $2 = $1;
       label$10 : do {
        wasm2asm_i32$0 = $3;
        wasm2asm_i32$1 = HEAPU32[$2 >> 2] | 0;
        HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3 + 4 | 0;
        wasm2asm_i32$1 = HEAPU32[($2 + 4 | 0) >> 2] | 0;
        HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3 + 8 | 0;
        wasm2asm_i32$1 = HEAPU32[($2 + 8 | 0) >> 2] | 0;
        HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3 + 12 | 0;
        wasm2asm_i32$1 = HEAPU32[($2 + 12 | 0) >> 2] | 0;
        HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
        $3 = $3 + 16 | 0;
        $2 = $2 + 16 | 0;
        $4 = $4 + 4294967280 | 0;
        if ($4 >>> 0 > 15 >>> 0) continue label$10;
        break label$10;
       } while (1);
       $1 = $1 + $8 | 0;
       $3 = 8;
       $4 = $6 - $7 | 0;
       if ($4 & 8 | 0) break label$8;
       break label$7;
      }
      $5 = $3;
      $3 = 8;
      if (($4 & 8 | 0 | 0) == (0 | 0)) break label$7;
     };
     wasm2asm_i32$0 = $5;
     wasm2asm_i32$1 = HEAPU32[$1 >> 2] | 0;
     HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
     wasm2asm_i32$0 = $5;
     wasm2asm_i32$1 = HEAPU32[($1 + 4 | 0) >> 2] | 0;
     HEAP32[(wasm2asm_i32$0 + 4 | 0) >> 2] = wasm2asm_i32$1;
     $1 = $1 + $3 | 0;
     $5 = $5 + $3 | 0;
    };
    label$11 : {
     label$12 : {
      label$13 : {
       if (($4 & 4 | 0 | 0) == (0 | 0)) {
        $3 = 2;
        if ($4 & 2 | 0) break label$13;
        break label$12;
       }
       wasm2asm_i32$0 = $5;
       wasm2asm_i32$1 = HEAPU32[$1 >> 2] | 0;
       HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
       $1 = $1 + 4 | 0;
       $5 = $5 + 4 | 0;
       $3 = 2;
       if (($4 & 2 | 0 | 0) == (0 | 0)) break label$12;
      };
      wasm2asm_i32$0 = $5;
      wasm2asm_i32$1 = HEAPU8[$1 >> 0] | 0;
      HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
      wasm2asm_i32$0 = $5;
      wasm2asm_i32$1 = HEAPU8[($1 + 1 | 0) >> 0] | 0;
      HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
      $5 = $5 + $3 | 0;
      $1 = $1 + $3 | 0;
      if ($4 & 1 | 0) break label$11;
      break label$1;
     };
     if (($4 & 1 | 0 | 0) == (0 | 0)) break label$1;
    };
    wasm2asm_i32$0 = $5;
    wasm2asm_i32$1 = HEAPU8[$1 >> 0] | 0;
    HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
    return $0 | 0;
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
               if ($4 >>> 0 < 32 >>> 0) break label$26;
               $2 = $3 & 3 | 0;
               if (($2 | 0) == (3 | 0)) break label$25;
               if (($2 | 0) == (2 | 0)) break label$24;
               if (($2 | 0) != (1 | 0)) break label$26;
               wasm2asm_i32$0 = $3;
               wasm2asm_i32$1 = HEAPU8[($1 + 1 | 0) >> 0] | 0;
               HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
               $6 = HEAPU32[$1 >> 2] | 0;
               wasm2asm_i32$0 = $3;
               wasm2asm_i32$1 = $6;
               HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
               wasm2asm_i32$0 = $3;
               wasm2asm_i32$1 = HEAPU8[($1 + 2 | 0) >> 0] | 0;
               HEAP8[(wasm2asm_i32$0 + 2 | 0) >> 0] = wasm2asm_i32$1;
               $2 = $1 + 16 | 0;
               $8 = $4 + 4294967277 | 0;
               $7 = $4 + 4294967293 | 0;
               $5 = $3 + 3 | 0;
               $9 = ($4 + 4294967276 | 0) & 4294967280 | 0;
               $10 = $9 + 19 | 0;
               $1 = $1 + $10 | 0;
               label$27 : do {
                $4 = HEAPU32[($2 + 4294967284 | 0) >> 2] | 0;
                wasm2asm_i32$0 = $5;
                wasm2asm_i32$1 = $4 << 8 | 0 | ($6 >>> 24 | 0) | 0;
                HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                $6 = HEAPU32[($2 + 4294967288 | 0) >> 2] | 0;
                wasm2asm_i32$0 = $5 + 4 | 0;
                wasm2asm_i32$1 = $6 << 8 | 0 | ($4 >>> 24 | 0) | 0;
                HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                $4 = HEAPU32[($2 + 4294967292 | 0) >> 2] | 0;
                wasm2asm_i32$0 = $5 + 8 | 0;
                wasm2asm_i32$1 = $4 << 8 | 0 | ($6 >>> 24 | 0) | 0;
                HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                $6 = HEAPU32[$2 >> 2] | 0;
                wasm2asm_i32$0 = $5 + 12 | 0;
                wasm2asm_i32$1 = $6 << 8 | 0 | ($4 >>> 24 | 0) | 0;
                HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
                $5 = $5 + 16 | 0;
                $2 = $2 + 16 | 0;
                $7 = $7 + 4294967280 | 0;
                if ($7 >>> 0 > 16 >>> 0) continue label$27;
                break label$27;
               } while (1);
               $4 = $8 - $9 | 0;
               $3 = $3 + $10 | 0;
              };
              $2 = 16;
              if ($4 & 16 | 0) break label$23;
              break label$22;
             };
             $6 = HEAPU32[$1 >> 2] | 0;
             wasm2asm_i32$0 = $3;
             wasm2asm_i32$1 = $6;
             HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
             $2 = $1 + 16 | 0;
             $8 = $4 + 4294967279 | 0;
             $7 = $4 + 4294967295 | 0;
             $5 = $3 + 1 | 0;
             $9 = ($4 + 4294967276 | 0) & 4294967280 | 0;
             $10 = $9 + 17 | 0;
             $1 = $1 + $10 | 0;
             label$28 : do {
              $4 = HEAPU32[($2 + 4294967284 | 0) >> 2] | 0;
              wasm2asm_i32$0 = $5;
              wasm2asm_i32$1 = $4 << 24 | 0 | ($6 >>> 8 | 0) | 0;
              HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
              $6 = HEAPU32[($2 + 4294967288 | 0) >> 2] | 0;
              wasm2asm_i32$0 = $5 + 4 | 0;
              wasm2asm_i32$1 = $6 << 24 | 0 | ($4 >>> 8 | 0) | 0;
              HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
              $4 = HEAPU32[($2 + 4294967292 | 0) >> 2] | 0;
              wasm2asm_i32$0 = $5 + 8 | 0;
              wasm2asm_i32$1 = $4 << 24 | 0 | ($6 >>> 8 | 0) | 0;
              HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
              $6 = HEAPU32[$2 >> 2] | 0;
              wasm2asm_i32$0 = $5 + 12 | 0;
              wasm2asm_i32$1 = $6 << 24 | 0 | ($4 >>> 8 | 0) | 0;
              HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
              $5 = $5 + 16 | 0;
              $2 = $2 + 16 | 0;
              $7 = $7 + 4294967280 | 0;
              if ($7 >>> 0 > 18 >>> 0) continue label$28;
              break label$28;
             } while (1);
             $3 = $3 + $10 | 0;
             $2 = 16;
             $4 = $8 - $9 | 0;
             if (($4 & 16 | 0 | 0) == (0 | 0)) break label$22;
             break label$23;
            };
            $6 = HEAPU32[$1 >> 2] | 0;
            wasm2asm_i32$0 = $3;
            wasm2asm_i32$1 = $6;
            HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
            wasm2asm_i32$0 = $3;
            wasm2asm_i32$1 = HEAPU8[($1 + 1 | 0) >> 0] | 0;
            HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
            $2 = $1 + 16 | 0;
            $8 = $4 + 4294967278 | 0;
            $7 = $4 + 4294967294 | 0;
            $5 = $3 + 2 | 0;
            $9 = ($4 + 4294967276 | 0) & 4294967280 | 0;
            $10 = $9 + 18 | 0;
            $1 = $1 + $10 | 0;
            label$29 : do {
             $4 = HEAPU32[($2 + 4294967284 | 0) >> 2] | 0;
             wasm2asm_i32$0 = $5;
             wasm2asm_i32$1 = $4 << 16 | 0 | ($6 >>> 16 | 0) | 0;
             HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
             $6 = HEAPU32[($2 + 4294967288 | 0) >> 2] | 0;
             wasm2asm_i32$0 = $5 + 4 | 0;
             wasm2asm_i32$1 = $6 << 16 | 0 | ($4 >>> 16 | 0) | 0;
             HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
             $4 = HEAPU32[($2 + 4294967292 | 0) >> 2] | 0;
             wasm2asm_i32$0 = $5 + 8 | 0;
             wasm2asm_i32$1 = $4 << 16 | 0 | ($6 >>> 16 | 0) | 0;
             HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
             $6 = HEAPU32[$2 >> 2] | 0;
             wasm2asm_i32$0 = $5 + 12 | 0;
             wasm2asm_i32$1 = $6 << 16 | 0 | ($4 >>> 16 | 0) | 0;
             HEAP32[wasm2asm_i32$0 >> 2] = wasm2asm_i32$1;
             $5 = $5 + 16 | 0;
             $2 = $2 + 16 | 0;
             $7 = $7 + 4294967280 | 0;
             if ($7 >>> 0 > 17 >>> 0) continue label$29;
             break label$29;
            } while (1);
            $3 = $3 + $10 | 0;
            $2 = 16;
            $4 = $8 - $9 | 0;
            if (($4 & 16 | 0 | 0) == (0 | 0)) break label$22;
           };
           wasm2asm_i32$0 = $3;
           wasm2asm_i32$1 = HEAPU8[($1 + 1 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3;
           wasm2asm_i32$1 = HEAPU8[($1 + 2 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 2 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3;
           wasm2asm_i32$1 = HEAPU8[($1 + 3 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 3 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3;
           wasm2asm_i32$1 = HEAPU8[($1 + 4 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 4 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3;
           wasm2asm_i32$1 = HEAPU8[($1 + 5 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 5 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3;
           wasm2asm_i32$1 = HEAPU8[($1 + 6 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 6 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3;
           wasm2asm_i32$1 = HEAPU8[($1 + 7 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 7 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3;
           wasm2asm_i32$1 = HEAPU8[($1 + 8 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 8 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3;
           wasm2asm_i32$1 = HEAPU8[($1 + 9 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 9 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3;
           wasm2asm_i32$1 = HEAPU8[($1 + 10 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 10 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3;
           wasm2asm_i32$1 = HEAPU8[($1 + 11 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 11 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3;
           wasm2asm_i32$1 = HEAPU8[($1 + 12 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 12 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3;
           wasm2asm_i32$1 = HEAPU8[($1 + 13 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 13 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3;
           wasm2asm_i32$1 = HEAPU8[($1 + 14 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 14 | 0) >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3;
           wasm2asm_i32$1 = HEAPU8[$1 >> 0] | 0;
           HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
           wasm2asm_i32$0 = $3;
           wasm2asm_i32$1 = HEAPU8[($1 + 15 | 0) >> 0] | 0;
           HEAP8[(wasm2asm_i32$0 + 15 | 0) >> 0] = wasm2asm_i32$1;
           $3 = $3 + $2 | 0;
           $1 = $1 + $2 | 0;
           $2 = 8;
           if (($4 & 8 | 0 | 0) == (0 | 0)) break label$21;
           break label$20;
          };
          $2 = 8;
          if ($4 & 8 | 0) break label$20;
         };
         $2 = 4;
         if ($4 & 4 | 0) break label$19;
         break label$18;
        };
        wasm2asm_i32$0 = $3;
        wasm2asm_i32$1 = HEAPU8[$1 >> 0] | 0;
        HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3;
        wasm2asm_i32$1 = HEAPU8[($1 + 1 | 0) >> 0] | 0;
        HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3;
        wasm2asm_i32$1 = HEAPU8[($1 + 2 | 0) >> 0] | 0;
        HEAP8[(wasm2asm_i32$0 + 2 | 0) >> 0] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3;
        wasm2asm_i32$1 = HEAPU8[($1 + 3 | 0) >> 0] | 0;
        HEAP8[(wasm2asm_i32$0 + 3 | 0) >> 0] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3;
        wasm2asm_i32$1 = HEAPU8[($1 + 4 | 0) >> 0] | 0;
        HEAP8[(wasm2asm_i32$0 + 4 | 0) >> 0] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3;
        wasm2asm_i32$1 = HEAPU8[($1 + 5 | 0) >> 0] | 0;
        HEAP8[(wasm2asm_i32$0 + 5 | 0) >> 0] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3;
        wasm2asm_i32$1 = HEAPU8[($1 + 6 | 0) >> 0] | 0;
        HEAP8[(wasm2asm_i32$0 + 6 | 0) >> 0] = wasm2asm_i32$1;
        wasm2asm_i32$0 = $3;
        wasm2asm_i32$1 = HEAPU8[($1 + 7 | 0) >> 0] | 0;
        HEAP8[(wasm2asm_i32$0 + 7 | 0) >> 0] = wasm2asm_i32$1;
        $3 = $3 + $2 | 0;
        $1 = $1 + $2 | 0;
        $2 = 4;
        if (($4 & 4 | 0 | 0) == (0 | 0)) break label$18;
       };
       wasm2asm_i32$0 = $3;
       wasm2asm_i32$1 = HEAPU8[$1 >> 0] | 0;
       HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
       wasm2asm_i32$0 = $3;
       wasm2asm_i32$1 = HEAPU8[($1 + 1 | 0) >> 0] | 0;
       HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
       wasm2asm_i32$0 = $3;
       wasm2asm_i32$1 = HEAPU8[($1 + 2 | 0) >> 0] | 0;
       HEAP8[(wasm2asm_i32$0 + 2 | 0) >> 0] = wasm2asm_i32$1;
       wasm2asm_i32$0 = $3;
       wasm2asm_i32$1 = HEAPU8[($1 + 3 | 0) >> 0] | 0;
       HEAP8[(wasm2asm_i32$0 + 3 | 0) >> 0] = wasm2asm_i32$1;
       $3 = $3 + $2 | 0;
       $1 = $1 + $2 | 0;
       $2 = 2;
       if (($4 & 2 | 0 | 0) == (0 | 0)) break label$17;
       break label$16;
      };
      $2 = 2;
      if ($4 & 2 | 0) break label$16;
     };
     if ($4 & 1 | 0) break label$15;
     break label$1;
    };
    wasm2asm_i32$0 = $3;
    wasm2asm_i32$1 = HEAPU8[$1 >> 0] | 0;
    HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
    wasm2asm_i32$0 = $3;
    wasm2asm_i32$1 = HEAPU8[($1 + 1 | 0) >> 0] | 0;
    HEAP8[(wasm2asm_i32$0 + 1 | 0) >> 0] = wasm2asm_i32$1;
    $3 = $3 + $2 | 0;
    $1 = $1 + $2 | 0;
    if (($4 & 1 | 0 | 0) == (0 | 0)) break label$1;
   };
   wasm2asm_i32$0 = $3;
   wasm2asm_i32$1 = HEAPU8[$1 >> 0] | 0;
   HEAP8[wasm2asm_i32$0 >> 0] = wasm2asm_i32$1;
  };
  return $0 | 0;
 }
 
 function strlen($0) {
  $0 = $0 | 0;
  var $1 = 0, $2 = 0, $3 = 0;
  label$1 : {
   label$2 : {
    label$3 : {
     $1 = $0;
     if (($1 & 3 | 0 | 0) == (0 | 0)) break label$3;
     if ((HEAPU8[$0 >> 0] | 0 | 0) == (0 | 0)) break label$2;
     $1 = $0 + 1 | 0;
     label$4 : do {
      if (($1 & 3 | 0 | 0) == (0 | 0)) break label$3;
      $2 = HEAPU8[$1 >> 0] | 0;
      $3 = $1 + 1 | 0;
      $1 = $3;
      if ($2) continue label$4;
      break label$4;
     } while (1);
     return ($3 + 4294967295 | 0) - $0 | 0 | 0;
    };
    $1 = $1 + 4294967292 | 0;
    label$5 : do {
     $1 = $1 + 4 | 0;
     $2 = HEAPU32[$1 >> 2] | 0;
     if (((($2 ^ 4294967295 | 0) & ($2 + 4278124287 | 0) | 0) & 2155905152 | 0 | 0) == (0 | 0)) continue label$5;
     break label$5;
    } while (1);
    if (($2 & 255 | 0 | 0) == (0 | 0)) break label$1;
    label$6 : do {
     $2 = HEAPU8[($1 + 1 | 0) >> 0] | 0;
     $3 = $1 + 1 | 0;
     $1 = $3;
     if ($2) continue label$6;
     break label$6;
    } while (1);
    return $3 - $0 | 0 | 0;
   };
   return 0 | 0;
  };
  return $1 - $0 | 0 | 0;
 }
 
 var FUNCTION_TABLE_ii = [__stdio_close, __stdio_close, __stdio_close, __stdio_close, __stdio_close, __stdio_close, __stdio_close, __stdio_close];
 var FUNCTION_TABLE_iiii = [__stdio_write, __stdio_write, __stdio_write, __stdout_write, __stdio_write, __stdio_write, __stdio_write, __stdio_write];
 var FUNCTION_TABLE_iiiii = [__stdio_seek, __stdio_seek, __stdio_seek, __stdio_seek, __stdio_seek, __stdio_seek, __stdio_seek, __stdio_seek];
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
  main: main, 
  writev_c: writev_c
 };
}
