#define WASM_EXPORT __attribute__((visibility("default")))

typedef unsigned char byte;

// Controller takes 3 * num_bots as arena size; we just assume this is enough for now
#define MAXBOTS 25
#define MAXSZ (3 * MAXBOTS)

struct bot {
  byte id, x, y;
};

WASM_EXPORT
byte grid[MAXSZ * MAXSZ];

struct bot bots[MAXBOTS];

WASM_EXPORT
byte *bots_data = (byte*)bots;


WASM_EXPORT
int hoihoi() {
  return grid[0];
}