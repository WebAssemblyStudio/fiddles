#define WASM_EXPORT __attribute__((visibility("default")))

extern int  Global_getWindow();
extern int  Global_createEventListener();
extern int  Window_alert(int window,char* msg_start, int msg_length);
extern int  Window_get_document(int window);
extern int  Document_querySelector(int document, char* query_start, int query_length);
extern int  EventTarget_addEventListener(int target, char* ev_start, int ev_len, int listener);
extern void CanvasRenderingContext2D_fillRect(int context, int x, int y, int w, int h);

WASM_EXPORT
void callback() {
  int   win  = Global_getWindow();
  char *msg  = "Hello World!";
  Window_alert(win,msg,12);
}

WASM_EXPORT
int main() {
  int   win       = Global_getWindow();
  int   doc       = Window_get_document(win);
  char *query     = "button";
  int   button    = Document_querySelector(doc,query,6);
  int   listener   = Global_createEventListener();
  char *click     = "click";
  EventTarget_addEventListener(button,click,5,listener);
  return 0;
}