
import { keccak } from "./keccak";
import { RLPData, decode } from "./rlp";

export declare function sayHello(a: i32): void;

@external("main", "debug")
export declare function debug(a: i32): void;

@external("env", "eth2_blockDataSize")
export declare function getBlockDataSize(): i32;

@external("env", "eth2_blockDataCopy")
export declare function copyBlockData(srcOffset: i32, length: i32, outputOffset: i32): void;


/**
 * Verify a proof for the Ethereum Merkle-Patricia-Trie.
 * 
 * Verification logic was ported from https://github.com/ethereumjs/merkle-patricia-tree/blob/v3.0.0/src/proof.js#L31-L39.
 * 
 * 
 * Input:
 *   * `proof_nodes[]`: a merkle proof, which is an array of nodes (from the root node to the account leaf)
 *   * pre-state root. should match `keccak(proof_nodes[0])`
 *   * account address
 *     * keccak(address) is in the leaf node, but the address itelf is the hash preimage and thus unknown unless included in the input
 *     * technically, only the latter part of keccak(address) is in the leaf node (some initial portion is the "key" or "path" from the root to the leaf)
 * 
 *  
   * keccak(address) is the key for the leaf node
   * the key is used when verifying the proof
   * hex chars in the key give the path down from the root node, through the branch nodes, and to the leaf

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

 */

