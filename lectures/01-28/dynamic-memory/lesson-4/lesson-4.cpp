#include <iostream>
#include "my_arr.h"

using namespace std;

int main(int argc, char** argv)
{
  if (argc != 3) {
    cerr << argv[0] << " <num of array> <size of array>" << endl;
    return -1;
  }

  int num = atoi(argv[1]);
  if (num < 1) {
    cerr << "num of array must be greater than 0" << endl;
    return -2;
  }


  int sz = atoi(argv[2]);
  if (sz < 1) {
    cerr << "size of array must be greater than 0" << endl;
    return -2;
  }

  srand(0);

  my_arr** v = new my_arr*[num];
  for (int i=0; i<num; ++i) {
    v[i] = alloc_arr(sz);
    cout << v[i] << endl;
    gen_arr(*v[i]);  
    prn_arr(*v[i]);
    dealloc_arr(&v[i]);
    cout << v[i] << endl;
  }
  delete [] v;

  return 0;
}
