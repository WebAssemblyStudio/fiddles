

import { RLPData, decode } from "./rlp";

export declare function sayHello(a: i32): void;

@external("env", "eth2_blockDataSize")
export declare function getBlockDataSize(): i32;

@external("env", "eth2_blockDataCopy")
export declare function copyBlockData(srcOffset: i32, length: i32, outputOffset: i32): void;


// to call an external wasm function from within assemblyscript, I guess
// we have declare it as an import. the function won't actually be imported,
// because in gulpfile.js we splice the wat code and paste keccak-funcs.wat
// into the assemblyscript output main.wat.
// then the keccak function will be declared twice, so to make it valid again
// gulpfile.js will also find and delete the import statement
// that assemblyscript generates

@external("watimports", "$keccak")
export declare function keccak(ctx: i32, inputOffset: i32, inputLen: i32, outputOffset: i32): void;

/*
  (func $test_keccak (result i32)
    (call $keccak (i32.const 168) (i32.const 0) (i32.const 136) (i32.const 136))
    (return (i32.const 136))
  )

;; Main entry point is $KECCAK which has 4 parameters:
;; - context offset (i32) -> 616 bytes of context
;; - input offset (i32)
;; - input length (i32)
;; - output offset (i32) -> 32 byte hash
;;
;; The context is laid out as follows:
;;   0: 1600 bits - 200 bytes - hashing state
;; 200:   64 bits -   8 bytes - residue position
;; 208: 1536 bits - 192 bytes - residue buffer
;; 400: 1536 bits - 192 bytes - round constants
;; 592:  192 bits -  24 bytes - rotation constants
;;

* test vector from https://github.com/axic/keccak-wasm/blob/master/test.wast
;; input (136 bytes of zeroes): 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
;; output (keccak-256): 3a5912a7c5faa06ee4fe906253e339467a9ce87d533c65be3c15cb231cdb25f9
*
*/

//export function add(x: i32, y: i32): i32 {