export function mpt_verify(): i32 {

  // allocate keccak context. will be reused repeatedly
  let keccakCtx = new ArrayBuffer(650); // more than 616 (see the docs in keccak.tx)
  let keccakCtxBuf = changetype<usize>(keccakCtx);

  // also allocate the keccak output buffer. will be reused repeatedly
  let hashOutputBuf = new ArrayBuffer(32);
  let hashOutput = Uint64Array.wrap(hashOutputBuf, 0, 4);
  // another option is hashOutput = Uint8Array.wrap(hashOutputBuf, 0, 32)
  // Uint64Array is more efficient than Uint8Array, because we can test equivalence of hashes by checking 4 elements rather than 32
  let hashOutputPtr = changetype<usize>(hashOutputBuf);


  // INPUT 1: root hash (the pre-state root), hardcoded for testing TODO: fetch from EEI
  let root_hash = Array.create<u8>(32);
  // 0x65b7b9ccb7a4d828986e488e081bc11bfa5ef6141fb06b0af2e9a0bda273a753
  root_hash = [101, 183, 185, 204, 183, 164, 216, 40, 152, 110, 72, 142, 8, 27, 193, 27, 250, 94, 246, 20, 31, 176, 107, 10, 242, 233, 160, 189, 162, 115, 167, 83];
  let root_hash_data = Uint64Array.wrap(root_hash.buffer, 0, 4);


  // INPUT 2: address is another input, also hardcoded for testing.
  let address_raw = Array.create<u8>(20);
  // keccak("6cdf39d8d75538a0cad721f24276ec48562e5c90")
  address_raw = [108, 223, 57, 216, 215, 85, 56, 160, 202, 215, 33, 242, 66, 118, 236, 72, 86, 46, 92, 144];
  let address_data = Uint8Array.wrap(address_raw.buffer, 0, 20);

  // get the key for the account leaf (the hash of the address)
  let addressHashOutput = new ArrayBuffer(32);
  let addressHashOutputPtr = changetype<usize>(addressHashOutput);
  keccak(keccakCtxBuf, address_data.dataStart, 20, addressHashOutputPtr);
  //debug(addressHashOutputPtr);

  // use Uint8 for address_hash because it'll be converted into nibbles
  let address_hash = Uint8Array.wrap(addressHashOutput, 0, 32);

  /**
   * Next we convert address_hash to an array of nibbles (i.e. single hex chars)
   * We use the var name `key_path` for the array of nibbles, because
   * the key is used to derive the path while iterating over the proof nodes.
   * 
   * The path is implicit in the proof data structure, and is reconstructed
   * by calling matchingNibbleLength() as nodes are traversed.
   * In the simple cases the call to matchingNibbleLength is not needed,
   * because the result is just 1 nibble. Branch nodes are the simple cases.
   * Reminder: there are three node types:  branch, leaf, and extension.
   * A call to matchingNibbleLength is only done for leaf nodes and extension nodes.
   * A more optimized proof encoding might precompute the calls to matchingNibbleLength()
   * and include the results in the proof data, to avoid bit twiddling during verification.
   */

  let key_path = uintArrToNibbleArr(address_hash);


  // INPUT 3: get proof data from the EEI
  let input_data_len = getBlockDataSize();
  let input_data_buff = new ArrayBuffer(input_data_len);
  let input_data_buff_ptr = changetype<usize>(input_data_buff);
  copyBlockData(0, input_data_len, input_data_buff_ptr);
  let input_data = Uint8Array.wrap(input_data_buff, 0, input_data_len);

  //sayHello(888);
  //sayHello(input_data_len);

  // proof data is RLP. decode it into an array of nodes.
  let proof_decoded = decode(input_data);
  // proof_decoded is type RLPData: { buffer: Uint8Array, children: RLPData[] }

  /**
   * Note on the data types
   * Three main AS types for dealing with data:
   * (1) ArrayBuffer  (2) UintXArray aka TypedArray  (3) DataView
   * ArrayBuffer is the "backing buffer" for both TypedArray and DataViews (access with uint_arr.buffer and data_view.buffer)
   * 
   * Note that you cannot read directly from an ArrayBuffer, you need to wrap it in a TypedArray or a DataView
   * 
   * To read from a DataView, you use `data_view.getUint8(0)` or `getUint64(19)`
   * To read from a TypedArray, you use `uint_arr[0]` or `uint_arr[19]`.
   * So the difference is a DataView lets you read any width uints, but a UintXArray you can only read width X.
   * 
   * The RLPData class uses Uint8Arrays, but the Uint8Array with the data is confusingly named `rlp_node.buffer` (so the backing buffer is at `rlp_node.buffer.buffer`)
   * TODO: rename it to rlp_node.uint_arr (or something)
   */

  //sayHello(999);
  //sayHello(proof_decoded.children.length);

  // key_path_i counter tracks how many nibbles in the key_path have been traversed (starting from the root node)
  let kp_i = 0;

  // wantHash is initially set to the root hash, because the root node is first one processed in the main loop
  var wantHash = Uint64Array.wrap(root_hash.buffer, 0, 4);



  // Main Loop. process each node in the proof starting from the root node, down to the leaf
  for (let i = 0; i < proof_decoded.children.length; i++) {
    //sayHello(55555);
    //sayHello(i);

    // hash the node and check it against wantHash
    // reuse the same context, and same output
    keccak(keccakCtxBuf, proof_decoded.children[i].buffer.dataStart, proof_decoded.children[i].buffer.length, hashOutputPtr);
    //debug(hashOutputPtr);

    //debug(wantHash.dataStart);
    //debug(wantHash.length);
    //debug(changetype<usize>(root_hash));
    //debug(changetype<usize>(root_hash_data.buffer));

    if (  (wantHash[0] != hashOutput[0])
        || (wantHash[1] != hashOutput[1])
        || (wantHash[2] != hashOutput[2])
        || (wantHash[3] != hashOutput[3]) ) {
      //sayHello(696969);
      throw new Error('hashes dont match!');
    }

    // RLP decode the trie node
    let node_decoded = decode(proof_decoded.children[i].buffer);
    let node_type = getNodeType(node_decoded.children);

    //sayHello(node_decoded.children.length);
    //sayHello(54321);

    // NEXT STEP. use key_path[kp_i] to get the next wantHash
    if (node_type == NodeType.Branch) {
      var next_in_path = node_decoded.children[key_path[kp_i]];
      kp_i = kp_i + 1;

      // TODO: if key.length === 0 throw

      if (next_in_path.children.length == 2) {
        throw new Error('TODO: handle embedded node');
      }

      //sayHello(121212);
      //debug(next_in_path.buffer.dataStart);

      //wantHash = next_in_path.buffer;
      //next_in_path.buffer.byteOffset
      wantHash = Uint64Array.wrap(next_in_path.buffer.buffer, next_in_path.buffer.byteOffset, 4);
      //debug(wantHash.dataStart);

    } // end branch case


    if (node_type == NodeType.Leaf) {
      //sayHello(131313);
      // TODO: extension node handled here too

      // step 1. check that the node's key matches the path key

      let node_key = node_decoded.children[0];
      let node_value = node_decoded.children[1];

      //debug(1311);
      //debug(node_key.buffer.dataStart);
      /// node_key.buffer 200cd89ae762119fed6ecd8dc969077bb2d6a3471c639a10e710a9374a121db8

      // key: 2         25b40cd89ae762119fed6ecd8dc969077bb2d6a3471c639a10e710a9374a121d

      // node_key needs to become an array of nibbles
      let node_key_nibs = uintArrToNibbleArr(node_key.buffer);
      node_key_nibs = removeHexPrefix(node_key_nibs);

      let sliced_path_for_nibble_matching = key_path.slice(kp_i);
      //debug(1212);
      let match_len = matchingNibbleLength(node_key_nibs, sliced_path_for_nibble_matching);
      //debug(match_len);

      if (match_len !== node_key_nibs.length) {
        //sayHello(1393939);
        throw new Error('Key does not match with the proof one (extention|leaf)');
      }

      // TODO: should increment kp_i here?
      // in the current test vector, the leaf case is terminal so it doesn't matter
      // kp_i = kp_i + node_key_nibs.length;

      //debug(kp_i);
      //debug(key_path.length);
      //debug(sliced_path.length);

      // TODO: we need another slice of the key_path
      let sliced_path_for_length_check = sliced_path_for_nibble_matching.slice(node_key_nibs.length);

      if (sliced_path_for_length_check.length == 0) { // TODO: check this == 0
        //sayHello(141414);
        if (node_value.buffer.length == 17) {
          throw new Error('TODO: handle embedded branch');
        }
        // TODO check that this is the last node in the proof
        // i !== proof.length - 1

        //sayHello(6969696);
        //debug(node_value.buffer.dataStart);
        return node_value.buffer.dataStart;

      }

      //sayHello(151515);
      //debug(node_value.buffer.dataStart);

      //next_in_path.buffer.byteOffset
      wantHash = Uint64Array.wrap(node_value.buffer.buffer, node_value.buffer.byteOffset, 4);
      debug(wantHash.dataStart);
    } // end leaf case


  } // close for loop


  return 123;

}



