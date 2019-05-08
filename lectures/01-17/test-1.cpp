#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream f("test-1.txt");
    if (f.is_open()) {
        cout << "Successfully opened file" << endl;

        while (!f.eof() && !f.fail()) {
            int n;
            f >> n;
            cout << "Number read: " << n << endl;
        }
    }
    else {
        cerr << "Cannot open file" << endl;
    }
    
    // int n;
    // f >> n;
    // cout << "Number read: " << n << endl;

    // int n;
    // cin >> n;
    // cout << "Number entered: " << n << endl;

    return 0;
}