export function mpt_verify(x: i32, y: i32): i32 {

  //const input_data: u8[] = [248,107,159,32,12,216,154,231,98,17,159,237,110,205,141,201,105,7,123,178,214,163,71,28,99,154,16,231,16,169,55,74,18,29,184,73,248,71,128,131,255,255,255,160,86,232,31,23,27,204,85,166,255,131,69,230,146,192,248,110,91,72,224,27,153,108,173,192,1,98,47,181,227,99,180,33,160,197,210,70,1,134,247,35,60,146,126,125,178,220,199,3,192,229,0,182,83,202,130,39,59,123,250,216,4,93,133,164,112];

  //const input_data: u8[] = [112,164,133,93,4,216,250,123,59,39,130,202,83,182,0,229,192,3,199,220,178,125,126,146,60,35,247,134,1,70,210,197,160,33,180,99,227,181,47,98,1,192,173,108,153,27,224,72,91,110,248,192,146,230,69,131,255,166,85,204,27,23,31,232,86,160,255,255,255,131,128,71,248,73,184,29,18,74,55,169,16,231,16,154,99,28,71,163,214,178,123,7,105,201,141,205,110,237,159,17,98,231,154,216,12,32,159,107,248];
  
  //var input_data = new Uint8Array(109);
  //var input_data = new Array(109);
  //var input_data = new Uint8Array(109);
  //var first_el: u8 = input_data[0];
  //return input_data.dataStart;
  
  
  //return 99;
  //var input_data_buf = changetype<ArrayBuffer>(input_data_raw);

  // hard-coding the length for now..
  //var input_data_raw = Array.create<u8>(109);
  //input_data_raw = [248,107,159,32,12,216,154,231,98,17,159,237,110,205,141,201,105,7,123,178,214,163,71,28,99,154,16,231,16,169,55,74,18,29,184,73,248,71,128,131,255,255,255,160,86,232,31,23,27,204,85,166,255,131,69,230,146,192,248,110,91,72,224,27,153,108,173,192,1,98,47,181,227,99,180,33,160,197,210,70,1,134,247,35,60,146,126,125,178,220,199,3,192,229,0,182,83,202,130,39,59,123,250,216,4,93,133,164,112];
  //var input_data = Uint8Array.wrap(input_data_raw.buffer, 0, 109);
  
  /*
  var input_data_raw = Array.create<u8>(532);
  input_data_raw = [249,2,17,160,66,213,240,64,29,39,189,174,5,69,44,229,43,206,228,42,44,101,156,17,45,21,181,243,11,18,107,158,194,76,104,192,160,69,69,76,203,148,230,46,253,188,208,132,35,183,238,244,202,196,54,20,2,80,16,196,49,42,116,95,103,64,21,136,165,160,42,251,25,6,154,36,124,137,118,30,142,239,112,6,73,201,87,67,241,101,30,131,124,38,170,182,136,2,40,190,219,243,160,48,93,213,83,144,210,186,234,145,87,180,177,132,27,241,53,107,17,135,49,11,172,197,235,132,140,52,206,19,145,135,90,160,181,58,121,214,126,231,114,207,220,141,240,52,2,225,64,14,127,244,223,78,151,66,58,98,150,194,183,26,118,73,175,28,160,223,175,254,247,124,149,229,25,189,159,46,244,100,198,149,69,181,8,81,6,215,103,237,29,252,178,254,241,45,63,148,245,160,168,152,173,1,226,114,195,80,221,74,121,84,189,62,218,16,131,126,231,157,230,215,169,146,69,163,181,214,56,173,81,174,160,213,71,104,120,253,55,208,130,244,112,132,64,69,146,220,95,225,248,137,17,226,87,9,134,47,7,135,18,128,111,12,0,160,52,90,228,80,56,55,104,92,118,86,161,215,117,59,160,43,175,236,120,247,221,153,225,139,127,52,175,154,42,224,213,245,160,11,51,12,133,48,57,118,159,47,108,25,62,222,13,89,126,132,193,102,148,195,11,244,90,229,66,199,68,238,8,112,90,160,245,196,141,112,104,98,50,93,118,64,143,32,223,57,244,30,124,77,189,55,223,191,24,98,251,95,237,149,50,77,124,180,160,104,238,169,16,120,128,88,188,121,147,159,232,7,119,19,188,138,24,84,109,31,126,165,136,59,237,151,10,130,203,195,207,160,102,185,253,147,35,211,224,25,44,166,147,147,65,56,18,187,46,190,2,94,187,18,13,49,152,79,158,154,122,38,219,216,160,152,82,205,98,219,50,78,107,178,201,77,4,165,224,178,65,116,175,125,250,236,235,255,88,128,27,232,15,77,30,84,0,160,65,75,239,177,57,45,89,200,14,192,67,127,238,171,21,96,128,194,55,37,126,242,179,82,112,111,25,70,222,198,193,186,160,96,165,0,113,145,184,2,158,27,3,120,91,34,8,232,110,69,78,255,35,116,140,50,106,130,118,125,227,225,107,192,94,128];
  var input_data = Uint8Array.wrap(input_data_raw.buffer, 0, 532);
  */
  
  

  var decoded = decode(input_data);
  return decoded.children.length;

  // this is wrong, not the right offset
  // var input_ptr = changetype<usize>(input_data);
  //return input_ptr;

  // this is right
  //return input_data.dataStart;


  // hash should be bd47c4f9db488edbfab24643591aabab4ec3d104abf6235a361d41bdd3ca7f70
  // length is 109
  //var input_len: i32 = input_data.length();

  var keccakCtx = new ArrayBuffer(650); // 616 should be sufficient
  var keccakCtxBuf = changetype<usize>(keccakCtx);

  // to hash 136 zero bytes like the test case
  //var buff = new ArrayBuffer(136);
  //var buffPtr = changetype<usize>(buff);

  var hashOutput = new ArrayBuffer(32);
  var hashOutputPtr = changetype<usize>(hashOutput);

  //keccak(keccakCtxBuf, buffPtr, 136, hashOutputPtr);
  keccak(keccakCtxBuf, input_data.dataStart, 109, hashOutputPtr);

  var hashview = new DataView(hashOutput);
  var hash = hashview.getUint32(0);
  return hashOutputPtr;


  // if input_data[0] <= 0x7f
  // return one byte

  // else if input[0] <= 0xb7
  // a string 0-55 bytes long

  // else if input[0] <= 0xbf
  // a strong longer than 55 bytes

  // else if input[0] <= 0xf7
  // a list 0-55 bytes long

  // else
  // a list over 55 bytes long
  //var list_len = input_data[0] - 0xf6;
  // totalLength = list_length + input_length;
  // TODO: check that totalLength <= input_length
  // TODO: check that list_len == input_length
  //var decoded_input = Array.create<DataView>(list_len);


  //return list_len;

  //input_data

  //return 99;
}


  // TODO: iterate over an array of hashes


  /** 
  * input rlp: f86b9f200cd89ae762119fed6ecd8dc969077bb2d6a3471c639a10e710a9374a121db849f8478083ffffffa056e81f171bcc55a6ff8345e692c0f86e5b48e01b996cadc001622fb5e363b421a0c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470
  * output: got decoded rlp: [ <Buffer 20 0c d8 9a e7 62 11 9f ed 6e cd 8d c9 69 07 7b b2 d6 a3 47 1c 63 9a 10 e7 10 a9 37 4a 12 1d>,
  *<Buffer f8 47 80 83 ff ff ff a0 56 e8 1f 17 1b cc 55 a6 ff 83 45 e6 92 c0 f8 6e 5b 48 e0 1b 99 6c ad c0 01 62 2f b5 e3 63 b4 21 a0 c5 d2 46 01 86 f7 23 3c 92 ... 23 more bytes> ]
  */

  /*
  var buff = new ArrayBuffer(10);
  var view1 = new DataView(buff);
  view1.setUint8(0, 254);
  view1.setUint8(1, 254);
  var num = view1.getUint32(0);

  var rlpExample = Array.create<ArrayBuffer>(2);
  rlpExample[0] = new ArrayBuffer(5);
  var viewEl1 = new DataView(rlpExample[0]);
  viewEl1.setUint8(0, 127);
  viewEl1.setUint8(1, 127);
  var rlpnum = viewEl1.getUint32(0);
  return rlpnum;
  */





  /*
  var x_val: i32 = 5;
  var vec1 = new Vec_3(3, 3, 3);
  var vec2 = new Vec_3(8, 8, 8);

  var vec_result = vec1 + vec2;
  //var vec_result = vec1.add_vector(vec2);
  //return vec_result.x;
  var length = vec_result.length;
  //return length;


  // return num;
  */



/*
class Buffer {
  data: Array<
}
*/

/*
class Vec_3 {
  x: i32;
  y: i32;
  z: i32;

  constructor( x: i32, y: i32, z: i32) {
    this.x = x;
    this.y = y;
    this.z = z;
  }

  @inline @operator.binary("+")
  public add_vector(other: Vec_3): Vec_3 {
    return new Vec_3(this.x + other.x, this.y + other.y, this.z + other.z);
  }

  public get length(): i32 {
    return i32(Math.sqrt(this.x * this.x + this.y * this.y + this.z + this.z));
    //return this.x + this.y + this.z;
  }
}
*/
