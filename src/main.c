#define EXPORT __attribute__((visibility("default")))

#define GL_DEPTH_BUFFER_BIT         0x0100
#define GL_STENCIL_BUFFER_BIT       0x0400
#define GL_COLOR_BUFFER_BIT         0x4000
#define GL_POINTS                   0x0000
#define GL_LINES                    0x0001
#define GL_LINE_LOOP                0x0002
#define GL_LINE_STRIP               0x0003
#define GL_TRIANGLES                0x0004
#define GL_TRIANGLE_STRIP           0x0005
#define GL_TRIANGLE_FAN             0x0006
#define GL_ZERO                     0x0000
#define GL_ONE                      0x0001
#define GL_SRC_COLOR                0x0300
#define GL_ONE_MINUS_SRC_COLOR      0x0301
#define GL_SRC_ALPHA                0x0302
#define GL_ONE_MINUS_SRC_ALPHA      0x0303
#define GL_DST_ALPHA                0x0304
#define GL_ONE_MINUS_DST_ALPHA      0x0305
#define GL_DST_COLOR                0x0306
#define GL_ONE_MINUS_DST_COLOR      0x0307
#define GL_SRC_ALPHA_SATURATE       0x0308
#define GL_CONSTANT_COLOR           0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_CONSTANT_ALPHA           0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_FUNC_ADD                 0x8006
#define GL_FUNC_SUBTRACT            0x800A
#define GL_FUNC_REVERSE_SUBTRACT    0x800B

EXPORT
int main() {
  return 42;
}
