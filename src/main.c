#define WASM_EXPORT __attribute__((visibility("default")))

/* External function that is implemented in Native Lauguage. */
extern void print(char *s);

void reverse(char str[], int length) 
{ 
    int start = 0; 
    int end = length -1; 
    while (start < end) 
    { 
        swap(*(str+start), *(str+end)); 
        start++; 
        end--; 
    } 
} 

char* itoa(int num, char* str, int base) 
{ 
    int i = 0; 
    bool isNegative = false; 
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    if (num < 0 && base == 10) 
    { 
        isNegative = true; 
        num = -num; 
    } 
  
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
  
    // If number is negative, append '-' 
    if (isNegative) 
        str[i++] = '-'; 
  
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
    reverse(str, i); 
  
    return str; 
} 

void printValue(char *title, int value) {
   char *p = title;
   int len = 0;
   while(*p) {
     len ++;
   }
   char buf[256];
   for(int i = 0; i < len; i ++) {
     buf[i] = title[i];
   }
   p = buf + i;
   itoa(value, p, 10);
   print(buf);
}

WASM_EXPORT
int main() {
  print("Hello World.\n");
  return 42;
}
