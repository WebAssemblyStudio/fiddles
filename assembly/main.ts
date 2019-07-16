
import { ethash_keccak256 } from "./keccak";

/** debugging functions
export declare function sayHello(a: i32): void;

@external("main", "debug")
export declare function debug(a: i32): void;
*/


// https://github.com/ewasm/ewasm-rust-api/blob/master/src/eth2.rs#L22
// pub fn eth2_blockDataCopy(outputOfset: *const u32, offset: u32, length: u32);



export function main(): i32 {

  // allocate keccak output buffer
  let hashOutputBuf = new ArrayBuffer(32);
  let hashOutput = Uint64Array.wrap(hashOutputBuf, 0, 4);
  // another option is Uint8Array.wrap(hashOutputBuf, 0, 32)
  // we use Uint64Array so we can test equivalence of hashes by checking 4 elements rather than 32
  let hashOutputPtr = changetype<usize>(hashOutputBuf);

  /*
  let hashOutputBuffers = Array.create<ArrayBuffer>(200);
  let hashOutputPtrs = Array.create<usize>(200);
  for (let i = 0; i < 100; i++) {
    hashOutputBuffers[i] = new ArrayBuffer(32);
    hashOutputPtrs[i] = changetype<usize>(hashOutputBuffers[i]);
  }
  */

  // INPUT 3: get proof data from the EEI
  /*
  let input_data_len = getBlockDataSize();
  let input_data_buff = new ArrayBuffer(input_data_len);
  let input_data_buff_ptr = changetype<usize>(input_data_buff);
  //copyBlockData(0, input_data_len, input_data_buff_ptr);
  copyBlockData(input_data_buff_ptr, 0, input_data_len);
  let input_data = Uint8Array.wrap(input_data_buff, 0, input_data_len);
  */

  let input_data_buff = new ArrayBuffer(266);
  let input_data_buff_ptr = changetype<usize>(input_data_buff);

  for (let i = 0; i < 200; i++) {
    //input_data[0] = i;
    //keccak(keccakCtxBuf, input_data.dataStart, input_data_len, hashOutputPtr);
    //keccak(keccakCtxBuf, input_data.dataStart, input_data_len, hashOutputPtrs[i]);
    ethash_keccak256(hashOutputPtr, input_data_buff_ptr, 266);
  }


  return hashOutputPtr;
} 

