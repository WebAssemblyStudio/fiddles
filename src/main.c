#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdio.h>
#include <string.h>
#include <math.h>

#define HEIGHT 360
#define WIDTH 640

int data[WIDTH * HEIGHT];

void drawCircle(int centerX, int centerY, int radius, int color)
{
  for (int rowIndex = centerY; rowIndex < HEIGHT; rowIndex++)
  {
    int yw = rowIndex * WIDTH;
    for (int colIndex = centerX; colIndex < WIDTH; colIndex++)
    {
      if ((pow(1.0*(colIndex - centerX), 2)) + (pow(1.0*(rowIndex - centerY), 2)) <= pow(1.0*radius, 2))
      {
          data[yw + colIndex] = color;
      }
    }
  }

  for (int rowIndex = 0; rowIndex < centerY; rowIndex++)
  {
    int yw = rowIndex * WIDTH;
    for (int colIndex = 0; colIndex < centerX; colIndex++)
    {
      if ((pow(1.0*(colIndex - centerX), 2)) + (pow(1.0*(rowIndex - centerY), 2)) <= pow(1.0*radius, 2))
      {
          data[yw + colIndex] = color;
      }
    }
  }

  for (int rowIndex = 0; rowIndex < centerY; rowIndex++)
  {
    int yw = rowIndex * WIDTH;
    for (int colIndex = centerX; colIndex < WIDTH; colIndex++)
    {
      if ((pow(1.0*(colIndex - centerX), 2)) + (pow(1.0*(rowIndex - centerY), 2)) <= pow(1.0*radius, 2))
      {
          data[yw + colIndex] = color;
      }
    }
  }

  for (int rowIndex = centerY; rowIndex < HEIGHT; rowIndex++)
  {
    int yw = rowIndex * WIDTH;
    for (int colIndex = 0; colIndex < centerX; colIndex++)
    {
        if ((pow(1.0*(colIndex - centerX), 2)) + (pow(1.0*(rowIndex - centerY), 2)) <= pow(1.0*radius, 2))
        {
          data[yw + colIndex] = color;
        }
    }
  }
}

WASM_EXPORT
int* getData(int radius)
{
  int centerY = HEIGHT/2;
  int centerX = WIDTH/2;
  int color = (255 << 24) | 255; //red;

  drawCircle(centerX, centerY, radius, color);
  return &data[0];
}