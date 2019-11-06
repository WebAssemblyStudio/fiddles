let width: i32;
let height: i32;
let size: i32;

export function init(inputWidth: i32, inputHeight: i32): void {
  width = inputWidth;
  height = inputHeight;
  size = width * height;
}

export function step(): void {

  for(let row = 0; row < height; ++row) {

    const rowMinus1 = row == 0 ? height - 1 : row - 1;
    const rowPlus1 = row == height - 1 ? 0 : row + 1;

    for(let column = 0; column < width; ++column){
      const columnMinus1 = column == 0 ? width - 1 : column - 1;
      const columnPlus1 = column == width - 1 ? 0 : column + 1;

      const aliveNeighbors =
        load<u8>(rowMinus1 * width + columnMinus1) +
        load<u8>(rowMinus1 * width + column) +
        load<u8>(rowMinus1 * width + columnPlus1) +
        load<u8>(row * width + columnMinus1) +
        load<u8>(row * width + columnPlus1) +
        load<u8>(rowPlus1 * width + columnMinus1) +
        load<u8>(rowPlus1 * width + column) +
        load<u8>(rowPlus1 * width + columnPlus1);

      const alive = load<u8>(row * width + column);
      if(alive){
        switch(aliveNeighbors){
          default: {
            store<u8>(row * width + column,0);
            break;
          }
          case 2:
          case 3:
        }
      } else {
        switch(aliveNeighbors){
          case 3: {
            store<u8>(row * width + column, 1);          
            break
          }
          default:
        }
      }

    }
  }       

}