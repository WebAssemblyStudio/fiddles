#define EXPORT __attribute__((visibility("default")))

void set(int* ptr) asm("set");

#define i8 char
#define i16 short
#define i32 int
#define ui8 unsigned char
#define ui16 unsigned short
#define ui32 unsigned int
#define RGBA(r, g, b, a) (((ui8)(a)) << 24 | ((ui16)((ui8)(b)) << 16) | (((ui16)(ui8)(g)) << 8) | (((ui16)(ui8)(r)) << 0))
int seed = 123456789;
int m = 0x8000;
int a = 1103515245;
int c = 12345;
int rand()
{
    seed = (a * seed + c) % m;
    return seed;
}

const int w = 100;
const int h = 100;
i32 screen[w*h];

EXPORT
void set(int* ptr)
{
    for(int x = 0;x < w;++x){
        for(int y = 0;y < h; ++y){
            ptr[y*w+x] = RGBA(
                rand() % 255, 
                rand() % 255,
                rand() % 255,
                255);
        }
    }
}

EXPORT
int main()
{
    return 14;
}