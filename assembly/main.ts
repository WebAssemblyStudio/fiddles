import "allocator/arena";

// @ts-ignore
import { LOAD, STORE } from "internal/arraybuffer";

const minRunLen: u32 = ASC_SHRINK_LEVEL >= 1 ? 16 : 48;
const EMPTY: u32 = 0xFFFFFFFF;
const INSERTION_SORT_THRESHOLD: u32 = ASC_SHRINK_LEVEL >= 1 ? 128 : 96;

// @ts-ignore
@inline
function log2(n: u32): u32 {
	return 31 - clz(n);
}

// @ts-ignore
// @inline
function insertionSort<T>(
  inout: ArrayBuffer,
  left: u32,
  right: u32,
  presorted: u32
): void {
  if (ASC_SHRINK_LEVEL >= 1) {
    for (let i = left + presorted; i <= right; ++i) {
      let j = i - 1;
      let a = LOAD<T>(inout, i);
      while (j >= left) {
        let b = LOAD<T>(inout, j);
        if ((a - b) < 0) {
          STORE<T>(inout, j-- + 1, b);
        } else break;
      }
      STORE<T>(inout, j + 1, a);
    }
  } else {
    let i = left + ((right - left + 1) & 1) + presorted;
    for (; i <= right; i += 2) {
      let a = LOAD<T>(inout, i + 0);
      let b = LOAD<T>(inout, i + 1);
      let min = b, max = a;
      if ((a - b) <= 0) {
        min = a, max = b;
      }
      let j = i - 1;
      while (j >= left) {
        a = LOAD<T>(inout, j);
        if ((a - max) > 0) {
          STORE<T>(inout, j-- + 2, a);
        } else break;
      }
      STORE<T>(inout, j + 2, max);
      while (j >= left) {
        a = LOAD<T>(inout, j);
        if ((a - min) > 0) {
          STORE<T>(inout, j-- + 1, a);
        } else break;
      }
      STORE<T>(inout, j + 1, min);
    }
  }
}

// @ts-ignore
@inline
function nodePower(left: u32, right: u32, startA: u32, startB: u32, endB: u32): u32 {
  var n: u64 = right - left + 1; // n
  var s = startB - (left << 1);
  var l = startA + s;
  var r = endB   + s + 1;
  var a = (<u64>l << 30) / n;
  var b = (<u64>r << 30) / n;
  return clz(<u32>(a ^ b));
}

function extendRunRight<T>(inout: ArrayBuffer, i: u32, right: u32): u32 {
	let j = i;
	if (j == right) return j;
	if ((LOAD<T>(inout, j) - LOAD<T>(inout, ++j)) > 0) {
		while (j < right && (LOAD<T>(inout, j + 1) - LOAD<T>(inout, j)) < 0) ++j;
    let k = j;
    // reverse
    while (i < k) {
  		let tmp = LOAD<T>(inout, i);
      STORE<T>(inout, i++, LOAD<T>(inout, k));
      STORE<T>(inout, k--, tmp);
    }
	} else {
		while (j < right && (LOAD<T>(inout, j + 1) - LOAD<T>(inout, j)) >= 0) ++j;
	}
	return j;
}

/** Merges arr[l..m - 1] and arr[m..r] */
function mergeRuns<T>(inout: ArrayBuffer, l: u32, m: u32, r: u32, buffer: usize): void {
  --m; // accounts for different convention in Sedgewick’s book
  var i: u32, j: u32, k: u32;
  for (i = m + 1; i  > l; --i) store<T>(buffer + ((i - 1    ) << alignof<T>()), LOAD<T>(inout, i - 1));
  for (j = m;     j  < r; ++j) store<T>(buffer + ((r + m - j) << alignof<T>()), LOAD<T>(inout, j + 1));
  for (k = l;     k <= r; ++k) {
    let a = load<T>(buffer + (j << alignof<T>()));
    let b = load<T>(buffer + (i << alignof<T>()));
    // @ts-ignore
    let c = (a - b);
    STORE<T>(inout, k, select(a, b, c < 0));
    STORE<T>(inout, k, select(b, a, c < 0));
    j -= u32(c  < 0);
    i += u32(c >= 0);
  }
}

