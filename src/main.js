//FFT
var fft_instance, _memory, _bit_reversed, _trig_tables, _mem_re, _mem_im, _tbl_len, bpe = 4; // Change for f64

function random_reals (n) {
  for (var result = [], i = 0; i < n; i++) result[i] = Math.random();
  return result
}
var inputreal = [0.726342088655105,0.8550564302806558,0.3109301539033327,0.6103328534413192,0.6248425658022126,0.1977104399875762,0.848211814135725,0.03759252898744869],
    inputimag = [0.602800712010653,0.5758535050045942,0.10352383332444925,0.355691439031539,0.09966505427471117,0.791602352062037,0.14322068479426764,0.30618731490133966];

console.log("init", inputreal, inputimag);
var which="js";
_fft_init(8).then(() => {
  _mem_re.set(inputreal, 0);
  _mem_im.set(inputimag, 0);
  if (which=="js") {
    _fft(-1, _mem_re, _mem_im, "js");
    console.log("fft js", _mem_re)
    console.log(_mem_im)
  } else if (which=="wasm") {
    _fft(-1, _mem_re, _mem_im, "wasm");
    console.log("fft wasm", _mem_re);
    console.log(_mem_im)
  }
  //console.log("log", new Float32Array(_memory.buffer, _tbl_len*2, _tbl_len/4))
})

function _fft_init (n) {
  return new Promise(resolve => {
    _tbl_len = n * bpe;
    let wasmAwait = () => {}, offset = x => 2 * _tbl_len + x * bpe;
    if ("WebAssembly" in window && which=="wasm") {
      if (!fft_instance) {
        _memory = new WebAssembly.Memory({initial: 1});
        //WebAssembly.instantiateStreaming(fetch('wasm/fft.wasm'), importObj).then(results => { //application/wasm
        fetch('wasm/fft.wasm', {mode: "no-cors"})
          .then(response => response.arrayBuffer())
          .then(bytes => WebAssembly.instantiate(bytes, {js: {memory:_memory}}))
          .then(results => resolve(fft_instance = results.instance.exports.fft));
      } else wasmAwait = resolve;
    } else if (which=="js") {
      _memory = new ArrayBuffer(4 * _tbl_len);
      wasmAwait = resolve
    }
    var m = _memory.buffer || _memory;
    console.log(offset(0))
    _bit_reversed = new Uint32Array(m, 0, n);
    _trig_tables = new Float32Array(m, _tbl_len, n);
    _mem_re = new Float32Array(m, offset(0), n);
    _mem_im = new Float32Array(m, offset(n), n);
    for (var levels = 0, m = n; m > 1; m >>= 1) levels++;
    for (var i = 0; i < n; i++)
      for (var x = i, j = 0; j < levels; j++, x >>= 1) _bit_reversed[i] = (_bit_reversed[i] << 1) | (x & 1);
    for (var i = 0; i < n; i++) _trig_tables[i] = i % 2 ?
      Math.sin(Math.PI * (i - 1) / n):
      Math.cos(Math.PI * i / n); //XXX: Make accurate
    wasmAwait()
  })
}

function _fft (dir, re, im, which) {
  var n = re.length;
  if (n < 4 || n > Number.MAX_SAFE_INTEGER || n & (n-1) != 0) return null; //XXX:4?
  if ("WebAssembly" in window && which=="wasm") {
    console.log("log", fft_instance(n, dir));
    re = _mem_re;
    im = _mem_im
  } else if (which=="js") {
    console.log(re, im)
    var levels, i, j, tmp, tmp2, s, step, k, l;
    // Bit-reversed addressing permutation
    for (i = 1, j, tmp; i < n - 1; i++) {
      j = _bit_reversed[i];
      if (j > i) {
        tmp = re[i]; re[i] = re[j]; re[j] = tmp;
        tmp = im[i]; im[i] = im[j]; im[j] = tmp;
      }
    }
    // Cooley-Tukey decimation-in-time radix-2 FFT
    for (s = 1; s < n; s <<= 1) {
      step = n / s;
      for (i = 0; i < n; i += s << 1) {
        for (j = i, k = 0; j < i + s; j++, k += step) {
          l = j + s;
          tmp = re[l] * _trig_tables[k] + dir * im[l] * _trig_tables[k + 1];
          tmp2 = im[l] * _trig_tables[k] - dir * re[l] * _trig_tables[k + 1];
          re[l] = re[j] - tmp; im[l] = im[j] - tmp2;
          re[j] += tmp; im[j] += tmp2;
        }
      }
    }
    // Scaling for forward transform
    if (dir == -1) for (i = 0; i < n; i++) { re[i] /= n; im[i] /= n }
  }
}