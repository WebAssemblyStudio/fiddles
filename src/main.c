#include <stdio.h>
#include <stdint.h>

#define WASM_EXPORT __attribute__((visibility("default")))

typedef struct ranctx {
   uint32_t a;
   uint32_t b;
   uint32_t c;
   uint32_t d;
} ranctx;

#define rot(x,k) (((x)<<(k))|((x)>>(32-(k))))

WASM_EXPORT
uint32_t ranval( ranctx *x ) {
    uint32_t e = x->a - rot(x->b, 27);

    x->a = x->b ^ rot(x->c, 17);
    x->b = x->c + x->d;
    x->c = x->d + e;
    x->d = e + x->a;

    return x->d;
}

WASM_EXPORT
void raninit( ranctx *x, uint32_t seed ) {
    uint32_t i;
    x->a = 0xf1ea5eed, x->b = x->c = x->d = seed;
    for (i=0; i<20; ++i) {
        (void)ranval(x);
    }
}
