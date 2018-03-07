function fft_init (n) {
  if (n < 4 || n > Number.MAX_SAFE_INTEGER || n & (n-1) != 0) return null;
  bitrev_len = n * bpe;
  trigtbl_len = 2 * n * bpe;
  memory = new WebAssembly.Memory({initial: 1});
  var bit_reversed = new Uint32Array(memory.buffer, 0, bitrev_len/4);
  var trig_tables = new Float32Array(memory.buffer, bitrev_len, trigtbl_len/4); // Change for f64
  for (var levels = 0, m = n; m > 1; m >>= 1) levels++;
  for (var i = 0; i < n; i++)
    for (var x = i, j = 0; j < levels; j++, x >>= 1) bit_reversed[i] = (bit_reversed[i] << 1) | (x & 1);
  for (var i = 0; i < n; i++) trig_tables[i] = i % 2 ?
    Math.sin(Math.PI * (i - 1) / n):
    Math.cos(Math.PI * i / n); //XXX: Make accurate
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
    console.log("fft wasm", re, im)
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
var __re = inputreal.slice(), __im = inputimag.slice();
_fft(-1, inputreal, inputimag)
fft(-1, __re, __im);
fft_js(-1, _re, _im);
console.log("fft naive", _re, _im)
console.log("fft naive2", __re, __im)

function fft_js (dir, re, im) {
  var levels, n, i, j, temp, size, tablestep, k, l, tpre, tpim;
  n = re.length;
  // Bit-reversed addressing permutation
  var bit_reversed = new Uint32Array(memory.buffer, 0, bitrev_len/4)
	for (i = 1, j, temp; i < n - 1; i = i + 1) {
		j = bit_reversed[i];
		if (j > i) {
			temp = re[i];
			re[i] = re[j];
			re[j] = temp;
			temp = im[i];
			im[i] = im[j];
			im[j] = temp;
		}
	}
	// Cooley-Tukey decimation-in-time radix-2 FFT
  var test = [], testix = 0;
  var trig_tables = new Float32Array(memory.buffer, bitrev_len, trigtbl_len/4);
	for (size = 1; size < n; size = size << 1) {
    test[testix++] = size;
		tablestep = n / size;
		for (i = 0; i < n; i = i + (size << 1)) {
			for (j = i, k = 0; j < i + size; j = j + 1, k = k + tablestep) {
				l = j + size;
				tpre = re[l] * trig_tables[k] + dir * im[l] * trig_tables[k + 1];
				tpim = im[l] * trig_tables[k] - dir * re[l] * trig_tables[k + 1];
				re[l] = re[j] - tpre;
				im[l] = im[j] - tpim;
				re[j] = re[j] + tpre;
				im[j] = im[j] + tpim;
			}
		}
	}
  // Scaling for forward transform
  if (dir == -1) for (i = 0; i < n; i++) { re[i] /= n; im[i] /= n }
}
