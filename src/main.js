
let memory;
function array2Buffer(memory, array, offset) {
  const shared = new Uint32Array(memory.buffer, offset, array.length);
  array.forEach((c, i) => shared[i] = c);
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
    println(offset, len) {
      let shared = new Uint32Array(memory.buffer, offset, len);
      console.log(`[After Sort]: ${shared}`);
    }
  }
})).then(ret => {
   const exports = ret.instance.exports;
  memory = exports.memory;
  const arr = getRandomArray(10);
  console.log(`[Before Sort]: ${arr}`);
  array2Buffer(memory, arr, exports.getArrayOffset());
  
  const startTime = performance.now();
  exports.sort();
  const endTime = performance.now();
  console.log(`wasm done in ${endTime - startTime}ms.`);
  sortByJs(arr);
}).catch(console.error);

function sortByJs(arr) {
  const startTime = performance.now();
  console.log('[After Sort]:', sort(arr));
  const endTime = performance.now();
  console.log('js done in ${endTime - startTime}ms.');
}



function quicksort(arr, start, end) {
  if (end - start <= 0) return;
  let left = start;
  let right = end - 1;
  while (left < right) {
    if (arr[left] > arr[left + 1]) {
      // [arr[left], arr[left + 1]] = [arr[left + 1], arr[left]];
      const tmp = arr[left];
      arr[left] = arr[left + 1];
      arr[left+1] = tmp;
      left++;
    } else {
      const tmp = arr[right];
      arr[right] = arr[left + 1];
      arr[left+1] = tmp;
      right--;
    }
  }
  quicksort(arr, start, left);
  quicksort(arr, left + 1, end);
}

function sort(arr) {
  const arr = arr.slice();
  quicksort(arr, 0, arr.length);
  return arr;
}

