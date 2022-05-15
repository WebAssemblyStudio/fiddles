#define WASM_EXPORT __attribute__((visibility("default")))

const int SIZE = 256;
unsigned char BUFFER[SIZE][SIZE][4];
const int R = 0;
const int G = 1;
const int B = 2;
const int A = 3;

WASM_EXPORT
void* get_offset() {
  return &BUFFER;
}

WASM_EXPORT
int get_size() {
  return SIZE;
}

WASM_EXPORT
// Génère une image dans BUFFER
void fill() {
  for (int y=0; y<SIZE; y++) {
    for (int x=0; x<SIZE; x++) {
      BUFFER[y][x][R] = x % 256;
      BUFFER[y][x][G] = x % 256;
      BUFFER[y][x][B] = x % 256;
      BUFFER[y][x][A] = 255;
    }
  }
}

int ord_fourmi;
int abs_fourmi;
int dim = 10;
int L;
int left = 0;
int right = 1;
int up = 2;
int down = 3;
int dir;
int ord_fourmi_tmp;
int abs_fourmi_tmp;
int compteur = 0;
int grille[10][10];

void initialisation() {
  int grille[dim][dim];
  
  ord_fourmi = (int) (dim / 2);
  abs_fourmi = (int) (dim / 2);

  for(int i = 0; i < dim; i++) {
    for(int j = 0; j < dim; j++) {
      grille[j][i] = 0;
    }
  }
  dir = up;
}

void deplacement() {
  compteur++;
  ord_fourmi_tmp = ord_fourmi;
  abs_fourmi_tmp = abs_fourmi;
 
 if ( grille[abs_fourmi_tmp][ord_fourmi_tmp] == 0) {
   if (dir == up) {
     dir = left;
     abs_fourmi = abs_fourmi - 1;
    } 
    else if ( dir == left) {
      dir = down;
      ord_fourmi = ord_fourmi + 1;
    } 
    else if ( dir == down ) {
      dir = right;
      abs_fourmi = abs_fourmi + 1;
    } 
    else if ( dir == right ) {
      dir = up;
      ord_fourmi = ord_fourmi - 1;
    }

  } 
  else if ( grille[abs_fourmi_tmp][ord_fourmi_tmp] == 1) {
    if ( dir == up ) {
      dir = right;
      abs_fourmi = abs_fourmi + 1;

    } 
    else if ( dir == left) {
      dir = up;
      ord_fourmi = ord_fourmi - 1;
    } 
    else if ( dir == down ) {
      dir = left;
      abs_fourmi = abs_fourmi - 1;
    } 
    else if ( dir == right ) {
      dir = down;
      ord_fourmi = ord_fourmi + 1;
    }
 }
 grille[abs_fourmi_tmp][ord_fourmi_tmp] = 1 - grille[abs_fourmi_tmp][ord_fourmi_tmp];
}


void arret() {
  if(abs_fourmi < 0 || abs_fourmi >= dim || ord_fourmi < 0 || ord_fourmi >= dim || compteur == 200) {
    printf("fin du jeu");
  }
}

void draw() {
  deplacement();
  arret();
  printf("Deplacements :", compteur, 20, 20);
}






