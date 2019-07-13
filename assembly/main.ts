
import { keccak } from "./keccak";
import { RLPData, decode } from "./rlp";

export declare function sayHello(a: i32): void;

@external("main", "debug")
export declare function debug(a: i32): void;

@external("env", "eth2_blockDataSize")
export declare function getBlockDataSize(): i32;

@external("env", "eth2_blockDataCopy")
export declare function copyBlockData(srcOffset: i32, length: i32, outputOffset: i32): void;



export function mpt_verify(): i32 {

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
      let node_value = node_decoded.children[1];

      /*
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
      */

      debug(kp_i); // 4

      debug(1311);
      debug(node_key.buffer.dataStart);
      /// node_key.buffer 200cd89ae762119fed6ecd8dc969077bb2d6a3471c639a10e710a9374a121db8

      // key: 2         25b40cd89ae762119fed6ecd8dc969077bb2d6a3471c639a10e710a9374a121d

      // node_key needs to become an array of nibbles
      let node_key_nibs = uintArrToNibbleArr(node_key.buffer);
      node_key_nibs = removeHexPrefix(node_key_nibs);
      // TODO: debug node_key_nibs

      /*
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
      */


      let sliced_path_for_nibble_matching = key_path.slice(kp_i);
      debug(1212);
      let match_len = matchingNibbleLength(node_key_nibs, sliced_path_for_nibble_matching);
      debug(match_len);

      if (match_len !== node_key_nibs.length) {
        sayHello(1393939);
        throw new Error('Key does not match with the proof one (extention|leaf)');
      }

      /*
      
      debug(kp_i);
      // TODO: kp_i is counting nibbles, node_key.buffer.length is counting bytes
      //kp_i = kp_i + node_key.buffer.length;
      kp_i = kp_i + node_key_nibs.length;

      debug(kp_i);
      debug(key_path.length);
      debug(sliced_path.length);

      */

      // TODO: we need another slice of the key_path
      let sliced_path_for_length_check = sliced_path_for_nibble_matching.slice(node_key_nibs.length);

      if (sliced_path_for_length_check.length == 0) {
        sayHello(141414);
        if (node_value.buffer.length == 17) {
          throw new Error('TODO: handle embedded branch');
        }
        // TODO check that this is the last node in the proof
        // i !== proof.length - 1

        sayHello(6969696);
        debug(node_value.buffer.dataStart);
        return node_value.buffer.dataStart;

      }
      
      sayHello(1313444);

      /*
      // if key.length === 0
      if (kp_i === sliced_path.length) {
        sayHello(141414);
        throw new Error('TODO: handle embedded branch');
        // TODO: value is an embedded branch?
      }
      */
      // TODO: value needs to be decoded to check if it has length 17??
      //if (value.length === 17 && key.length === 1) {
      //}


      sayHello(151515);
      debug(node_value.buffer.dataStart); // this is correct

      //next_in_path.buffer.byteOffset
      wantHash = Uint64Array.wrap(node_value.buffer.buffer, node_value.buffer.byteOffset, 4);
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

  var i = 0;
  for (; i < nib1.length; i++) {
    debug(i);
    debug(nib1[i]);
    debug(nib2[i]);

    if (nib1[i] != nib2[i]) {
      break;
    }
    i = i + 1;
  }
  
  /*
  while ( (nib1[i] == nib2[i]) && (nib1.length > i) ) {
    i = i + 1;
  }*/
  debug(i);
  debug(1241);
  return i;
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
