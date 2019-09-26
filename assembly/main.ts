declare function log(value: string): void;
declare function render(board: boolean[][]): void;

var board: boolean[][];

export function add(x: i32, y: i32): i32 {
  var arr: i32[] = [1, 2, 3];
  return arr[0] + arr[1];
}

export function gameOfLife(maxX: i32, maxY: i32): void {
  board = new Array(maxY)
  for (let y: i32 = 0; y < maxY; y++) {
    board[y] = new Array(maxX)
    for (let x: i32 = 0; x < maxX; x++) {
      board[y][x] = true
    }
  }
}

export function tick(): void {
  // render(board)
}