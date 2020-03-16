class Data {
  rgb: i32
}

const CHUNK_SIZE = 10;
const START_COLOR = 0xFF00FF;

class Chunk {
  data: Data[];

  constructor() {
    this.data = new Array<Data>(CHUNK_SIZE);
    for (let i = 0; i < CHUNK_SIZE; i++) {
      this.data[i].rgb = START_COLOR; // this is expected to abort
    }
  }
}

export function testAbort(): Chunk {
  return new Chunk();
}