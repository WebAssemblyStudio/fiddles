fft:
	emcc fft.c -o fft.wasm --no-entry -s EXPORTED_FUNCTIONS='["_FFT","_iFFT","_bit_reverse","_malloc"]'