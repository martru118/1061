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
  this->c = 'u';
}

Square::~Square()
{
  if (pPiece) delete pPiece;
}

void Square::set_color(char c)
{
  this->c = c;
}

void Square::set_piece(Piece* pPiece)
{
  if (this->pPiece) {
    delete this->pPiece;    
  }
  this->pPiece = pPiece;
}

ostream& operator<<(ostream& os, const Square& s)
{
  os << s.c;
  if (s.pPiece) {
    os << s.pPiece->get_symbol();
    os << s.pPiece->get_player();
  }
  else {
    os << "  ";
  }

  return os;
}

Board::Board()
{
  // I have 8x8 squares.  Each square is colored 'u'.
  // I need to assign colors to these squares.

  for (int i=0; i<8; ++i) {
    for (int j=0; j<8; ++j) {
      if ((i + j) % 2 == 0) {
        board[i][j].set_color('b');
      }
      else {
        board[i][j].set_color('w');
      }
    }
  }  
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

void Board::setup_game()
{
  Player players[] = {white, black};

  // i, represents file
  // j, represent rank
  for (int k=0; k<2; ++k){ 
    board[0][k*7].set_piece(new Rook(players[k]));
    board[1][k*7].set_piece(new Knight(players[k]));
    board[2][k*7].set_piece(new Bishop(players[k]));
    board[3][k*7].set_piece(new Queen(players[k]));
    board[4][k*7].set_piece(new King(players[k]));
    board[5][k*7].set_piece(new Bishop(players[k]));
    board[6][k*7].set_piece(new Knight(players[k]));
    board[7][k*7].set_piece(new Rook(players[k]));

    for (int i=0; i<8; ++i){
      board[i][1+k*5].set_piece(new Pawn(players[k]));
    }
  }
}

ostream& operator<<(ostream& os, const Board& b)
{
  for (int rank=7; rank>=0; --rank) {
    os << rank+1 << "\t";
    for (int file=0; file<8; ++file) {
      os << b.board[file][rank] << " ";
    }
    os << endl;
  }

  os << "\n\t";
  for (int file=0; file<8; ++file) {
    os << (char)('a'+file)  << "   ";
  }

  return os;
}

void Chess::add_player(const string& std)
{
  cout << "Not implemented." << endl;
}

void Chess::set_board()
{ 
  board.setup_game();
}

void Chess::prn_board()
{
  cout << board << endl;
}
