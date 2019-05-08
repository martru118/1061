#include "chess.h"

Piece::Piece(char symbol, Player player)
{
  this->symbol = symbol;
  this->player = player;
}

Pawn::Pawn(Player player) : Piece('P', player) {}

King::King(Player player) : Piece('K', player) {}

Queen::Queen(Player player) : Piece('Q', player) {}

Rook::Rook(Player player) : Piece('R', player) {}

Bishop::Bishop(Player player) : Piece('B', player) {}

Knight::Knight(Player player) : Piece('N', player) {}

Square::Square(Piece* pPiece)
{
  this->pPiece = pPiece;
}

Square::~Square()
{
  if (pPiece) delete pPiece;
}

Board::Board()
{
  for (int i=0; i<8; ++i) {
    for (int j=0; j<8; ++j) {
      board[i][j] = Square(new King(white));
    }
  }

  // i, represents file
  // j, represent rank
  // for (int k=0; k<2; ++k){ 
  //   board[0][k*7] = 'R';
  //   board[1][k*7] = 'N';
  //   board[2][k*7] = 'B';
  //   board[3][k*7] = 'Q';
  //   board[4][k*7] = 'K';
  //   board[5][k*7] = 'B';
  //   board[6][k*7] = 'N';
  //   board[7][k*7] = 'R';

  //   for (int i=0; i<8; ++i){
  //     board[i][1+k*5] = 'P';
  //   }
  // }
}

Square& Board::get_square(const string& loc)
{
   int file = loc[0] - 'a';
   int rank = loc[1] - '1';
   return board[file][rank];
}

const Square& Board::get_square(const string& loc) const
{
   int file = loc[0] - 'a';
   int rank = loc[1] - '1';
   return board[file][rank];
}

void Chess::add_player(const string& std)
{
  cout << "Not implemented." << endl;
}

void Chess::set_board()
{ 
  cout << "Not implemented." << endl;
}

void Chess::prn_board()
{
  cout << "Not implemented." << endl;
}
