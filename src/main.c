#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT

int main(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return main(n - 1) + main(n - 2);
	}
}

WASM_EXPORT 
int test(int a,int b){
  return a+b;
}