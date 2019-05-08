#ifndef __Stack_h__
#define __Stack_h__

#include "Buffer.h"

//Stack() has access to Buffer()
class Stack : public Buffer
{
  protected:
  int i;  //index in the stack

  public:
  Stack();
  void push(char a);
  char pop();

  int read(istream& is);
  int write(ostream& os) const;
  
  friend ostream& operator<< (ostream& os, const Stack& s);
};

#endif