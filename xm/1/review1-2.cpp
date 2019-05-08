//filename: connect4.cpp
#include <iostream>

using namespace std;

#define NCOLS 7
#define NROWS 6

void print_board(char board[][NCOLS]) 
{
    cout << "Board:" << endl;

    //TODO
}

void reset_board(char board[][NCOLS])
{
    cout << "Board:" << endl;

    //TODO
}

void add(char board[][NCOLS], int ncol, char player) 
{
    if (ncol < 0 || ncol >= NCOLS) {
        cout << "Invalid move." << endl;
        return;
    }

    //TODO

    cout << "Invalid move." << endl;
}

int main()
{
    char board[NROWS][NCOLS];
    char players[] = {'r', 'b'};
    int player = 1, col;

    reset_board(board);

    do {
        cout << "Player " << player << " move: ";
        cin >> col;

        if (col >= 0) {
            //TODO
        } else if (col < 0) {
            cout << "Exit" << endl;
            break;
        }
    } while (true);

    print_board(board);
}