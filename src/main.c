#include <stdio.h>
#include <malloc.h>
char * buf;
char * data="1234567890";
int i;
int p=0;
void init()
{
buf=(char *)malloc(100);

if (buf!=NULL) {for (i=0; i<10; i++) buf[i]=data[i];}
}
char getone()
{
   p++;
   return buf[p];
}
int main(){return 0;}