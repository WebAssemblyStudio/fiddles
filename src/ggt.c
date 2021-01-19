#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int ggT(int a, int b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    for (;;)
    {
        if (a == 0)
            return b;
        b %= a;
        if (b == 0)
            return a;
        a %= b;
    }
}