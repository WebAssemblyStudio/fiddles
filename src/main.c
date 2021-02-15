#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int bufferSum(unsigned char* buffer, int buffer_size)
{
    unsigned char res = 0;
    for (int i = 0; i < buffer_size; i++)
    {
        res += buffer[i];
        buffer[i] = 1;
    }
    return res;
}