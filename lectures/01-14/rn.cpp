#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    cout << "RAND_MAX = " << RAND_MAX << endl;

    // int between 0 and RAND_MAX
    for (int i=0; i<5; i++) {
        cout << rand() << endl;
    }

    // int between 0 and 5
    for (int i=0; i<5; i++) {
        cout << rand()%6 << endl;
    }

    // float between 0.0 and 1.0
    for (int i=0; i<5; i++) {
        cout << static_cast<float>(rand())/RAND_MAX << endl;
    }

    return 0;
}
