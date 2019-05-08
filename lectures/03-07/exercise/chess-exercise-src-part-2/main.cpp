#include <iostream>
#include "chess.h"

using namespace std;

int main()
{
  Chess game;
  // game.add_player("Jane");
  // game.add_player("John");

  game.set_board();

  game.prn_board();

  // game.move_piece(a3, c4);
  // // and so on ...

  // game.prn_allowed_moves(c4);
  // // and so on ...
  
  return 0;
}
