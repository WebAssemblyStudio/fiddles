#define WASM_EXPORT __attribute__((visibility("default")))

int program_counter = 0;
int program_accumulator = 0;
int program_memory[4096];

void load(int address){
  program_accumulator = program_memory[address];
}

void store(int address){
  program_memory[address] = program_accumulator;
}

void add(int address){
  program_accumulator += program_memory[address];
}

void sub(int address){
  program_accumulator -= program_memory[address];
}


WASM_EXPORT
int main() {
  return 42;
}
