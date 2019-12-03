function swapRows(vals: Float64Array, dim: i32, row1: i32, row2: i32): void {
  for (let i: i32 = 0, i1: i32 = row1 * dim, i2: i32 = row2 * dim; i < dim; ++i, ++i1, ++i2) {
    const e = vals[i1];
    vals[i1] = vals[i2];
    vals[i2] = e;
  }
}

export function mdeterm(mem2: usize): f64 {
//export function mdeterm(vals: Array<f64>): f64 {

    trace("1", 1, mem2);

    const vals = new Float64Array(4);
    const O = 0;
    vals[0] = load<u8>(O);
    vals[1] = load<u8>(O + 1);
    vals[2] = load<u8>(O + 2);
    vals[3] = load<u8>(O + 3);

    trace("1", 4, load<u8>(O), vals[1], vals[2], vals[3]);

    // only square matrixes have a determinant
    const dim: i32 = i32(Math.sqrt(vals.length));

    // shortcut: use compact formulas for small matrixes
    switch (dim) {
        case 1: return vals[0];
        case 2: return vals[0] * vals[3] - vals[1] * vals[2];
        case 3: return vals[0] * vals[4] * vals[8] + vals[1] * vals[5] * vals[6] + vals[2] * vals[3] * vals[7]
                     - vals[6] * vals[4] * vals[2] - vals[7] * vals[5] * vals[0] - vals[8] * vals[3] * vals[1];
    }

    // clone the matrix for in-place LU decomposition
    const luVals = new Float64Array(vals.length);
    for (let i = 0, l = vals.length; i < l; ++i) {
      luVals[i] = vals[i];
    }

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
        if (row === dim) { return 0; }

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
