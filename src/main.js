"use strict";

function eratosthenes(limit) {
    var prms = new Array();
    if (limit >= 2) prms.push(2);
    if (limit >= 3) {
        let sqrtlmt = (Math.sqrt(limit) - 3) >> 1;
        let lmt  = (limit - 3) >> 1;
        let bfsz = (lmt >> 5) + 1
        let buf  = new Array();
        for (let i = 0; i < bfsz; ++i)
            buf.push(0);
        for (let i = 0; i <= sqrtlmt; ++i)
            if ((buf[i >> 5] & (1 << (i & 31))) == 0) {
                let p = 2 * i + 3;
                for (let j = (p * p - 3) >> 1; j <= lmt; j += p)
                    buf[j >> 5] |= 1 << (j & 31);
            }
        for (let i = 0; i <= lmt; ++i)
            if ((buf[i >> 5] & (1 << (i & 31))) == 0)
                prms.push(2 * i + 3);
    }
    return prms;
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    log(val) {
      console.log(val);
    }    
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  const limit = 10000000;

  eratosthenes(limit);
  eratosthenes(limit);
  eratosthenes(limit);
  eratosthenes(limit);
  eratosthenes(limit);
  eratosthenes(limit);

  console.time('js');
  eratosthenes(limit);
  console.timeEnd('js');

  exports.eratosthenes(limit);
  exports.eratosthenes(limit);
  exports.eratosthenes(limit);
  exports.eratosthenes(limit);
  exports.eratosthenes(limit);
  exports.eratosthenes(limit);
  
  console.time('as');
  exports.eratosthenes(limit);
  console.timeEnd('as');
}).catch(console.error);
