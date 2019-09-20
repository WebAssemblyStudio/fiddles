#include <stdio.h>
#include <emscripten/emscripten.h>

void TestPrintf(int a);

int main(int argc, char **argv)
{
	printf("call 1\n");
	TestPrintf(100);
	printf("call 2\n");
}


#ifdef __cplusplus
extern "C" {
#endif
    void EMSCRIPTEN_KEEPALIVE myFunction(int argc, char ** argv) {
		TestPrintf(10);
    }
    
#ifdef __cplusplus
}
#endif