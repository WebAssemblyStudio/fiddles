const { check_sudoku_rs } = wasm_bindgen;

function runApp() {
  performance.mark("rs")
  check_sudoku_rs();
  performance.mark("rs2")
  performance.mark("ts")
  check_sudoku_ts();
  performance.mark("ts2")

  performance.measure("rsm", "rs", "rs2")
  performance.measure("tsm", "ts", "ts2")

  console.log(performance.getEntriesByType("measure"));
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);

function check_sudoku_ts () {
  var goodSudoku1 = new Sudoku([
    [7, 8, 4, 1, 5, 9, 3, 2, 6],
    [5, 3, 9, 6, 7, 2, 8, 4, 1],
    [6, 1, 2, 4, 3, 8, 7, 5, 9],
    [9, 2, 8, 7, 1, 5, 4, 6, 3],
    [3, 5, 7, 8, 4, 6, 1, 9, 2],
    [4, 6, 1, 9, 2, 3, 5, 8, 7],
    [8, 7, 6, 3, 9, 4, 2, 1, 5],
    [2, 4, 3, 5, 6, 1, 9, 7, 8],
    [1, 9, 5, 2, 8, 7, 6, 3, 4]
  ]);
  alert(`ts is valid: ${goodSudoku1.isValid()}!`, );
}

"use strict";
class Sudoku {
    constructor(board) {
        this.board = board;
        this.max_length = this.max_length_in_board();
    }
    static Range(n) {
        return new Set(Array.from({ length: n }, (n, i) => i + 1));
    }
    is_valid_row(row) {
        let expected_numbers = Sudoku.Range(this.max_length);
        return row.every(n => {
            if (expected_numbers.has(n)) {
                expected_numbers.delete(n);
                return true;
            }
            else {
                return false;
            }
        });
    }
    transpose_board() {
        let columns = [];
        for (let colIndex = 0; colIndex < this.max_length; colIndex++) {
            let new_row = [];
            for (let row of this.board) {
                new_row.push(row[colIndex]);
            }
            columns.push(new_row);
        }
        return columns;
    }
    has_valid_cols() {
        let columns = this.transpose_board();
        if (!columns.every(c => this.is_valid_row(c))) {
            return false;
        }
        return true;
    }
    has_valid_boxes() {
        // little squares have sides equal to the square root of the size
        let box_size = Math.sqrt(this.max_length);
        let boxes = [];
        for (let rowI = 0; rowI < this.max_length; rowI += box_size) {
            for (let colI = 0; colI < this.max_length; colI += box_size) {
                let new_box = [];
                for (let box_ri = rowI; box_ri < rowI + box_size; box_ri++) {
                    for (let box_ci = colI; box_ci < colI + box_size; box_ci++) {
                        new_box.push(this.board[box_ri][box_ci]);
                    }
                }
                boxes.push(new_box);
            }
        }
        if (!boxes.every(b => this.is_valid_row(b))) {
            return false;
        }
        return true;
    }
    max_length_in_board() {
        let max_length = this.board.length;
        for (let rowIndex = 0; rowIndex < this.board.length; rowIndex++) {
            let current_row_length = this.board[rowIndex].length;
            if (current_row_length > max_length) {
                max_length = current_row_length;
            }
        }
        return max_length;
    }
    isValid() {
        if (!this.board.every(row => this.is_valid_row(row))) {
            return false;
        }
        if (!this.has_valid_cols()) {
            return false;
        }
        if (!this.has_valid_boxes()) {
            return false;
        }
        return true;
    }
}
