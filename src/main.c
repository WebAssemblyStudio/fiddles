#include <stdlib.h>
#include <stdio.h>

typedef struct OBJETO OBJETO;

struct OBJETO{
	int x,y;
	//ANIMACAO* animacao;
	int mov_x,mov_y;
};

OBJETO* objeto_criar(){
	OBJETO* o = malloc(sizeof(OBJETO));
	o->x = 0;
	o->y = 0;
	o->mov_x = o->mov_y = 0;
	//o->animacao = animacao_criar();

	return o;
}

int objeto_destruir(OBJETO* o);

int objeto_get_x(OBJETO* o){
	return o->x;
}

int objeto_get_y(OBJETO* o){
	return o->y;
}

/*----
//NAO SEI SE EH BOM PODER EDITAR O X E Y SEPARADOS (pra evitar confusao) 
//o mov_x,mov_y devem ser prioridade para movimento)

int objeto_set_x(OBJETO* o, int x){
	o->x = x;
	return 0;
}

int objeto_set_y(OBJETO* o, int y){
	o->y = y;
	return 0;
}
*/

int objeto_set_posicao(OBJETO* o, int x, int y){
	o->x = x;
	o->y = y;
	return 0;
}

int objeto_set_movimento(OBJETO* o, int mov_x, int mov_y){
  o->mov_x = mov_x;
  o->mov_y = mov_y;

  return 0;
}

int objeto_get_animacao(OBJETO* o){
	//return o->animacao;
}

int objeto_set_animacao(OBJETO* o){//adicionar ANIMACAO* a ***
	//o->animacao = a;
	return 0;
}

int objeto_update(OBJETO *o){
	//mover objeto
	o->x += o->mov_x;
	o->y += o->mov_y;

	//atualizar frame de animacao se precisar
	
}




#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  OBJETO* o;
  o = objeto_criar();
  printf("ini\n%d %d\n",objeto_get_x(o),objeto_get_y(o));
  objeto_set_posicao(o, 9, 99);
  printf("pos set posicao\n%d %d\n",objeto_get_x(o),objeto_get_y(o));
  objeto_set_movimento(o,1,1);
  objeto_update(o);
  printf("pos update\n%d %d\n",objeto_get_x(o),objeto_get_y(o));
}

/* External function that is implemented in JavaScript. */
extern void putc_js(char c);

/* Basic implementation of the writev sys call. */ 
WASM_EXPORT
size_t writev_c(int fd, const struct iovec *iov, int iovcnt) {
  size_t cnt = 0;
  for (int i = 0; i < iovcnt; i++) {
    for (int j = 0; j < iov[i].iov_len; j++) {
      putc_js(((char *)iov[i].iov_base)[j]);
    }
    cnt += iov[i].iov_len;
  }
  return cnt;
}
