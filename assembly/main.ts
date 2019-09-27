
declare function log(v: i32): void;
declare function logChar(v: u16): void;

const arr1: string[] = ['0', '13', 'abc1', 'abcde2', 'abcdef abcdef abcdef abcdef 1234', 'abcdef abcdef abcdef abcdef abcdef abcdef abcdef 1234', 'abcdef abcdef abcdef abcdef abcdef abcdef abcdef 1235'];
const arr2: string[] = ['1', '12', 'abc', 'abcde', 'abcdef abcdef abcdef abcdef 123433456', 'abcdef abcdef abcdef abcdef abcdef abcdef abcdef 1235', 'abcdef abcdef abcdef abcdef abcdef abcdef abcdef 1234'];

export function test(): boolean {
  let acc = false;
  for (let i = 0, len = arr1.length; i < len; i++) {
    acc = acc || (arr1[i] == arr2[i]);
  }
  return acc;
}

function compareImpl2(str1: string, index1: usize, str2: string, index2: usize, len: usize): i32 {
  var ptr1 = changetype<usize>(str1) + (index1 << 1);
  var ptr2 = changetype<usize>(str2) + (index2 << 1);

  if (len >= 4 && !((ptr1 & 7) | (ptr2 & 7))) {
    let i = 0;
    do {
      if (load<u64>(ptr1) != load<u64>(ptr2)) break;
      ptr1 += 8;
      ptr2 += 8;
      len  -= 4;
    } while (len >= 4);
  }
  while (len--) {
    let a = <i32>load<u16>(ptr1);
    let b = <i32>load<u16>(ptr2);
    if (a != b) return a - b;
    ptr1 += 2;
    ptr2 += 2;
  }
  return 0;
}

function eq(left: String | null, right: String | null): bool {
  if (left === right) return true;
  if (left === null || right === null) return false;
  var leftLength = left.length;
  if (leftLength != right.length) return false;
  // @ts-ignore: string <-> String
  return !compareImpl2(left, 0, right, 0, leftLength);
}

export function test2(): bool {
  let acc = false;
  for (let i = 0, len = arr1.length; i < len; i++) {
    acc = acc || eq(arr1[i], arr2[i]);
  }
  return acc;
}
