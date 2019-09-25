declare function log(value: string): void;

log("Hello from web assembly");

var board: boolean[][];

export function add(x: i32, y: i32): i32 {
  var arr: i32[] = [1, 2, 3];
  return arr[0] + arr[1];
}

export function gameOfLife(maxX: i32, maxY: i32): void {
  for (var y = 0; y < maxY; y++) {
    board[y] = []
    for (var x = 0; x < maxX; x++) {
      board[y][x] = false
    }
  }
}

export function tick(): void {
  for (var y = 0; y < board.length; y++) {
    board[y] = []
    for (var x = 0; x < board[0].length; x++) {
      board[y][x] = true
    }
  }
}