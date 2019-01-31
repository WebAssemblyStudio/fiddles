#define WASM_EXPORT __attribute__((visibility("default")))

extern int  Global_getWindow();
extern int  Global_createEventListener();
extern int  Window_alert(int window,char* msg_start, int msg_length);
extern int  Window_get_document(int window);
extern int  Document_querySelector(int document, char* query_start, int query_length);
extern int  EventTarget_addEventListener(int target, char* ev_start, int ev_len, int listener);
extern int  HTMLCanvasElement_getContext(int canvas, char* ctx_start, int ctx_len);
extern void CanvasRenderingContext2D_fillRect(int context, int x, int y, int w, int h);

char *CONTEXT_2D        = "2d";
int   CONTEXT_2D_LEN    = 2;
char *EVENT_KEYDOWN     = "keydown";
int   EVENT_KEYDOWN_LEN = 7;

int keydown_listener   = -1;
int animation_callback = -1;
int ctx                = -1;

WASM_EXPORT
void callback(e) {
  if(e == keydown_listener){
    // handle keydown callback
  }
}

WASM_EXPORT
int main() {
  int   win       = Global_getWindow();
  int   doc       = Window_get_document(win);
  char *query     = "#screen";
  int   screen    = Document_querySelector(doc,query,7);
  ctx             = HTMLCanvasElement_getContext(screen,CONTEXT_2D,CONTEXT_2D_LEN);

  keydown_listener   = Global_createEventListener();
  animation_callback = Global_createEventListener();
  EventTarget_addEventListener(doc,EVENT_KEYDOWN,EVENT_KEYDOWN_LEN,keydown_listener);
  return 0;
}