#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(){
	int len=8,i,asc= 65, rand_num=0,s_len;
	char paswd= '\0';
	char search[73] = "0123456789qwertyuioplkjhgfdsazxcvbnm!@#$%^&*?AQWERTYUIOPSDFGHJKLMNBVCXZ";
	srand(time(NULL));
	s_len = strlen(search);
	rand_num = rand()%s_len;
    
    for(i=0;i<len;i++){
		rand_num = rand()%s_len;
		paswd = search[rand_num];
//      int ipaswd = (int)paswd;
		printf("%c",paswd);
	}
	
	return 0;
}