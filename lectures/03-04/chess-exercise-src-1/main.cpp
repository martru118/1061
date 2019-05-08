#include <iostream>
#include <string>
#include "chess.h"

using namespace std;

int main()
{
  Board b;
  cout << b.get_square("a1") << endl;
  cout << b.get_square("g8") << endl;

  Pawn p(white, "a2");

  Chess game;
  game.add_player("Jane");
  game.add_player("John");
  game.set_board();
  game.prn_board();

  return 0;
}
