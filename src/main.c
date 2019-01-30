#define WASM_EXPORT __attribute__((visibility("default")))

extern int  get_window();
extern int  Window_get_document(int window);
extern int  Document_querySelector(int document, char* query_start, int query_length);
extern int  HTMLCanvasElement_getContext(int canvas, char* ctx_start, int ctx_len);
extern void CanvasRenderingContext2D_fillRect(int context, int x, int y, int w, int h);

WASM_EXPORT
int main() {
  int   win       = get_window();
  int   doc       = Window_get_document(win);
  char *query     = "#screen";
  int   screen    = Document_querySelector(doc,query,7);
  char *ctxString = "2d";
  int   ctx       = HTMLCanvasElement_getContext(screen,ctxString,2);
  CanvasRenderingContext2D_fillRect(ctx,0,0,50,50);
  return 0;
}