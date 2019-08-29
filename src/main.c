#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT


int main(){
	int len,i,asc= 65, rand_num=0,s_len;
	char paswd= '\0';
	char search[73] = "0123456789qwertyuioplkjhgfdsazxcvbnm!@#$%^&*?AQWERTYUIOPSDFGHJKLMNBVCXZ";
	printf("\nthe pasword length should be between 8-32");
	printf("\nenter the length of your password: ");
	scanf("%d",&len);
	srand(time(NULL));
	s_len = strlen(search);
	//rand_num = rand()%s_len;
	if(len<8 || len > 32){
	printf("\nplease kindly follow the instruction given above, thank you");
}
	else{
	printf("\nyour password is:");
	for(i=0;i<len;i++){
		rand_num = rand()%s_len;
		paswd = search[rand_num];
		printf("%c",paswd);
	}
	
}
	
	return 0;
}
