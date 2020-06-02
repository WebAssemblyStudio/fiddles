#define WASM_EXPORT __attribute__((visibility("default")))

#define SIZE 256
unsigned int IMAGE[SIZE][SIZE];
//Ligne
unsigned int X;
//Colonne
unsigned int Y;

//Direction de la fourmi
// 0=haut
// 1=droite
// 2=bas
// 3=gauche
unsigned int direction;

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

//Init d'une case en noir
unsigned int init() {
  return rgb(0,0,0);
}

void* avancer(unsigned int dir){
  //On avance en haut
  if(dir==0){
    if(X==0){
      X=255;
    } else{
      X=X-1;
    }
  //On avance à gauche
  } else if(dir==1){
    if(Y==255){
      Y=0;
    } else {
      Y=Y+1;
    }
  //On descend
  } else if(dir==2){
    if(X==255){
      X=0;
    } else{
      X=X+1;
    }
  } else if(dir==3){
    if(Y==0){
      Y=255;
    } else {
      Y=Y-1;
    }
  }
}

void* move(){
  //La case est noire
  if(IMAGE[X][Y]==rgb(0,0,0)){
    //On passe la couleur de la case au blanc
    IMAGE[X][Y]=rgb(255,255,255);

    //On tourne de 90° à gauche
    if(direction==0){
      direction=3;
    } else {
      direction = direction-1;
    }

    //Avancer
    avancer(direction);

  //La case est blanche
  } else if(IMAGE[X][Y]==rgb(255,255,255)){
    //On passe la couleur de la case au noir
    IMAGE[X][Y]=rgb(0,0,0);

    //On tourne de 90° à droite
    if(direction==3){
      direction=0;
    } else {
      direction = direction+1;
    }

    //Avancer
    avancer(direction);
  }
}



WASM_EXPORT
void* fill_image() {
  for (int i=0; i<SIZE; i+=1) {
    for (int j=0; j<SIZE; j+=1) {
      IMAGE[i][j] = init();
    }
  }
  //Init position fourmi
  IMAGE[128][128]=rgb(255,255,255);
  X=128;
  Y=128;
  direction=0;
  
}


WASM_EXPORT
void* iteration() {
  move();
}