// proof_decoded: RLPData /* { buffer: Uint8Array, children: RLPData[] } */
// root_hash
function verifyProof()




enum NodeType {
  Branch,
  Leaf,
  Extension,
  Err
}


function getNodeType(node_data: RLPData[]): NodeType {
  //sayHello(789);
  //sayHello(node_data.length);
  if (node_data.length == 17) {
    //sayHello(171717);
    return NodeType.Branch;
  } else if (node_data.length == 2) {
    // first nibble of the key is a node type indicator
    let key = node_data[0];

    // key is an RLPData type, so key.buffer is a Uint8Array
    // Get the first byte of a Uint8Array with uint_arr[0]
    let bkey = i32(key.buffer[0]);
    // we only need to check the first nibble here
    let first_nibble = bkey >> 4;
    // second nibble = bkey % 16;

    // if isTerminator(key)
    if (first_nibble > 1) {
      //sayHello(3333);
      return NodeType.Leaf;
    }

    return NodeType.Extension;
  }

  //sayHello(66666);
  return NodeType.Err;
}


function matchingNibbleLength(nib1: Array<u8>, nib2: Array<u8>): i32 {
  //debug(1231);

  var i = 0;
  for (; i < nib1.length; i++) {
    //debug(i);
    //debug(nib1[i]);
    //debug(nib2[i]);

    if (nib1[i] != nib2[i]) {
      break;
    }
    i = i + 1;
  }
  
  //debug(i);
  //debug(1241);
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


function getPathFromAddressHash(address_hash: Uint8Array): Array<u8> {

  var key_path = Array.create<u8>(64); // length is num of hex chars for address_hash
  // TODO: we probably don't need to convert the whole thing to nibbles, just enough chars to follow the path to the proof

  let q = 0;
  for (let i = 0; i < address_hash.length; i++) {
    q = i * 2;
    key_path[q] = address_hash[i] >> 4;
    q = q + 1;
    key_path[q] = address_hash[i] % 16;
  }

  // Note: getting a pointer using changetype on key_path, a regular Array, is not working
  // debug(changetype<usize>(key_path));

  return key_path;
}







  /** 
  * input rlp: f86b9f200cd89ae762119fed6ecd8dc969077bb2d6a3471c639a10e710a9374a121db849f8478083ffffffa056e81f171bcc55a6ff8345e692c0f86e5b48e01b996cadc001622fb5e363b421a0c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470
  * output: got decoded rlp: [ <Buffer 20 0c d8 9a e7 62 11 9f ed 6e cd 8d c9 69 07 7b b2 d6 a3 47 1c 63 9a 10 e7 10 a9 37 4a 12 1d>,
  *<Buffer f8 47 80 83 ff ff ff a0 56 e8 1f 17 1b cc 55 a6 ff 83 45 e6 92 c0 f8 6e 5b 48 e0 1b 99 6c ad c0 01 62 2f b5 e3 63 b4 21 a0 c5 d2 46 01 86 f7 23 3c 92 ... 23 more bytes> ]
  */


  /* ** this is what I started before deciding to first ask if anyone has already implemented RLP in AS.

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

  */


