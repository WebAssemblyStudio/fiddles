#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
void remap(int width, int height, char *inputData, char *outputData, char *from, char *to)
{
    float fR = from[0];
    float fG = from[1];
    float fB = from[2];
    float tR = to[0];
    float tG = to[1];
    float tB = to[2];

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int i = (y * width + x) * 4;

            float r = inputData[i];
            float g = inputData[i + 1];
            float b = inputData[i + 2];
            float a = inputData[i + 3];

            r = fR + (tR - fR) * (r / 255);
            g = fG + (tG - fG) * (g / 255);
            b = fB + (tB - fB) * (b / 255);

            outputData[i] = r;
            outputData[i + 1] = g;
            outputData[i + 2] = b;
            outputData[i + 3] = a;
        }
    }

    return outputData;
}

