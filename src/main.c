#define WASM_EXPORT __attribute__((visibility("default")))
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

WASM_EXPORT
int getRandomNumber(int min, int max) {
  return (rand() * (min - max) + max);
}

WASM_EXPORT
double getXFromAngle(int x, double angle, int distance) {
  return round(cos(angle * M_PI / 180) * distance + x);
}

WASM_EXPORT
double getYFromAngle(int y, double angle, int distance) {
  return round(sin(angle * M_PI / 180) * distance + y);
}

WASM_EXPORT
double getAngle(int p1x, int p1y, int p2x, int p2y, bool useRadians) {

  double angleInRadians = atan2(p2y - p1y, p2x - p1x);
  if(useRadians)
  {
    return angleInRadians;
  }

  return angleInRadians * 180 / M_PI;
}

WASM_EXPORT
double getPercentageFromNumber(int val, int min, int max) {
  return ((double)(val - min) / (max - min)) * 100;
}

WASM_EXPORT
double getNumberFromPercentage(int percent, int min, int max) {
  return (((double)percent * (max - min)) / 100) + min;
}

WASM_EXPORT
double getDistanceBetweenTwoPoints(int x1, int y1, int x2, int y2) {
  double betweenX = x1 - x2;
  double betweenY = y1 - y2;
  return sqrt((betweenX * betweenX) + (betweenY * betweenY));
}

WASM_EXPORT
double degreeToRadians(int degrees) {
  return degrees * M_PI / 180;
}

WASM_EXPORT
double fract(double val) {
  return val - floor(val);
}

WASM_EXPORT
double mod(double val, int modulus) {
  return fmod((fmod(val, modulus) + modulus), modulus);
}

WASM_EXPORT
double mix(double a, double b, double alpha) {
  return a * (1 - alpha) + b * alpha;
}

WASM_EXPORT
double smoothStep(double min, double max, double val) {
  double initStep = (val - min) / (max - min);
  double nextStep = (((1) < (initStep)) ? (1) : (initStep));
  double finalStep = (((0) > (nextStep)) ? (0) : (nextStep));
  return finalStep * finalStep * (3 - 2 * finalStep);
}