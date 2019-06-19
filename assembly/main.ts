class Matrix {
    rows:i64;
    cols:i64;
    data:f64[][];
   constructor(rows:i64, cols:i64) {  
     this.rows = rows;
     this.cols = cols;
     this.data = [];
     for (let i = 0; i < this.rows; i++) {
         this.data[i] = [];
       for (let j = 0; j < this.cols; j++) {
         this.data[i][j] = 0;         
       }
     }           
   }

  ranomize(matrix: Matrix): void {
      for (let i = 0; i < this.rows; i++) {
        for (let j = 0; j < this.cols; j++) {
          this.data[i][j].push(Math.random() * 2 - 1);
        }
      }
   }

  @operator('+')
   add(matrix: Matrix): Matrix {
       return new Matrix(this.rows + matrix.rows, this.cols + matrix.cols);
   }


}



export function add(): Matrix {
  let m1  = new Matrix(2, 2);
  m1.ranomize();
  let m2  = new Matrix(2, 2);
  m2.ranomize()
  return m1 + m2;
}
