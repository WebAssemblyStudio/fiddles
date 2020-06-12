#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT

enum { TAILLE_TERRAIN_H = 50 };
enum { TAILLE_TERRAIN_W = 50 };

typedef struct {
  int r;
  int g;
  int b;
} Pixel;

void initPixel (Pixel* this) {
  this->r = this->g = this->b = 255; 
}

void changePixels (int r, int g, int b, Pixel* this){
  this->r = r;
  this->g = g;
  this->b = b;
}

typedef struct {
  Pixel terrain[TAILLE_TERRAIN_H][TAILLE_TERRAIN_W];
} Terrain;

void initTerrain (Terrain* this) {
  for (int i = 0; i < TAILLE_TERRAIN_H; i++) {
    for (int j = 0; j < TAILLE_TERRAIN_W; j++) {
      initPixel(&(this->terrain[i][j]));
    }
  }
}

typedef struct {
  Pixel color;
  int pos_x;
  int pos_y;

} Ant;

void initAnt(Ant* this, Pixel color) {
  this->color = color;
  this->pos_x = TAILLE_TERRAIN_W/2;
  this->pos_y = TAILLE_TERRAIN_H/2;
} 

int main() {

  return 42;
}
