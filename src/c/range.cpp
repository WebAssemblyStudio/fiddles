float* range(float *data, int length) {
  float min = data[0];
  float max = data[0];
  
  for(int i = 0; i < length; ++i) {
    min = data[i]<min ? data[i] : min;
    max = data[i]>max ? data[i] : max;
  }

  float[] range =[min, max];

  float* ptr = &range[0];
  return ptr;
}
