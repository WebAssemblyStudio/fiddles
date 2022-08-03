#include <emscripten.h>
#include<stdio.h>
#include "func.h"
int my_sum(int a,int b)
{
	return a+b;
}

int my_square(int a)
{
	return a*a;
}

char* my_string(char* str)
{
	return str;
}

void my_hello()
{
	my_func();
}
