#ifndef _que_h_
#define _que_h_

#include <iostream>
#include <cstdlib>
#include <cassert>
#include "str.h"


struct Node
{
    char data;
    Node* next;
};

class que {
    protected:
        Node* front;
        Node* back;
        str _storage; // This is your string class that can dynamically grow when needed.
        
    public:
        que();  // Default constructor.  Creates an empty queue.
        que(const str &s);
        ~que(); // Destructor.
        bool isEmpty(); //checks if queue is empty
        int size();
        void compress();
        
        char pop();
        void push(char c); 
};

char random_char()
{
  char ch = char((rand() % 26) + 65);
  return ch;
}

int main()
{
/*
    que q;

    for (int i=0; i<10; ++i) q.push(random_char());
    cout << "size = " << q.size() << endl;
    
    for (int i=0; i<4; ++i) cout << q.pop() << endl;
    cout << "size = " << q.size() << endl;

    q.compress();
    cout << "size = " << q.size() << endl;
    
    return 0;
*/

    que q;
    q.push('h');
    q.push('d');
    cout << q.pop() << endl;
    cout << q.pop() << endl;
}


#endif