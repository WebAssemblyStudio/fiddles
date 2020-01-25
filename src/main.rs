type Key = [u8; 8];

const FIRST_BIT:        u32 = 1 << 31;
const HALF_KEY_SIZE:    i64 = KEY_SIZE / 2;
const KEY_SIZE:         i64 = 56;

enum Ip {
    Direct,
    Reverse
}

fn circular_left_shift(ci: u32, di: u32, shift_count: u8) -> (u32, u32) {
    let mut ci_next = ci;
    let mut di_next = di;
    for _ in 0 .. shift_count {
        ci_next = (ci_next << 1) | ((ci_next & FIRST_BIT) >> (HALF_KEY_SIZE - 1));
        di_next = (di_next << 1) | ((di_next & FIRST_BIT) >> (HALF_KEY_SIZE - 1));
    }
    (ci_next, di_next)
}

fn delta_swap(a: u64, delta: u8, mask: u64) -> u64 {
    let b = (a ^ (a >> delta)) & mask;
    a ^ b ^ (b << delta)
}

fn key_to_u64(key: &Key) -> u64 {
    let mut result = 0;
    for &part in key {
        result <<= 8;
        result += part as u64;
    }
    result
}

fn message_to_u64s(message: &[u8]) -> Vec<u64> {
    message.chunks(8)
        .map(|m| {
            let mut result: u64 = 0;
            for &part in m {
                result <<= 8;
                result += part as u64;
            }
            if m.len() < 8 {
                result <<= 8 * (8 - m.len());
            }
            result
        })
        .collect()
}

fn to_u8_vec(num: u64) -> Vec<u8> {
    vec![
        ((num & 0xFF00000000000000) >> 56) as u8,
        ((num & 0x00FF000000000000) >> 48) as u8,
        ((num & 0x0000FF0000000000) >> 40) as u8,
        ((num & 0x000000FF00000000) >> 32) as u8,
        ((num & 0x00000000FF000000) >> 24) as u8,
        ((num & 0x0000000000FF0000) >> 16) as u8,
        ((num & 0x000000000000FF00) >>  8) as u8,
        ((num & 0x00000000000000FF) >>  0) as u8
    ]
}

fn compute_subkeys(key: u64) -> Vec<u64> {
    let table = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1];
    let k0 = pc1(key);
    let mut subkeys = vec![k0];

    for shift_count in &table {
        let last_key = *subkeys.last().unwrap();
        let last_ci = ((last_key & 0xFFFFFFF000000000) >> 32) as u32;
        let last_di = (last_key >> 4) as u32;
        let (ci, di) = circular_left_shift(last_ci, last_di, *shift_count);
        let current_key = ((ci as u64) << 32) | ((di as u64) << 4);
        subkeys.push(current_key);
    }

    subkeys.remove(0);
    subkeys.iter().map(|&n| { pc2(n) }).collect()
}

fn pc1(key: u64) -> u64 {
    let key = delta_swap(key,  2, 0x3333000033330000);
    let key = delta_swap(key,  4, 0x0F0F0F0F00000000);
    let key = delta_swap(key,  8, 0x009A000A00A200A8);
    let key = delta_swap(key, 16, 0x00006C6C0000CCCC);
    let key = delta_swap(key,  1, 0x1045500500550550);
    let key = delta_swap(key, 32, 0x00000000F0F0F5FA);
    let key = delta_swap(key,  8, 0x00550055006A00AA);
    let key = delta_swap(key,  2, 0x0000333330000300);
    key & 0xFFFFFFFFFFFFFF00
}

fn pc2(key: u64) -> u64 {
    const PC_2_TABLE: [u8; 48] = [
        14, 17, 11, 24,  1,  5,
         3, 28, 15,  6, 21, 10,
        23, 19, 12,  4, 26,  8,
        16,  7, 27, 20, 13,  2,
        41, 52, 31, 37, 47, 55,
        30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34 ,53,
        46, 42, 50, 36, 29, 32
    ];
    const OUT_SIZE: u8 = 64;

    let mut result: u64 = 0;
    for m in 0 .. PC_2_TABLE.len() as usize {
        if PC_2_TABLE[m] > m as u8 {
            result |= (key & (0x01 << OUT_SIZE - PC_2_TABLE[m])) << PC_2_TABLE[m] - (m as u8 + 1);
        } else {
            result |= (key & (0x01 << OUT_SIZE - PC_2_TABLE[m])) >> (m as u8 + 1) - PC_2_TABLE[m];
        }
    }
    result & 0xFFFFFFFFFFFF0000
}

fn e(block: u32) -> u64 {
    const BLOCK_LEN: usize = 32;
    const RESULT_LEN: usize = 48;
    let block_exp = (block as u64) << 32;
    let b1 = ((block_exp << (BLOCK_LEN - 1))    & 0x8000000000000000) as u64;
    let b2 = ((block_exp >> 1)                  & 0x7C00000000000000) as u64;
    let b3 = ((block_exp >> 3)                  & 0x03F0000000000000) as u64;
    let b4 = ((block_exp >> 5)                  & 0x000FC00000000000) as u64;
    let b5 = ((block_exp >> 7)                  & 0x00003F0000000000) as u64;
    let b6 = ((block_exp >> 9)                  & 0x000000FC00000000) as u64;
    let b7 = ((block_exp >> 11)                 & 0x00000003F0000000) as u64;
    let b8 = ((block_exp >> 13)                 & 0x000000000FC00000) as u64;
    let b9 = ((block_exp >> 15)                 & 0x00000000003E0000) as u64;
    let b10 = ((block_exp >> (RESULT_LEN - 1))  & 0x0000000000010000) as u64;
    b1 | b2 | b3 | b4 | b5 | b6 | b7 | b8 | b9 | b10
}

