@external("env", "board")
declare function board(index: i32): i32;//returns the piece at the given board position

@external("env", "maxlegal")//returns the number of possible legal moves
declare function maxlegal(): i32;

@external("env", "randint")//returns a random number between 0 and max (exclusive)
declare function randint(max: i32): i32;

@external("env", "legal")//returns the nth legal move
declare function legal(index: i32): i32;

// This is called on every move, it should return a legal move in the correct encoding
// An instance of a program only plays for one side at a time
export function move(): i32 {
  // Iterate over all legal moves
  for (var i=0;i<maxlegal();i++) {
    // Query the board for the piece at the source square of the legal move
    var piece = board(legal(i)&(64-1))
    // If it is a white or black pawn... (a program may play as black or white, we didn't check
    // what color we are, but since legal moves only use our own pieces, we can check this way)
    if (piece == 1 || piece == 2) {
      // Use this legal move
      return legal(i);
    }
  }
  // Otherwise just use a random legal move
  return legal(randint(maxlegal()));
}