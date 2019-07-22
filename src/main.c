#define WASM_EXPORT __attribute__((visibility("default")))
 
WASM_EXPORT

void menu()
{
	printf("****************************\n");
	printf("***** 1.add      2.sub *****\n");
	printf("***** 3.mul      4.div *****\n");
	printf("******     0.exit      *****\n");
	printf("****************************\n");
}
int main()
{
  menu();
 
}