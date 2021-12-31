#define WASM_EXPORT __attribute__((visibility("default")))

typedef struct s_data 
{
    int a;
    int b;
} t_data;

WASM_EXPORT t_data new_struct(int a, int b) {
  t_data data;
  data.a = a;
  data.b = b;
  return data;
}

WASM_EXPORT int new_int(int a, int b) {
  return a + b;
}
