#define WASM_EXPORT __attribute__((visibility("default")))
extern "C" void consoleLog(int callback_id);
extern "C" void ctxClearRect(float x, float y, float w, float h);
extern "C" void ctxBeginPath();
extern "C" void ctxMoveTo(float x, float y);
extern "C" void ctxLineTo(float x, float y);
extern "C" void ctxStroke();

WASM_EXPORT
int main() { 
  consoleLog(1);
  return 0; 
}

WASM_EXPORT
void update(int dt) {  
  ctxClearRect(0, 0, 640, 480);
  ctxBeginPath();
  ctxMoveTo(0, 0);
  ctxLineTo(100, 100);
  ctxStroke();  
}
