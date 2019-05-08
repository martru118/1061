#include <iostream>
#include "person.h"

using namespace std;

int main()
{
  Person a("Mathilda", 2000, 01, 01);
  cout << a << endl;

  Person b;
  cout << b << endl;

  Person c(a);
  cout << c << endl;  

  return 0;
}
