
import { keccak } from "./keccak";

/** debugging functions
export declare function sayHello(a: i32): void;

@external("main", "debug")
export declare function debug(a: i32): void;
*/

@external("env", "eth2_blockDataSize")
export declare function getBlockDataSize(): i32;

@external("env", "eth2_blockDataCopy")
//export declare function copyBlockData(srcOffset: i32, length: i32, outputOffset: i32): void;
export declare function copyBlockData(outputOffset: i32, srcOffset: i32, length: i32): void;

// https://github.com/ewasm/ewasm-rust-api/blob/master/src/eth2.rs#L22
// pub fn eth2_blockDataCopy(outputOfset: *const u32, offset: u32, length: u32);


export function main(): i32 {


  // define two globals for using keccak: the context and the output buffer
  // both will be reused repeatedly when calling keccak

  // allocate keccak context buffer
  let keccakCtx = new ArrayBuffer(650); // more than 616 (see the docs in keccak.tx)
  let keccakCtxBuf = changetype<usize>(keccakCtx);

  // allocate keccak output buffer
  let hashOutputBuf = new ArrayBuffer(32);
  let hashOutput = Uint64Array.wrap(hashOutputBuf, 0, 4);
  // another option is Uint8Array.wrap(hashOutputBuf, 0, 32)
  // we use Uint64Array so we can test equivalence of hashes by checking 4 elements rather than 32
  let hashOutputPtr = changetype<usize>(hashOutputBuf);

  let hashOutputBuffers = Array.create<ArrayBuffer>(100);
  let hashOutputPtrs = Array.create<usize>(100);

  for (let i = 0; i < 100; i++) {
    hashOutputBuffers[i] = new ArrayBuffer(32);
    hashOutputPtrs[i] = changetype<usize>(hashOutputBuffers[i]);
  }

  // INPUT 3: get proof data from the EEI
  let input_data_len = getBlockDataSize();
  let input_data_buff = new ArrayBuffer(input_data_len);
  let input_data_buff_ptr = changetype<usize>(input_data_buff);
  //copyBlockData(0, input_data_len, input_data_buff_ptr);
  copyBlockData(input_data_buff_ptr, 0, input_data_len);
  let input_data = Uint8Array.wrap(input_data_buff, 0, input_data_len);


  let result: i32;
  for (let i = 0; i < 100; i++) {
    input_data[0] = i;
    //keccak(keccakCtxBuf, input_data.dataStart, input_data_len, hashOutputPtr);
    keccak(keccakCtxBuf, input_data.dataStart, input_data_len, hashOutputPtrs[i]);
  }


  return hashOutputPtrs[1];
} 

