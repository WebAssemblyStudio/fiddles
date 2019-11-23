#define WASM_EXPORT __attribute__((visibility("default")))

const int WIDTH = 1200;
const int HEIGHT = 800;

const int KEY_UP = 0x10;
const int KEY_DOWN = 0x20;
const int KEY_LEFT = 0x40;
const int KEY_RIGHT = 0x80;
const int KEY_BUTTON1 = 0x01;
const int KEY_BUTTON2 = 0x02;
const int KEY_BUTTON3 = 0x04;

unsigned char image[WIDTH * HEIGHT * 4];

void consoleLog (char* offset, int len);
void consoleLogNum (float num);

int screenWidth;
int screenHeight;

int globmaxIterations = 1000;
double globcx = -0.7436447860; 
double globcy = 0.1318252536;
double globdiameter = 0.00029336;

unsigned char colour(int iteration, int offset, int scale) {
  iteration = ((iteration * scale) + offset) % 1024;
  if (iteration < 256) {
    return iteration;
  } else if (iteration < 512) {
    return 255 - (iteration - 255);
  } else {
    return 0;
  }
}

int iterateEquation(double x0, double y0, int maxiterations) {
  double a = 0.0, b = 0.0, rx = 0.0, ry = 0.0;
  int iterations = 0;
  while (iterations < maxiterations && (rx * rx + ry * ry <= 4.0)) {
    rx = a * a - b * b + x0;
    ry = 2.0 * a * b + y0;
    a = rx;
    b = ry;
    iterations++;
  }
  return iterations;
}

double scale(double domainStart, double domainLength, double screenLength, double step) {
  return domainStart + domainLength * ((step - screenLength) / screenLength);
}

void mandelbrot(int maxIterations, double cx, double cy, double diameter) {
  double verticalDiameter = diameter * screenHeight / screenWidth;
  for(double x = 0.0; x < screenWidth; x++) {
    for(double y = 0.0; y < screenHeight; y++) {
      // map to mandelbrot coordinates
      double rx = scale(cx, diameter, screenWidth, x);
      double ry = scale(cy, verticalDiameter, screenHeight, y);
      int iterations = iterateEquation(rx, ry, maxIterations);
      int idx = ((x + y * screenWidth) * 4);
      // set the red and alpha components
      image[idx] = iterations == maxIterations ? 0 : colour(iterations, 0, 4);
      image[idx + 1] = iterations == maxIterations ? 0 : colour(iterations, 128, 4);
      image[idx + 2] = iterations == maxIterations ? 0 : colour(iterations, 356, 4);
      image[idx + 3] = 255;
    }
  }
}

WASM_EXPORT
void init(int width, height){
    screenWidth = width;
    screenHeight = height;
}

WASM_EXPORT
unsigned char* nextFrame(){
  mandelbrot(globmaxIterations, globcx, globcy, globdiameter);
  return &image[0];
}

WASM_EXPORT
void onKeyDown(int code){
  if (code == KEY_UP){
    globcy -= 0.00001;
  }
  if (code == KEY_DOWN){
    globcy += 0.00001;
  }
  if (code == KEY_LEFT){
    globcx -= 0.00001;
  }
  if (code == KEY_RIGHT){
    globcx += 0.00001;
  }
  if (code == KEY_BUTTON1){
    globdiameter -= 0.001;
  }
  if (code == KEY_BUTTON2){
    globdiameter += 0.001;
  }
  consoleLogNum(code);
}

WASM_EXPORT
void onKeyUp(int code){
  consoleLogNum(code);
}