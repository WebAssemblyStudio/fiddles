#include <math.h>

#define WASM_EXPORT __attribute__((visibility("default")))
#define DONT_EXPORT __attribute__ ((visibility ("hidden")))

const static unsigned char perm[] = {
    151,160,137,91,90,15,
    131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
    190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
    88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
    77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
    102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
    135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
    5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
    223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
    129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
    251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
    49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
    138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180,151,
    151,160,137,91,90,15
};


DONT_EXPORT static double Fade(double t)
{
    return t * t * t * (t * (t * 6 - 15) + 10);
}

DONT_EXPORT static double Lerp(double t, double a, double b)
{
    return a + t * (b - a);
}

DONT_EXPORT static double Grad1D(int hash, double x)
{
    return (hash & 1) == 0 ? x : -x;
}

DONT_EXPORT static double Grad2D(int hash, double x, double y)
{
    return ((hash & 1) == 0 ? x : -x) + ((hash & 2) == 0 ? y : -y);
}

DONT_EXPORT static double Grad3D(int hash, double x, double y, double z)
{
    int h = hash & 15;
    double u = h < 8 ? x : y;
    double v = h < 4 ? y : (h == 12 || h == 14 ? x : z);
    return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}


WASM_EXPORT double a(double x)
{
    double floorOfX = floor(x);
    int X = ((int) floorOfX) & 0xff;
    x -= floorOfX;
    double u = Fade(x);
    return Lerp(u, Grad1D(perm[X], x), Grad1D(perm[X+1], x-1)) * 2;
}

WASM_EXPORT double b(double x, double y)
{
    double floorOfX = floor(x);
    double floorOfY = floor(y);
    int X = ((int) floorOfX) & 0xff;
    int Y = ((int) floorOfY) & 0xff;
    x -= floorOfX;
    y -= floorOfY;
    double u = Fade(x);
    double v = Fade(y);
    int A = (perm[X  ] + Y) & 0xff;
    int B = (perm[X+1] + Y) & 0xff;
    return Lerp(v, Lerp(u, Grad2D(perm[A  ], x, y  ), Grad2D(perm[B  ], x-1, y  )),
                    Lerp(u, Grad2D(perm[A+1], x, y-1), Grad2D(perm[B+1], x-1, y-1)));
}

WASM_EXPORT double c(double x, double y, double z)
{
    double floorOfX = floor(x);
    double floorOfY = floor(y);
    double floorOfZ = floor(z);
    int X = ((int) floorOfX) & 0xff;
    int Y = ((int) floorOfY) & 0xff;
    int Z = ((int) floorOfZ) & 0xff;
    x -= floorOfX;
    y -= floorOfY;
    z -= floorOfZ;
    double u = Fade(x);
    double v = Fade(y);
    double w = Fade(z);
    int A  = (perm[X  ] + Y) & 0xff;
    int B  = (perm[X+1] + Y) & 0xff;
    int AA = (perm[A  ] + Z) & 0xff;
    int BA = (perm[B  ] + Z) & 0xff;
    int AB = (perm[A+1] + Z) & 0xff;
    int BB = (perm[B+1] + Z) & 0xff;
    return Lerp(w, Lerp(v, Lerp(u, Grad3D(perm[AA  ], x, y  , z  ), Grad3D(perm[BA  ], x-1, y  , z  )),
                            Lerp(u, Grad3D(perm[AB  ], x, y-1, z  ), Grad3D(perm[BB  ], x-1, y-1, z  ))),
                    Lerp(v, Lerp(u, Grad3D(perm[AA+1], x, y  , z-1), Grad3D(perm[BA+1], x-1, y  , z-1)),
                            Lerp(u, Grad3D(perm[AB+1], x, y-1, z-1), Grad3D(perm[BB+1], x-1, y-1, z-1))));
}