fn p(block: u32) -> u32 {
    const P_TABLE: [u8; 32] = [
        16,  7, 20, 21, 29, 12, 28, 17,
         1, 15, 23, 26,  5, 18, 31, 10,
         2,  8, 24, 14, 32, 27,  3,  9,
        19, 13, 30,  6, 22, 11,  4, 25
    ];
    const BLOCK_SIZE: u8 = 32;

    let mut result: u32 = 0;
    for m in 0 .. P_TABLE.len() as usize {
        if P_TABLE[m] > m as u8 {
            result |= (block & (0x01 << BLOCK_SIZE - P_TABLE[m])) << P_TABLE[m] - (m as u8 + 1);
        } else {
            result |= (block & (0x01 << BLOCK_SIZE - P_TABLE[m])) >> (m as u8 + 1) - P_TABLE[m];
        }
    }
    result
}

fn s(box_id: usize, block: u8) -> u8 {
    const TABLES: [[[u8; 16]; 4]; 8] = [
        [
            [ 14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7],
            [  0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8],
            [  4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0],
            [ 15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13]
        ],
        [
            [ 15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10],
            [  3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5],
            [  0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15],
            [ 13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9]
        ],
        [
            [ 10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8],
            [ 13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1],
            [ 13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7],
            [  1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12]
        ],
        [
            [  7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15],
            [ 13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9],
            [ 10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4],
            [  3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14]
        ],
        [
            [  2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9],
            [ 14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6],
            [  4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14],
            [ 11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3]
        ],
        [
            [ 12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11],
            [ 10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8],
            [  9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6],
            [  4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13]
        ],
        [
            [  4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1],
            [ 13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6],
            [  1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2],
            [  6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12]
        ],
        [
            [ 13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7],
            [  1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2],
            [  7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8],
            [  2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11]
        ]
    ];
    let i = ((block & 0x20) >> 4 | (block & 0x01)) as usize;
    let j = ((block & 0x1E) >> 1) as usize;
    TABLES[box_id][i][j]
}

fn ip(message: u64, dir: Ip) -> u64 {
    const COUNT: usize = 5;
    const MASK: [u64; COUNT] = [
        0x0055005500550055,
        0x0000333300003333,
        0x000000000F0F0F0F,
        0x00000000FF00FF00,
        0x000000FF000000FF
    ];
    const DELTA: [u8; COUNT] = [ 9, 18, 36, 24, 24];

    let mut result: u64 = message;
    match dir {
        Ip::Direct  => for i in 0 .. COUNT {
            result = delta_swap(result, DELTA[i], MASK[i])
        },
        Ip::Reverse => for i in (0 .. COUNT).rev() {
            result = delta_swap(result, DELTA[i], MASK[i])
        }
    }
    result
}

fn feistel(half_block: u32, subkey: u64) -> u32 {
    let expanded = e(half_block);
    let mut intermediate = expanded ^ subkey;
    let mut result = 0 as u32;

    for i in 0 .. 8 {
        let block = ((intermediate & 0xFC00000000000000) >> 58) as u8;
        intermediate <<= 6;
        result <<= 4;
        result |= s(i, block) as u32;
    }

    p(result)
}

fn des(message: &[u8], subkeys: Vec<u64>) -> Vec<u8> {
    let message_len = message.len();
    let message = message_to_u64s(message);

    let mut blocks = vec![];

    for msg in message {
        let permuted = ip(msg, Ip::Direct);
        let mut li: u32 = ((permuted & 0xFFFFFFFF00000000) >> 32) as u32;
        let mut ri: u32 = ((permuted & 0x00000000FFFFFFFF)) as u32;

        for subkey in &subkeys {
            let last_li = li;
            li = ri;
            ri = last_li ^ feistel(ri, *subkey);
        }

        let r16l16 = ( ( ri as u64 ) << 32 ) | li as u64;
        blocks.push(to_u8_vec(ip(r16l16, Ip::Reverse)));
    }

    let mut result = Vec::with_capacity(message_len);
    for mut block in blocks.into_iter() {
        result.append(&mut block);
    }
    result
}

use std::mem;

pub struct JsBytes {
    ptr: u32,
    len: u32,
    cap: u32,
}

impl JsBytes {
    pub fn new(mut bytes: Vec<u8>) -> *mut JsBytes {
        let ptr = bytes.as_mut_ptr() as u32;
        let len = bytes.len() as u32;
        let cap = bytes.capacity() as u32;
        mem::forget(bytes);
        let boxed = Box::new(JsBytes { ptr, len, cap });
        Box::into_raw(boxed)
    }
}

#[no_mangle]
pub fn encrypt(msg: &str) -> *mut JsBytes {
    let key = key_to_u64(b"*sqlite*");
    let subkeys = compute_subkeys(key);
    JsBytes::new(des(msg.as_bytes(), subkeys))
     // des(msg.as_bytes(), subkeys)
}

#[no_mangle]
pub fn dropBuf(ptr: *mut JsBytes) {
    unsafe {
        let boxed: Box<JsBytes> = Box::from_raw(ptr);
        Vec::from_raw_parts(boxed.ptr as *mut u8, boxed.len as usize, boxed.cap as usize);
    }
}

/*
pub fn decrypt(cipher: &[u8], key: &Key) -> Vec<u8> {
    let key = key_to_u64(key);
    let mut subkeys = compute_subkeys(key);
    subkeys.reverse();
    des(cipher, subkeys)
}
*/