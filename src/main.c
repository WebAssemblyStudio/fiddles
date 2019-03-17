#define WASM_EXPORT __attribute__((visibility("default")))


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define M_PI		3.14159265358979323846	/* pi */

static  char *str_east = "east";
static  char  *str_west = "west";
static  char  *str_height = "height";
static  char  *str_width = "width";
static  char  *str_south = "south";
static  char  *str_north = "north";
static time_t dn = 0;

static inline double mercY(double t) {
	const static double pif = M_PI / 4;
	return log(tan(t / 2 + pif));
}
static int getWindLevel(double maxWind) {
	const static float windLevelScale[] = { 0, 0.3, 1.6, 3.4, 5.5, 8.0, 10.8, 13.9, 17.2, 20.8, 24.5, 28.5, 32.7, 37, 41.5, 46.2, 51, 56.1, 61.2 };
	const static int windScaleLength = sizeof(windLevelScale) / sizeof(float);
	for (int i = 0; i < windScaleLength; i++) {
		if (maxWind >= windLevelScale[i]) continue;
		else return i - 1;
	}
	return 17;
}
static 	void g(double t, double i, double *n, double *e, double *a, double *o, double *out_uv) {
	double r = 1 - t
		, s = 1 - i
		, l = r * s
		, h = t * s
		, d = r * i
		, u = t * i
		, c = n[0] * l + e[0] * h + a[0] * d + o[0] * u
		, f = n[1] * l + e[1] * h + a[1] * d + o[1] * u;
	out_uv[0] = c;
	out_uv[1] = f;
	out_uv[2] = sqrt(c * c + f * f);
}
static void sinebowColor(double t, double i, double *outColor) {
	double n = t * 2 * M_PI * 5 * .75 / 6;
	double e = sin(n)
		, a = cos(n)
		, o = floor(255 * fmax(0, -a))
		, r = floor(255 * fmax(e, 0))
		, s = floor(255 * fmax(a, fmax(0, -e)));
	outColor[0] = o;
	outColor[1] = r;
	outColor[2] = s;
	outColor[3] = i;
}
static 	void extendedSinebowColor(double w, double h, double *outColor) {
	const static float c = 0.45;
	const static int f_five[] = { 255,255,255 };
	static double e_result[3] = { -1 };
	static double n, e, a, o, r, s;
	if (e_result[0] == -1) {
		sinebowColor(1, 0, e_result);
		n = e_result[0]; e = e_result[1]; a = e_result[2];
		o = f_five[0] - n; r = f_five[1] - e; s = f_five[2] - a;
	}
	w = fmin(w, 100) / 100;
	if (c >= w)
		return  sinebowColor(w / c, h, outColor);
	else {
		double t = (w - c) / (1 - c);
		outColor[0] = floor(n + t * o);
		outColor[1] = floor(e + t * r);
		outColor[2] = floor(a + t * s);
		outColor[3] = h;
	}
}
WASM_EXPORT
int test() {
	return 953999998;
}
WASM_EXPORT
int main(int argc, char **argv) {
	return 10;
}