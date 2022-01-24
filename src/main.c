#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int Increment(int value)
{
	return (value + 1);
}

