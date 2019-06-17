
export function createMatrix(rows: i32, cols: i32): f64[][] {
   const data: f64[][] = new Array(rows);
   for (let i = 0; i < rows; i++) {
      data[i] = new Array<f64>(cols);
      for (let j = 0; j < cols; j++) {
          data[i][j] = Math.random() * 2 - 1;         
      }
   }     
   return data;     
}


