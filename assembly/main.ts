function swapRows(vals: Array<f64>, dim: i32, row1: i32, row2: i32): void {
  const i1 = row1 * dim;
  const i2 = row2 * dim;
  for (let c: i32 = 0; c < dim; ++c) {
    const e = vals[i1 + c];
    vals[i1 + c] = vals[i2 + c];
    vals[i2 + c] = e;
  }
}

export function mdeterm(n1: f64, n2: f64, n3: f64, n4: f64): f64 {
//export function mdeterm(vals: Array<f64>): f64 {

    const vals = [n1, n2, n3, n4];
    // only square matrixes have a determinant
    const dim: i32 = i32(Math.sqrt(vals.length));

    trace("dim", vals.length);

    // shortcut: use compact formulas for small matrixes
    switch (dim) {
        case 1: return vals[0];
        case 2: return vals[0] * vals[3] - vals[1] * vals[2];
        //case 3: return vals[0][0] * vals[1][1] * vals[2][2] + vals[0][1] * vals[1][2] * vals[2][0] + vals[0][2] * vals[1][0] * vals[2][1]
        //            - vals[2][0] * vals[1][1] * vals[0][2] - vals[2][1] * vals[1][2] * vals[0][0] - vals[2][2] * vals[1][0] * vals[0][1];
    }

    // clone the matrix for in-place LU decomposition
    const luVals = new Array<f64>();
    for (let i = 0; i < vals.length; ++i) luVals.push(vals[i]);

    // the sign of the determinant changes with every row-swap
    let sign: i32 = 1;

    // in-place LU decomposition: matrix L and U will be stored in the same matrix,
    // the diagonal elements of L (all one) will not be stored
    for (let i: i32 = 0, row: i32 = 0; i < dim; i += 1) {

        // find the first row with non-zero element in column `i` (skip leading rows)
        for (row = i; row < dim; row += 1) {
            if (luVals[row * dim + i] !== 0) { break; }
        }

        // if column `i` contains zeros only, the matrix is not invertible (determinant is zero)
        if (row === dim) { return 42; }

        // swap rows to move the row with non-zero column element to position `i`
        if (i !== row) {
            swapRows(luVals, dim, i, row);
            sign = -sign;
        }

        // the diagonal element
        const diag = luVals[i * dim + i];

        // update the remaining (following) rows in the matrix
        for (row = i + 1; row < dim; row += 1) {
            let irow = row * dim;
            // calculate the elements of the L matrix
            luVals[irow + i] /= diag;
            // calculate the elements of the U matrix
            const factor = -luVals[irow + i];
            for (let col = i + 1; col < dim; col += 1) {
                luVals[irow + col] += factor * luVals[i * dim + col];
            }
        }
    }

    // multiply the resulting diagonal elements of the U matrix
    let result: f64 = sign;
    for (let i = 0; i < dim; ++i) {
      result *= luVals[i * dim + i];
    }
    return result;
}
