import { quickselectSlow } from './quickselect-slow';
import { quickselectFast } from './quickselect-fast';

let arr = new Array<i32>(100000);

for (let i = 0; i < arr.length; i++) {
  arr[i] = (arr.length - i) % 1000;
}


export function benchSlow(): void {
  quickselectSlow(arr, (a, b) => a - b, 500);
}

export function benchFast(): void {
  quickselectFast(arr, (a, b) => a - b, 500);
}