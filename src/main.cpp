#define WASM_EXPORT __attribute__((visibility("default")))

struct Data {
  unsigned int rgb;
};

#define CHUNK_SIZE 4
#define START_COLOR 0xFF00FF00

class Chunk {
public:
  Data* data;

  Chunk() {
    data = new Data[CHUNK_SIZE];
    for (int i = 0; i < CHUNK_SIZE; i++) {
      // this.data[i] = new Data() 
      data[i].rgb = START_COLOR; // this is expected to abort
    }
  }
};

WASM_EXPORT
Chunk* test() {
  return new Chunk();
}