function powersort<T>(arr: T[]): T[] {
  var lo: u32 = 0;
  var hi: u32 = arr.length - 1;
  var n = hi - lo + 1;
  // @ts-ignore
  var arrbuf = <ArrayBuffer>(arr.buffer_);

  if (n <= INSERTION_SORT_THRESHOLD) {
    if (ASC_SHRINK_LEVEL < 1) {
      switch (n) {
        case 3: {
          let a = LOAD<T>(arrbuf, 1);
          let b = LOAD<T>(arrbuf, 2);
          let c = (a - b);
          STORE<T>(arrbuf, 1, select(a, b, c < 0));
          b = select(b, a, c < 0);
          a = LOAD<T>(arrbuf, 0);
          c = (a - b);
          STORE<T>(arrbuf, 0, select(a, b, c < 0));
          STORE<T>(arrbuf, 2, select(b, a, c < 0));
        }
        case 2: {
          let a = LOAD<T>(arrbuf, 0);
          let b = LOAD<T>(arrbuf, 1);
          let c = (a - b);
          STORE<T>(arrbuf, 0, select(a, b, c < 0));
          STORE<T>(arrbuf, 1, select(b, a, c < 0));
        }
        case 1:
        case 0: return arr;
      }
    }
    insertionSort<T>(arrbuf, 0, hi, 0);
    return arr;
  }

  var lgPlus2         = (log2(n) + 2) << alignof<u32>();
  var leftRunStartBuf = memory.allocate(lgPlus2);
  var leftRunEndBuf   = memory.allocate(lgPlus2);

  memory.fill(leftRunStartBuf, 0xFF, <usize>lgPlus2);

	var top = 0;
  var buffer = memory.allocate(n << alignof<T>());

  var startA = lo;
  var endA   = extendRunRight<T>(arrbuf, startA, hi);

  var lenA = endA - startA + 1;
	if (lenA < minRunLen) {
		endA = min(hi, startA + minRunLen - 1);
		insertionSort<T>(arrbuf, startA, endA, lenA);
  }

  while (endA < hi) {
    let startB = endA + 1;
    let endB = extendRunRight<T>(arrbuf, startB, hi);
		let lenB = endB - startB + 1;

		if (lenB < minRunLen) {
			endB = min(hi, startB + minRunLen - 1);
			insertionSort<T>(arrbuf, startB, endB, lenB);
    }

    let k = nodePower(lo, hi, startA, startB, endB);

    for (let i: u32 = top; i > k; --i) {
      let offset = i << alignof<u32>();
      let start = load<u32>(leftRunStartBuf + offset);
			if (start == EMPTY) continue;
			mergeRuns<T>(arrbuf, start, load<u32>(leftRunEndBuf + offset) + 1, endA, buffer);
			startA = start;
			store<u32>(leftRunStartBuf + offset, EMPTY);
    }

    let offset = k << alignof<u32>();
		store<u32>(leftRunStartBuf + offset, startA);
    store<u32>(leftRunEndBuf   + offset, endA);
    startA = startB;
    endA = endB;
    top = k;
  }

	for (let i: u32 = top; i != 0; --i) {
    let offset = i << alignof<u32>();
    let start = load<u32>(leftRunStartBuf + offset);
		if (start == EMPTY) continue;
		mergeRuns<T>(arrbuf, start, load<u32>(leftRunEndBuf + offset) + 1, hi, buffer);
  }

  // dealloc aux buffers
  memory.free(leftRunStartBuf);
  memory.free(leftRunEndBuf);
  memory.free(buffer);

  return arr;
}

var arr: i32[];

export function init(): void {
  NativeMath.seedRandom(333);
  arr = new Array<i32>(1000000);
  for (let i = 0, len = arr.length; i < len; i++) {
    arr[i] = <i32><u64>(Math.random() * 1000000);
    // arr[i] = arr.length - 1 - i;
  }
}

export function test(): void {
  // powersort<i32>(arr, (a, b) => a - b);
  powersort<i32>(arr);
  // arr.sort((a, b) => a - b);
  // assert(isSorted<i32>(arr));
}