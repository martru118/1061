#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    // argc = number of command line arguments
    // argv = values -- list of char arrays

    cout << "argc = " << argc << endl;

    for (int i=0; i<argc; ++i) {
        cout << i << " = " << argv[i] << endl;
    }

    return 0;
}