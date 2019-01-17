#include <math.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT int main() {
  return 42;
}

WASM_EXPORT double tilex2long(int x, int z) {
    return x / pow(2.0, z) * 360.0 - 180;
}

WASM_EXPORT double tiley2lat(int y, int z) {
    double n = M_PI - 2.0 * M_PI * y / pow(2.0, z);
    return 180.0 / M_PI * atan(0.5 * (exp(n) - exp(-n)));
}

WASM_EXPORT int long2tilex(double lon, int z) {
    return (int) (floor((lon + 180.0) / 360.0 * pow(2.0, z)));
}

WASM_EXPORT int lat2tiley(double lat, int z) {
    return (int) (floor((1.0 - log(tan(lat * M_PI / 180.0) + 1.0 / cos(lat * M_PI / 180.0)) / M_PI) / 2.0 * pow(2.0, z)));
}
