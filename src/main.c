#define WASM_EXPORT __attribute__((visibility("default")))

#include "brainfuck"

WASM_EXPORT

int main(){
	string s;
	getline(cin, s);
	brainfuck(s.c_str());
	
	return 0;
}
