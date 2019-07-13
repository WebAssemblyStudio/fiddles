

import { RLPData, decode } from "./rlp";

export declare function sayHello(a: i32): void;

@external("main", "debug")
export declare function debug(a: i32): void;

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
  
  var root_hash = Array.create<u8>(32);
  root_hash = [101, 183, 185, 204, 183, 164, 216, 40, 152, 110, 72, 142, 8, 27, 193, 27, 250, 94, 246, 20, 31, 176, 107, 10, 242, 233, 160, 189, 162, 115, 167, 83];
  //var root_hash_data = Uint8Array.wrap(root_hash.buffer, 0, 32);
  var root_hash_data = Uint64Array.wrap(root_hash.buffer, 0, 4);


  var address_raw = Array.create<u8>(20);
  // keccak("6cdf39d8d75538a0cad721f24276ec48562e5c90")
  address_raw = [108, 223, 57, 216, 215, 85, 56, 160, 202, 215, 33, 242, 66, 118, 236, 72, 86, 46, 92, 144];
  var address_data = Uint8Array.wrap(address_raw.buffer, 0, 20);

  var keccakCtx = new ArrayBuffer(650); // 616 should be sufficient
  var keccakCtxBuf = changetype<usize>(keccakCtx);

  var addressHashOutput = new ArrayBuffer(32);
  var addressHashOutputPtr = changetype<usize>(addressHashOutput);

  keccak(keccakCtxBuf, address_data.dataStart, 20, addressHashOutputPtr);

  debug(addressHashOutputPtr);

  var address_hash = Uint8Array.wrap(addressHashOutput, 0, 32);
  
  // function getPathFromAddressHash(address_hash: Uint8Array) {

  var key_path = Array.create<u8>(64); // length is num of hex chars for address_hash
  // TODO: we might not need to convert the whole thing to nibbles, just enough chars to follow the path to the proof

  let q = 0;
  for (let i = 0; i < address_hash.length; i++) {
    q = i * 2;
    key_path[q] = address_hash[i] >> 4;
    q = q + 1;
    key_path[q] = address_hash[i] % 16;
  }

  // changetype on key_path, a regular Array, is not working
  // debug(changetype<usize>(key_path));

  // } end function




  var input_data_len = getBlockDataSize();
  var input_data_buff = new ArrayBuffer(input_data_len);
  var input_data_buff_ptr = changetype<usize>(input_data_buff);

  copyBlockData(0, input_data_len, input_data_buff_ptr);

  sayHello(888);
  sayHello(input_data_len);
  //return input_data_buff_ptr;

  var input_data = Uint8Array.wrap(input_data_buff, 0, input_data_len);
  sayHello(777);

  var proof_decoded = decode(input_data);
  // decoded result: { data: RLPData[], remainder: Uint8Array }
  // decode() returns result.data
  // RLPData: { buffer: Uint8Array, children: RLPData[] }

  sayHello(999);
  sayHello(proof_decoded.children.length);
  //sayHello(888);
  //sayHello(decoded.children[0].children.length);
  //return decoded.children.length;


  /*
  let node_decoded = decode(proof_decoded.children[4].buffer);
  sayHello(55555);
  sayHello(node_decoded.children.length);
  //let node_type = getNodeType(node_decoded.children[0].buffer);
  // pass in the array, because getNodeType checks how many elements in the decoded node
  let node_type = getNodeType(node_decoded.children);
  */

  /***
  * TODO:
  *   to verify the proof (proves that a leaf is in the trie), we also need the key for the leaf.
  *  the key is the hash of the address.
  *   keccak("6cdf39d8d75538a0cad721f24276ec48562e5c90")
  * 
  *  the key tells us what path to follow in order to verify the proof
  *  the root node is always branch node (iirc).
  *  the first byte of the key tells us which branch index to follow from the root node
  *  get the hash at that branch index.
  *  then go to the next node in the proof and hash it, and check that the hashes match
  *
  **/

  let kp_i = 0; // key_path_i
  // TODO: set wantHash to roothash
  //var wantHash: Uint8Array;
  //let wantHash = root_hash_data;
  //var wantHash = Uint8Array.wrap(root_hash_data.buffer, 0, 32);
  //var wantHash = Uint8Array.wrap(root_hash.buffer, 0, 32);
  var wantHash = Uint64Array.wrap(root_hash.buffer, 0, 4);
  //var wantHashPtr = changetype<usize>(wantHash);

  //root_hash_data

  var hashOutputBuf = new ArrayBuffer(32);
  //var hashOutput = Uint8Array.wrap(hashOutputBuf, 0, 32);
  var hashOutput = Uint64Array.wrap(hashOutputBuf, 0, 4);
  var hashOutputPtr = changetype<usize>(hashOutputBuf);



  for (let i = 0; i < proof_decoded.children.length; i++) {
    sayHello(55555);
    sayHello(i);

    // hash the node and check it against wantHash
    // reuse the same context, and same output
    keccak(keccakCtxBuf, proof_decoded.children[i].buffer.dataStart, proof_decoded.children[i].buffer.length, hashOutputPtr);
    debug(hashOutputPtr);
    //debug(changetype<usize>(root_hash));
    //debug(wantHashPtr);
    debug(wantHash.dataStart);
    //debug(wantHash.length);
    //debug(changetype<usize>(root_hash_data.buffer));

    if (wantHash[0] != hashOutput[0]
    || wantHash[1] != hashOutput[1]
    || wantHash[2] != hashOutput[2]
    || wantHash[3] != hashOutput[3]) {
      sayHello(696969);
      throw new Error('hashes dont match!');
    }

    // RLP decode the trie node
    let node_decoded = decode(proof_decoded.children[i].buffer);

    sayHello(node_decoded.children.length);
    let node_type = getNodeType(node_decoded.children);

    sayHello(54321);
    sayHello(node_type);

    // get the next wantHash
    //key_path[kp_i]

    if (node_type == NodeType.Branch) {
      var next_in_path = node_decoded.children[key_path[kp_i]];
      kp_i = kp_i + 1;

      // TODO: if key.length === 0 throw

      if (next_in_path.children.length == 2) {
        throw new Error('TODO: handle embedded node');
      }

      //wantHash = next_in_path.buffer;

      sayHello(121212);
      debug(next_in_path.buffer.dataStart); // this is correct

      //next_in_path.buffer.byteOffset
      wantHash = Uint64Array.wrap(next_in_path.buffer.buffer, next_in_path.buffer.byteOffset, 4);
      debug(wantHash.dataStart);

    } // end branch case


    if (node_type == NodeType.Leaf) {
      sayHello(131313);
      // TODO: extension node handled here too

      // check that the node's key matches the path key

      let node_key = node_decoded.children[0];
      let value = node_decoded.children[1];

      debug(0);
      debug(key_path[0]); // 2
      debug(1);
      debug(key_path[1]); // 5
      debug(2);
      debug(key_path[2]); // 11 b
      debug(3);
      debug(key_path[3]); // ??
      debug(4);
      debug(key_path[4]); // 0
      debug(5);
      debug(key_path[5]); // 12 c
      debug(6);
      debug(key_path[6]); // 13 d

      debug(kp_i); // 4

      debug(1311);
      debug(node_key.buffer.dataStart);
      /// node_key.buffer 200cd89ae762119fed6ecd8dc969077bb2d6a3471c639a10e710a9374a121db8

      // key: 2         25b40cd89ae762119fed6ecd8dc969077bb2d6a3471c639a10e710a9374a121d

      // node_key needs to become an array of nibbles
      let node_key_nibs = uintArrToNibbleArr(node_key.buffer);
      node_key_nibs = removeHexPrefix(node_key_nibs);
      // TODO: debug node_key_nibs


      debug(0);
      debug(node_key_nibs[0]); // ??
      debug(1);
      debug(node_key_nibs[1]); // 12 c
      debug(2);
      debug(node_key_nibs[2]); // 13 d
      debug(3);
      debug(node_key_nibs[3]); // 8
      debug(4);
      debug(node_key_nibs[4]); // 9

      let sliced_path = key_path.slice(kp_i);
      debug(1212);

      let match_len = matchingNibbleLength(node_key_nibs, sliced_path);

      debug(match_len);

      //let match_len = 0;
      //let node_key_nibs = Array.create<u8>(2);

      
      if (match_len !== node_key_nibs.length) {
        sayHello(1393939);
        throw new Error('Key does not match with the proof one (extention|leaf)');
      }

      sayHello(1313444);
      debug(kp_i);
      // TODO: kp_i is counting nibbles, node_key.buffer.length is counting bytes


      kp_i = kp_i + node_key.buffer.length;
      debug(kp_i);
      debug(key_path.length);

      // if key.length === 0
      if (kp_i === key_path.length) {
        sayHello(141414);
        throw new Error('TODO: handle embedded branch');
        // TODO: value is an embedded branch?
      }
      // TODO: value needs to be decoded to check if it has length 17??
      //if (value.length === 17 && key.length === 1) {
      //}


      sayHello(151515);
      debug(value.buffer.dataStart); // this is correct

      //next_in_path.buffer.byteOffset
      wantHash = Uint64Array.wrap(value.buffer.buffer, value.buffer.byteOffset, 4);
      debug(wantHash.dataStart);
    } // end leaf case

    //throw new Error('TODO: verify leaf!');
  } // close for loop


  return 123;



  // this is wrong, not the right offset
  // var input_ptr = changetype<usize>(input_data);
  //return input_ptr;

  // this is right
  //return input_data.dataStart;


  // hash should be bd47c4f9db488edbfab24643591aabab4ec3d104abf6235a361d41bdd3ca7f70
  // length is 109
  //var input_len: i32 = input_data.length();

  /*
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
  */


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



