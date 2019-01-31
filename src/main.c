#define WASM_EXPORT __attribute__((visibility("default")))

extern int  global_getWindow();
extern int  global_createEventListener();
extern int  Window_alert(int window,char* msg_start, int msg_length);
extern int  Window_get_document(int window);
extern int  Document_querySelector(int document, char* query_start, int query_length);
extern int  EventTarget_addEventListener(int target, char* ev_start, int ev_len, int listener);
extern int  HTMLCanvasElement_getContext(int canvas, char* ctx_start, int ctx_len);
extern int  CanvasRenderingContext2D_set_fillStyle(int canvas, char* style_start, int style_len);
extern void CanvasRenderingContext2D_fillRect(int context, int x, int y, int w, int h);
extern int  KeyboardEvent_get_keyCode(int evt);

int   WIDTH = 320;
int   HEIGHT = 200;

char *CONTEXT_2D        = "2d";
int   CONTEXT_2D_LEN    = 2;
char *EVENT_KEYDOWN     = "keydown";
int   EVENT_KEYDOWN_LEN = 7;
char *COLOR_RED         = "red";
int   COLOR_RED_LEN     = 3;
char *COLOR_BLACK       = "black";
int   COLOR_BLACK_LEN   = 5;

int KEYCODE_RIGHT = 39;
int KEYCODE_LEFT  = 37;
int KEYCODE_UP    = 38;
int KEYCODE_DOWN  = 40;

int keydown_listener   = -1;
int animation_callback = -1;
int ctx                = -1;

int pos_x = 0;
int pos_y = 0;

void render(){
  CanvasRenderingContext2D_set_fillStyle(ctx,COLOR_BLACK,COLOR_BLACK_LEN);
  CanvasRenderingContext2D_fillRect(ctx,0,0,WIDTH,HEIGHT);
  CanvasRenderingContext2D_set_fillStyle(ctx,COLOR_RED,COLOR_RED_LEN);
  CanvasRenderingContext2D_fillRect(ctx,pos_x*5,pos_y*5,50,50);
}

WASM_EXPORT
void callback(int handler, int evt) {
  if(handler == keydown_listener){
    // handle keydown callback
    int code = KeyboardEvent_get_keyCode(evt);
    if(code == KEYCODE_RIGHT){
      pos_x += 1;
    } else if(code == KEYCODE_LEFT){
      pos_x -= 1;
    } else if(code == KEYCODE_UP){
      pos_y -= 1;
    } else if(code == KEYCODE_DOWN){
      pos_y += 1;
    }
  }
  render();  
}

WASM_EXPORT
int main() {
  int   win       = global_getWindow();
  int   doc       = Window_get_document(win);
  char *query     = "#screen";
  int   screen    = Document_querySelector(doc,query,7);
  ctx             = HTMLCanvasElement_getContext(screen,CONTEXT_2D,CONTEXT_2D_LEN);

  keydown_listener   = global_createEventListener();
  animation_callback = global_createEventListener();
  EventTarget_addEventListener(doc,EVENT_KEYDOWN,EVENT_KEYDOWN_LEN,keydown_listener);
  render();
  return 0;
}