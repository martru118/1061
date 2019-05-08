#include <iostream>
using namespace std;

int square(int x) 
{
    return x*x;
}

int neg(int x)
{
    return -x;
}

void print(int x)
{
    cout << x << endl;
}


//functor is a class that 
//overloads the function operator
class CSCI1061
{
    protected:
    int data;

    public:
    CSCI1061() {data = 0;}
    int operator()(int x) {return x*x;}
};

template <typename T>
void processing(T op, int x) {
    cout << op(x) << endl;
}

int main()
{

/*PART 1

    //function that takes an int and returns an int
    int (*fttaiarai)(int x); 
    fttaiarai = square;

    cout << square(2) << endl;
    cout << fttaiarai(2) << endl;

    CSCI1061 monday;
    cout << monday(8) << endl;

    for (int i=0; i<10; i++) {
        cout << fttaiarai(i) << endl;
    }
    cout << "Function was called ?? times" << endl;
*/

/*PART 2

    processing(square, 45);
    processing(neg, 45);

    CSCI1061 monday;
    processing(monday, 45);
*/
}