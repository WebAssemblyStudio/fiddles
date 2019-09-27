#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT

using namespace std;
int main()
{
cout << "Hello, World!";
system("pause");
return 0;
}
