#include "StackInt.h"
#include "Stack.h"
#include <iostream>
using namespace std;

StackInt::StackInt() 
{
    stride = 0;
    i = 0;
    resize(0);
    Stack();
}

void StackInt::push(int val)
{
    string sval = to_string(val);

    for (int n = 0; n < sval.length(); n++) {
        m[i] = sval[n];
        Stack::push(m[i]);
    }

    //clean up formatting
    Stack::push(',');
    stride += 1;    //increment stride after every comma

}

int StackInt::pop()
{
    int comma = 0;
    int start = 0;  //where to start popping
    int newSZ = 0;  //new size of the array

    string popped = "";

    if (m[i-1] != '\0') {
        //find the index to start popping
        for (int n = 0; n < i; n++) {
            if (m[n] == ',') {
                comma += 1;
            } else if (comma == stride-1) {
                start = n;
                break;
            }
        }

        //pop the elements
        for (int n = start; n < i; n++) {
            if (isalnum(m[n])) {
                popped += m[n];
                newSZ += 1;
            }
        }
        resize(i -= newSZ+1);
        stride -= 1;

    } else {
        cerr << "There is nothing in the stack" << endl;
    }

    return stoi(popped);    //int being popped

}

int StackInt::read(istream& is)
{
    return Stack::read(is);
}

int StackInt::write(ostream& os) const
{
    return Buffer::write(os);
}

ostream& operator<< (ostream& os, const StackInt& s) 
{
    static_cast<const Stack&>(s);

    cout << "StackInt = " << s.stride << "[";
    for (int i=0; i<s.size(); ++i) {
        cout << s.mem()[i];
    }
    cout << "]";
    return os;
}
