const sizeof_double = Float64Array.BYTES_PER_ELEMENT;

export async function fftmod(n = 12) {
  const N = 1 << n;
  const { instance, module } = await WebAssembly.instantiate(
    await (await fetch("fft.wasm")).arrayBuffer()
  );

  const heap = instance.exports.memory.buffer;

  const stblRef = instance.exports.malloc((N / 4) * sizeof_double);
  const stbl = new Float64Array(heap, stblRef, N / 4);
  for (let i = 0; i < N / 4; i++) {
    stbl[i] = Math.sin((2 * Math.PI * i) / N);
  }

  const complexRef = instance.exports.malloc(N * 6 * sizeof_double);
  const complex = new Float64Array(heap, complexRef, N * 6);
  const cindex = [0, 2 * N, 2 * N];
  const fftInput = complex.subarray(0, cindex[1]);
  const bit_reversed_fft_result = complex.subarray(cindex[1], cindex[2]);

  const FFT = instance.exports.FFT;
  const iFFT = instance.exports.iFFT;
  const bit_reverse = instance.exports.bit_reverse;

  let wptr = 0;
  const inputPCM = (arr) => {
    arr.forEach((v) => {
      if (wptr * 2 >= N) wptr = 0;
      fftInput[2 * wptr] = v;
      fftInput[2 * wptr + 1] = 0;
      wptr++;
    });
  };

  function getFloatFrequencyData() {
    FFT(complexRef, n, stblRef);
    bit_reverse(complexRef, n);
    complex.copyWithin(cindex[2], cindex[0], cindex[1]);
    bit_reverse(complexRef, n);
    return complex.subarray(cindex[2]);
  }
  return {
    stbl,
    stblRef,
    complexRef,
    getFloatFrequencyData,
    inputPCM,
    FFT,
    iFFT,
    bit_reverse,
    instance,
    module,
    complex,
    heap,
    wptr,
  };
}
