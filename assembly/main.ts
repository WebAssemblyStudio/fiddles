declare function sayHello(): void;

sayHello();

declare function setBignumStack(startData: i32, len: i32): void;

// 0x6001600101600055
// [ 96, 1, 96, 1, 1, 96, 0, 85 ]

// bignum stack size is 100 elements
// each stack element is 32 bytes
let BignumStackSize = 100;
let BignumStack = new ArrayBuffer(32*BignumStackSize);
//let BignumStackPtr = changetype<usize>(BignumStack);
//setBignumStack(BignumStackPtr, 100);
let BignumStackElements = Array<Uint8Array>(100)

for (let i = 0; i < BignumStackSize; i++) {
  let input_data = Uint8Array.wrap(BignumStack, i*BignumStackSize, 32);
}


let code_array: u8[] = [96, 1, 96, 1, 1, 96, 0, 85];
let result: i32 = 0;
let pc: i32 = 0;

const push1: u8 = 0x60;
const add: u8 = 0x01;
const sstore: u8 = 0x85;

export function run_evm(): i32 {
  //code_array = [ 96, 1, 96, 1, 1, 96, 0, 85 ]

  while (pc < code_array.length) {
    let opcode: i8 = code_array[pc];

    switch (opcode) {
      case push1:
        // push to bignum stack
        result = result + 1;
        // advance pc 1 byte for the push value
        pc = pc + 1;
        break;

      case add:
        result = result * 2;
        break;

      case sstore:
        break;

      default:
        break;
    }

    pc++;
  }

  return result;
}
