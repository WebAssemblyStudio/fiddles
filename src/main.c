#define WASM_EXPORT __attribute__((visibility("default")))

// const int SIZE = 3;
// int data[SIZE] = {1, 2, 3};

// WASM_EXPORT
// void add(int value) { 
//   for (int i=0; i<SIZE; i++) {
//     data[i] = data[i] + value;
//   }
// }

// WASM_EXPORT
// int* getData() {
//   return &data[0];
// }

WASM_EXPORT
int bufferSum(int buffer_offset, int buffer_size)
{
  unsigned char* memory = 0;
  unsigned char* buffer = memory + buffer_offset;
  unsigned char res = 0;
  for (int i = 0; i < buffer_size; i++)
  {
      res += buffer[i];
      buffer[i] = 1;
  }
  return res;
}

WASM_EXPORT
void bufferOffset(unsigned char* buffer, int buffer_size)
{
    for (int i = 0; i < buffer_size; i++)
    {
        buffer[i] += 2;
    }
}

