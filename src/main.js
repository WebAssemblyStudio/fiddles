//FFT
var fft_instance, _memory, _bit_reversed, _trig_tables, _mem_re, _mem_im, _tbl_len, bpe = 4; // Change for f64

function random_reals (n) {
  for (var result = [], i = 0; i < n; i++) result[i] = Math.random();
  return result
}
var inputreal = random_reals(8),
    inputimag = random_reals(8),
    _re = inputreal.slice(),
    _im = inputimag.slice();
console.log("init", inputreal, inputimag);
_fft_init(8).then(() => {
  _fft(-1, inputreal, inputimag, "");
  console.log("fft js", inputreal)
  console.log(inputimag);
  _fft(-1, _re, _im, "wasm");
  console.log("fft wasm", _re);
  console.log(_im)
})

function _fft_init (n) {
  return new Promise(resolve => {
    _tbl_len = n * bpe;
    let wasmAwait = () => {};
    if ("WebAssembly" in window) {
      if (!fft_instance) {
        _memory = new WebAssembly.Memory({initial: 1});
        var offset = x => 2 * _tbl_len + x * bpe;
        _mem_re = new Float32Array(_memory.buffer, offset(0), n);
        _mem_im = new Float32Array(_memory.buffer, offset(n), n);
        //WebAssembly.instantiateStreaming(fetch('wasm/fft.wasm'), importObj).then(results => { //application/wasm
        fetch('wasm/fft.wasm', {mode: "no-cors"})
          .then(response => response.arrayBuffer())
          .then(bytes => WebAssembly.instantiate(bytes, {js: {memory:_memory}, gvar: {tbl_len:_tbl_len}}))
          .then(results => resolve(fft_instance = results.instance.exports.fft));
      } else wasmAwait = resolve;
    } else {
      _memory = new ArrayBuffer(2 * n * bpe);
      wasmAwait = resolve
    }
    _bit_reversed = new Uint32Array(_memory.buffer, 0, _tbl_len / bpe);
    _trig_tables = new Float32Array(_memory.buffer, _tbl_len, _tbl_len / bpe);
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
    _mem_re.set(re, 0);
    _mem_im.set(im, 0);
    fft_instance(n, dir);
    re = _mem_re;
    im = _mem_im
  } else {
    var levels, i, j, temp, s, tablestep, k, l, tpre, tpim;
    // Bit-reversed addressing permutation
    for (i = 1, j, temp; i < n - 1; i++) {
      j = _bit_reversed[i];
      if (j > i) {
        temp = re[i]; re[i] = re[j]; re[j] = temp;
        temp = im[i]; im[i] = im[j]; im[j] = temp;
      }
    }
    // Cooley-Tukey decimation-in-time radix-2 FFT
    for (s = 1; s < n; s <<= 1) {
      tablestep = n / s;
      for (i = 0; i < n; i += s << 1) {
        for (j = i, k = 0; j < i + s; j++, k += tablestep) {
          l = j + s;
          tpre = re[l] * _trig_tables[k] + dir * im[l] * _trig_tables[k + 1];
          tpim = im[l] * _trig_tables[k] - dir * re[l] * _trig_tables[k + 1];
          re[l] = re[j] - tpre; im[l] = im[j] - tpim;
          re[j] += tpre; im[j] += tpim;
        }
      }
    }
    // Scaling for forward transform
    if (dir == -1) for (i = 0; i < n; i++) { re[i] /= n; im[i] /= n }
  }
}