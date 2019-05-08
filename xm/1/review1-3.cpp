#include <iostream>

using namespace std;

void reset_pattern(int pattern[][10]) 
{
    //TODO
}

void print_pattern(int pattern[][10]) 
{
    bool row_printed = false;

    for (int i = 0; i < 10; ++i) {
        row_printed = false;
        for (int j = 0; j < 10; ++j) {
            if (pattern[i][j] > 0) {
                row_printed = true;
                cout << pattern[i][j] << ' ';
            }
        }

        if (!row_printed) {
            cout << endl;
        }
    }
}

int main() 
{
    int height;
    int coef = 1;
    cout << "Enter height (between 1 and 10): ";
    cin >> height;

    int pattern[10][10];
    //reset_pattern(pattern);

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if (j == 0 || i == 0)
                coef = 1;
            else
                coef = coef*(i-j+1)/j;

            cout << coef << ' ';
        }
        cout << endl;
    }

    //print_pattern(pattern);

    return 0;
}