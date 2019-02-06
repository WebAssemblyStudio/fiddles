#define EXPORT __attribute__((visibility("default")))

#define GL_DEPTH_BUFFER_BIT   0x0100
#define GL_STENCIL_BUFFER_BIT 0x0400
#define GL_COLOR_BUFFER_BIT   0x4000
#define GL_POINTS             0x0000
#define GL_LINES              0x0001
#define GL_LINE_LOOP          0x0002
#define GL_LINE_STRIP         0x0003
#define GL_TRIANGLES          0x0004
#define GL_TRIANGLE_STRIP     0x0005
#define GL_TRIANGLE_FAN       0x0006

WASM_EXPORT
int main() {
  return 42;
}
