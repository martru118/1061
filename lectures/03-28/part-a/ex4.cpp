#include <iostream>

using namespace std;

int main()
{
  int *p;

  try {
  while(true) {
    p = new int[99999999999];
  }
  }
  catch(...) {
    cout << "Please save your work.  Not enough memory." << endl;
  }

  return 0;
}
