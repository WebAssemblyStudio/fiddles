function fft_init (n) {
  if (n < 4 || n > Number.MAX_SAFE_INTEGER || n & (n-1) != 0) return null;
  bitrev_len = n * bpe;
  trigtbl_len = n * bpe;
  for (var levels = 0, m = n; m > 1; m >>= 1) levels++;
  memory = new WebAssembly.Memory({initial: 1});
  var bit_reversed = new Uint32Array(memory.buffer, 0, bitrev_len/4);
  var trig_tables = new Float32Array(memory.buffer, bitrev_len, trigtbl_len/4); // Change for f64
  for (var i = 0; i < n; i++)
    for (var x = i, j = 0; j < levels; j++, x >>= 1) bit_reversed[i] = (bit_reversed[i] << 1) | (x & 1);
  for (var i = 0; i < n; i++) trig_tables[i] = i % 2 ? Math.sin(Math.PI * (i - 1) / n) : Math.cos(Math.PI * i / n); //XXX: Make accurate
  console.log(trig_tables)
}

var bitrev_len, trigtbl_len, memory,
    bpe = 4; // Change for f64

function _fft (dir, re, im) {
  var n = re.length,
      offset = n => bitrev_len + trigtbl_len + n * bpe,
      mem_re = new Float32Array(memory.buffer, offset(0), n),
      mem_im = new Float32Array(memory.buffer, offset(n), n),
      importObj = {js: {memory}, gvar: {dir, bitrev_len, trigtbl_len}};
  mem_re.set(re, 0);
  mem_im.set(im, 0);
  //WebAssembly.instantiateStreaming(fetch('wasm/fft.wasm'), importObj).then(results => { //application/wasm
  fetch('wasm/fft.wasm').then(response =>
    response.arrayBuffer()
  ).then(bytes => WebAssembly.instantiate(bytes, importObj)).then(results => {
    instance = results.instance;
    console.log("log", instance.exports.fft(n));
    var re = new Float32Array(memory.buffer, offset(0), n),
        im = new Float32Array(memory.buffer, offset(n), n);
    console.log("fft wasm", re.slice(0,2), im.slice(0,2))
    //document.getElementById("container").innerText = bytes.toString()
  });
}

function random_reals (n) {
  for (var result = [], i = 0; i < n; i++) result[i] = Math.random();
  return result
}
var inputreal = random_reals(64),
    inputimag = random_reals(64);
console.log("init", inputreal.slice(0,2), inputimag.slice(0,2));
fft_init(64);
var _re = inputreal.slice(), _im = inputimag.slice();
_fft(-1, inputreal, inputimag)
fft(-1, _re, _im, true);
console.log("fft naive", _re.slice(0,2), _im.slice(0,2))

function fft (dir, x, y, test) {
  var nn, i, i1, j, k, i2, l, l1, l2,
      c1, c2, u1, u2, tmp, tmp2;

  // Calculate the number of points
  nn = x.length;
  for (var s = 0, n = nn; n > 1; n >>= 1) s++;

  // Do the bit reversal
  i2 = nn >> 1;
  j = 0;
  for (i = 0; i < nn - 1; i++) {
    if (i < j) {
      tmp = x[i]; x[i] = x[j]; x[j] = tmp;
      tmp = y[i]; y[i] = y[j]; y[j] = tmp;
    }
    k = i2;
    while (k <= j) {
      j -= k;
      k >>= 1;
    }
    j += k;
  }

  // Compute the FFT
  c1 = -1; c2 = 0; l2 = 1;
  for (l = 0; l < s; l++) {
    l1 = l2; l2 <<= 1; u1 = 1; u2 = 0;
    for (j = 0; j < l1; j++) {
      for (i = j; i < nn; i += l2) {
        i1 = i + l1;
        tmp = u1 * x[i1] - u2 * y[i1];
        tmp2 = u1 * y[i1] + u2 * x[i1];
        x[i1] = x[i] - tmp;
        y[i1] = y[i] - tmp2;
        x[i] += tmp;
        y[i] += tmp2;
      }
      tmp = u1 * c1 - u2 * c2;
      u2 = u1 * c2 + u2 * c1;
      u1 = tmp
    }
    c2 = Math.sqrt((1 - c1) / 2);
    if (dir == 1) c2 = -c2;
    c1 = Math.sqrt((1 + c1) / 2)
  }

  // Scaling for forward transform
  if (dir == -1) {
    var scale_f = 1 / nn;
    for (i = 0; i < nn; i++) {
      x[i] *= scale_f;
      y[i] *= scale_f
    }
  }
}