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

  ranomize(): void {
      for (let i = 0; i < this.rows; i++) {
        for (let j = 0; j < this.cols; j++) {
          this.data[i][j] = Math.random() * 2 - 1;
        }
      }
   }

  @operator('+')
   add(n: Matrix): void {
         if (n instanceof Matrix) {
        for (let i = 0; i < this.rows; i++) {
          for (let j = 0; j < this.cols; j++) {
            this.data[i][j] += n.data[i][j];
          }
        }
      } else {
        for (let i = 0; i < this.rows; i++) {
          for (let j = 0; j < this.cols; j++) {
            this.data[i][j] += n;
          }
        }
      }
   }

}



export function add(): Matrix {
  let m1  = new Matrix(2, 2);
  m1.ranomize();
  let m2  = new Matrix(2, 2);
  m2.ranomize()
  var res =  m1 + m2;
  returnres;
}
