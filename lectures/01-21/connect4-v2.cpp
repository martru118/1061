#include <iostream>
#include <string>
#include <fstream>



#include "functions.h"

using namespace std;

int main(int argc, char** argv)
{
    // Comment
    cout << "eho";

    std::string filename;
    std::string players[2];
    char disks[] = { 'r', 'y' };
    int turn = 0; // 0 -> first player, 1 -> second player
    char board[6][7];
    int fill[7];

    switch (argc)
    {
    case 3:
        players[0] = string(argv[1]);
        players[1] = string(argv[2]);
        setup_board(board, fill);
        break;
    case 2:
        filename = string(argv[1]);
        if (!load_state_from_binary(filename, board, fill, players, disks, turn)) {
          cerr << "Error loading " << filename << endl;
          return -2;
        }
        break;
    default:
        cerr << "Usage: " << argv[0] << " <player one> <player two>" << endl;
        return -1; 
    }
        
    // if (argc != 3) {
    //     cerr << "Usage: " << argv[0] << " <player one> <player two>" << endl;
    //     return -1; 
    // }
    // else {
    //     players[0] = string(argv[2]);
    //     players[1] = string(argv[1]);
    // }

    while (true) {
        print_board(board);
        cout << players[turn] << "'s turn: ";
        char dummy;
        cin >> dummy;
        if (dummy != 'q') cin.putback(dummy);
        else break;

        int c;
        cin >> c; 
        if (c < 1 || c > 7) continue;
        else if (!place_disk(board, c-1, disks[turn], fill)) {
            cout << "Illegal move." << endl;
            continue;
        }
        else;
        turn = 1-turn;
    }

    save_state_as_binary("connect4-state.bin", board, fill, players, disks, turn);

    // for (int i=0; i<7; ++i) cout << fill[i] << " ";
    // save_state_as_binary("connect4-state.bin", board, fill, players, disks, turn);
    
    return 0;
}
