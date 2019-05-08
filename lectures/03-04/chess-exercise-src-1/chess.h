#ifndef __chess_h__
#define __chess_h__

#include <iostream>
#include <string>

using namespace std;

enum Player {
  white = 0,
  black
};

class Square
{
};

class Piece : public Square
{
  protected:
  char symbol;
  Player player;
  string location;
  
  public:
  virtual void move(const string& mv) {}
};

class Pawn : public Piece
{
  public:
  Pawn(Player player, const string& location) 
  {
    symbol = 'P';
    this->location = location;
    this->player = player;
  }
  void move(const string& new_location) {
    // Logic
    location = new_location;
  }
};

class Board
{
  protected:
  char board[8][8];

  public:
  Board();
  const char& get_square(const string& loc) const;  
  char& get_square(const string& loc);  
};

class Chess
{
  public:

  
  void add_player(const string& std);
  void set_board();
  void prn_board();
};

#endif
