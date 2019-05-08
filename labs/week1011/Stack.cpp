#include "Stack.h"
#include "Buffer.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
    i = 0;
    Buffer();
}

void Stack::push(char a)
{
    resize(i += 1);
    m[i-1] = a;
}

char Stack::pop()
{
    char popped;    //element being popped

    if (m[i-1] != '\0') {
        popped = m[i-1];
        resize(i -= 1);

        return popped;
        
    } else{
        cerr << "There is nothing in the stack" << endl;
    }
}

int Stack::read(istream& is)
{
    int n;
    is.read((char*)&n, sizeof(int));
    resize(n);
    is.read(m,n);
    i = n;
    
    return is.gcount();
}

int Stack::write(ostream& os) const
{
    return Buffer::write(os);
}

ostream& operator<< (ostream& os, const Stack& s) 
{
    static_cast<const Buffer&>(s);

    cout << "Stack = " << s.size() << "[";
    for (int i=0; i<s.size(); ++i) {
        cout << s.mem()[i];
    }
    cout << "]";
    return os;
}
