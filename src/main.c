#define WASM_EXPORT __attribute__((visibility("default")))

/* External functions provided by wasmcc. */
extern int __print(const char *msg, int len);
extern int __get_parameter(int paramNumber, const char *result);
extern int __get_state(const char *msg, int len, const char *value);
extern int __put_state(const char *key, int keySize, const char *value, int valueSize);
extern int __delete_state(const char *msg, int len);
extern int __return_result(const char *msg, int len);

void __print_wrapper(const char *str);
void __print_wrapper_size(const char *str, int size);
void __return_result_wrapper(const char *str);
int char2int(const char *array, int n);
char *int2char(int iNumber);

/* Custom malloc as predefined malloc doesn't work */
/*
 * In case of importing starting index for memory allocation
 *
 * extern unsigned char __heap_base;
 * unsigned int bump_pointer = __heap_base;
 */

unsigned int bump_pointer = 5000;

void *malloc(unsigned long n) {
    unsigned int r = bump_pointer;
    bump_pointer += n;
    return (void *) r;
}


WASM_EXPORT
int init(int args) {

    //Should have 4 arguments
    if (args != 4) {
        const char *str = "ERROR! Incorrect number of arguments. Expecting 4";
        __print_wrapper(str);
        return -1;
    }

   
    return 0;
}


WASM_EXPORT
int invoke(int args) {

    //printing the value
    const char *str = "hello world";
    __return_result_wrapper(str);

}

void __print_wrapper_size(const char *str, int size) {
    __print(str, size);
}

void __print_wrapper(const char *str) {
    int size;
    for (size = 0; str[size] != '\0'; ++size);
    __print_wrapper_size(str, size);
}

void __return_result_wrapper(const char *str) {
    int size;
    for (size = 0; str[size] != '\0'; ++size);
    __return_result(str, size);
}

int char2int(const char *array, int n) {
    int counter = 0;
    int results = 0;
    while (1) {
        if (array[counter] == '\0') {
            break;
        } else {
            results *= 10;
            results += (int) array[counter] - 48;
            counter++;
        }
    }
    return results;

}

char *int2char(int iNumber) {
    int iNumbersCount = 0;
    int iTmpNum = iNumber;
    while (iTmpNum) {
        iTmpNum /= 10;
        iNumbersCount++;
    }
    char *buffer = malloc(iNumbersCount + 1);
    for (int i = iNumbersCount - 1; i >= 0; i--) {
        buffer[i] = (char) ((iNumber % 10) | 48);
        iNumber /= 10;
    }
    buffer[iNumbersCount] = '\0';
    return buffer;

}
