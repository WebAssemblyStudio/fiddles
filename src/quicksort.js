function quicksort(arr, start, end) {
  if (end - start <= 0) return;
  let left = start;
  let right = end - 1;
  while (left < right) {
    console.log(left, right, arr);
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

window.sort = function sort(arr) {
  const arr = arr.slice();
  quicksort(arr, 0, arr.length);
  return arr;
}