enum NodeType {
  Branch,
  Leaf,
  Extension,
  Err
}


function getNodeType(node_data: RLPData[]): NodeType {
  sayHello(789);
  sayHello(node_data.length);
  if (node_data.length == 17) {
    sayHello(171717);
    return NodeType.Branch;
  } else if (node_data.length == 2) {
    // first nibble of the key is a node type indicator
    let key = node_data[0];

    // DataViews are only needed on ArrayBuffers.
    // with a Uint8Array, you can just get the byte/number
    //var key_view = new DataView(key.buffer, 0, 1); // only need the first byte
    //let bkey = key_view.getUint8(0);

    let bkey = i32(key.buffer[0]);
    let first_nibble = bkey >> 4;
    // second nibble = bkey % 16;

    sayHello(2222);
  
    //sayHello(key_view.byteLength);
    // dataStart does exist, the IDE underlines it red because IDE is unaware
    //debug(key_view.dataStart);
  
    // if isTerminator(key)
    if (first_nibble > 1) {
      sayHello(3333);
      return NodeType.Leaf;
    }

    return NodeType.Extension;
  }

  sayHello(66666);
  return NodeType.Err;
}


// key_path = Array.create<u8>(64); // length is num of hex chars for address_hash
function matchingNibbleLength(nib1: Array<u8>, nib2: Array<u8>): i32 {
  debug(1231);

  var j = 0;
  for (let i = 0; i < nib1.length; i++) {
    debug(i);
    debug(nib1[i]);
    debug(nib2[i]);

    if (nib1[i] != nib2[i]) {
      break;
    }
    i = i + 1;
    j = j + 1;
  }
  
  /*
  while ( (nib1[i] == nib2[i]) && (nib1.length > i) ) {
    i = i + 1;
  }*/
  debug(j);
  debug(1241);
  return j;
}


function removeHexPrefix(nib_arr: Array<u8>): Array<u8> {
  // the hex prefix is merkle-patricia-trie encoding, not RLP
  if (nib_arr[0] % 2) {
    return nib_arr.slice(1);
  } else {
    return nib_arr.slice(2);
  }
}

function uintArrToNibbleArr(uint_arr: Uint8Array): Array<u8> {
  var len = uint_arr.length;

  var nib_arr = Array.create<u8>(len * 2); // length is num of hex chars for address_hash
  // TODO: we might not need to convert the whole thing to nibbles, just enough chars to follow the path to the proof

  let q = 0;
  for (let i = 0; i < len; i++) {
    q = i * 2;
    nib_arr[q] = uint_arr[i] >> 4;
    q = q + 1;
    nib_arr[q] = uint_arr[i] % 16;
  }

  return nib_arr;
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
