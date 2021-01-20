#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int primes()
{
    int num1 = 1;
    int num2 = 100000;
    int isMod, i, j;
    int counter;

    for (i = num1 + 1; i < num2; ++i)
    {
        isMod = 0;
        for (j = 2; j <= i / 2; ++j)
        {
            if (i % j == 0)
            {
                isMod = 1;
                break;
            }
        }
        if (isMod == 0)
        {
            counter += 1;
        }
    }
    return counter;
}