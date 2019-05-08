#include <iostream>
#include "my_arr.h"

using namespace std;

int main(int argc, char** argv)
{
  if (argc != 2) {
    cerr << argv[0] << " <size of array>" << endl;
    return -1;
  }

  int sz = atoi(argv[1]);
  if (sz < 1) {
    cerr << "size of array must be greater than 0" << endl;
    return -2;
  }

  srand(0);

  my_arr* v = alloc_arr(sz);
  cout << v << endl;
  gen_arr(*v);  // dereferencing
  prn_arr(*v);
  dealloc_arr(&v);
  cout << v << endl;
  
  return 0;
}
