// Bitwise operator

#include <iostream>

using namespace std;

// Hexadecimal
//0  0000
//1  0001
//2  0010
//3  0011
//4  0100
//5  0101
//6  0110
//7  0111
//8  1000
//9  1001
//A  1010
//B  1011
//C  1100
//D  1101
//E  1110
//F  1111

int main(int argc, char** argv)
{
    // c: 65 (int)
    // c: 87654321
    //    01000001 (binary)
    // c: 41 (hex)

    unsigned char c = 'A';

    cout << c << endl;
    cout << static_cast<int>(c) << endl;
    cout << dec << static_cast<int>(c) << endl;
    cout << hex << static_cast<int>(c) << endl;
    cout << oct << static_cast<int>(c) << endl;
    
    int i = -34332;
    cout << hex << i << endl;

    return 0;
}
