#ifndef __chess_h__
#define __chess_h__

#include <iostream>
#include <string>

using namespace std;

enum Player {
  white = 0,
  black
};

class Piece
{
  protected:
  char symbol;
  Player player;

  public:
  Piece(char symbol, Player player);

  inline char get_symbol() const { return symbol; }
  inline Player get_player() const { return player; }
};

class Pawn : public Piece
{
  public:
  Pawn(Player player);
};

class King : public Piece
{
  public:
  King(Player player);
};

class Queen : public Piece
{
  public:
  Queen(Player player);
};

class Bishop : public Piece
{
  public:
  Bishop(Player player);
};

class Rook : public Piece
{
  public:
  Rook(Player player);
};

class Knight : public Piece
{
  public:
  Knight(Player player);
};

class Square
{
  protected:
  Piece* pPiece;
  char c;

  public:
  Square(Piece* pPiece = 0);
  ~Square();

  void set_color(char c);
  void set_piece(Piece* pPiece);
  
  friend ostream& operator<<(ostream& os, const Square& s);
};

class Board
{
  protected:
  Square board[8][8];

  public:
  Board();
  
  Square& get_square(const string& loc);
  const Square& get_square(const string& loc) const;

  friend ostream& operator<<(ostream& os, const Board& b);

  void setup_game();
};

class Chess
{
  protected:
  Board board;

  
  public:

  void add_player(const string& std);
  void set_board();
  void prn_board();
};

#endif
