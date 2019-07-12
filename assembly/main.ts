declare function sayHello(): void;

sayHello();

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

export function add(x: i32, y: i32): i32 {

  var buff = new ArrayBuffer(136);
  var buffPtr = changetype<usize>(buff);
  //return buffPtr;
  var hashOutput = new ArrayBuffer(32);
  var hashOutputPtr = changetype<usize>(hashOutput);
  //return hashOutputPtr;

  //keccak(1680, 1000, 136, 1136);
  keccak(1680, buffPtr, 136, hashOutputPtr);

  var hashview = new DataView(hashOutput);
  var hash = hashview.getUint32(0);
  return hash;
  // Result: 978916007
  // (978916007).toString(16)
  // "3a5912a7"



  /*
  var x_val: i32 = 5;
  var vec1 = new Vec_3(3, 3, 3);
  var vec2 = new Vec_3(8, 8, 8);

  var vec_result = vec1 + vec2;
  //var vec_result = vec1.add_vector(vec2);
  //return vec_result.x;
  var length = vec_result.length;
  //return length;

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

  // return num;
}


/*
class Buffer {
  data: Array<
}
*/


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
