#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  double* pvalue  = NULL; // 初始化为 null 的指针
   pvalue  = new double;   // 为变量请求内存
  return 42;
}
