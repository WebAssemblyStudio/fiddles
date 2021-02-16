#include <stdint.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
uint8_t *image_to_gray(uint8_t *image_buffer, int img_width, int img_height)
{

    int offset_buffer_write = img_width * img_height * 4;

    uint8_t *buffer_write = (uint8_t *)(image_buffer + offset_buffer_write);

    for (int i = 0; i < img_height; i++)
    {
        for (int j = 0; j < img_width; j++)
        {
            uint8_t val = 0.3 * image_buffer[0] + 0.59 * image_buffer[1] + 0.11 * image_buffer[2];
            buffer_write[0] = val;
            buffer_write[1] = val;
            buffer_write[2] = val;
            buffer_write[3] = 255;
            image_buffer += 4;
            buffer_write += 4;
        }
    }

    return image_buffer;
}
