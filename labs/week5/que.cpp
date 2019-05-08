#include "que.h"

using namespace std;

//creates an empty que
que::que() {
    front = NULL;
    back = NULL;
}

//deletes the que
que::~que() {
    while(!isEmpty()) {
        pop();
    }
}

//check if the que is empty
bool que::isEmpty() {
    return (front == NULL && back == NULL);
}

//adds a new Node to the back of the que
void que::push(char c) {
    Node *nq = new Node;
    nq->data = c;
    nq->next = front;   //connect new node to the front
    front = nq;     //declare front equal to a new node
}

//delete a Node from the front of the que
char que::pop() {
    if (!isEmpty()) {
        char dq = front->data;
        Node *current = new Node;
        Node *previous = new Node;
        current = front;
        
        //move pointers through que
        while(current->next != NULL) {
            previous = current;
            current = current->next;
        }
        //point previous node to the second-last node
        back = previous;
        previous->next = NULL;

        //current node points to last node before being deleted
        delete current;
        return dq;

    } else {
        cerr << "Nothing in que." << endl;
        exit(1);
    }
}
