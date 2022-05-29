#include <windows.h>

void main(void){
  system("wmic path win32_physicalmedia get SerialNumber");
}