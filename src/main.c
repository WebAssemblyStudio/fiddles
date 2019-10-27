#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int add(int x, int y)
{
	return x + y;
}

WASM_EXPORT
int sub(int x, int y)
{
	return x - y;
}

WASM_EXPORT
int mul(int x, int y)
{
	return x * y;
}

WASM_EXPORT
int div(int x, int y)
{
	return x / y;
}

WASM_EXPORT
int main() {
  return 1;
}
