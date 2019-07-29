declare function sayHello(): void;

sayHello();

// 0x6001600101600055
// [ 96, 1, 96, 1, 1, 96, 0, 85 ]

export function run_evm(): i32 {
  //code_array = [ 96, 1, 96, 1, 1, 96, 0, 85 ]
  let code_array: i8[] = [ 96, 1, 96, 1, 1, 96, 0, 85 ];
  let result: i32 = 0;
  let pc: i32 = 0;
  while (pc < code_array.length) {
    let opcode: i8 = code_array[pc];
    result = result + opcode;
    pc++;
  }
  //for (let i=0; i < code_array.length; i++) {
  //  result = result + code_array[i];
  //}

  //return code_array.length;
  return result;
}
