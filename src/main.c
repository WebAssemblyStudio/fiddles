static const int width = 3;
static const int height = 3;

struct game {
  int challenger;
  int host;
  int turn;
  int winner;
  int board[9];
};


struct game* create(int challenger,int host) {
    struct game g;
    g.challenger = challenger;
    g.host = host;
    g.turn = host;
    g.winner = 0;
    initialize_board(&g);
    return &g;
}

