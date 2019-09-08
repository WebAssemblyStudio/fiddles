

let instance = null;
let memoryStates = new WeakMap();

const N = 1000;
function array2Buffer(memory, offset, array) {
  const shared = new Uint32Array(memory.buffer, offset, array.length);
  array.forEach((c, i) => shared[i] = c);
}

function buffer2Array(memory, offset, len) {
  const shared = new Uint32Array(memory.buffer, offset, len);
  return Array.from(shared);
}

function getRandomArray(n) {
  const arr = [];
  while(n--) arr.push(Math.round(Math.random() * n));
  return arr;
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {
   env: {
     getSize: () => N
  }
})).then(ret => {
  instance = ret.instance;
  const arr = getRandomArray(N);
  console.log(`[Before Sort]: ${arr}`);
  sortByWasm(arr);
  sortByJs(arr);
}).catch(console.error);


function sortByWasm(arr) {
  const { memory, sort, getArrayOffset } = instance.exports;
  const offset = getArrayOffset();
  array2Buffer(memory, offset, arr);
  const startTime = performance.now();
  sort();
  const endTime = performance.now();
  const array = buffer2Array(memory, offset, arr.length);
  console.log(`[After Sort By Wasm]: ${array.slice(0, 10)}... const ${endTime - startTime}ms.`);
}

function sortByJs(arr) {
  const array = arr.slice();
  const startTime = performance.now();
  quicksort(array, 0, array.length);
  const endTime = performance.now();
  console.log(`[After Sort By js]: ${array.slice(0, 10)}... cost ${endTime - startTime}ms.`);
}

function quicksort(arr, start, end) {
  if (end - start <= 0) return;
  let left = start;
  let right = end - 1;
  while (left < right) {
    if (arr[left] > arr[left + 1]) {
      [arr[left], arr[left + 1]] = [arr[left + 1], arr[left]];
      left++;
    } else {
      [arr[right], arr[left + 1]] = [arr[left + 1], arr[right]];
      right--;
    }
  }
  quicksort(arr, start, left);
  quicksort(arr, left + 1, end);
}




function syscall(instance, n, args) {
  switch (n) {
    default:
      // console.log("Syscall " + n + " NYI.");
      break;
    case /* brk */ 45: return 0;
    case /* writev */ 146:
      return instance.exports.writev_c(args[0], args[1], args[2]);
    case /* mmap2 */ 192:
      debugger;
      const memory = instance.exports.memory;
      let memoryState = memoryStates.get(instance);
      const requested = args[1];
      if (!memoryState) {
        memoryState = {
          object: memory,
          currentPosition: memory.buffer.byteLength,
        };
        memoryStates.set(instance, memoryState);
      }
      let cur = memoryState.currentPosition;
      if (cur + requested > memory.buffer.byteLength) {
        const need = Math.ceil((cur + requested - memory.buffer.byteLength) / 65536);
        memory.grow(need);
      }
      memoryState.currentPosition += requested;
      return cur;
  }
}