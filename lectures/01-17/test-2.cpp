#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream f("test-1.txt", ios::app);

    f << 99999 << endl;

    return 0;
}