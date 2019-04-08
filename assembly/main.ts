import "allocator/arena";

import {
  LOAD,
  STORE,
  HEADER_SIZE,
  allocateUnsafe,
} from "internal/arraybuffer";

const minRunLen: u32 = ASC_SHRINK_LEVEL >= 1 ? 16 : 48;
// const minRunLen: u32 = 16;
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
  var twoN = right - left + 1; // 2 * n
  var l2 = left << 1;
  var l = startA + startB - l2;
  var r = startB + endB   - l2 + 1;
  var a = (<u64>l << 30) / twoN;
  var b = (<u64>r << 30) / twoN;
  return clz(<u32>(a ^ b));
}

function extendRunRight<T>(inout: ArrayBuffer, i: u32, right: u32): u32 {
	// assert(i <= right);
	let j = i;
	if (j == right) return j;
  // Find end of run, and reverse range if descending
	if ((LOAD<T>(inout, j) - LOAD<T>(inout, ++j)) > 0) { // Strictly Descending
		while (j < right && (LOAD<T>(inout, j + 1) - LOAD<T>(inout, j)) < 0) ++j;
    let k = j;
    // reverse
    while (i < k) {
  		let tmp = LOAD<T>(inout, i);
      STORE<T>(inout, i++, LOAD<T>(inout, k));
      STORE<T>(inout, k--, tmp);
    }
	} else { // Weakly Ascending
		while (j < right && (LOAD<T>(inout, j + 1) - LOAD<T>(inout, j)) >= 0) ++j;
	}
	return j;
}

// Merges runs arr[l..m-1] and arr[m..r] in-place into arr[l..r]
function mergeRuns<T>(inout: ArrayBuffer, l: u32, m: u32, r: u32, buffer: ArrayBuffer): void {
  --m; // accounts for different convention in Sedgewick’s book
  // assert(buffer.length >= r + 1);
  var i: u32, j: u32, k: u32;
  for (i = m + 1; i  > l; --i) STORE<T>(buffer, i - 1    , LOAD<T>(inout, i - 1));
  for (j = m;     j  < r; ++j) STORE<T>(buffer, r + m - j, LOAD<T>(inout, j + 1));
  for (k = l;     k <= r; ++k) {
    let a = LOAD<T>(buffer, j);
    let b = LOAD<T>(buffer, i);
    if ((a - b) < 0) {
      STORE<T>(inout, k, a); --j;
    } else {
      STORE<T>(inout, k, b); ++i;
    }
  }
}

function powersort<T>(arr: T[]): T[] {
  var lo: u32 = 0;
  var hi: u32 = arr.length - 1;
  var n = hi - lo + 1;
  var arrbuf = <ArrayBuffer>(arr.buffer_);

  if (n <= INSERTION_SORT_THRESHOLD) {
    if (ASC_SHRINK_LEVEL < 1) {
      switch (n) {
        case 3: {
          let a = LOAD<T>(arrbuf, 1), b = LOAD<T>(arrbuf, 2);
          if ((a - b) < 0) {
            STORE<T>(arrbuf, 1, b), STORE<T>(arrbuf, 2, a);
          }
          a = LOAD<T>(arrbuf, 0), b = LOAD<T>(arrbuf, 2);
          if ((a - b) < 0) {
            STORE<T>(arrbuf, 0, b), STORE<T>(arrbuf, 2, a);
          }
        }
        case 2: {
          let a = LOAD<T>(arrbuf, 0), b = LOAD<T>(arrbuf, 1);
          if ((a - b) < 0) {
            STORE<T>(arrbuf, 0, b), STORE<T>(arrbuf, 1, a);
          }
        }
        case 1:
        case 0: return arr;
      }
    }
    insertionSort<T>(arrbuf, 0, hi, 0);
    return arr;
  }

  var lgPlus2Size = (log2(n) + 2) << alignof<u32>();
  var leftRunStartBuf = allocateUnsafe(lgPlus2Size);
  var leftRunEndBuf   = allocateUnsafe(lgPlus2Size);

  memory.fill(
    changetype<usize>(leftRunStartBuf) + HEADER_SIZE,
    0xFF,
    <usize>lgPlus2Size
  );

	var top = 0;
  var buffer = allocateUnsafe(n << alignof<T>());

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
    // extend to minRunLen
		let lenB = endB - startB + 1;

		if (lenB < minRunLen) {
			endB = min(hi, startB + minRunLen - 1);
			insertionSort<T>(arrbuf, startB, endB, lenB);
    }

    let k = nodePower(lo, hi, startA, startB, endB);

    // assert(k !== top, "k !== top");

    for (let i: u32 = top; i > k; --i) {
      let start = LOAD<u32>(leftRunStartBuf, i);
			if (start == EMPTY) continue;
			mergeRuns<T>(arrbuf, start, LOAD<u32>(leftRunEndBuf, i) + 1, endA, buffer);
			startA = start;
			STORE<u32>(leftRunStartBuf, i, EMPTY);
    }

    // store left half of merge between A and B
		STORE<u32>(leftRunStartBuf, k, startA);
    STORE<u32>(leftRunEndBuf, k, endA);
    startA = startB;
    endA = endB;
    top = k;
  }

  // assert(endA == right, 'endA == right');

	for (let i: u32 = top; i != 0; --i) {
    let start = LOAD<u32>(leftRunStartBuf, i);
		if (start == EMPTY) continue;
		mergeRuns<T>(arrbuf, start, LOAD<u32>(leftRunEndBuf, i) + 1, hi, buffer);
  }

  // dealloc aux buffers
  memory.free(changetype<usize>(buffer));
  memory.free(changetype<usize>(leftRunStartBuf));
  memory.free(changetype<usize>(leftRunEndBuf));

  return arr;
}

var arr: i32[];

export function init(): void {
  // NativeMath.seedRandom(333);
  arr = new Array<i32>(1000000);
  for (let i = 0; i < arr.length; i++) {
    // arr[i] = <i32><u64>(Math.random() * 1000000);
    arr[i] = arr.length - 1 - i;
  }
}

export function test(): void {
  // powersort<i32>(arr, (a, b) => a - b);
  powersort<i32>(arr);
  // arr.sort((a, b) => a - b);
  // assert(isSorted<i32>(arr));
}
