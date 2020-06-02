#define WASM_EXPORT __attribute__((visibility("default")))

#define SIZE 128
unsigned int IMAGE[SIZE][SIZE];
int POSX;
int POSY;
unsigned int WHITE;
unsigned int BLACK;
unsigned int ORIENTATION; // 0 => Haut; Droite => 1; Bas => 2; Gauche => 3
unsigned int REGARD_HAUT;
unsigned int REGARD_DROITE;
unsigned int REGARD_BAS;
unsigned int REGARD_GAUCHE;

WASM_EXPORT
void* get_image() {
  return (void*)IMAGE;
}

WASM_EXPORT
unsigned int get_size() {
  return SIZE;
}

unsigned int rgb(unsigned char r, unsigned char g, unsigned char b) {
  return r + 256*g + 256*256*b + 0xff000000;
}

WASM_EXPORT
void fill_image() {
  for (int i=0; i<SIZE; i+=1) {
    for (int j=0; j<SIZE; j+=1) {
      IMAGE[i][j] = rgb(
        i*256/SIZE,
        j*256/SIZE,
        (SIZE-i)*256/SIZE
      );
    }
  }
}

void initialize_color() {
  WHITE = rgb(255,255,255);
  BLACK = rgb(0,0,0);
}


void initialize_image() {
  for (int i=0; i<SIZE; i+=1) {
    for (int j=0; j<SIZE; j+=1) {
      IMAGE[i][j] = WHITE;
    }
  }
}


void initialize_fourmi() {
  POSX = SIZE / 2;
  POSY = SIZE / 2;
}

void initialize_regard() {
  REGARD_HAUT = 0;
  REGARD_DROITE = 1;
  REGARD_BAS = 2;
  REGARD_GAUCHE = 3;

  ORIENTATION = REGARD_GAUCHE;
}

WASM_EXPORT
void initialize_game() {
  initialize_regard();
  initialize_color();
  initialize_image();
  initialize_fourmi();
}

int get_Color(int posX,int posY) {
  // Cette fonction est utile pour ceux qui comme moi ont peur d'inverser le X et le Y du tableau 
  return IMAGE[posY][posX];
}

void set_color(int posX,int posY, int color) {
  // Cette fonction est utile pour ceux qui comme moi ont peur d'inverser le X et le Y du tableau 
  IMAGE[posY][posX] = color;
}

void change_color(int posX,int posY) {
  int oldColor = get_Color(posX,posY);
  int newColor = WHITE;
  if(oldColor == WHITE) {
    newColor = BLACK;
  }
  set_color(posX,posY,newColor);
}

void left_turn() {
  if(ORIENTATION == REGARD_HAUT) {
    ORIENTATION = REGARD_GAUCHE;
  } else if(ORIENTATION == REGARD_GAUCHE) {
    ORIENTATION = REGARD_BAS;
  } else if(ORIENTATION == REGARD_BAS) {
    ORIENTATION = REGARD_DROITE;
  } else {
    ORIENTATION = REGARD_HAUT;
  }
  //Optimisable en :
  // if(ORIENTATION == REGARD_HAUT) {
  //  ORIENTATION == REGARD_GAUCHE
  //} else {
  //  ORIENTATION--;
  //}
}

void right_turn() {
  if(ORIENTATION == REGARD_HAUT) {
    ORIENTATION = REGARD_DROITE;
  } else if(ORIENTATION == REGARD_DROITE) {
    ORIENTATION = REGARD_BAS;
  } else if(ORIENTATION == REGARD_BAS) {
    ORIENTATION = REGARD_GAUCHE;
  } else {
    ORIENTATION = REGARD_HAUT;
  }
  //Optimisable en :
  //ORIENTATION = (ORIENTATION + 1) % 4
}

void always_in_image() {
  if(POSX == -1) {
    POSX = SIZE - 1;
  } else if(POSX == SIZE) {
    POSX = 0;
  }
  if(POSY == -1) {
    POSY = SIZE - 1;
  } else if(POSY == SIZE) {
    POSY = 0;
  }
}

void avancer() {
  if(ORIENTATION == REGARD_GAUCHE) {
    POSX--;
  } else if(ORIENTATION == REGARD_DROITE) {
    POSX++;
  } else if(ORIENTATION == REGARD_HAUT) {
    POSY--;
  } else if(ORIENTATION == REGARD_BAS) {
    POSY++;
  }
  always_in_image();
}

WASM_EXPORT
void move_fourmis() {
  int oldColor = get_Color(POSX,POSY);
  change_color(POSX,POSY);
  if(oldColor == WHITE) {
    right_turn();
  } else {
    left_turn();
  }
  avancer();
}
