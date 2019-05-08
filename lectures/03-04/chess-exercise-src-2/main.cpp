#include <iostream>
#include "chess.h"

using namespace std;

int main()
{
  Chess game;
  game.add_player("Jane");
  game.add_player("John");
  game.set_board();
  game.prn_board();

  return 0;
}
