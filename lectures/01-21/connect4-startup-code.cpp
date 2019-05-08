#include <iostream>
#include <string>

using namespace std;

void setup_board(char board[][7], int fill[])
{
    for (int i=0; i<7; ++i) fill[i] = 0;

    // _ -> empty, r -> red, y -> yellow
    for (int r=0; r<6; ++r) {
        for (int c=0; c<7; ++c) {
            board[r][c] = '_';
        }
    }
}

void print_board(char board[][7])
{
    for (int r=5; r>=0; --r) {
        for (int c=0; c<7; ++c) {
            cout << board[r][c] << ' ';
        }
        cout << endl;
    }
}

bool place_disk(char board[][7], int c, char d, int fill[])
{
    if (fill[c] > 5) return false;

    board[fill[c]][c] = d;
    fill[c] = fill[c] + 1;
    return true;
}

int main(int argc, char** argv)
{
    std::string players[2];
    char disks[] = { 'r', 'y' };
    int turn = 0; // 0 -> first player, 1 -> second player

    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <player one> <player two>" << endl;
        return -1; 
    }
    else {
        players[0] = string(argv[2]);
        players[1] = string(argv[1]);
    }

    char board[6][7];
    int fill[7];
    setup_board(board, fill);

    while (true) {
        cout << players[turn] << "'s turn: ";
        int c;
        cin >> c; 
        if (c < 1 || c > 7) continue;
        else if (!place_disk(board, c-1, disks[turn], fill)) {
            cout << "Illegal move." << endl;
            continue;
        }
        else;
        print_board(board);
        turn = 1-turn;
    }

    return 0;
}